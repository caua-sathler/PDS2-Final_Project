#include "Game.hpp"
#ifndef REVERSI_H
#define REVERSI_H
#include <array>
#include <list>

class Reversi : public Game {
    private:
        int num_pieces_player_X;
        int num_pieces_player_O;
    public:
        Reversi();
        void start_reversi_board();
        bool is_valid_move() const override;
        bool is_valid_move(std::array<int, 2>& move_coordinates, char player_piece_type, std::list<std::array<int, 2>>& squares_to_make_move);
        bool is_space_free(int x, int y) const;
        bool is_move_inside_board(int x, int y) const override;
        bool is_there_player_piece_at_the_direction(const char player_piece, const std::array<int, 2>& direction, 
             std::array<int, 2> adjacent_square) const;
        void flip_pieces(std::array<int, 2> directions, std::array<int, 2> move_coordinates, char player_piece);
        void make_move() override;
        void make_move(std::array<int, 2> move_coordinates, char player_piece, std::list<std::array<int, 2>>& directions_to_capture_opponents); 
        virtual void check_win() const override; 
        void find_directions_that_make_moves_against_opponent(const std::array<int, 2>& move_coordinates, char player_piece_type, std::list<std::array<int, 2>>& squares_to_make_move);
        bool process_move(std::array<int, 2> move_coordinates, char player_piece_type);
};

#endif