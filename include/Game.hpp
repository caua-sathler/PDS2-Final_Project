#ifndef GAME_H
#define GAME_H
#include "Board.hpp"
#include <array>

/**
 * @file Game.hpp
 * @brief Classe base abstrata para jogos genéricos com tabuleiro.
 * 
 * Define a estrutura e os métodos principais para jogos que utilizam um tabuleiro.
 */

/**
 * @class Game
 * @brief Classe base para jogos com tabuleiro.
 * 
 * Serve como base para implementar diferentes tipos de jogos, fornecendo
 * métodos abstratos para validação de jogadas, execução de jogadas e verificação de vitória.
 */
class Game {
    protected:
        Board game_board; /**< Representa o tabuleiro utilizado no jogo. */

    public:
        /**
         * @brief Constrói um jogo com um tabuleiro de tamanho especificado.
         * @param num_rows_received Número de linhas do tabuleiro.
         * @param num_columns_received Número de colunas do tabuleiro.
         */
        Game(int num_rows_received, int num_columns_received);


        /**
         * @brief Verifica se uma jogada é válida.
         * 
         * Método abstrato que deve ser implementado pelas classes derivadas.
         * @return `true` se a jogada for válida, `false` caso contrário.
         */
        virtual bool is_valid_move() const = 0;


        /**
         * @brief Realiza uma jogada.
         * 
         * Método abstrato que deve ser implementado pelas classes derivadas.
         */
        virtual void make_move() = 0;


        /**
         * @brief Verifica se há um vencedor no jogo.
         * 
         * Método abstrato que deve ser implementado pelas classes derivadas.
         * @return `true` se houver um vencedor, `false` caso contrário.
         */
        virtual bool check_win() = 0;


        /**
         * @brief Alterna entre os jogadores.
         * @param current_player Jogador atual ('X' ou 'O').
         * @return O caractere do próximo jogador.
         */
        char switch_players(char current_player);


        /**
         * @brief Destrutor da classe base Game.
         * 
         * Não realiza nenhuma operação específica.
         */
        ~Game() {}
};

#endif
