#include "Game.hpp"
#include <iostream>

void Game::create_game_board() {
    this->game_board = new int*[num_rows];
    for(int i = 0; i < num_rows; i++){
        this->game_board[i] = new int[num_columns];
    }
}

Game::Game(int num_rows_received, int num_columns_received) : 
num_columns(num_columns_received), num_rows(num_rows_received) {
    create_game_board();
}

Game::~Game() {
    for(int i = 0; i < num_rows; i++) {
        delete[] game_board[i];
    }
    delete[] game_board;
}

void Game::print_game_board() {
    for(int i = 0; i < num_rows; i++) {
     std::cout << "|" << std::ends;   
        for(int j = 0; j < num_columns; j++) {
            std::cout << this->game_board[i][j] << "|" << std::ends;
        }
        std::cout << std::endl;
    }
}