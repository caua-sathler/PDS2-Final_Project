#ifndef TIC_H
#define TIC_H

#include "Game.hpp"

class tic_tac_toe : public Game {
    protected:
        char current_player;

    public:
        tic_tac_toe();
        bool is_move_inside_board(int x, int y) const override;
        void make_move() override;
        void make_move(int x, int y);
        bool is_valid_move() const override;
        bool is_valid_move(int& x, int& y);
        void check_win() const override;
        char check_win(bool& win);
        void switch_players();
        bool is_space_free(int& x, int& y) const;
        ~tic_tac_toe();
};

#endif
