#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tic_tac_toe.hpp"

void create_tic_tac_toe_board(tic_tac_toe &game, const std::vector<std::vector<char>> &board_setup) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            game.game_board.set_space(i, j, board_setup[i][j]);
        }
    }
}

TEST_CASE("Testes da classe Tic_tac_toe") 
{
    tic_tac_toe jogo;

    SUBCASE("Verificar jogador atual ao iniciar o jogo") 
        CHECK(jogo.get_current_player() == 'X');
    

    SUBCASE("Verificar se uma jogada é válida") 
    {
        int x = 1, y = 1; 
        CHECK(jogo.is_valid_move(x, y) == true);

        x = 4, y = 4; 
        CHECK(jogo.is_valid_move(x, y) == false);

        x = 1, y = 1;
        jogo.make_move(x, y); 
        CHECK(jogo.is_valid_move(x, y) == false);
    }

    SUBCASE("Realizar uma jogada válida") 
    {
        int x = 2, y = 2;
        jogo.make_move(x, y);
        CHECK(jogo.get_current_player() == 'O'); 
    }

    SUBCASE("Detectar vitória horizontal") 
    {
        std::vector<std::vector<char>> setup = 
        {
            {'X', 'X', 'X'},
            {' ', 'O', 'O'},
            {' ', ' ', ' '}
        };
        create_tic_tac_toe_board(jogo, setup);
        CHECK(jogo.check_tic_tac_toe_win() == 'X');
    }

    SUBCASE("Detectar vitória vertical") 
    {
        std::vector<std::vector<char>> setup = 
        {
            {'X', 'O', ' '},
            {'X', 'O', ' '},
            {'X', ' ', ' '}
        };
        create_tic_tac_toe_board(jogo, setup);
        CHECK(jogo.check_tic_tac_toe_win() == 'X');
    }

    SUBCASE("Detectar vitória diagonal") 
    {
        std::vector<std::vector<char>> setup = 
        {
            {'X', 'O', ' '},
            {'O', 'X', ' '},
            {' ', ' ', 'X'}
        };
        create_tic_tac_toe_board(jogo, setup);
        CHECK(jogo.check_tic_tac_toe_win() == 'X');
    }

    SUBCASE("Detectar empate") 
    {
        std::vector<std::vector<char>> setup = 
        {
            {'X', 'O', 'X'},
            {'O', 'X', 'O'},
            {'O', 'X', 'O'}
        };
        create_tic_tac_toe_board(jogo, setup);
        CHECK(jogo.check_tie() == true);
    }

    SUBCASE("Verificar alternância entre jogadores") 
    {
        jogo.make_move(1, 1); 
        CHECK(jogo.get_current_player() == 'O'); 
        jogo.make_move(1, 2); 
        CHECK(jogo.get_current_player() == 'X');

    } 

    SUBCASE("Detectar tabuleiro vazio ao iniciar") 
    {
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                CHECK(jogo.game_board.get_space(i, j) == ' ');
            }
        }   
    }   
}
