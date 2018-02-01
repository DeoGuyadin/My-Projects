/* Author: Deo Guyadin*/

#include <conio.h>
#include <iostream>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

typedef char box[11][21];

box empty_box =  {{' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                  {' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '}};

box select_box = {{' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
                  {'|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
                  {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                  {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                  {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                  {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                  {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                  {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                  {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                  {'|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
                  {' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '}};

box x_box =     {{' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '}};

box x_select =  {{' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
                 {'|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
                 {'|', '#', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', '#', '|'},
                 {'|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
                 {' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '}};

box o_box =     {{' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'O', 'O', 'O', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'O', 'O', 'O', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                 {' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '}};

box o_select =  {{' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '},
                 {'|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'O', 'O', 'O', 'O', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'O', 'O', 'O', 'O', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
                 {'|', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '|'},
                 {' ', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '}};

void assign_places (box *board[][3], int current_place[], int next_place[]);
bool check_winner (box *board[][3], char c_board[][3], char player, box *player_select);

int main(int argc, char const *argv[]) {
    system("cls");
    int input_key = 0;
    char winner = '\0';
    box *board[3][3]; // game board
    char c_board[3][3] = {{'\0', '\0', '\0'}, // equivalence board to determine exact win arrangement
                          {'\0', '\0', '\0'},
                          {'\0', '\0', '\0'}};

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            board[i][j] = &empty_box;
        }
    }
    board[1][1] = &select_box;
    int current_place[2] = {1, 1};
    int next_place[2] = {1, 1};
    box *current_player = &x_select;

    while (true) {

        // Prints current board configuration
        for (size_t i = 0; i < 3; i++) {
            for (size_t k = 0; k < 11; k++) {
                for (size_t j = 0; j < 3; j++) {
                    for (size_t l = 0; l < 21; l++) {
                        std::cout << (*board[i][j])[k][l];
                    }
                }
                std::cout << std::endl;
            }
        }

        do {
            input_key = _getch ();
            if (input_key == 0 || input_key == 0xE0) {
                input_key = _getch ();
            }
        } while (input_key != KEY_UP && input_key != KEY_DOWN && input_key != KEY_LEFT && input_key != KEY_RIGHT && input_key != KEY_ENTER);

        if (input_key == KEY_UP) {
            next_place[0] = ( ( (next_place[0] - 1 ) % 3 + 3) % 3 );
            assign_places (board, current_place, next_place);
        }
        else if (input_key == KEY_DOWN) {
            next_place[0] = (next_place[0] + 1 ) % 3;
            assign_places (board, current_place, next_place);
        }
        else if (input_key == KEY_LEFT) {
            next_place[1] = ( ( (next_place[1] - 1 ) % 3 + 3) % 3 );
            assign_places (board, current_place, next_place);
        }
        else if (input_key == KEY_RIGHT) {
            next_place[1] = (next_place[1] + 1 ) % 3;
            assign_places (board, current_place, next_place);
        }
        else if (input_key == KEY_ENTER) {
            if (board[current_place[0]][current_place[1]] != &x_select && board[current_place[0]][current_place[1]] != &o_select) {
                if (current_player == &x_select) {
                    board[current_place[0]][current_place[1]] = current_player;
                    c_board[current_place[0]][current_place[1]] = 'X';
                    current_player = &o_select;
                }
                else if (current_player == &o_select) {
                    board[current_place[0]][current_place[1]] = current_player;
                    c_board[current_place[0]][current_place[1]] = 'O';
                    current_player = &x_select;
                }
            }
        }

        system("cls");

        if (check_winner (board, c_board, 'X', &x_select)) {
            winner = 'X';
            break;
        }
        else if (check_winner (board, c_board, 'O', &o_select)) {
            winner = 'O';
            break;
        }
        else if (c_board[0][0] != '\0' && c_board[0][1] != '\0' && c_board[0][2] != '\0' &&
                 c_board[1][0] != '\0' && c_board[1][1] != '\0' && c_board[1][2] != '\0' &&
                 c_board[2][0] != '\0' && c_board[2][1] != '\0' && c_board[2][2] != '\0') {
            break;
        }
    }

    //Print winning board
    for (size_t i = 0; i < 3; i++) {
        for (size_t k = 0; k < 11; k++) {
            for (size_t j = 0; j < 3; j++) {
                for (size_t l = 0; l < 21; l++) {
                    std::cout << (*board[i][j])[k][l];
                }
            }
            std::cout << std::endl;
        }
    }
    if (winner != '\0') {
        std::cout << "\t\t" << winner << " wins!!! Press Enter to exit game";
    }
    else {
        std::cout << "\t\t" << "DRAW!!! Press Enter to exit game";
    }

    int end_game = 0;
    while (end_game != KEY_ENTER) {
        end_game = _getch ();
        if (end_game == 0 || end_game == 0xE0) {
            end_game = _getch ();
        }
    }

    return 0;
}

// determine and assign next and current box on game board
void assign_places (box *board[][3], int current_place[], int next_place[]) {
    if (board[current_place[0]][current_place[1]] != &x_select && board[current_place[0]][current_place[1]] != &o_select) {
        if (board[next_place[0]][next_place[1]] != &x_box && board[next_place[0]][next_place[1]] != &o_box) {
            board[next_place[0]][next_place[1]] =  &select_box;
        }
        else if (board[next_place[0]][next_place[1]] == &x_box) {
            board[next_place[0]][next_place[1]] = &x_select;
        }
        else if (board[next_place[0]][next_place[1]] == &o_box) {
            board[next_place[0]][next_place[1]] = &o_select;
        }
        board[current_place[0]][current_place[1]] = &empty_box;
        current_place[0] = next_place[0];
        current_place[1] = next_place[1];
    }
    else if (board[current_place[0]][current_place[1]] == &x_select) {
        if (board[next_place[0]][next_place[1]] != &x_box && board[next_place[0]][next_place[1]] != &o_box) {
            board[next_place[0]][next_place[1]] =  &select_box;
        }
        else if (board[next_place[0]][next_place[1]] == &x_box) {
            board[next_place[0]][next_place[1]] = &x_select;
        }
        else if (board[next_place[0]][next_place[1]] == &o_box) {
            board[next_place[0]][next_place[1]] = &o_select;
        }
        board[current_place[0]][current_place[1]] = &x_box;
        current_place[0] = next_place[0];
        current_place[1] = next_place[1];
    }
    else if (board[current_place[0]][current_place[1]] == &o_select) {
        if (board[next_place[0]][next_place[1]] != &x_box && board[next_place[0]][next_place[1]] != &o_box) {
            board[next_place[0]][next_place[1]] =  &select_box;
        }
        else if (board[next_place[0]][next_place[1]] == &x_box) {
            board[next_place[0]][next_place[1]] = &x_select;
        }
        else if (board[next_place[0]][next_place[1]] == &o_box) {
            board[next_place[0]][next_place[1]] = &o_select;
        }
        board[current_place[0]][current_place[1]] = &o_box;
        current_place[0] = next_place[0];
        current_place[1] = next_place[1];
    }
}

// determine if there is a winner and the configuration in which they won.
bool check_winner (box *board[][3], char c_board[][3], char player, box *player_select) {
    if (!((c_board[0][0] == player && c_board[0][1] == player && c_board[0][2] == player) ||
            (c_board[1][0] == player && c_board[1][1] == player && c_board[1][2] == player) ||
            (c_board[2][0] == player && c_board[2][1] == player && c_board[2][2] == player) ||
            (c_board[0][0] == player && c_board[1][0] == player && c_board[2][0] == player) ||
            (c_board[0][1] == player && c_board[1][1] == player && c_board[2][1] == player) ||
            (c_board[0][2] == player && c_board[1][2] == player && c_board[2][2] == player) ||
            (c_board[0][0] == player && c_board[1][1] == player && c_board[2][2] == player) ||
            (c_board[0][2] == player && c_board[1][1] == player && c_board[2][0] == player))) {

        return false;
    }

    if (c_board[0][0] == player && c_board[0][1] == player && c_board[0][2] == player) {
        board[0][0] = player_select;
        board[0][1] = player_select;
        board[0][1] = player_select;
    }
    else if (c_board[1][0] == player && c_board[1][1] == player && c_board[1][2] == player) {
        board[1][0] = player_select;
        board[1][1] = player_select;
        board[1][2] = player_select;
    }
    else if (c_board[2][0] == player && c_board[2][1] == player && c_board[2][2] == player) {
        board[2][0] = player_select;
        board[2][1] = player_select;
        board[2][2] = player_select;
    }
    else if (c_board[0][0] == player && c_board[1][0] == player && c_board[2][0] == player) {
        board[0][0] = player_select;
        board[1][0] = player_select;
        board[2][0] = player_select;
    }
    else if (c_board[0][1] == player && c_board[1][1] == player && c_board[2][1] == player) {
        board[0][1] = player_select;
        board[1][1] = player_select;
        board[2][1] = player_select;
    }
    else if (c_board[0][2] == player && c_board[1][2] == player && c_board[2][2] == player) {
        board[0][2] = player_select;
        board[1][2] = player_select;
        board[2][2] = player_select;
    }
    else if (c_board[0][0] == player && c_board[1][1] == player && c_board[2][2] == player) {
        board[0][0] = player_select;
        board[1][1] = player_select;
        board[2][2] = player_select;
    }
    else if (c_board[0][2] == player && c_board[1][1] == player && c_board[2][0] == player) {
        board[0][2] = player_select;
        board[1][1] = player_select;
        board[2][0] = player_select;
    }

    return true;
}
