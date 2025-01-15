#include "Connect4.hpp"
#include <iostream>

Connect4::Connect4() : Game(6, 7), current_player('X'){
}

bool Connect4::is_valid_move() const {
    return false;
}

void Connect4::make_move(){

}

// If the move is valid return true, otherwise return false
bool Connect4::is_valid_move(int column) const {
    column--; 
    int rows = 6;
    if (game_board.get_space(0, column) != ' ' || !game_board.is_move_inside_board(rows, column)) {
        //Exceptions and error handling, fix 
        return false;
    }
    return true;
}


void Connect4::make_move(int column) {
        column--;
        for(int i = 5; i >= 0; i--) {
            if(game_board.get_space(i, column) == ' ') {
                game_board.set_space(i, column, current_player);
                return;
            }
        }
}

bool Connect4::check_win(){
    // If the current player wins, return true, otherwise return false

    // horizontal verification 

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row, col + 1) == current_player &&
                game_board.get_space(row, col + 2) == current_player && 
                game_board.get_space(row, col + 3) == current_player) {
                    return true;
            }
        }
    }

    // vertical verification 

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row + 1, col) == current_player &&
                game_board.get_space(row + 2, col) == current_player && 
                game_board.get_space(row + 3, col) == current_player) {
                    return true;
            }
        }
    }

    // right diagonal check

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row + 1, col + 1) == current_player &&
                game_board.get_space(row + 2, col + 2) == current_player && 
                game_board.get_space(row + 3, col + 3) == current_player) {
                    return true;
            }
        }
    }

    // left diagonal check

    for (int row = 3; row < 6; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row - 1, col + 1) == current_player &&
                game_board.get_space(row - 2, col + 2) == current_player && 
                game_board.get_space(row - 3, col + 2) == current_player) {
                    return true;
            }
        }
    }
    return false;
}

char Connect4::get_current_player() const {
    return current_player;
}

bool Connect4::is_board_full() const{
    for(int col = 0; col < 7; ++col) {
        if(game_board.get_space(0, col) == ' ') {
            return false;
        }
    }
    return true;
}

void Connect4::print_game_board() const{
    game_board.print_game_board();
}

Connect4::~Connect4() {
}