#include "Tic_tac_toe.hpp"
#include "Player.hpp"
#include <iostream>

const int num_rows_received = 3;
const int num_columns_received = 3;

Tic_tac_toe::Tic_tac_toe() : Game(num_rows_received, num_columns_received), current_player('X'), winner('F') {}


bool Tic_tac_toe::is_valid_move(int& x, int& y) const 
{
    int board_x = x - 1;
    int board_y = y - 1;

    if (!game_board.is_move_inside_board(board_x, board_y) || 
        !game_board.is_space_free(board_x, board_y)) 
    {
        throw std::runtime_error("Coordenada invalida, vez passada para o oponente");
    }
    return true; 
}

 
void Tic_tac_toe::print_tic_tac_toe_board() const 
{
    game_board.print_game_board();
}


void Tic_tac_toe::make_move(int x, int y) 
{
    try 
    {   if (is_valid_move(x, y)) 
        {
            game_board.set_space(x - 1, y - 1, current_player);
    
            if (check_tic_tac_toe_win() != 'F') 
                winner = current_player;

            else 
                current_player = switch_players(current_player);
        }
    }

    catch (const std::runtime_error& e) 
    {
        std::cout << "Erro: " << e.what() << std::endl;
        current_player = switch_players(current_player);
    }

}

char Tic_tac_toe::check_tic_tac_toe_win() const 
{
    for (int i = 0; i < 3; ++i) 
    {
        // Verifica linhas e colunas para ambos os jogadores
        if ((game_board.get_space(i, 0) == 'X' && game_board.get_space(i, 1) == 'X' && game_board.get_space(i, 2) == 'X') ||
            (game_board.get_space(0, i) == 'X' && game_board.get_space(1, i) == 'X' && game_board.get_space(2, i) == 'X')) 
            return 'X';

        if ((game_board.get_space(i, 0) == 'O' && game_board.get_space(i, 1) == 'O' && game_board.get_space(i, 2) == 'O') ||
            (game_board.get_space(0, i) == 'O' && game_board.get_space(1, i) == 'O' && game_board.get_space(2, i) == 'O')) 
            return 'O';
    }

    // Verifica diagonais
    if ((game_board.get_space(0, 0) == 'X' && game_board.get_space(1, 1) == 'X' && game_board.get_space(2, 2) == 'X') ||
        (game_board.get_space(0, 2) == 'X' && game_board.get_space(1, 1) == 'X' && game_board.get_space(2, 0) == 'X')) 
        return 'X';

    if ((game_board.get_space(0, 0) == 'O' && game_board.get_space(1, 1) == 'O' && game_board.get_space(2, 2) == 'O') ||
        (game_board.get_space(0, 2) == 'O' && game_board.get_space(1, 1) == 'O' && game_board.get_space(2, 0) == 'O')) 
        return 'O';

    return 'F'; 
}


bool Tic_tac_toe::check_tie() const 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (game_board.get_space(i, j) == ' ') 
                return false;
        }
    }

return true;
}


char Tic_tac_toe::get_current_player() const 
{
    return current_player;
}

Board& Tic_tac_toe::get_game_board(){
    return this->game_board;
}

Tic_tac_toe::~Tic_tac_toe() {}


// Funções declaradas somente para fins de sobregarga.
bool Tic_tac_toe::is_valid_move() const { return true; }

void Tic_tac_toe::make_move() {}

bool Tic_tac_toe::check_win() { return false; }

