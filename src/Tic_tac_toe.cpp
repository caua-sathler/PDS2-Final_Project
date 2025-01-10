#include "Tic_tac_toe.hpp"
#include <iostream>

const int num_rows_received = 3;
const int num_columns_received = 3;

tic_tac_toe::tic_tac_toe() : Game(num_rows_received, num_columns_received), current_player('X') {
}

bool tic_tac_toe::is_space_free(int& x, int& y) const {

    if (!is_move_inside_board(x, y)) {
        std::cout << "Jogada fora do tabuleiro\n";
        return false;
    }

    if (game_board[x][y] == ' ') {
        std::cout << "Espaço livre\n";
        return true;
    }

    std::cout << "Espaço ocupado\n";
    return false;
}

bool tic_tac_toe::is_valid_move(int& x, int& y) {
    return is_move_inside_board(x, y) && is_space_free(x, y);
}

bool tic_tac_toe::is_move_inside_board(int x, int y) const {
    if (x >= 0 && x < num_rows && y >= 0 && y < num_columns && game_board[x][y] == ' ') {
        std::cout << "Jogada dentro do tabuleiro" << std::endl;
        return true; 
    }
    std::cout << "Jogada fora do tabuleiro\n";
    return false; 
}

void tic_tac_toe::make_move(int x, int y) {
    x -= 1;
    y -= 1;

    bool win = false;
    if (check_win(win) != 'F') {
        std::cout<< "Fim do jogo\n";
        return;
    }


    if (is_valid_move(x, y)) {
        game_board[x][y] = current_player; 
        Game::print_game_board();
        switch_players();
    }

    else
        std::cout << "Jogada invalida, tente novamente\n";
    }


void tic_tac_toe::switch_players() {
    if(current_player == 'X')
        current_player = 'O';

    else 
        current_player = 'X';
}

char tic_tac_toe::check_win(bool& win) {
    for (int i = 0; i < 3; ++i) {
        if ((game_board[i][0] == current_player && game_board[i][1] == current_player && game_board[i][2] == current_player) ||
            (game_board[0][i] == current_player && game_board[1][i] == current_player && game_board[2][i] == current_player)) {
            win = true;
            return current_player;
        }
    }

    if ((game_board[0][0] == current_player && game_board[1][1] == current_player && game_board[2][2] == current_player) ||
        (game_board[0][2] == current_player && game_board[1][1] == current_player && game_board[2][0] == current_player)) {
        win = true;
        return current_player;
    }

    return 'F'; 
}

char tic_tac_toe::get_current_player() const {
    return current_player;
}


bool tic_tac_toe::is_valid_move() const {
    return true;
}

void tic_tac_toe::make_move() {

}

void tic_tac_toe::check_win() const {
}

tic_tac_toe::~tic_tac_toe() {
}
