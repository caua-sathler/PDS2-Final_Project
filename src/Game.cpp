#include "Game.hpp"
#include <iostream>

/**
 * @class Game
 * @brief Classe base que representa um jogo genérico com um tabuleiro.
 */

/**
 * @brief Construtor da classe Game.
 * 
 * @param num_rows_received Número de linhas do tabuleiro.
 * @param num_columns_received Número de colunas do tabuleiro.
 */
Game::Game(int num_rows_received, int num_columns_received) : game_board(num_rows_received, num_columns_received) {};

/**
 * @brief Alterna entre os jogadores X e O.
 * 
 * @param current_player O jogador atual ('X' ou 'O').
 * @return O jogador oposto ao atual.
 */
char Game::switch_players(char current_player) {
    char opponent_player = (current_player == 'X') ? 'O' : 'X'; // Se o jogador atual for 'X', retorna 'O'; caso contrário, retorna 'X'
    return opponent_player;
}
