#include "Reversi.hpp"
#include <iostream>

using namespace std;

int main() {
    Reversi reversi1;
    reversi1.game_board[2][1]='X';
    reversi1.game_board[3][3]='X';
    reversi1.game_board[4][4]='X';
    reversi1.game_board[5][5]='X';
    reversi1.game_board[2][2]='O';
    reversi1.game_board[3][4]='O';
    reversi1.game_board[4][3]='O';
    reversi1.game_board[5][4]='O';
    reversi1.print_game_board();

    reversi1.process_move({3,5},'X');
    reversi1.process_move({3,2},'O');
    reversi1.process_move({4,3},'O');
    reversi1.process_move({5,6},'O');
    reversi1.process_move({6,7},'O');

    reversi1.process_move({3,3},'O');
    reversi1.process_move({4,6},'O');
}