#include "Game.hpp"
#include <iostream>

void Game::create_game_board() {
    this->game_board = new char*[num_rows];
    for(int i = 0; i < num_rows; i++){
        this->game_board[i] = new char[num_columns];
        for(int j = 0; j < num_columns; j++){
            this->game_board[i][j] = ' ';
        }
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