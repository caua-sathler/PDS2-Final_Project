#include "Board.hpp"
#include <iostream>
//set_space
void Board::set_space(int row, int column, char value) 
{
    this->game_board[row][column] = value;
}
//get_space
char Board::get_space(int row, int column) const 
{
    return this->game_board[row][column];
}

Board::Board(int num_rows_received, int num_columns_received) : num_rows(num_rows_received), 
num_columns(num_columns_received) 
{   
    game_board = std::unique_ptr<std::unique_ptr<char[]>[]>(new std::unique_ptr<char[]>[num_rows]);

    // Inicializar cada linha com um array de inteiros
    for (int i = 0; i < num_rows; ++i) {
        game_board[i] = std::unique_ptr<char[]>(new char[num_columns]);
        for (int j=0; j < num_columns; j++){
            game_board[i][j] = ' ';
        }
    }

    /*std::unique_ptr<std::unique_ptr<int[]>[]> arr(new std::unique_ptr<int[]>[100]);
    for (int i = 0; i < 100; i++)
    {
    arr[i] = std::unique_ptr<int[]>(new int[100]);
    } 
    for(int i = 0; i < num_rows; ++i) 
        game_board[i] = std::make_unique<char[]>(num_columns);
        
    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_columns; j++)
            this->game_board[i][j] = ' ';
    }*/
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
