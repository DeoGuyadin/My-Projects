Title: image.cpp

Author: Deo Guyadin

Description: 

	1) Program contains the definition of an image class which contains a a numeric text
	   representation of a gray-scale image with additional features.

	2) Also, on the declaration of an image, it's histogram is also created.

	3) Class variables include integer variable defining the images number of rows (rows),
	   number of columns (cols), minimum gray-scale value in the image (min_val), maximum
	   gray-scale value in the image (max_val). Also contains a 2-dimensional integer vector
	   representation of the image and an integer vector containing the histogram.

	4) Class functions auto_thresh_image and manual_thresh_image allow you to perform
	   thresholding on an image to convert the gray-scale image to a binary image with the
	   latter allowing you to enter a custom threshold value as a parameter. The function
	   auto_thresh_val allows for the automatic calculation of a suitable threshold value
	   using the deepest concavity method.

	5) Non-class functions avg_filter and median_filter allow for average filtering and
	   median filtering respectively, to be performed on the image. 
