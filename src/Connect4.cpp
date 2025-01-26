#include "Connect4.hpp"
#include <iostream>


Connect4::Connect4() : Game(6, 7), current_player('X') {}

// Funções declaradas somente para fins de sobrecarga
bool Connect4::is_valid_move() const { return true; }

void Connect4::make_move() {}
//

bool Connect4::is_valid_move(int column) 
{
    column--; 
    if (game_board.get_space(0, column) != ' ') return false;
    if (column < 0 || column >= 7) return false;
    return true;
}

void Connect4::make_move(int column) 
{
    column--;
    // Encontra a linha mais baixa disponível na coluna e coloca a peça do jogador atual
    for(int i = 5; i >= 0; i--) 
    {
        if(game_board.get_space(i, column) == ' ') 
        {
            game_board.set_space(i, column, current_player);
            return;
        }
    }
}


bool Connect4::check_win() 
{
    // Verificação de vitória horizontal
    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col <= 3; ++col) 
        {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row, col + 1) == current_player &&
                game_board.get_space(row, col + 2) == current_player && 
                game_board.get_space(row, col + 3) == current_player) {
                    return true;
            }
        }
    }

    // Verificação de vitória vertical
    for (int row = 0; row <= 2; ++row) 
    {
        for (int col = 0; col < 7; ++col) 
        {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row + 1, col) == current_player &&
                game_board.get_space(row + 2, col) == current_player && 
                game_board.get_space(row + 3, col) == current_player) {
                    return true;
            }
        }
    }

    // Verificação de vitória diagonal para a direita
    for (int row = 0; row <= 2; ++row) 
    {
        for (int col = 0; col <= 3; ++col) 
        {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row + 1, col + 1) == current_player &&
                game_board.get_space(row + 2, col + 2) == current_player && 
                game_board.get_space(row + 3, col + 3) == current_player) {
                    return true;
            }
        }
    }

    // Verificação de vitória diagonal para a esquerda
    for (int row = 3; row < 6; ++row) 
    {
        for (int col = 0; col <= 3; ++col) 
        {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row - 1, col + 1) == current_player &&
                game_board.get_space(row - 2, col + 2) == current_player && 
                game_board.get_space(row - 3, col + 3) == current_player) {
                    return true;
            }
        }
    }
    return false;
}

char Connect4::get_current_player()
{
    return current_player;
}

bool Connect4::is_board_full() const 
{
    for(int col = 0; col < 7; ++col) 
    {
        if(game_board.get_space(0, col) == ' ') 
        {
            return false;
        }
    }
    return true;
}

void Connect4::print_game_board() const
{
    game_board.print_game_board();
}

void Connect4::set_current_player(char player) 
{
    current_player = player;
}

Connect4::~Connect4() {}