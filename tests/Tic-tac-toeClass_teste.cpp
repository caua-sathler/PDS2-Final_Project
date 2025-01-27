#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include "Tic_tac_toe.hpp"

const int num_rows_received = 3;
const int num_columns_received = 3;

void create_game_board_situation(char game_board_situation[num_rows_received][num_columns_received], tic_tac_toe &tic_tac_toe_game){
    char *board[num_columns_received];
    for (int i = 0; i < num_columns_received; i++){
        board[i] = game_board_situation[i];
    }

    tic_tac_toe_game.get_game_board().set_game_board(board);
}

TEST_CASE("Function is_valid_move test") {
    tic_tac_toe jogo;

    char game_board_situation[num_rows_received][num_columns_received] = {
        {'X', ' ', ' '},
        {' ', 'O', ' '},
        {' ', ' ', ' '}
    };

    create_game_board_situation(game_board_situation, jogo);

    SUBCASE("Move inside board and position free") {
        int x = 1, y = 1;
        CHECK(jogo.is_valid_move(x, y) == true);
    }

    SUBCASE("Move out of the board") {
        int x = 4, y = 4; 
        CHECK(jogo.is_valid_move(x, y) == false);

        x = INT_MAX + 1, y = INT_MAX + 1; 
        CHECK(jogo.is_valid_move(x, y) == false);

        x = INT_MIN - 1, y = INT_MIN - 1;
        CHECK(jogo.is_valid_move(x, y) == false);
    }

    SUBCASE("Move on a ocuppied position") {
        jogo.make_move(1, 1);
        int x = 1, y = 1;
        CHECK(jogo.is_valid_move(x, y) == false);
    }
}
