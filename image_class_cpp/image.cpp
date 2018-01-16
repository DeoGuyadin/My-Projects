/* Author: Deo Guyadin */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>


/* image class collects data on a greyscale image.
   Images represented as text file.
   Both computes information based on the image and also alters images.
   image text file represtentation as:
        <num_rows> <num cols> <min pixel value> <max pixel value>
        [2D Image Matrix]
*/
class image {
private:
    std::vector< std::vector<int> > input_image;
    std::vector<int> histogram;
    int rows, cols, min_val, max_val;


    /* Computes the histogram of the image. */
    void compute_histogram () {
        histogram.resize (this->max_val, 0);

        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                this->histogram[this->input_image[i][j]]++;
            }
        }
    } // compute_histogram


    /* load 9x9 neighbors of a designated pixel into an aray label neigh_ary */
    void load_neighbors (int neigh_ary[], std::vector< std::vector<int> > &mirror_framed, int row, int col) {
        int ind = 0;
        for (size_t i = row - 1; i <= row + 1; i++) {
            for (size_t j = col - 1; j <= col + 1; j++) {
                neigh_ary[ind++] = mirror_framed[i][j];
            }
        }
    } // load_neighbors


    /* Performs mirror framing on a image to be filtered. */
    void mirror_framing (std::vector< std::vector<int> > &input, int num_rows, int num_cols) {
        for(size_t i = 1; i < num_rows; i++) {
            input[i][0] = input[i][1];
            input[i][num_cols + 1] = input[i][num_cols];
        }

        for(size_t j = 1; j < num_cols; j++) {
            input[0][j] = input[1][j];
            input[num_rows + 1][j] = input[num_rows][j];
        }
    }// mirrorFramed


    friend image avg_filter (image &in_image);
    friend image median_filter (image &in_image);
    friend class connected_component;


public:
    /* Load from decalred variables */
    image (std::vector< std::vector<int> > &in_image, int num_rows, int num_cols, int min_val, int max_val) {
        this->rows = num_rows;
        this->cols = num_cols;
        this->min_val = min_val;
        this->max_val = max_val;

        input_image.resize (this->rows, std::vector<int> (this->cols, 0));
        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                this->input_image[i][j] = in_image[i][j];
            }
        }

        compute_histogram ();
    } // CONSTRUCTOR


    /* Load from input text file by specifying the text file address. */
    image (std::string input) {
        std::ifstream infile;
        infile.open (input.c_str());
        if (!infile) {
            std::cerr << "Cannot Open File";
            exit (1);
        }

        infile >> rows;
        infile >> cols;
        infile >> min_val;
        infile >> max_val;

        input_image.resize (this->rows, std::vector<int> (this->cols, 0));
        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                infile >> this->input_image[i][j];
            }
        }

        compute_histogram ();

        infile.close ();
    } // CONSTRUCTOR


    /* Threshold an image with an automatically determined threshold value. */
    image auto_thresh_image () {
        return this->manual_thresh_image (this->auto_thresh_val ());
    } // auto_thres_image


    /* Threshold an image by manually inputting a threshold value. */
    image manual_thresh_image (int thres_val) {
        std::vector< std::vector<int> > thresh_out;
        thresh_out.resize (this->rows, std::vector<int> (this->cols, 0));

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                if (this->input_image[i][j] < thres_val)
                    thresh_out[i][j] = 0;
                else
                    thresh_out[i][j] = 1;
            }
        }

        return image(thresh_out, this->rows, this->cols, 0, 1);
    } // manual_thresh_image


    /* Auto compute ideal threshold value for an image using the deepest
       concavity method.
    */
    int auto_thresh_val () {
        image avg_image = avg_filter (*this);
        std::vector<int> mirrored_histogram (avg_image.max_val + 4, 0);
        std::vector<int> smoothed_histogram (avg_image.max_val, 0);
        int neigh_ary[5], cycle = 0;
        for (size_t i = 2; i < avg_image.max_val + 2; i++) {
            mirrored_histogram[i] = avg_image.histogram[i-2];
        }

        while (cycle++ < 8) {
            mirrored_histogram[0] = mirrored_histogram[3];
            mirrored_histogram[1] = mirrored_histogram[2];
            mirrored_histogram[avg_image.max_val] = mirrored_histogram[avg_image.max_val - 1];
            mirrored_histogram[avg_image.max_val + 1] = mirrored_histogram[avg_image.max_val - 2];

            for (size_t i = 2; i < avg_image.max_val + 2; i++) {
                neigh_ary[0] = mirrored_histogram[i - 2];
                neigh_ary[1] = mirrored_histogram[i - 1];
                neigh_ary[2] = mirrored_histogram[i];
                neigh_ary[3] = mirrored_histogram[i + 1];
                neigh_ary[4] = mirrored_histogram[i + 2];
                std::sort (neigh_ary, neigh_ary + 5);
                smoothed_histogram[i] = neigh_ary[2];
            }

            for (size_t i = 2; i < avg_image.max_val + 2; i++) {
                mirrored_histogram[i] = smoothed_histogram[i-2];
            }
        }

        int p1, p2, index = 0;

        do {
            p1 = index++;
        } while(smoothed_histogram[p1] <= smoothed_histogram[index]);
        do {
            p2 = index++;
        } while(smoothed_histogram[p2] >= smoothed_histogram[index]);
        do {
            p2 = index++;
        } while(smoothed_histogram[p2] <= smoothed_histogram[index]);

        double m = (double)((smoothed_histogram[p2] - smoothed_histogram[p1]) / (p2 - p1));
        double b = (double)(smoothed_histogram[p1] / (m * p1));

        index = p1;
        int thresh_ind = p1;
        double diff = (double)((m * index) + b) - (double)(smoothed_histogram[index]);
        for (index = p1+1; index <= p2; index++) {
            if (diff <= (double)((m * index) + b) - (double)(smoothed_histogram[index])) {
                diff = (double)((m * index) + b) - (double)(smoothed_histogram[index]);
                thresh_ind = index;
            }
        }

        std::cout << "auto-thres-val: " << avg_image.histogram[thresh_ind] << "\n\n";
        return avg_image.histogram[thresh_ind];
    } // auto_thres_val


    /* Prints the text file representation of a greyscale or binary image. */
    void print (std::string dest_path) {
        std::ofstream outfile;
        outfile.open (dest_path.c_str ());
        if (!outfile) {
            std::cerr << "Cannot Open File\n";
            exit (1);
        }

        outfile << this->rows << " ";
        outfile << this->cols << " ";
        outfile << this->min_val << " ";
        outfile << this->max_val << std::endl;

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                outfile << this->input_image[i][j] << " ";
            }
            outfile << std::endl;
        }
    } // print


    /* Print the image to a user designated text file without printing zeroes
       to easily distinguish the image from its background. (Performs better on
       images already thresholded.)
    */
    void pretty_print (std::string dest_path) {
        std::ofstream outfile;
        outfile.open (dest_path.c_str ());
        if (!outfile) {
            std::cerr << "Cannot Open File\n";
            exit (1);
        }

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                if (this->input_image[i][j] > 0) {
                    outfile << this->input_image[i][j] << " ";
                }
                else
                    outfile << "  ";
            }
            outfile << std::endl;
        }

        outfile.close ();
    } // pretty_print


    /* Prints calculated histogram to destination text file. */
    void print_histogram (std::string dest_path) {
        std::ofstream outfile;
        outfile.open (dest_path.c_str ());
        if (!outfile) {
            std::cerr << "Cannot Open File\n";
            exit (1);
        }

        for (size_t i = 0; i <= this->max_val; i++) {
            outfile << "(" << i << ")" << this->histogram[i] << "\t";
            for (size_t j = 0; j < this->histogram[i]; j++) {
                outfile << "+";
            }
            outfile << std::endl;
        }

        outfile.close ();
    } // print_histogram
};


/* Performs 3x3 average filtering on an image and returns a new filtered
   image.
*/
image avg_filter (image &in_image) {
    int neighbor_ary[9];
    for (size_t i = 0; i < 9; i++) {
        neighbor_ary[i] = 0;
    }

    std::vector< std::vector<int> > mirror_framed_ary;
    mirror_framed_ary.resize (in_image.rows + 2, std::vector<int> (in_image.cols + 2, 0));

    for (size_t i = 1; i < in_image.rows + 1; i++) {
        for (size_t j = 1; j < in_image.cols + 1; j++) {
            mirror_framed_ary[i][j] = in_image.input_image[i-1][j-1];
        }
    }

    std::vector< std::vector<int> > temp_ary;
    temp_ary.resize (in_image.rows, std::vector<int> (in_image.cols, 0));

    in_image.mirror_framing (mirror_framed_ary, in_image.rows, in_image.cols);

    int neighbor_sum;
    int new_min = in_image.max_val;
    int new_max = in_image.min_val;
    for (size_t i = 1; i < in_image.rows + 1; i++) {
        for (size_t j = 1; j < in_image.cols + 1; j++) {
            neighbor_sum = 0;
            in_image.load_neighbors (neighbor_ary, mirror_framed_ary, i, j);
            for (size_t ind = 0; ind < 9; ind++) {
                neighbor_sum += neighbor_ary[ind];
            }
            temp_ary[i-1][j-1] = neighbor_sum/9;
            if (temp_ary[i-1][j-1] < new_min) {
                new_min = temp_ary[i-1][j-1];
            }
            if (temp_ary[i-1][j-1] > new_max) {
                new_max = temp_ary[i-1][j-1];
            }
        }
    }

    return image (temp_ary, in_image.rows, in_image.cols, new_min, new_max);
} // avg_filter


/* Performs 3x3 median filtering on an image and returns a new filtered
   image.
*/
image median_filter (image &in_image) {
    int neighbor_ary[9];
    for (size_t i = 0; i < 9; i++) {
        neighbor_ary[i] = 0;
    }
    std::vector< std::vector<int> > mirror_framed_ary;
    mirror_framed_ary.resize (in_image.rows + 2, std::vector<int> (in_image.cols + 2, 0));
    for (size_t i = 1; i < in_image.rows + 1; i++) {
        for (size_t j = 1; j < in_image.cols + 1; j++) {
            mirror_framed_ary[i][j] = in_image.input_image[i-1][j-1];
        }
    }

    std::vector< std::vector<int> > temp_ary;
    temp_ary.resize (in_image.rows, std::vector<int> (in_image.cols, 0));

    in_image.mirror_framing (mirror_framed_ary, in_image.rows, in_image.cols);
    int new_min = in_image.max_val;
    int new_max = in_image.min_val;
    for (size_t i = 1; i < in_image.rows + 1; i++) {
        for (size_t j = 1; j < in_image.cols + 1; j++) {
            in_image.load_neighbors (neighbor_ary, mirror_framed_ary, i, j);
            std::sort (neighbor_ary, neighbor_ary + 9);
            temp_ary[i-1][j-1] = neighbor_ary[5];
            if (temp_ary[i-1][j-1] < new_min) {
                new_min = temp_ary[i-1][j-1];
            }
            if (temp_ary[i-1][j-1] > new_max) {
                new_max = temp_ary[i-1][j-1];
            }
        }
    }
    return image (temp_ary, in_image.rows, in_image.cols, new_min, new_max);
} // median_filter
