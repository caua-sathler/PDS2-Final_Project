#include "Tic_tac_toe.hpp"
#include <iostream>

tic_tac_toe::tic_tac_toe() : Game(3,3), current_player('X') {
}

bool tic_tac_toe::verify_valid_move(int x, int y) const {
    if (x >= 0 && x < num_rows && y >= 0 && y < num_columns && game_board[x][y] == ' ') {
        return true; 
    }

    else {
        std::cout << "INVALIDO\n";
        return false; 
    }
}

void tic_tac_toe::make_move(int x, int y) {
    x -= 1;
    y -= 1;

    if (verify_valid_move(x, y)) {
        game_board[x][y] = current_player; 
        switch_players();
}
}

void tic_tac_toe::switch_players() {
    if(current_player == 'X')
        current_player = 'O';

    else 
        current_player = 'X';
}

void tic_tac_toe::check_win() const {

}

tic_tac_toe::~tic_tac_toe() {
}
