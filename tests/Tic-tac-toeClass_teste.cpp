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

TEST_CASE("Function is_valid_move test") 
{
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

TEST_CASE("Function make_move test") 
{
    tic_tac_toe jogo;

    char game_board_situation[num_rows_received][num_columns_received] = {
        {'X', ' ', ' '},
        {' ', 'O', ' '},
        {' ', ' ', ' '}
    };

    create_game_board_situation(game_board_situation, jogo);

    SUBCASE("Valid move switches the player and update the board") 
    {
        int x = 2, y = 2;
        jogo.make_move(x, y);
        CHECK(jogo.get_game_board().get_space(x - 1, y - 1) == 'X');
        CHECK(jogo.get_current_player() == 'O');
        int x = 3, y = 3;
        CHECK(jogo.get_game_board().get_space(x, y) == 'O');
        CHECK(jogo.get_current_player() == 'X');
    }

    SUBCASE("Invalid move switch the player and does not update the board") 
    {
        int x = 2, y = 2; 
        jogo.make_move(x, y);
        CHECK(jogo.get_game_board().get_space(x - 1, y - 1) == 'O');
        CHECK(jogo.get_current_player() == 'O');
    }
}

TEST_CASE("Function check_tie test") 
{
    tic_tac_toe jogo;

    SUBCASE("Game is a tie (board full, no winner)") 
    {
        char tie_board[num_rows_received][num_columns_received] = 
        {
            {'X', 'O', 'X'},
            {'X', 'X', 'O'},
            {'O', 'X', 'O'}
        };

        create_game_board_situation(tie_board, jogo);
        CHECK(jogo.check_tie() == true);
    }

    SUBCASE("Game is not a tie (there is a winner)") 
    {
        char winner_board[num_rows_received][num_columns_received] = 
        {
            {'X', 'X', 'X'},
            {'O', 'O', ' '},
            {' ', ' ', ' '}
        };

        create_game_board_situation(winner_board, jogo);
        CHECK(jogo.check_tie() == false);
    }

}





