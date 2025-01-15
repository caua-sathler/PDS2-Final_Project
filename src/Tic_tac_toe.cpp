#include "Tic_tac_toe.hpp"
#include "Player.hpp"
#include <iostream>

const int num_rows_received = 3;
const int num_columns_received = 3;

tic_tac_toe::tic_tac_toe() : Game(num_rows_received, num_columns_received), current_player('X') {
    reset_game();
}

bool tic_tac_toe::is_valid_move(int& x, int& y) const {
    std::cout << "Chamada da função is_valid_move\n";
    return game_board.is_move_inside_board(x, y) && game_board.is_space_free(x, y);
}

void tic_tac_toe::print_tic_tac_toe_board() const {
    game_board.print_game_board();
}

void tic_tac_toe::make_move(int x, int y) {

    std::cout << "Chamada make_move\n";
  
    static bool win = false;
    if (win) {
        std::cout << "Teste\n";
        return;
    }

    if(check_tie()) {
        std::cout << "Empate" << std::endl;
        return;
    }

    x -= 1;
    y -= 1;

    if (is_valid_move(x, y)) {
        game_board.set_space(x, y, current_player);
    
     if (check_win(win) != 'F') {
            winner = current_player;
        } 

        else if (check_tie()) {
            std::cout << "Empate" << std::endl;
            return;
        }

        else 
            current_player = switch_players(current_player);
}
}

char tic_tac_toe::check_win(bool& win) {

    for (int i = 0; i < 3; ++i) {
        if (game_board.get_space(i, 0) == current_player && 
            game_board.get_space(i, 1) == current_player && 
            game_board.get_space(i, 2) == current_player) {
            win = true;
            return current_player;
        }

        if (game_board.get_space(0, i) == current_player && 
            game_board.get_space(1, i) == current_player && 
            game_board.get_space(2, i) == current_player) {
            win = true;
            return current_player;
        }
    }

    if (game_board.get_space(0, 0) == current_player && 
        game_board.get_space(1, 1) == current_player && 
        game_board.get_space(2, 2) == current_player) {
        win = true;
        return current_player; 
    }

    if (game_board.get_space(0, 2) == current_player && 
        game_board.get_space(1, 1) == current_player && 
        game_board.get_space(2, 0) == current_player) {
        win = true;
        return current_player; 
    }

    win = false;
    return 'F'; 
}

bool tic_tac_toe::check_tie() const {

    for (int i = 0; i < 3; i++) {
        for (int j =0; j < 3; j++) {
            if (game_board.get_space(i, j) == ' ') {
                return false;
            }
        }
    }

return true;
}

void tic_tac_toe::reset_game() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            game_board.set_space(i, j, ' ');
        }
    }

    std::cout << "Chamda reset_game\n";
    current_player = 'X'; 
    winner = 'F';           
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
    std::cout << "Chamada destrutor\n";
    reset_game();
}