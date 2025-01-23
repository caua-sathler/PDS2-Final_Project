#include "Board.hpp"
#include <iostream>

/**
 * @class Board
 * @brief Classe que representa um tabuleiro genérico para jogos.
 */

/**
 * @brief Define o valor de uma posição no tabuleiro.
 * 
 * @param row Linha da posição.
 * @param column Coluna da posição.
 * @param value Valor a ser definido na posição.
 */
void Board::set_space(int row, int column, char value) 
{
    this->game_board[row][column] = value;
}

/**
 * @brief Retorna o valor de uma posição no tabuleiro.
 * 
 * @param row Linha da posição.
 * @param column Coluna da posição.
 * @return Valor contido na posição especificada.
 */
char Board::get_space(int row, int column) const 
{
    return this->game_board[row][column];
}

/**
 * @brief Construtor da classe Board.
 * 
 * @param num_rows_received Número de linhas do tabuleiro.
 * @param num_columns_received Número de colunas do tabuleiro.
 */
Board::Board(int num_rows_received, int num_columns_received) : num_rows(num_rows_received), 
num_columns(num_columns_received) 
{   
    // Aloca memória para o tabuleiro como um array de ponteiros inteligentes
    game_board = std::unique_ptr<std::unique_ptr<char[]>[]>(new std::unique_ptr<char[]>[num_rows]);

    // Inicializa cada linha com um array de caracteres e preenche com espaços vazios (' ')
    for (int i = 0; i < num_rows; ++i) {
        game_board[i] = std::unique_ptr<char[]>(new char[num_columns]);
        for (int j = 0; j < num_columns; j++){
            game_board[i][j] = ' ';
        }
    }
}

/**
 * @brief Imprime o tabuleiro no console.
 */
void Board::print_game_board() const 
{
    for(int i = 0; i < num_rows; i++) {
        std::cout << "|" << std::ends;   
        for(int j = 0; j < num_columns; j++) {
            std::cout << this->game_board[i][j] << "|" << std::ends;
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Verifica se as coordenadas estão dentro dos limites do tabuleiro.
 * 
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @return True se as coordenadas estiverem dentro dos limites.
 * @throws std::out_of_range Se as coordenadas estiverem fora dos limites do tabuleiro.
 */
bool Board::is_move_inside_board(int x, int y) const
{
    if ((x < 0 || x > this->num_rows - 1) || (y < 0 || y > this->num_columns - 1)) 
        throw std::out_of_range("Coordinates out of board!");
    
    return true;
}

/**
 * @brief Verifica se uma posição está livre no tabuleiro.
 * 
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @return True se a posição estiver livre.
 * @throws std::runtime_error Se a posição já estiver ocupada.
 */
bool Board::is_space_free(int x, int y) const
{
    if ((this->game_board[x][y] == ' '))
        return true;

    throw std::runtime_error("Position occupied!");
}
