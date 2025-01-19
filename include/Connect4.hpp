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
        void make_move() override;
        bool check_win() override;
    
        bool is_valid_move(int column); //Sobrecarga
        void make_move(int column); //Sobrecarga
        char get_current_player();
        bool is_board_full() const;
        void print_game_board() const;
        void set_current_player(char player);
        ~Connect4();
};

#endif