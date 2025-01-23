#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Reversi.hpp"
#include <iostream>
#include <array>
using namespace std;

const int num_columns_and_rows_reversi = 8;

void create_game_board_situation(char game_board_situation[num_columns_and_rows_reversi][num_columns_and_rows_reversi], Reversi &reversi_game ){
    char* board[num_columns_and_rows_reversi];
    for (int i = 0; i < num_columns_and_rows_reversi; i++) {
        board[i] = game_board_situation[i];
    }
    
    reversi_game.get_game_board().set_game_board(board);
}

TEST_CASE("Function is_there_player_piece_at_the_direction test")
{
    Reversi reversi_game;
    char game_board_situation[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'O', '*', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', 'O', 'X', ' ', ' ', ' '},
        {' ', ' ', '*', 'X', 'O', '*', '*', ' '},
        {' ', ' ', '*', 'O', 'X', 'O', '*', ' '},
        {' ', ' ', ' ', '*', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
         
    };
    create_game_board_situation(game_board_situation, reversi_game);

    CHECK(reversi_game.is_there_player_piece_at_the_direction('O',{-1, 0}, {1, 3})==0);
    CHECK(reversi_game.is_there_player_piece_at_the_direction('X',{-1, -1}, {5, 5})==1);
    CHECK(reversi_game.is_there_player_piece_at_the_direction('O',{-1, 1}, {5, 2})==1);
    CHECK(reversi_game.is_there_player_piece_at_the_direction('X',{0, 1}, {4, 5})==0);
    CHECK(reversi_game.is_there_player_piece_at_the_direction('O',{-1, 0}, {6, 4})==1);
    CHECK(reversi_game.is_there_player_piece_at_the_direction('X',{0, -1}, {4, 4})==0);

}

TEST_CASE("Function is_space_free_reversi test"){
    Reversi reversi_game;
    char game_board_situation[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', '*', ' ', 'X', ' ', ' '},
        {' ', ' ', 'X', 'O', 'X', ' ', ' ', ' '},
        {' ', '*', 'O', 'X', 'O', '*', ' ', ' '},
        {' ', 'O', '*', ' ', '*', 'O', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    create_game_board_situation(game_board_situation, reversi_game);
    CHECK(reversi_game.is_space_free_reversi(2,3) == 1);
    CHECK(reversi_game.is_space_free_reversi(2,5) == 0);
    CHECK(reversi_game.is_space_free_reversi(0,3) == 1);
    CHECK(reversi_game.is_space_free_reversi(5,5) == 0);
}

TEST_CASE("Function is_valid_move test"){
    Reversi reversi_game;
    char game_board_situation1[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '},
        {' ', ' ', 'X', 'O', 'X', ' ', ' ', ' '},
        {' ', ' ', 'O', 'X', 'O', ' ', ' ', ' '},
        {' ', 'O', ' ', ' ', ' ', 'O', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           
    };
    create_game_board_situation(game_board_situation1, reversi_game);
    
    std::array<int, 2> coordinates = {2, 4};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==0);
    coordinates = {4,1};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==1);
    coordinates = {2,2};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==1);
    coordinates = {1,7};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==0);

    char game_board_situation2 [num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'O', ' ', ' ', 'X', ' ', ' '},
        {'X', ' ', 'O', 'O', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', 'O', 'O', ' ', ' ', ' '},
        {' ', ' ', 'X', 'X', 'O', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    
    };
    create_game_board_situation(game_board_situation2, reversi_game);
    coordinates = {1,2};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==1);
    coordinates = {3,1};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==1);
    coordinates = {2,1};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==0);
    coordinates = {1,5};
    CHECK(reversi_game.is_valid_move(coordinates, 'X')==0);

}

