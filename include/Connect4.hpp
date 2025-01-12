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
        void make_move() override;
        void make_move(int column); //Sobrecarga
        bool check_win();
        char get_current_player() const;
        bool is_board_full() const;
        void print_game_board() const;
        ~Connect4();
};

#endif