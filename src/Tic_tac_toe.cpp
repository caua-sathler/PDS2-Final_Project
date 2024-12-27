#include "Tic_tac_toe.hpp"
#include <iostream>

tic_tac_toe::tic_tac_toe(int num_rows_received, int num_columns_received) : Game(num_rows_received, num_columns_received) {
}

bool tic_tac_toe::verify_valid_move(int x, int y) {
    if (x >= 0 && x < num_rows && y >= 0 && y < num_columns && get_game_board()[x][y] == ' ') {
        return true; 
    }
    return false; 

}

void tic_tac_toe::make_move(int x, int y) {
    x -=1;
    y -=1;


}
void tic_tac_toe::check_win() {

}

tic_tac_toe::~tic_tac_toe() {
}
