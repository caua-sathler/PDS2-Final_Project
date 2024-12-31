#include "Tic_tac_toe.hpp"
#include <iostream>

tic_tac_toe::tic_tac_toe() : Game(3,3), current_player('X') {
}

bool tic_tac_toe::is_valid_move(bool& win) {
    check_win(win);

return !win;
}

bool tic_tac_toe::is_move_inside_board(int x, int y) const {
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

    if (is_move_inside_board(x, y)) {
        game_board[x][y] = current_player; 
        Game::print_game_board();

        bool win = false;
        if (!is_valid_move(win)) {
            exit(0);
        }

        switch_players();
    }
}

void tic_tac_toe::switch_players() {
    if(current_player == 'X')
        current_player = 'O';

    else 
        current_player = 'X';
}

void tic_tac_toe::check_win(bool& win) {
    for (int i = 0; i < 3; ++i) { 
        if ((game_board[i][0] == current_player && game_board[i][1] == current_player && game_board[i][2] == current_player) || 
            (game_board[0][i] == current_player && game_board[1][i] == current_player && game_board[2][i] == current_player)) {
            std::cout << "Jogador " << current_player << " venceu!\n";
            win = true;
            return;
        }
    }

     if ((game_board[0][0] == current_player && game_board[1][1] == current_player && game_board[2][2] == current_player) || 
        (game_board[0][2] == current_player && game_board[1][1] == current_player && game_board[2][0] == current_player)) {
        std::cout << "Jogador " << current_player << " venceu!\n";
        win = true;
        return;
    }
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
