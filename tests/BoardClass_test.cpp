#include "doctest.h"
#include "Board.hpp"
#include <array>
const int num_columns_and_rows_reversi = 8;
const int num_columns_and_rows_tic_tac_toe = 3;
const int num_columns_lig4 = 7;
const int num_rows_lig4 = 6;

TEST_CASE("Function set_game_board test") 
{

    Board board(num_columns_and_rows_reversi, num_columns_and_rows_reversi);

    // Cria o tabuleiro diretamente como ponteiro duplo
    char** board_sample = new char*[num_columns_and_rows_reversi];
    for (int i = 0; i < num_columns_and_rows_reversi; ++i) {
        board_sample[i] = new char[num_columns_and_rows_reversi];
    }

    // Inicializa os valores do tabuleiro
    char board_values[num_columns_and_rows_reversi][num_columns_and_rows_reversi] = {
        {' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'O', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', 'O', 'X', ' ', ' ', ' '},
        {' ', ' ', '*', 'X', 'O', '*', '*', ' '},
        {' ', ' ', '*', 'O', 'X', 'O', '*', ' '},
        {' ', ' ', ' ', '*', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < num_columns_and_rows_reversi; ++i) {
        for (int j = 0; j < num_columns_and_rows_reversi; ++j) {
            board_sample[i][j] = board_values[i][j];
        }
    }

    board.set_game_board(board_sample);

    auto& empty_board = board.get_game_board(); // Obtém o tabuleiro interno
    for (int i = 0; i < num_columns_and_rows_reversi; ++i) 
    {
        for (int j = 0; j < num_columns_and_rows_reversi; ++j) 
            CHECK(empty_board[i][j] == board_values[i][j]);
        
    }
}