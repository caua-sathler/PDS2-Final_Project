#include "Connect4.hpp"
#include <iostream>

/**
 * @class Connect4
 * @brief Classe que implementa o jogo Connect4.
 */

/**
 * @brief Construtor da classe Connect4.
 * 
 * Inicializa o tabuleiro com 6 linhas e 7 colunas, e define o jogador atual como 'X'.
 */
Connect4::Connect4() : Game(6, 7), current_player('X'){
}

/**
 * @brief Placeholder para verificar se um movimento é válido.
 * 
 * @return Sempre retorna true (deve ser implementado corretamente).
 */
bool Connect4::is_valid_move() const {
    return true;
}

/**
 * @brief Placeholder para realizar um movimento.
 * 
 * Esta função deve ser implementada corretamente.
 */
void Connect4::make_move(){
}

/**
 * @brief Verifica se a coluna escolhida é válida para um movimento.
 * 
 * @param column Coluna escolhida pelo jogador (1-7).
 * @return True se a coluna for válida, false caso contrário.
 */
bool Connect4::is_valid_move(int column) {
    column--; // Ajusta o índice para base 0
    int rows = 6;
    // Verifica se a coluna está cheia ou se a jogada é dentro do tabuleiro
    if (game_board.get_space(0, column) != ' ' || game_board.is_move_inside_board(rows, column)) {
        return false;
    }
    return true;
}

/**
 * @brief Realiza o movimento colocando a peça na posição mais baixa da coluna.
 * 
 * @param column Coluna escolhida pelo jogador (1-7).
 */
void Connect4::make_move(int column) 
{
    column--; // Ajusta o índice para base 0
    for(int i = 5; i >= 0; i--) 
    {
        if(game_board.get_space(i, column) == ' ') 
        {
            game_board.set_space(i, column, current_player);
            return;
        }
    }
}

/**
 * @brief Verifica se o jogador atual venceu o jogo.
 * 
 * @return True se o jogador atual venceu, false caso contrário.
 */
bool Connect4::check_win(){
    // Verificação horizontal
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row, col + 1) == current_player &&
                game_board.get_space(row, col + 2) == current_player && 
                game_board.get_space(row, col + 3) == current_player) {
                    return true;
            }
        }
    }

    // Verificação vertical
    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row + 1, col) == current_player &&
                game_board.get_space(row + 2, col) == current_player && 
                game_board.get_space(row + 3, col) == current_player) {
                    return true;
            }
        }
    }

    // Verificação diagonal direita
    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 3; ++col) {
            if (game_board.get_space(row, col) == current_player && 
                game_board.get_space(row + 1, col + 1) == current_player &&
                game_board.get_space(row + 2, col + 2) == current_player && 
                game_board.get_space(row + 3, col + 3) == current_player) {
                    return true;
            }
        }
    }

    // Verificação diagonal esquerda
    for (int row = 3; row < 6; ++row) {
        for (int col = 0; col <= 3; ++col) {
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

/**
 * @brief Retorna o jogador atual.
 * 
 * @return O caractere representando o jogador atual ('X' ou 'O').
 */
char Connect4::get_current_player()
{
    return current_player;
}

/**
 * @brief Verifica se o tabuleiro está completamente cheio.
 * 
 * @return True se o tabuleiro estiver cheio, false caso contrário.
 */
bool Connect4::is_board_full() const 
{
    for(int col = 0; col < 7; ++col) 
    {
        if(game_board.get_space(0, col) == ' ') {
            return false;
        }
    }
    return true;
}

/**
 * @brief Imprime o estado atual do tabuleiro no console.
 */
void Connect4::print_game_board() const
{
    game_board.print_game_board();
}

/**
 * @brief Define o jogador atual.
 * 
 * @param player O caractere representando o jogador ('X' ou 'O').
 */
void Connect4::set_current_player(char player) 
{
    current_player = player;
}

/**
 * @brief Destrutor da classe Connect4.
 */
Connect4::~Connect4() {
}
