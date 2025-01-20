#include "Tic_tac_toe.hpp"
#include "Player.hpp"
#include <iostream>

const int num_rows_received = 3;
const int num_columns_received = 3;

Tic_tac_toe::Tic_tac_toe() : Game(num_rows_received, num_columns_received), current_player('X'), winner('F') {}

bool Tic_tac_toe::is_valid_move(int& x, int& y) const 
{
    game_board.is_move_inside_board(x, y); 
    game_board.is_space_free(x, y); 
    return true; 
}
 

void Tic_tac_toe::print_tic_tac_toe_board() const 
{
    game_board.print_game_board();
}

void Tic_tac_toe::make_move(int x, int y) 
{

    x -= 1;
    y -= 1;

    try 
    {
        if (is_valid_move(x, y)) 
        {
            game_board.set_space(x, y, current_player);
    
            if (check_tic_tac_toe_win() != 'F') 
                winner = current_player;

            else 
                current_player = switch_players(current_player);
        }
    }   
    
    catch (const std::out_of_range& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    catch(const std::runtime_error& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

char Tic_tac_toe::check_tic_tac_toe_win() const 
{

    for (int i = 0; i < 3; ++i) {
        if (game_board.get_space(i, 0) == current_player && 
            game_board.get_space(i, 1) == current_player && 
            game_board.get_space(i, 2) == current_player) 
            return current_player;


        if (game_board.get_space(0, i) == current_player && 
            game_board.get_space(1, i) == current_player && 
            game_board.get_space(2, i) == current_player) 
            return current_player;
        
    }

    if (game_board.get_space(0, 0) == current_player && 
        game_board.get_space(1, 1) == current_player && 
        game_board.get_space(2, 2) == current_player) 
        return current_player; 
    

    if (game_board.get_space(0, 2) == current_player && 
        game_board.get_space(1, 1) == current_player && 
        game_board.get_space(2, 0) == current_player) 
        return current_player; 
    
    return 'F'; 
}

bool Tic_tac_toe::check_tie() const 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j =0; j < 3; j++) 
        {
            if (game_board.get_space(i, j) == ' ') 
                return false;
        }
    }

return true;
}


char Tic_tac_toe::get_current_player() const {
    return current_player;
}


bool Tic_tac_toe::is_valid_move() const {
    return true;
}


void Tic_tac_toe::make_move() {}


bool Tic_tac_toe::check_win() {
    return false;
}

Tic_tac_toe::~Tic_tac_toe() {}