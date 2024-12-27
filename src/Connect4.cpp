#include "Connect4.hpp"
#include <iostream>

Connect4::Connect4() : Game(6, 7){
    creater_game_board();
    current_player = "X"; //jogador X = jogador 1
}

bool Connect4::make_move(int column) {
    
    if(!verify_valid_move(column)) {
        std::cout << "jogada invalida" << std::endl;
        return false;
    }

    for(int i = 5; i>= 0; i--) {
        if(game_board[i][column] == ' ') {
            game_board[i][column] = current_player;
            return true;
        }
    }
    return false;
}

bool Connect4::verify_valid_move(int column){
    if( 1 <= column <= 7 || (game_board[0][column--] == 'X' || game_board[0][column--] == 'O')){
        return false;
    }
    return true;
}

void Connect4::check_win() {

}