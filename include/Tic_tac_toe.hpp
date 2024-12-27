#ifndef TIC_H
#define TIC_H

#include "Game.hpp"

class tic_tac_toe : public Game {
    private:
        int num_rows;
        int num_columns;

    public:
        tic_tac_toe(int num_rows_received, int num_columns_received);
        bool verify_valid_move(int x, int y) override;
        void make_move(int x, int y);
        void check_win() override;
        ~tic_tac_toe();
};

#endif
