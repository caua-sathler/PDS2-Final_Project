#ifndef CONNECT4_HPP
#define CONNECT4_HPP

#include "Game.hpp"
#include <iostream>
#include <string>

class Connect4 : public Game {
    private:
        std::string current_player;
    public:
        Connect4(int num_rows, int num_columns);

        bool verify_valid_move(int column) override;
        bool make_move(int column) override;
        void check_win() override;
};

#endif