#include "Reversi.hpp"
#include <iostream>

using namespace std;

int main() {
    Reversi reversi1;
    reversi1.game_board[2][2]='X';
    reversi1.game_board[3][3]='X';
    reversi1.game_board[4][4]='X';
    reversi1.game_board[5][5]='X';
    reversi1.game_board[2][3]='O';
    reversi1.game_board[3][4]='O';
    reversi1.game_board[4][3]='O';
    reversi1.game_board[5][4]='O';
    reversi1.print_game_board();

    int x=0,y=0;
    char peca= ' ';

    while(x!=-1&&y!=-1){
        cin>>x>>y>>peca;
        reversi1.process_move({x,y},peca);
    }
    
}