#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Board.hpp"
#include <array>
const int num_columns_and_rows_reversi = 8;
const int num_columns_and_rows_tic_tac_toe = 3;
const int num_columns_lig4 = 7;
const int num_rows_lig4 = 6;

TEST_CASE("Function set_game_board test - Reversi board") 
{
    // Cria o tabuleiro como ponteiro duplo de char
    char** board_sample = new char*[num_columns_and_rows_reversi];
    for (int i = 0; i < num_columns_and_rows_reversi; ++i) 
        board_sample[i] = new char[num_columns_and_rows_reversi];
    
    // Inicializa os valores do tabuleiro
    char board_initial_values[num_columns_and_rows_reversi][num_columns_and_rows_reversi] = 
    {
        {' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'O', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', 'O', 'X', ' ', ' ', ' '},
        {' ', ' ', '*', 'X', 'O', '*', '*', ' '},
        {' ', ' ', '*', 'O', 'X', 'O', '*', ' '},
        {' ', ' ', ' ', '*', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    // Iguala o tabuleiro de **char com os valores inciais
    for (int i = 0; i < num_columns_and_rows_reversi; ++i) 
    {
        for (int j = 0; j < num_columns_and_rows_reversi; ++j)
            board_sample[i][j] = board_initial_values[i][j];
        
    }

    // Utiliza a função para igualar o tabuleiro criado pelo construtor da classe
    // com o tabuleiro **char
    Board board(num_columns_and_rows_reversi, num_columns_and_rows_reversi);
    board.set_game_board(board_sample);

    auto& class_board = board.get_game_board();
    for (int i = 0; i < num_columns_and_rows_reversi; ++i) 
    {
        for (int j = 0; j < num_columns_and_rows_reversi; ++j) 
        // Confere se cada elemento foi copiado adequadamente
            CHECK(class_board[i][j] == board_initial_values[i][j]);
        
    }
}


TEST_CASE("Function set_game_board test - Lig4 board") 
{


    // Cria o tabuleiro como ponteiro duplo de char
    char** board_sample = new char*[num_rows_lig4];
    for (int i = 0; i < num_rows_lig4; ++i) 
        board_sample[i] = new char[num_columns_lig4];
    

    // Inicializa os valores do tabuleiro
    char board_initial_values[num_rows_lig4][num_columns_lig4] = 
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'O', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', 'O', 'X', ' ', ' '},
        {' ', ' ', 'O', 'X', 'O', ' ', ' '},
        {'O', ' ', 'O', 'O', 'X', 'O', ' '},
        {'X', 'X', 'X', 'X', 'X', 'O', ' '},
    };

    // Iguala o tabuleiro de **char com os valores inciais
    for (int i = 0; i < num_rows_lig4; ++i) 
    {
        for (int j = 0; j < num_columns_lig4; ++j) 
            board_sample[i][j] = board_initial_values[i][j];
        
    }

    // Utiliza a função para igualar o tabuleiro criado pelo construtor da classe
    // com o tabuleiro **char
    Board board(num_rows_lig4, num_columns_lig4);
    board.set_game_board(board_sample);

    auto& class_board = board.get_game_board();
    for (int i = 0; i < num_rows_lig4; ++i) 
    {
        for (int j = 0; j < num_columns_lig4; ++j) 
        // Confere se cada elemento foi copiado adequadamente
            CHECK(class_board[i][j] == board_initial_values[i][j]);
    }
}

TEST_CASE("Function set_game_board test - Tic tac toe board") 
{


    // Cria o tabuleiro como ponteiro duplo de char
    char** board_sample = new char*[num_columns_and_rows_tic_tac_toe];
    for (int i = 0; i < num_columns_and_rows_tic_tac_toe; ++i) 
        board_sample[i] = new char[num_columns_and_rows_tic_tac_toe];
    

    // Inicializa os valores do tabuleiro
    char board_initial_values[num_columns_and_rows_tic_tac_toe][num_columns_and_rows_tic_tac_toe] = 
    {
        {'O', ' ', ' '},
        {'X', 'O', 'O'},
        {'X', ' ', 'X'},
        
    };

    // Iguala o tabuleiro de **char com os valores inciais
    for (int i = 0; i < num_columns_and_rows_tic_tac_toe; ++i) 
    {
        for (int j = 0; j < num_columns_and_rows_tic_tac_toe; ++j) 
            board_sample[i][j] = board_initial_values[i][j];
    }

    // Utiliza a função para igualar o tabuleiro criado pelo construtor da classe
    // com o tabuleiro **char
    Board board(num_columns_and_rows_tic_tac_toe, num_columns_and_rows_tic_tac_toe);
    board.set_game_board(board_sample);

    auto& class_board = board.get_game_board();
    for (int i = 0; i < num_columns_and_rows_tic_tac_toe; ++i) 
    {
        for (int j = 0; j < num_columns_and_rows_tic_tac_toe; ++j) 
        // Confere se cada elemento foi copiado adequadamente
            CHECK(class_board[i][j] == board_initial_values[i][j]);
        
    }
}

TEST_CASE("Function is_move_inside_board test - Reversi Board") 
{
    // Constroi um tabuleiro vazio na dimensão do Reversi
    Board board(num_columns_and_rows_reversi, num_columns_and_rows_reversi);
    
    CHECK(board.is_move_inside_board(0,0) == 1);
    CHECK(board.is_move_inside_board(0,7) == 1);
    CHECK(board.is_move_inside_board(7,0) == 1);
    CHECK(board.is_move_inside_board(7,7) == 1);
    CHECK(board.is_move_inside_board(3,5) == 1);
    CHECK(board.is_move_inside_board(0,-1) == 0);
    CHECK(board.is_move_inside_board(5,12) == 0);
    CHECK(board.is_move_inside_board(9,3) == 0);
    CHECK(board.is_move_inside_board(-15,12) == 0);
}

TEST_CASE("Function is_move_inside_board test - Lig4 board") 
{
    // Constroi um tabuleiro vazio na dimensão do Lig4
    Board board(num_rows_lig4, num_columns_lig4);
    
    CHECK(board.is_move_inside_board(0,0) == 1);
    CHECK(board.is_move_inside_board(0,6) == 1);
    CHECK(board.is_move_inside_board(5,0) == 1);
    CHECK(board.is_move_inside_board(5,6) == 1);
    CHECK(board.is_move_inside_board(3,5) == 1);
    CHECK(board.is_move_inside_board(0,-1) == 0);
    CHECK(board.is_move_inside_board(5,12) == 0);
    CHECK(board.is_move_inside_board(6,7) == 0);
    CHECK(board.is_move_inside_board(-1,12) == 0);
}

TEST_CASE("Function is_move_inside_board test - Tic tac toe board") 
{
    // Constroi um tabuleiro vazio na dimensão do Jogo da Velha
    Board board(num_columns_and_rows_tic_tac_toe, num_columns_and_rows_tic_tac_toe);
    
    CHECK(board.is_move_inside_board(0,0) == 1);
    CHECK(board.is_move_inside_board(0,2) == 1);
    CHECK(board.is_move_inside_board(2,0) == 1);
    CHECK(board.is_move_inside_board(2,2) == 1);
    CHECK(board.is_move_inside_board(0,1) == 1);
    CHECK(board.is_move_inside_board(0,-1) == 0);
    CHECK(board.is_move_inside_board(3,3) == 0);
    CHECK(board.is_move_inside_board(4,3) == 0);
    CHECK(board.is_move_inside_board(-1,1) == 0);
}

TEST_CASE("Function is_space_free test") 
{
    //Passos iniciais seguem a mesma lógica do teste da função set_game_board 
    char** board_sample = new char*[num_columns_and_rows_reversi];
    for (int i = 0; i < num_columns_and_rows_reversi; ++i) 
        board_sample[i] = new char[num_columns_and_rows_reversi];
    
    char board_initial_values[num_columns_and_rows_reversi][num_columns_and_rows_reversi] = 
    {
        {' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'O', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', 'O', 'X', ' ', ' ', ' '},
        {' ', 'O', '*', 'X', 'O', '*', '*', ' '},
        {' ', ' ', '*', 'O', 'X', 'O', '*', ' '},
        {' ', ' ', ' ', '*', 'X', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < num_columns_and_rows_reversi; ++i) 
    {
        for (int j = 0; j < num_columns_and_rows_reversi; ++j)
            board_sample[i][j] = board_initial_values[i][j];
    }
    
    // Utiliza set_game_board (já testada) para igualar o tabuleiro criado pelo construtor 
    //da classe com o tabuleiro **char
    Board board(num_columns_and_rows_reversi, num_columns_and_rows_reversi);
    board.set_game_board(board_sample);

    CHECK(board.is_space_free(6,1) == 0);
    CHECK(board.is_space_free(3,4) == 0);
    CHECK(board.is_space_free(3,2) == 0);
    CHECK(board.is_space_free(0,0) == 1);
    CHECK(board.is_space_free(5,5) == 1);
}

