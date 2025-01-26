#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Reversi.hpp"
#include <iostream>
#include <array>
using namespace std;

const int num_columns_and_rows_reversi = 8;

/**
 * @brief Aloca um tabuleiro com situações de teste no Reversi sem a necessidade de uma
 * partida real.
 * @param game_board_situation Tabuleiro que simula situações de jogo
 * @param reversi_game Instância da classe Reversi
 */
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

TEST_CASE("Function is_there_direction_that_captures_opponent") {
    Reversi reversi_game;
    char game_board_situation[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', 'X', ' ', '*'},
        {' ', ' ', 'X', 'X', ' ', ' ', '*', 'O'},
        {' ', 'O', 'X', 'O', ' ', ' ', ' ', ' '},
        {'X', ' ', 'O', 'O', 'O', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', 'O', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    create_game_board_situation(game_board_situation, reversi_game);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({1,2}, 'O') == 1);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({5,3}, 'X') == 1);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({7,7}, 'O') == 1);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({6,4}, 'X') == 1);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({4,5}, 'X') == 0);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({7,3}, 'O') == 0);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({7,7}, 'X') == 0);
    CHECK(reversi_game.is_there_direction_that_captures_opponent({1,6}, 'O') == 0);    
}




TEST_CASE("Function is_there_valid_move_for_player test"){
    Reversi reversi_game;
    char game_board_situation1[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '},
        {' ', ' ', 'X', 'X', 'X', ' ', ' ', ' '},
        {' ', ' ', 'X', 'X', 'X', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           
    };
    create_game_board_situation(game_board_situation1, reversi_game);
    CHECK(reversi_game.is_there_valid_move_for_player('O') == 0);
    CHECK(reversi_game.is_there_valid_move_for_player('X') == 0);
    char game_board_situation2[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {'X', ' ', 'X', 'X', 'X', 'X', 'X', ' '},
        {'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', ' '},
        {'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', ' '},
        {' ', ' ', ' ', 'O', ' ', 'O', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'O', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O'}
    };
    create_game_board_situation(game_board_situation2, reversi_game);
    CHECK(reversi_game.is_there_valid_move_for_player('O') == 0);
    CHECK(reversi_game.is_there_valid_move_for_player('X') == 1);
    char game_board_situation3[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {'X', ' ', 'X', ' ', ' ', ' ', ' ', ' '},
        {'X', 'X', 'X', ' ', ' ', ' ', ' ', ' '},
        {'X', 'X', 'X', ' ', 'X', ' ', ' ', ' '},
        {'X', 'X', 'X', 'X', 'O', 'O', '*', ' '},
        {'X', 'O', 'O', 'O', 'O', 'O', '*', ' '},
        {'*', '*', '*', 'O', '*', 'O', ' ', ' '},
        {' ', ' ', ' ', '*', '*', ' ', 'O', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O'}
    };
    create_game_board_situation(game_board_situation3, reversi_game);
    CHECK(reversi_game.is_there_valid_move_for_player('O') == 1);
    CHECK(reversi_game.is_there_valid_move_for_player('X') == 1);

}  

TEST_CASE("Function check_win test"){
    Reversi reversi_game;
    char game_board_situation1[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'O', ' ', ' ', ' ', 'O', ' ', ' '},
        {' ', ' ', 'O', 'O', 'O', ' ', ' ', ' '},
        {' ', ' ', 'O', 'O', 'O', ' ', ' ', ' '},
        {' ', 'O', ' ', ' ', ' ', 'O', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'O', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           
    };
    create_game_board_situation(game_board_situation1, reversi_game);
    CHECK(reversi_game.check_win(reversi_game.is_there_valid_move_for_player('O'), 'X') == 1);
    
    char game_board_situation2[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '},
        {' ', ' ', 'X', 'X', 'X', ' ', ' ', ' '},
        {' ', ' ', 'X', 'X', 'X', ' ', ' ', ' '},
        {' ', 'X', ' ', ' ', ' ', 'X', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'X', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           
    };
    create_game_board_situation(game_board_situation2, reversi_game);
    CHECK(reversi_game.check_win(reversi_game.is_there_valid_move_for_player('X'), 'O') == 1);
    char game_board_situation3[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {'X', ' ', 'X', ' ', ' ', ' ', ' ', ' '},
        {'X', 'X', 'X', ' ', ' ', ' ', ' ', ' '},
        {'X', 'X', 'X', ' ', 'X', ' ', ' ', ' '},
        {'X', 'X', 'X', 'X', 'O', 'O', '*', ' '},
        {'X', 'O', 'O', 'O', 'O', 'O', '*', ' '},
        {'*', '*', '*', 'O', '*', 'O', ' ', ' '},
        {' ', ' ', ' ', '*', '*', ' ', 'O', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O'}
    };
    create_game_board_situation(game_board_situation3, reversi_game);
    CHECK(reversi_game.check_win(reversi_game.is_there_valid_move_for_player('O'), 'X') == 0);
    CHECK(reversi_game.check_win(reversi_game.is_there_valid_move_for_player('X'), 'O') == 0);
    char game_board_situation4[num_columns_and_rows_reversi][num_columns_and_rows_reversi]={
        {'X', 'X', 'X', 'X', 'X', 'X', ' ', ' '},
        {'X', 'X', 'X', 'X', 'X', 'X', ' ', ' '},
        {'X', 'O', 'X', 'X', 'X', 'X', ' ', 'X'},
        {' ', ' ', 'O', 'X', 'X', 'X', 'X', ' '},
        {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X'},
        {' ', ' ', 'X', ' ', 'O', 'X', 'X', 'X'},
        {' ', ' ', 'X', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', ' ', ' ', ' ', ' ', ' '}
    };
    create_game_board_situation(game_board_situation4, reversi_game);
    //X has valid moves, but O doesn't. Game is not over yet 
    CHECK(reversi_game.check_win(reversi_game.is_there_valid_move_for_player('O'), 'X') == 0);
    char game_board_situation5 [num_columns_and_rows_reversi][num_columns_and_rows_reversi]{
        {'X', ' ', 'O', 'O', ' ', ' ', 'O', 'O'},
        {'X', ' ', 'O', 'O', ' ', 'O', 'O', ' '},
        {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'X', ' ', 'X', 'X', 'O', 'O', 'O', 'O'},
        {' ', ' ', ' ', ' ', ' ', 'O', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    create_game_board_situation(game_board_situation5, reversi_game);
    //O has valid moves, but X doesn't. Game is not over yet 
    CHECK(reversi_game.check_win(reversi_game.is_there_valid_move_for_player('X'), 'O') == 0);
}

TEST_CASE("Function control_num_pieces_player test")
{
    Reversi reversi_game;
    reversi_game.set_num_pieces_player_O(10);
    reversi_game.set_num_pieces_player_X(2);

    reversi_game.control_num_pieces_players(3, 'X');
    CHECK(reversi_game.get_num_pieces_player_X() == 5);
    CHECK(reversi_game.get_num_pieces_player_O() == 7);

    reversi_game.control_num_pieces_players(5, 'O');
    CHECK(reversi_game.get_num_pieces_player_X() == 0);
    CHECK(reversi_game.get_num_pieces_player_O() == 12);
    
    reversi_game.control_num_pieces_players(0, 'O');
    CHECK(reversi_game.get_num_pieces_player_X() == 0);
    CHECK(reversi_game.get_num_pieces_player_O() == 12);
}

TEST_CASE("Function flip_pieces test") 
{
    Reversi reversi_game;
    char game_board_situation[num_columns_and_rows_reversi][num_columns_and_rows_reversi] =
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', 'O', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} 
    };
    create_game_board_situation(game_board_situation, reversi_game);
    reversi_game.set_num_pieces_player_O(1);
    reversi_game.set_num_pieces_player_X(1);
    // Armazena todas as direções em que é possível capturar um oponente
    std::list<std::array<int, 2>> directions_to_capture_opponents;
    directions_to_capture_opponents.push_back({0,1});

    std::array<int, 2> move_coordinates = {2, 1};

    for (auto direction : directions_to_capture_opponents)
        reversi_game.flip_pieces(direction, move_coordinates, 'O');

    // Verifica se a peça do jogador adversário foi tomada
    CHECK(reversi_game.get_game_board().get_space(2,2) == 'O');
    // Verifica se as peças flippadas foram adicionadas e subtraídas corretamente
    CHECK(reversi_game.get_num_pieces_player_O() == 2);
    CHECK(reversi_game.get_num_pieces_player_X() == 0);
    // Limpa a lista para iniciar os próximos testes
    directions_to_capture_opponents.clear();


    char game_board_situation2[num_columns_and_rows_reversi][num_columns_and_rows_reversi] =
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'O', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', 'O', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} 
    };
    create_game_board_situation(game_board_situation2, reversi_game);
    reversi_game.set_num_pieces_player_O(2);
    reversi_game.set_num_pieces_player_X(4);
    directions_to_capture_opponents.push_back({-1,-1});
    directions_to_capture_opponents.push_back({0,-1});
    move_coordinates = {5,5};
    for (auto direction : directions_to_capture_opponents)
        reversi_game.flip_pieces(direction, move_coordinates, 'O');

    CHECK(reversi_game.get_game_board().get_space(5,4) == 'O');
    CHECK(reversi_game.get_game_board().get_space(4,4) == 'O');
    CHECK(reversi_game.get_game_board().get_space(3,3) == 'O');
    CHECK(reversi_game.get_game_board().get_space(2,2) == 'O');

    CHECK(reversi_game.get_num_pieces_player_O() == 6);
    CHECK(reversi_game.get_num_pieces_player_X() == 0);
    directions_to_capture_opponents.clear();


    char game_board_situation3[num_columns_and_rows_reversi][num_columns_and_rows_reversi] =
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {' ', ' ', ' ', 'X', ' ', ' ', 'O', ' '},
        {' ', ' ', ' ', 'O', ' ', 'O', ' ', ' '},
        {' ', ' ', ' ', 'O', 'O', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'O', 'O', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '} 
    };
    create_game_board_situation(game_board_situation3, reversi_game);
    reversi_game.set_num_pieces_player_X(4);
    reversi_game.set_num_pieces_player_O(8);
    directions_to_capture_opponents.push_back({-1,1});
    directions_to_capture_opponents.push_back({-1,0});
    directions_to_capture_opponents.push_back({1,0});
    directions_to_capture_opponents.push_back({0,-1});
    move_coordinates = {5,3};
    for (auto direction : directions_to_capture_opponents)
        reversi_game.flip_pieces(direction, move_coordinates, 'X');
    
    CHECK(reversi_game.get_game_board().get_space(4,4) == 'X');
    CHECK(reversi_game.get_game_board().get_space(3,5) == 'X');
    CHECK(reversi_game.get_game_board().get_space(2,6) == 'X');
    CHECK(reversi_game.get_game_board().get_space(4,3) == 'X');
    CHECK(reversi_game.get_game_board().get_space(3,3) == 'X');
    CHECK(reversi_game.get_game_board().get_space(6,3) == 'X');
    CHECK(reversi_game.get_game_board().get_space(5,2) == 'X');
    CHECK(reversi_game.get_game_board().get_space(6,4) == 'O');

    CHECK(reversi_game.get_num_pieces_player_X() == 11);
    CHECK(reversi_game.get_num_pieces_player_O() == 1);
}


TEST_CASE("Function make_move test")
{
    Reversi reversi_game;
    char game_board_situation[num_columns_and_rows_reversi][num_columns_and_rows_reversi] =
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {' ', ' ', ' ', 'X', ' ', ' ', 'O', ' '},
        {' ', ' ', ' ', 'O', ' ', 'O', ' ', ' '},
        {' ', ' ', ' ', 'O', 'O', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'O', 'O', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '} 
    };
    create_game_board_situation(game_board_situation, reversi_game);
    std::list<std::array<int, 2>> directions_to_capture_opponents;
    std::array<int, 2> move_coordinates;

    directions_to_capture_opponents.push_back({-1,1});
    directions_to_capture_opponents.push_back({-1,0});
    directions_to_capture_opponents.push_back({1,0});
    directions_to_capture_opponents.push_back({0,-1});
    move_coordinates = {5,3};

    reversi_game.set_num_pieces_player_X(4);
    reversi_game.set_num_pieces_player_O(8);

    reversi_game.make_move(move_coordinates, 'X', directions_to_capture_opponents);
    // Verifica se as peças flippadas e a jogada foram somadas e subtraídas adequadamente 
    CHECK(reversi_game.get_num_pieces_player_X() == 12);
    CHECK(reversi_game.get_num_pieces_player_O() == 1);
    // Verifica se a peça jogada foi posicionada no tabuleiro
    CHECK(reversi_game.get_game_board().get_space(5,3) == 'X');
    directions_to_capture_opponents.clear();


   char game_board_situation2[num_columns_and_rows_reversi][num_columns_and_rows_reversi] =
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'O', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', 'X', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', 'O', 'X', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} 
    };
    create_game_board_situation(game_board_situation2, reversi_game);
    directions_to_capture_opponents.push_back({-1,-1});
    directions_to_capture_opponents.push_back({0,-1});
    move_coordinates = {5,5};   

    reversi_game.set_num_pieces_player_O(2);
    reversi_game.set_num_pieces_player_X(4);
    
    reversi_game.make_move(move_coordinates, 'O', directions_to_capture_opponents);

    CHECK(reversi_game.get_num_pieces_player_O() == 7);
    CHECK(reversi_game.get_num_pieces_player_X() == 0);
    CHECK(reversi_game.get_game_board().get_space(5,5) == 'O');
}

TEST_CASE("Function find_all_directions_that_make_move test"){
    Reversi reversi_game;
    
    char game_board_situation1 [num_columns_and_rows_reversi][num_columns_and_rows_reversi]{
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', '*', 'X', 'O', '*', ' '},
        {' ', 'O', 'X', '*', 'X', 'X', 'O', ' '},
        {' ', ' ', 'O', 'X', 'X', 'X', 'X', '*'},
        {' ', '*', 'X', 'O', 'X', '*', ' ', ' '},
        {' ', '*', 'O', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    create_game_board_situation(game_board_situation1, reversi_game);

    SUBCASE("Multiple directions"){
        std::list<std::array<int, 2>> directions_to_capture_opponents_function;
        std::array<int, 2> move = {2,3}, direction1 = {1,0}, direction2={0,1}, direction3={0,-1};
        std::list<std::array<int, 2>> directions_to_capture_opponents_test ={direction1, direction2, direction3};
        reversi_game.find_all_directions_to_make_move(move, 'O', directions_to_capture_opponents_function);

        CHECK(directions_to_capture_opponents_function == directions_to_capture_opponents_test);

        move = {4,5};
        directions_to_capture_opponents_function.clear();
        directions_to_capture_opponents_test.clear();
        direction1 = {0,-1};
        direction2 = {-1,0};
        directions_to_capture_opponents_test = {direction1, direction2};
        reversi_game.find_all_directions_to_make_move(move, 'O', directions_to_capture_opponents_function);
        CHECK(directions_to_capture_opponents_function == directions_to_capture_opponents_test);

    }
       
    SUBCASE("One direction"){
        std::array<int, 2> move = {2,7}, direction = {0,-1};
        std::list<std::array<int, 2>> directions_to_capture_opponents_test ={direction};
        std::list<std::array<int, 2>> directions_to_capture_opponents_function;
        reversi_game.find_all_directions_to_make_move(move, 'X', directions_to_capture_opponents_function);
        CHECK(directions_to_capture_opponents_function == directions_to_capture_opponents_test);
    }
    SUBCASE("No direction"){
        std::list<std::array<int, 2>> directions_to_capture_opponents_function;
        std::array<int, 2> move = {0,4};
        reversi_game.find_all_directions_to_make_move(move, 'X', directions_to_capture_opponents_function);
        CHECK(directions_to_capture_opponents_function.empty()==1);
    }
}
    
TEST_CASE("Function process_move"){
    Reversi reversi_game;
    
    char game_board_situation1 [num_columns_and_rows_reversi][num_columns_and_rows_reversi]{
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', '*', 'X', 'O', '*', ' '},
        {' ', 'O', 'X', '*', 'X', 'X', 'O', ' '},
        {' ', ' ', 'O', 'X', 'X', 'X', 'X', '*'},
        {' ', '*', 'X', 'O', 'X', '*', ' ', ' '},
        {' ', '*', 'O', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
         
    };
    create_game_board_situation(game_board_situation1, reversi_game);
    std::array<int, 2> move = {2,3};
    SUBCASE("Valid moves"){
        CHECK(reversi_game.process_move(move, 'O') == 1);
        move = {6,4};
        CHECK(reversi_game.process_move(move, 'X') == 1);
    }
    SUBCASE("Invalid moves"){
        move = {8,8};
        CHECK(reversi_game.process_move(move, 'X') == 0);
        move = {2,2};
        CHECK(reversi_game.process_move(move, 'O') == 0);
    }
}



//EP R Joao123 Maria999

//EP R Joao123 Maria999