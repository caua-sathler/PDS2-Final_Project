#ifndef TIC_H
#define TIC_H

#include "Game.hpp"

class tic_tac_toe : public Game {
    private:
        char current_player;

    public:
        tic_tac_toe();
        bool verify_valid_move(int x, int y) const override;
        void make_move(int x, int y);
        void check_win() const override;
        void switch_players();
        ~tic_tac_toe();
};

#endif
