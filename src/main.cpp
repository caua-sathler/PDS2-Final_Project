#include "Reversi.hpp"
#include <iostream>

using namespace std;

int main()
{
    Reversi reversi1;
    /*reversi1.game_board[2][2]='X';
    reversi1.game_board[3][3]='X';
    reversi1.game_board[4][4]='X';
    reversi1.game_board[5][5]='X';
    reversi1.game_board[2][3]='O';
    reversi1.game_board[3][4]='O';
    reversi1.game_board[4][3]='O';
    reversi1.game_board[5][4]='O';*/
    reversi1.print_game_board();

    char player_piece = 'X';
    char opponent_piece = 'O';

    while (true)
    {
        int x, y;

        bool is_there_movement_for_player = reversi1.is_there_any_valid_move_for_player(player_piece);
        bool someone_won = reversi1.check_win
        (is_there_movement_for_player, player_piece);

        if (someone_won)
        {

            break;
        }
        else if (is_there_movement_for_player && !someone_won)
        {

            cin >> x >> y;
            reversi1.process_move({x, y}, player_piece);

            player_piece = reversi1.switch_players(player_piece);
            opponent_piece = reversi1.switch_players(opponent_piece);
        }
        else if (!is_there_movement_for_player && !someone_won)
        {
            player_piece = reversi1.switch_players(player_piece);
            opponent_piece = reversi1.switch_players(opponent_piece);
        }
    }
   
}