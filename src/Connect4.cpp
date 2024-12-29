#include "Connect4.hpp"
#include <iostream>

Connect4::Connect4() : Game(6, 7), current_player('X'){
}

bool Connect4::is_move_inside_board(int column) const {
    if (column < 1 || column > 7) { 
        std::cout << "jogada inválida\n";
        return false;
    }
    return true;
}

// If the move is valid return true, otherwise return false
bool Connect4::is_valid_move(int column) const {
    column--; 
    if (game_board[0][column] != ' ' || !is_move_inside_board(column)) {
        std::cout << "jogada inválida\n";
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
                switch_players();
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

void Connect4::check_win() const {
    // If 'X' wins then player 1 wins, otherwise if 'O' wins then player 2 wins

    // horizontal verification 

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board[row][col] == 'X' && game_board[row][col + 1] == 'X' &&
                 game_board[row][col + 2] == 'X' && game_board[row][col + 3] == 'X') {
                    std::cout << "Jogador 1 venceu!\n";
                    return;
                } else if (game_board[row][col] == 'O' && game_board[row][col + 1] == 'O' &&
                 game_board[row][col + 2] == 'O' && game_board[row][col + 3] == 'O') {
                    std::cout << "Jogador 2 venceu!\n";
                    return;
            }
        }
    }

    // vertical verification 

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (game_board[row][col] == 'X' && game_board[row+1][col] == 'X' &&
                 game_board[row + 2][col] == 'X' && game_board[row + 3][col] == 'X') {
                    std::cout << "Jogador 1 venceu!\n";
                    return;
                } else if (game_board[row][col] == 'O' && game_board[row + 1][col] == 'O' &&
                 game_board[row + 2][col] == 'O' && game_board[row + 3][col] == 'O') {
                    std::cout << "Jogador 2 venceu!\n";
                    return;
            }
        }
    }

    // right diagonal check

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board[row][col] == 'X' && game_board[row+1][col+1] == 'X' &&
                 game_board[row + 2][col+2] == 'X' && game_board[row + 3][col+3] == 'X') {
                    std::cout << "Jogador 1 venceu!\n";
                    return;
                } else if (game_board[row][col] == 'O' && game_board[row + 1][col+1] == 'O' &&
                 game_board[row + 2][col+2] == 'O' && game_board[row + 3][col+3] == 'O') {
                    std::cout << "Jogador 2 venceu!\n";
                    return;
            }
        }
    }

    // left diagonal check

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board[row][col] == 'X' && game_board[row-1][col-1] == 'X' &&
                 game_board[row - 2][col - 2] == 'X' && game_board[row - 3][col - 3] == 'X') {
                    std::cout << "Jogador 1 venceu!\n";
                    return;
                } else if (game_board[row][col] == 'O' && game_board[row - 1][col - 1] == 'O' &&
                 game_board[row - 2][col - 2] == 'O' && game_board[row - 3][col - 3] == 'O') {
                    std::cout << "Jogador 2 venceu!\n";
                    return;
            }
        }
    }
}


Connect4::~Connect4() {
}