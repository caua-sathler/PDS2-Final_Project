#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tic_tac_toe.hpp"

void create_tic_tac_toe_board(tic_tac_toe &game, const std::vector<std::vector<char>> &board_setup) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            game.game_board.set_space(i, j, board_setup[i][j]);
        }
    }
}


