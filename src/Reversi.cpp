#include "Reversi.hpp"
#include <iostream>
#include "list"
#include "array"
const int num_columns_and_rows_reversi = 8;

Reversi::Reversi() : Game(num_columns_and_rows_reversi, num_columns_and_rows_reversi) {}

bool Reversi::is_valid_move() const
{
    return true;
}


bool Reversi::is_space_free(int x, int y) const
{
    if ((this->game_board[x - 1][y - 1] != ' '))
        return false;

    return true;
}


bool Reversi::is_there_player_piece_at_the_direction(const char player_piece, const std::array<int, 2>& direction, 
    std::array<int, 2> adjacent_square) const 
{
    std::array<int, 2> current_square = {adjacent_square[0] + direction[0], adjacent_square[1] + direction[1]};

    while (this->is_move_inside_board(current_square[0] + 1, current_square[1] + 1)) 
    {
        if (this->game_board[current_square[0]][current_square[1]] == player_piece) 
            return true;
        else if (this->game_board[current_square[0]][current_square[1]] == ' ')
            return false;
            
        current_square[0] += direction[0];
        current_square[1] += direction[1];
    }
    return false;
}

void Reversi::find_squares_that_make_moves_against_opponent(const std::array<int, 2> &move_coordinates, char player_piece_type, std::list<std::array<int, 2>>& squares_to_make_move) {
    char other_player_piece_type = (player_piece_type == 'X') ? 'O' : 'X';

    std::array<int, 2> adjacent_square = {0, 0};

    for (int i = 1; i > -2; i--)
    {
        for (int j = 1; j > -2; j--)
        {
            if (j != 0 || i != 0) {
                adjacent_square[0] = move_coordinates[0] + i;
                adjacent_square[1] = move_coordinates[1] + j;

                if (this->is_move_inside_board(adjacent_square[0] + 1, adjacent_square[1] + 1) && 
                    this->game_board[adjacent_square[0]][adjacent_square[1]] == other_player_piece_type)
                {
                    std::array<int, 2> direction = {adjacent_square[0] - move_coordinates[0], adjacent_square[1] - move_coordinates[1]};
                    if (is_there_player_piece_at_the_direction(player_piece_type, direction, adjacent_square)) {
                        squares_to_make_move.push_back(adjacent_square);
                    } 
                }
            }
        }
    }
}

 bool Reversi::is_valid_move(const std::array<int, 2>& move_coordinates, char player_piece_type, std::list<std::array<int, 2>>& squares_to_make_move)
{
    if (!this->is_move_inside_board(move_coordinates[0], move_coordinates[1]))
        return false;

    if (!this->is_space_free(move_coordinates[0], move_coordinates[1]))
        return false;

    this->find_squares_that_make_moves_against_opponent(move_coordinates, player_piece_type, squares_to_make_move);
    if (squares_to_make_move.empty()) {
        return false;
    }
    
    return true;
}

void Reversi::process_move(const std::array<int, 2>& move_coordinates, char player_piece) {
    std::list<std::array<int, 2>> squares_to_capture_opponents;
    if(this->is_valid_move(move_coordinates, player_piece, squares_to_capture_opponents)){
        std::cout<<"a"<<std::endl;
    }
    for(auto i:squares_to_capture_opponents){
        std::cout << i[0]<< ""<< i[1]<< std::endl;
    }
}

void Reversi::make_move()
{
    return;
}

/*void Reversi::make_move(int x, int y, char player_piece) {
    if(!is_valid_move(x, y, player_piece)) 
        return;
    
    x--;
    y--;

}*/

void Reversi::check_win() const
{
}

