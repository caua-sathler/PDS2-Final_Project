#ifndef TIC_H
#define TIC_H

#include "Game.hpp"

class tic_tac_toe : public Game {
    protected:
        char current_player;
        char winner;
        int moves_count;

    public:
        tic_tac_toe();
        int get_moves_count() const;
        void set_moves_count(int count);
        Board& get_game_board();
        void set_game_board(const char game_board_situation[3][3]);
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
