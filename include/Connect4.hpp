#ifndef CONNECT4_H
#define CONNECT4_H

#include "Game.hpp"
#include <iostream>

<<<<<<< HEAD
class Connect4 : public Game 
{
=======
/**
 * @file Connect4.hpp
 * @brief Implementa o jogo Connect4 (Lig4), baseado na classe genérica Game.
 * 
 * Contém as regras e ações específicas do jogo Connect4.
 */

/**
 * @class Connect4
 * @brief Gerencia as regras e funcionalidades do jogo Connect4.
 * 
 * Herda de Game e adiciona métodos específicos para o funcionamento
 * do jogo, como verificar jogadas válidas, realizar jogadas e
 * checar condições de vitória.
 */
class Connect4 : public Game {
>>>>>>> b27d12e511f1165fc823d2028f6edf6a8ddfebe8
    private:
        char current_player; /**< Representa o jogador atual ('X' ou 'O'). */

    public:
        /**
         * @brief Construtor padrão do Connect4, inicializa o jogo com 6 linhas, 7 colunas 
         * e o jogador 'X' como inicial.
         */
        Connect4();


        /**
         * @brief Função declarada somente para fins de sobregarga.
         */
        bool is_valid_move() const override;


        /**
         * @brief Função declarada somente para fins de sobregarga.
         */
        void make_move() override;


        /**
        * @brief Verifica em todas direções válidas se o jogador atual venceu o jogo.
        */
        bool check_win() override;


        /**
         * @brief Verifica se a jogada é válida para uma coluna específica.
         * @param column Coluna onde o jogador deseja jogar.
         * @return `true` se a jogada for válida, `false` caso contrário.
         */
        bool is_valid_move(int column);


        /**
         * @brief Realiza a jogada na coluna especificada.
         * @param column Coluna onde o jogador deseja jogar.
         */
        void make_move(int column);


        /**
         * @brief Retorna o jogador atual.
         * @return Caractere representando o jogador atual ('X' ou 'O').
         */
        char get_current_player();


        /**
         * @brief Verifica se o tabuleiro está completamente cheio.
         * @return `true` se o tabuleiro estiver cheio, `false` caso contrário.
         */
        bool is_board_full() const;


        /**
         * @brief Imprime o estado atual do tabuleiro.
         */
        void print_game_board() const;


        /**
         * @brief Define o jogador atual.
         * @param player Caractere representando o jogador ('X' ou 'O').
         */
        void set_current_player(char player);


        /**
         * @brief Destrutor do jogo Connect4.
         */
        ~Connect4();
};

#endif
