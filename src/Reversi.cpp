#include "Reversi.hpp"
#include <iostream>
#include "list"
#include "array"
#include "Player.hpp"

/**
 * @class Reversi
 * @brief Implementação do jogo Reversi.
 */

const int num_columns_and_rows_reversi = 8; ///< Tamanho fixo do tabuleiro de Reversi.

/**
 * @brief Inicializa o tabuleiro com as peças iniciais de Reversi.
 */
void Reversi::start_reversi_board()
{
    this->game_board.set_space(3, 3, 'X');
    this->game_board.set_space(4, 4, 'X');
    this->game_board.set_space(3, 4, 'O');
    this->game_board.set_space(4, 3, 'O');
}

/**
 * @brief Retorna o número de peças do jogador X.
 * 
 * @return Número de peças do jogador X.
 */
int Reversi::get_num_pieces_player_X()
{
    return this->num_pieces_player_X;
}

/**
 * @brief Retorna o número de peças do jogador O.
 * 
 * @return Número de peças do jogador O.
 */
int Reversi::get_num_pieces_player_O()
{
    return this->num_pieces_player_O;
}

/**
 * @brief Imprime o tabuleiro de Reversi.
 */
void Reversi::print_reversi_board() const 
{
    game_board.print_game_board();
}

/**
 * @brief Construtor: inicializa o tabuleiro e configura o número inicial de peças.
 */
Reversi::Reversi() : Game(num_columns_and_rows_reversi, num_columns_and_rows_reversi)
{
    this->start_reversi_board();
    this->num_pieces_player_X = 2;
    this->num_pieces_player_O = 2;
};

/**
 * @brief Verifica se uma posição está livre no tabuleiro.
 * 
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @return True se a posição está livre, false caso contrário.
 */
bool Reversi::is_space_free_reversi(int x, int y) const
{
    if (this->game_board.get_space(x, y) == '*' || this->game_board.is_space_free(x, y))
        return true;
    return false;
}

/**
 * @brief Verifica se há uma peça do jogador na direção especificada.
 * 
 * @param player_piece Peça do jogador ('X' ou 'O').
 * @param direction Direção para verificar.
 * @param adjacent_square Posição adjacente à verificação.
 * @return True se houver uma peça do jogador na direção, false caso contrário.
 */
bool Reversi::is_there_player_piece_at_the_direction(const char player_piece,
    const std::array<int, 2>& direction, std::array<int, 2> adjacent_square) const
{
    std::array<int, 2> current_square = { adjacent_square[0] + direction[0],
    adjacent_square[1] + direction[1] };

    while (game_board.is_move_inside_board(current_square[0], current_square[1]))
    {
        if (this->game_board.get_space(current_square[0], current_square[1]) == player_piece)
            return true;
        else if (this->game_board.get_space(current_square[0], current_square[1]) == ' ' 
        || this->game_board.get_space(current_square[0], current_square[1]) == '*')
            return false;

        current_square[0] += direction[0];
        current_square[1] += direction[1];
    }
    return false;
}

/**
 * @brief Verifica se um movimento captura peças do oponente em alguma direção.
 * 
 * @param move_coordinates Coordenadas do movimento.
 * @param player_piece_type Peça do jogador que está jogando.
 * @return True se captura peças, false caso contrário.
 */
bool Reversi::is_there_direction_that_captures_opponent(const std::array<int, 2>
    & move_coordinates, char player_piece_type)
{
    char opponent_player = switch_players(player_piece_type);
    std::array<int, 2> adjacent_square = { 0, 0 };

    for (int i = 1; i > -2; i--)
    {
        for (int j = 1; j > -2; j--) 
        {
            if (j != 0 || i != 0) 
            {
                adjacent_square[0] = move_coordinates[0] + i;
                adjacent_square[1] = move_coordinates[1] + j;

                if (this->game_board.is_move_inside_board(adjacent_square[0], adjacent_square[1]) &&
                    this->game_board.get_space(adjacent_square[0], adjacent_square[1]) == opponent_player) 
                    {
                    std::array<int, 2> direction = { i , j };

                    if (is_there_player_piece_at_the_direction(player_piece_type, direction, adjacent_square)) 
                        return true;
                    }
            }
        }
    }
    return false;
}

/**
 * @brief Verifica se um movimento é válido.
 * 
 * @param move_coordinates Coordenadas do movimento.
 * @param player_piece_type Peça do jogador.
 * @return True se o movimento é válido, false caso contrário.
 */
bool Reversi::is_valid_move(std::array<int, 2>& move_coordinates, char player_piece_type)
{
    if (!this->game_board.is_move_inside_board(move_coordinates[0], move_coordinates[1]))
        return false;

    if (!this->is_space_free_reversi(move_coordinates[0], move_coordinates[1]))
        return false;

    if (!this->is_there_direction_that_captures_opponent(move_coordinates, player_piece_type)) 
        return false;

    return true;
}

/**
 * @brief Encontra todas as direções para capturar peças do oponente.
 * 
 * @param move_coordinates Coordenadas do movimento.
 * @param player_piece Peça do jogador.
 * @param directions_to_capture_opponents Lista com as direções para capturar peças.
 */
void Reversi::find_all_directions_to_make_move(std::array<int, 2>& move_coordinates,
    char player_piece, std::list<std::array<int, 2>>& directions_to_capture_opponents)
{
    char opponent_player_piece = switch_players(player_piece);
    std::array<int, 2> adjacent_square = { 0, 0 };

    for (int i = 1; i > -2; i--) 
    {
        for (int j = 1; j > -2; j--) 
        {
            if (j != 0 || i != 0) 
            {
                adjacent_square[0] = move_coordinates[0] + i;
                adjacent_square[1] = move_coordinates[1] + j;

                if (this->game_board.is_move_inside_board(adjacent_square[0], adjacent_square[1]) &&
                    this->game_board.get_space(adjacent_square[0], adjacent_square[1]) == opponent_player_piece) 
                {
                    std::array<int, 2> direction = { i , j };

                    if (is_there_player_piece_at_the_direction(player_piece, direction, adjacent_square)) 
                        directions_to_capture_opponents.push_back(direction);
                }
            }
        }
    }
}

/**
 * @brief Vira peças do oponente nas direções capturadas.
 * 
 * @param directions Direção para virar as peças.
 * @param move_coordinates Coordenadas do movimento.
 * @param player_piece Peça do jogador.
 */
void Reversi::flip_pieces(std::array<int, 2> directions, std::array<int, 2> move_coordinates, char player_piece)
{
    char opponent_piece = switch_players(player_piece);
    int num_pieces_flipped = 0;

    std::array<int, 2> current_square = { directions[0] + move_coordinates[0],
    directions[1] + move_coordinates[1] };

    while (this->game_board.get_space(current_square[0], current_square[1]) == opponent_piece) 
    {
        this->game_board.set_space(current_square[0], current_square[1], player_piece);
        current_square[0] += directions[0];
        current_square[1] += directions[1];
        num_pieces_flipped++;
    }
    this->control_num_pieces_players(num_pieces_flipped, player_piece);
}

/**
 * @brief Atualiza o número de peças dos jogadores.
 * 
 * @param num_pieces_flipped Número de peças viradas.
 * @param player_piece Peça do jogador.
 */
void Reversi::control_num_pieces_players(int num_pieces_flipped, char player_piece)
{
    if (player_piece == 'X') 
    {
        this->num_pieces_player_X += num_pieces_flipped;
        this->num_pieces_player_O -= num_pieces_flipped;
    }
    else 
    {
        this->num_pieces_player_X -= num_pieces_flipped;
        this->num_pieces_player_O += num_pieces_flipped;
    }
}

/**
 * @brief Processa um movimento do jogador.
 * 
 * @param move_coordinates Coordenadas do movimento.
 * @param player_piece Peça do jogador.
 * @return True se o movimento foi bem-sucedido, false caso contrário.
 */
bool Reversi::process_move(std::array<int, 2> move_coordinates, char player_piece)
{
    move_coordinates[0] = move_coordinates[0] - 1;
    move_coordinates[1] = move_coordinates[1] - 1;
    std::list<std::array<int, 2>> directions_to_capture_opponents;

    if (this->is_valid_move(move_coordinates, player_piece)) 
    {
        find_all_directions_to_make_move(move_coordinates, player_piece, directions_to_capture_opponents);
        this->make_move(move_coordinates, player_piece, directions_to_capture_opponents);
        return true;
    }
    return false;
}

/**
 * @brief Verifica se há movimentos válidos para um jogador.
 * 
 * @param player_piece Peça do jogador.
 * @return True se houver movimentos válidos, false caso contrário.
 */
bool Reversi::is_there_valid_move_for_player(char player_piece)
{
    bool found_valid_move = false;
    for (int i = 0; i < num_columns_and_rows_reversi; i++) 
    {
        for (int j = 0; j < num_columns_and_rows_reversi; j++) 
        {
            if (this->game_board.get_space(i, j) == ' ' || this->game_board.get_space(i, j) == '*') 
            {
                std::array<int, 2> coordinates = { i, j };
                if (this->is_valid_move(coordinates, player_piece)) 
                {
                    this->game_board.set_space(i, j,'*');
                    found_valid_move = true;
                }
                else 
                {
                    if (this->game_board.get_space(i, j) == '*') 
                        this->game_board.set_space(i, j, ' ');
                }

            }
        }
    }
    return found_valid_move;
}

/**
 * @brief Registra o resultado do jogo para os jogadores.
 * 
 * @param player1 Jogador 1.
 * @param player2 Jogador 2.
 */
void Reversi::register_win_and_loss(Player *player1, Player *player2) 
{
    if(this->num_pieces_player_X > this->num_pieces_player_O)
    {
        player1->add_win("Reversi");
        player2->add_loss("Reversi");
    } 
    else if(this->num_pieces_player_X < this->num_pieces_player_O)
    {
        player2->add_win("Reversi");
        player1->add_loss("Reversi");
    }
}

/**
 * @brief Destrutor da classe Reversi.
 */
Reversi::~Reversi() {};
