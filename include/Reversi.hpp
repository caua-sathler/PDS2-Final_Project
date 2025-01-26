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
        void set_num_pieces_player_X(int x);
        void set_num_pieces_player_O(int x);

        Board& get_game_board();
        void start_reversi_board();

        //feito
        bool is_there_player_piece_at_the_direction(const char player_piece, const std::array<int, 2>& direction, 
             std::array<int, 2> adjacent_square) const;

        //feito     
        bool is_there_direction_that_captures_opponent(const std::array<int, 2> &move_coordinates, char player_piece_type);
        //feito
        bool is_space_free_reversi(int x, int y) const;
        //feito
        bool is_valid_move(std::array<int, 2>& move_coordinates, char player_piece_type);    
        //feito   
        bool is_there_valid_move_for_player(char player_piece);
        //feito
        bool check_win(bool is_there_move_for_player, char opponent_piece);
        //feito
        void flip_pieces(std::array<int, 2> directions, std::array<int, 2> move_coordinates, char player_piece);
        //julia
        void control_num_pieces_players(int num_pieces_flipped, char player_piece);
        //caua
        void make_move(std::array<int, 2> move_coordinates, char player_piece, std::list<std::array<int, 2>>& directions_to_capture_opponents);
        //julia
        void find_all_directions_to_make_move(std::array<int, 2>& move_coordinates, char player_piece, std::list<std::array<int, 2>>&directions_to_capture_opponents);
        //julia
        bool process_move(std::array<int, 2> move_coordinates, char player_piece_type);

        void register_win_and_loss(Player *player1, Player *player2);

        bool is_valid_move() const override;
        bool check_win() override;
        void make_move() override;
        ~Reversi();
};

#endif