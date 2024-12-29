#include "Game.hpp"
#ifndef REVERSI_H
#define REVERSI_H
class Reversi : public Game{
    private:
        int num_pieces_player1;
        int num_pieces_player2;
    public:
        Reversi();
        bool is_valid_move() const override;
        bool is_valid_move(int x, int y, char player_piece_type) const; 
        virtual void make_move() override;
        virtual void check_win() const override; 
};
#endif