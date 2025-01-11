#ifndef GAME_H
#define GAME_H
#include "Board.hpp"
#include <array>

class Game {
    protected:
        Board game_board;

    public:
        Game(int num_rows_received, int num_columns_received);
        virtual bool is_valid_move() const = 0;
        virtual void make_move() = 0;
        virtual bool check_win() = 0;
        char switch_players(char current_player);
        ~Game() {}
};

#endif