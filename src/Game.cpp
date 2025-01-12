#include "Game.hpp"
#include <iostream>

Game::Game(int num_rows_received, int num_columns_received) : game_board(num_rows_received, num_columns_received) {};


char Game::switch_players(char current_player) {
    char opponent_player = (current_player == 'X') ? 'O' : 'X';
return opponent_player;
}
