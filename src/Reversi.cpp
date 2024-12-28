#include "Reversi.hpp"
bool Reversi::is_valid_move() const
{
        return true;
}

bool Reversi::is_valid_move(int x, int y, char player_piece_type) const
{
        if (this->is_move_inside_board(x, y) == false){
                return false;
        }

        
}