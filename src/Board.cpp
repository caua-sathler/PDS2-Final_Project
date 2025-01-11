#include "Board.hpp"
#include <iostream>

char& Board::modify_space(int row, int column) 
{
    return this->game_board[row][column];
}

char Board::access_space(int row, int column) const 
{
    return this->game_board[row][column];
}

Board::Board(int num_rows_received, int num_columns_received) : num_rows(num_rows_received), 
num_columns(num_columns_received), game_board(std::make_unique<std::unique_ptr<char[]>[]>(num_rows)) 
{   
    for(int i = 0; i < num_rows; ++i) 
        game_board[i] = std::make_unique<char[]>(num_columns);
        
    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_columns; j++)
            this->game_board[i][j] = ' ';
    }
}


void Board::print_game_board() const 
{
    for(int i = 0; i < num_rows; i++) {
     std::cout << "|" << std::ends;   
        for(int j = 0; j < num_columns; j++) {
            std::cout << this->game_board[i][j] << "|" << std::ends;
        }
        std::cout << std::endl;
    }
}


bool Board::is_move_inside_board(int x, int y) const
{
    if ((x < 0 || x > this->num_rows - 1) || (y < 0 || y > this->num_columns - 1))
        return false;
            
    return true;
}

bool Board::is_space_free(int x, int y) const
{
    if ((this->game_board[x][y] == ' '))
        return true;

    return false;
}
