#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "Game.hpp"

/**
 * @file Tic_tac_toe.hpp
 * @brief Implementa o Jogo da Velha (Tic Tac Toe), baseado na classe genérica Game.
 * 
 * Contém as regras e ações específicas do Jogo da Velha.
 */

/**
 * @class Tic_tac_toe
 * @brief Gerencia as regras e funcionalidades do Jogo da Velha.
 * 
 * Herda de Game e adiciona métodos específicos para o funcionamento
 * do Jogo da Velha, como validação de jogadas, verificação de vitória e empate.
 */
class Tic_tac_toe : public Game {
    private:
        char current_player; /**< Jogador atual ('X' ou 'O'). */
        char winner; /**< Armazena o vencedor do jogo, se houver. */

    public:
        /**
         * @brief Construtor padrão do jogo da velha.
         * Inicializa o tabuleiro como 3x3, define o jogador atual como 'X' e o vencedor como 'F' (nenhum).
         */
        Tic_tac_toe();


        /**
         * @brief Função declarada somente para fins de sobregarga.
         */
        void make_move() override;


        /**
         * @brief Realiza uma jogada em uma posição específica.
         * 
         * Verifica se a jogada é válida, atualiza o tabuleiro e alterna o jogador através 
         * de funções da classe Tic_tac_toe e da classe Board.
         * @param x Coordenada da linha.
         * @param y Coordenada da coluna.
         */
        void make_move(int x, int y);


        /**
         * @brief Função declarada somente para fins de sobregarga.
         */
        bool is_valid_move() const override;


        /**
         * @brief Verifica se uma jogada específica é válida.
         * 
         * Valida se as coordenadas fornecidas estão dentro do tabuleiro e a posição está livre
         * através das funções da classe Board.
         * @param x Coordenada da linha da jogada.
         * @param y Coordenada da coluna da jogada.
         * @return `true` se a jogada for válida, `false` caso contrário.
         */
        bool is_valid_move(int& x, int& y) const;


        /**
         * @brief Função declarada somente para fins de sobregarga.
         */
        bool check_win() override;


        /**
         * @brief Verifica se há um vencedor no jogo.
         * 
         * Confere todas as linhas, colunas e diagonais para ver se há três peças consecutivas do mesmo jogador.
         * @return Caractere do jogador vencedor ('X' ou 'O') ou 'F' se não houver vencedor.
         */
        char check_tic_tac_toe_win() const;


        /**
         * @brief Retorna o jogador atual.
         * @return Caractere representando o jogador atual ('X' ou 'O').
         */
        char get_current_player() const;


        /**
         * @brief Verifica se o jogo terminou em empate.
         * 
         * Confere se todas as posições do tabuleiro estão ocupadas sem haver vitória.
         * @return `true` se houver empate, `false` caso contrário.
         */
        bool check_tie() const;


        /**
         * @brief Imprime o estado atual do tabuleiro.
         */
        void print_tic_tac_toe_board() const;


        /**
         * @brief Destrutor do Jogo da Velha.
         */
        ~Tic_tac_toe();
};

#endif
