#include "Reversi.hpp"
#include <iostream>
#include <limits>

using namespace std;


int main()
{
    Reversi reversi1;

    char player_piece = 'O';
    char opponent_piece = 'X';

    while (true)
    {
        int x, y;

        bool is_there_movement_for_player = reversi1.is_there_valid_move_for_player(player_piece);
        bool someone_won = reversi1.check_win
        (is_there_movement_for_player, player_piece);
        reversi1.print_reversi_board();

        if (someone_won)
        {

            break;
        }
        else if (is_there_movement_for_player && !someone_won)
        {
            std::cout<<player_piece<<std::endl;
            if (!(cin >> x >> y))
            {
                cout << "Invalid input. Please enter two integers for your move.\n";
                cin.clear();                // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue; // Retry input
            }


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