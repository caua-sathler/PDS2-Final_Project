#include "Reversi.hpp"
#include <iostream>
const int num_columns_and_rows_reversi = 8;

Reversi::Reversi() : Game(num_columns_and_rows_reversi, num_columns_and_rows_reversi) {}

bool Reversi::is_valid_move() const
{
    return true;
}


bool Reversi::is_space_free(int x, int y) const
{
    if ((this->game_board[x - 1][y - 1] != ' '))
    {
        return false;
    }
    return true;
}

bool Reversi::is_there_player_piece_at_the_direction(char player_piece, const int direction[2], const int adjacent_square[2]) const{
    int current_square[2];

    current_square[0]=adjacent_square[0]+direction[0];
    current_square[1]=adjacent_square[1]+direction[1];

    while(this->is_move_inside_board(current_square[0]+1,current_square[1]+1)){
        if(this->game_board[current_square[0]][current_square[1]]==player_piece){
            return true;
        }else if(this->game_board[current_square[0]][current_square[1]]==' '){
            return false;
        }
        current_square[0]+=direction[0];
        current_square[1]+=direction[1];
    }
    return false;

}

bool Reversi::is_valid_move(int x, int y, char player_piece_type) const
{
    if (this->is_move_inside_board(x, y) == false)
        return false;

    if (this->is_space_free(x, y) == false)
        return false;

    x--;
    y--;
    char other_player_piece_type = (player_piece_type == 'X') ? 'O' : 'X';

    int adjacent_square[2] = {0, 0};

    for (int i = 1; i > -2; i--)
    {
        for (int j = 1; j > -2; j--)
        {
            if (j != 0 || i != 0)
            {
                adjacent_square[0] = x + i;
                adjacent_square[1] = y + j;

                if (this->is_move_inside_board(adjacent_square[0], adjacent_square[1])&&this->game_board[adjacent_square[0]][adjacent_square[1]]==other_player_piece_type)
                {
                    int direction[2]={adjacent_square[0]-x, adjacent_square[1]-y};
                    if(is_there_player_piece_at_the_direction(player_piece_type, direction, adjacent_square)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Reversi::make_move()
{
}

void Reversi::check_win() const
{
}

