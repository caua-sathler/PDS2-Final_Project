#include "Tic_tac_toe.hpp"
#include <iostream>

const int num_rows_received = 3;
const int num_columns_received = 3;

tic_tac_toe::tic_tac_toe() : Game(num_rows_received, num_columns_received), current_player('X') {
}

bool tic_tac_toe::is_valid_move(int& x, int& y) const {
    return game_board.is_move_inside_board(x, y) && game_board.is_space_free(x, y);
}


void tic_tac_toe::make_move(int x, int y) {
  
    static bool win = false;
    if (win) {
        return;
    }

    x -= 1;
    y -= 1;


    if (is_valid_move(x, y)) {
        game_board.modify_space(x, y) = current_player; 
        game_board.print_game_board();
    
     if (check_win(win) != 'F') {
            winner = current_player;
        } 
        
        else 
            current_player = switch_players(current_player);
}
}

char tic_tac_toe::check_win(bool& win) {

    for (int i = 0; i < 3; ++i) {
        if (game_board.access_space(i, 0) == current_player && 
            game_board.access_space(i, 1) == current_player && 
            game_board.access_space(i, 2) == current_player) {
            win = true;
            return current_player;
        }

        if (game_board.access_space(0, i) == current_player && 
            game_board.access_space(1, i) == current_player && 
            game_board.access_space(2, i) == current_player) {
            win = true;
            return current_player;
        }
    }

    if (game_board.access_space(0, 0) == current_player && 
        game_board.access_space(1, 1) == current_player && 
        game_board.access_space(2, 2) == current_player) {
        win = true;
        return current_player; 
    }

    if (game_board.access_space(0, 2) == current_player && 
        game_board.access_space(1, 1) == current_player && 
        game_board.access_space(2, 0) == current_player) {
        win = true;
        return current_player; 
    }

    win = false;
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

bool tic_tac_toe::check_win() {
    return false;
}

tic_tac_toe::~tic_tac_toe() {
}