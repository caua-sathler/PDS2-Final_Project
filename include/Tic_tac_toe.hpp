#ifndef TIC_H
#define TIC_H

#include "Game.hpp"

class tic_tac_toe : public Game {
    protected:
        char current_player;
        char winner;

    public:
        tic_tac_toe();
        Board& get_game_board();
        void make_move() override;
        void make_move(int x, int y);
        bool is_valid_move() const override;
        bool is_valid_move(int& x, int& y) const;
        bool check_win() override;
        char check_tic_tac_toe_win() const;
        char get_current_player() const;
        bool check_tie() const;
        void print_tic_tac_toe_board() const;
        ~tic_tac_toe();
};

#endif
