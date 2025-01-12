#include "Connect4.hpp"
#include <iostream>

Connect4::Connect4() : Game(6, 7), current_player('X'){
}

bool Connect4::is_move_inside_board(int a, int column) const {
    if (column < 1 || column > 7) { 
        //Exceptions and error handling, fix
        return false;
    }
    return true;
}

// If the move is valid return true, otherwise return false
bool Connect4::is_valid_move(int column) const {
    column--; 
    if (game_board[0][column] != ' ' || !is_move_inside_board(column)) {
        //Exceptions and error handling, fix 
        return false;
    }
    return true;
}


void Connect4::make_move(int column) {
    if(is_valid_move(column)) {
        column--;
        for(int i = 5; i >= 0; i--) {
            if(game_board[i][column] == ' ') {
                game_board[i][column] = current_player;
                return;
            }
        }
    }
}

void Connect4::switch_players(){
    if(current_player == 'X') {
        current_player = 'O';
    } else {
        current_player = 'X';
    }
}

bool Connect4::check_win(){
    // If the current player wins, return true, otherwise return false

    // horizontal verification 

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board[row][col] == current_player && 
                game_board[row][col + 1] == current_player &&
                game_board[row][col + 2] == current_player && 
                game_board[row][col + 3] == current_player) {
                    return true;
            }
        }
    }

    // vertical verification 

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (game_board[row][col] == current_player && 
                game_board[row+1][col] == current_player &&
                game_board[row + 2][col] == current_player && 
                game_board[row + 3][col] == current_player) {
                    return true;
            }
        }
    }

    // right diagonal check

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board[row][col] == current_player && 
                game_board[row+1][col+1] == current_player &&
                game_board[row + 2][col+2] == current_player && 
                game_board[row + 3][col+3] == current_player) {
                    return true;
            }
        }
    }

    // left diagonal check

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board[row][col] == current_player && 
                game_board[row-1][col-1] == current_player &&
                game_board[row - 2][col - 2] == current_player && 
                game_board[row - 3][col - 3] == current_player) {
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
    for(int col = 0; col < num_columns; ++col) {
        if(game_board[0][col] == ' ') {
            return false;
        }
    }
    return true;
}

Connect4::~Connect4() {
}