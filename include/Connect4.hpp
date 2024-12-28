#ifndef CONNECT4_H
#define CONNECT4_H

#include "Game.hpp"
#include <iostream>

class Connect4 : public Game {
    private:
        char current_player;

    public:
        Connect4();
        bool is_valid_move(int column) const;
        bool is_move_inside_board(int column) const;
        void make_move(int column);
        void check_win() const;
        void switch_players();
        ~Connect4();
};

#endif