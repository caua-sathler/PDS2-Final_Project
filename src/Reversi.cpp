#include "Reversi.hpp"
#include <iostream>
const int num_columns_and_rows_reversi = 8;

Reversi::Reversi():Game(num_columns_and_rows_reversi, num_columns_and_rows_reversi){};

bool Reversi::is_valid_move() const{
    return true;
}

bool Reversi::is_valid_move(int x, int y, char player_piece_type) const{
    char other_player_piece_type;
    if (this->is_move_inside_board(x, y) == false)
    {
        return false;
    }

     if(player_piece_type=='X'){
        other_player_piece_type='O';
    }else if(player_piece_type=='O'){
        other_player_piece_type='X';
    }

    int adjacent_square_x=0;
    int adjacent_square_y=0;

    for(int i=1;i>-2;i--){
        for(int j=1;i>-2;i--){
            adjacent_square_x=x+1;
            adjacent_square_y=y+j;
            std::cout<<adjacent_square_x<<" "<<adjacent_square_y<<std::endl;
        }
    }

}