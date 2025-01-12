#include "Game.hpp"
#include "Player.hpp"
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
        int get_num_pieces_player_X();
        int get_num_pieces_player_O();
        void start_reversi_board();
        void print_reversi_board() const;
        bool is_there_player_piece_at_the_direction(const char player_piece, const std::array<int, 2>& direction, 
             std::array<int, 2> adjacent_square) const;
        bool is_space_free_reversi(int x, int y) const;
        bool is_there_direction_that_captures_opponent(const std::array<int, 2> &move_coordinates, char player_piece_type);
        bool is_valid_move() const override;
        bool is_valid_move(std::array<int, 2>& move_coordinates, char player_piece_type);        
        void indicate_all_direction_to_make_move();
        void find_all_directions_to_make_move(std::array<int, 2>& move_coordinates, char player_piece, std::list<std::array<int, 2>>&directions_to_capture_opponents);
        void flip_pieces(std::array<int, 2> directions, std::array<int, 2> move_coordinates, char player_piece);
        void control_num_pieces_players(int num_pieces_flipped, char player_piece);
        void make_move() override;
        void make_move(std::array<int, 2> move_coordinates, char player_piece, std::list<std::array<int, 2>>& directions_to_capture_opponents);
        bool is_there_valid_move_for_player(char player_piece);
        bool process_move(std::array<int, 2> move_coordinates, char player_piece_type);
        bool check_win() override;
        bool check_win(bool is_there_move_for_player, char opponent_piece);
        void register_win_and_loss(Player *player1, Player *player2);
        ~Reversi();
};

#endif