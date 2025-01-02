#ifndef CONNECT4_H
#define CONNECT4_H

#include "Game.hpp"
#include <iostream>

class Connect4 : public Game {
    private:
        char current_player;

    public:
        Connect4();
        bool is_valid_move() const override;
        bool is_valid_move(int column) const; //Sobrecarga
        bool is_move_inside_board(int = 0, int) const override;
        void make_move() override;
        void make_move(int column); //Sobrecarga
        void check_win() const override;
        void switch_players();
        ~Connect4();
};

#endif