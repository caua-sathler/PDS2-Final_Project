#include "Tic_tac_toe.hpp"
#include "Player.hpp"
#include <iostream>

/**
 * @class Tic_tac_toe
 * @brief Implementa o jogo da velha (Tic Tac Toe).
 */

const int num_rows_received = 3; ///< Dimensões do tabuleiro (linhas)
const int num_columns_received = 3; ///< Dimensões do tabuleiro (colunas)

/**
 * @brief Construtor: inicializa o tabuleiro e define o jogador atual e o vencedor.
 */
Tic_tac_toe::Tic_tac_toe() : Game(num_rows_received, num_columns_received), current_player('X'), winner('F') {}

/**
 * @brief Verifica se uma jogada é válida.
 * 
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @return True se a jogada é válida, false caso contrário.
 */
bool Tic_tac_toe::is_valid_move(int& x, int& y) const 
{
    // Verifica se o movimento está dentro do tabuleiro e se o espaço está livre
    if (game_board.is_move_inside_board(x, y) && game_board.is_space_free(x, y)) 
    {
        return true; // Movimento válido
    }
    return false; // Movimento inválido
}

/**
 * @brief Imprime o tabuleiro de Tic Tac Toe.
 */
void Tic_tac_toe::print_tic_tac_toe_board() const 
{
    game_board.print_game_board();
}

/**
 * @brief Realiza uma jogada no tabuleiro.
 * 
 * @param x Coordenada da linha (1-3).
 * @param y Coordenada da coluna (1-3).
 */
void Tic_tac_toe::make_move(int x, int y) 
{
    x -= 1; // Ajusta o índice para o formato baseado em zero
    y -= 1;

    try 
    {
        if (is_valid_move(x, y)) 
        {
            game_board.set_space(x, y, current_player); // Define o espaço no tabuleiro com o símbolo do jogador atual

            if (check_tic_tac_toe_win() != 'F') // Verifica se há um vencedor
                winner = current_player;
            else 
                current_player = switch_players(current_player); // Alterna para o próximo jogador
        }
    }   
    catch (const std::out_of_range& e) // Captura erros de índice fora do limite
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(const std::runtime_error& e) // Captura outros erros de execução
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

/**
 * @brief Verifica se o jogador atual venceu o jogo.
 * 
 * @return O jogador vencedor ('X' ou 'O'), ou 'F' se não houver vencedor.
 */
char Tic_tac_toe::check_tic_tac_toe_win() const 
{
    // Verifica linhas
    for (int i = 0; i < 3; ++i) {
        if (game_board.get_space(i, 0) == current_player && 
            game_board.get_space(i, 1) == current_player && 
            game_board.get_space(i, 2) == current_player) 
            return current_player;

        // Verifica colunas
        if (game_board.get_space(0, i) == current_player && 
            game_board.get_space(1, i) == current_player && 
            game_board.get_space(2, i) == current_player) 
            return current_player;
    }

    // Verifica a diagonal principal
    if (game_board.get_space(0, 0) == current_player && 
        game_board.get_space(1, 1) == current_player && 
        game_board.get_space(2, 2) == current_player) 
        return current_player; 

    // Verifica a diagonal secundária
    if (game_board.get_space(0, 2) == current_player && 
        game_board.get_space(1, 1) == current_player && 
        game_board.get_space(2, 0) == current_player) 
        return current_player; 

    return 'F'; // Retorna 'F' se não houver vencedor
}

/**
 * @brief Verifica se o jogo terminou em empate.
 * 
 * @return True se o jogo terminou em empate, false caso contrário.
 */
bool Tic_tac_toe::check_tie() const 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (game_board.get_space(i, j) == ' ') // Verifica se há espaços vazios
                return false;
        }
    }
    return true; // Retorna true se todos os espaços estiverem preenchidos
}

/**
 * @brief Retorna o jogador atual.
 * 
 * @return O caractere representando o jogador atual ('X' ou 'O').
 */
char Tic_tac_toe::get_current_player() const {
    return current_player;
}

/**
 * @brief Placeholder para verificação de movimento válido.
 * 
 * @return Sempre retorna true (deve ser implementado corretamente).
 */
bool Tic_tac_toe::is_valid_move() const {
    return true;
}

/**
 * @brief Placeholder para realizar uma jogada.
 */
void Tic_tac_toe::make_move() {}

/**
 * @brief Placeholder para verificar condição de vitória.
 * 
 * @return Sempre retorna false (deve ser implementado corretamente).
 */
bool Tic_tac_toe::check_win() {
    return false;
}

/**
 * @brief Destrutor da classe Tic Tac Toe.
 */
Tic_tac_toe::~Tic_tac_toe() {}
