#ifndef BOARD_H
#define BOARD_H
#include <memory>

/**
 * @file Board.hpp
 * @brief Representa o tabuleiro de um jogo genérico.
 * 
 * Define o tabuleiro com funcionalidades para manipular posições
 * e verificar condições dentro do jogo.
 */

/**
 * @class Board
 * @brief Gerencia o tabuleiro do jogo.
 * 
 * Oferece métodos para configurar e acessar espaços no tabuleiro,
 * além de verificar a validade de movimentos.
 */
class Board {
    private:
        int num_rows; /**< Número de linhas do tabuleiro. */
        int num_columns; /**< Número de colunas do tabuleiro. */
        std::unique_ptr<std::unique_ptr<char[]>[]> game_board = nullptr; /**< Estrutura que armazena o estado do tabuleiro. */

    public:
        /**
         * @brief Constrói o tabuleiro com o número de linhas e colunas especificado.
         * @param num_rows_received Número de linhas.
         * @param num_columns_received Número de colunas.
         */
        Board(int num_rows_received, int num_columns_received);


        /**
         * @brief Define um valor em uma posição específica do tabuleiro.
         * @param row Linha do tabuleiro.
         * @param column Coluna do tabuleiro.
         * @param value Valor a ser colocado na posição.
         */
        void set_space(int row, int column, char value); 


        /**
         * @brief Retorna o valor de uma posição específica do tabuleiro.
         * @param row Linha do tabuleiro.
         * @param column Coluna do tabuleiro.
         * @return O valor presente na posição.
         */
        char get_space(int row, int column) const;


        /**
         * @brief Imprime o estado atual do tabuleiro.
         */
        void print_game_board() const;


        /**
         * @brief Verifica se uma posição está dentro dos limites do tabuleiro.
         * @param x Coordenada da linha.
         * @param y Coordenada da coluna.
         * @return `true` se a posição está dentro dos limites, `false` caso contrário.
         */
        bool is_move_inside_board(int x, int y) const;


        /**
         * @brief Verifica se uma posição no tabuleiro está vazia.
         * @param x Coordenada da linha.
         * @param y Coordenada da coluna.
         * @return `true` se a posição está vazia, `false` caso contrário.
         */
        bool is_space_free(int x, int y) const;
};

#endif
