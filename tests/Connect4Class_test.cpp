#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Connect4.hpp"
#include <iostream>

TEST_CASE("Connect4 Class Tests") 
{
    Connect4 game;

    SUBCASE("Initialization Test") 
    {
        CHECK(game.get_current_player() == 'X'); // Jogador inicial deve ser 'X', que é referente ao player 1
        CHECK(game.is_board_full() == false);    // Tabuleiro não deve estar cheio no início
    }

    SUBCASE("Is valid Move Test") 
    {
        // Verifica movimentos válidos e inválidos
        CHECK(game.is_valid_move(1) == true);
        CHECK(game.is_valid_move(7) == true);
        CHECK(game.is_valid_move(0) == false);
        CHECK(game.is_valid_move(8) == false);
        CHECK(game.is_valid_move(99) == false);
    }

    SUBCASE("Make Move Test") 
    {
        // Verifica o jogadore inicial
        CHECK(game.get_current_player() == 'X');

        game.make_move(1);

        // Verifica se o local foi ocupado da maneira certa
        CHECK(game.get_space(5, 0) == 'X');

        // Jogador deve alternar para 'O'
        game.set_current_player('O'); 

        // Verifica se o jogador atual foi alterado corretamente
        CHECK(game.get_current_player() == 'O');

        // Verifica outras casas do tabuleiro
        CHECK(game.get_space(5, 1) == ' ');
        CHECK(game.get_space(4, 0) == ' ');

        // Verifica após mais uma jogada
        game.make_move(1);
        CHECK(game.get_space(5, 1) == ' ');
        CHECK(game.get_space(4, 0) == 'O');
    }

    SUBCASE("Win Condition Test - Horizontal") {
        // Teste 1: Vitória horizontal
        Connect4 game_horizontal1;
        game_horizontal1.make_move(1); // X
        game_horizontal1.make_move(1); // O
        game_horizontal1.make_move(2); // X
        game_horizontal1.make_move(2); // O
        game_horizontal1.make_move(3); // X
        game_horizontal1.make_move(3); // O
        game_horizontal1.make_move(4); // X
        CHECK(game_horizontal1.check_win() == true); // X deve vencer

        // Teste 2: Vitória horizontal 
        Connect4 game_horizontal2;
        game_horizontal2.make_move(1); // X
        game_horizontal2.make_move(1); // O
        game_horizontal2.make_move(1); // X
        game_horizontal2.make_move(1); // O
        game_horizontal2.make_move(1); // X
        game_horizontal2.make_move(1); // O
        game_horizontal2.make_move(2); // X
        game_horizontal2.make_move(2); // O
        game_horizontal2.make_move(2); // X
        game_horizontal2.make_move(2); // O
        game_horizontal2.make_move(3); // X
        game_horizontal2.make_move(3); // O
        game_horizontal2.make_move(3); // X
        game_horizontal2.make_move(3); // O
        game_horizontal2.make_move(4); // X
        CHECK(game_horizontal2.check_win() == true); // X deve vencer

        // Teste 3: Vitória horizontal na linha 3
        Connect4 game_horizontal3;
        game_horizontal3.make_move(1); // X
        game_horizontal3.make_move(2); // O
        game_horizontal3.make_move(3); // X
        game_horizontal3.make_move(4); // O
        game_horizontal3.make_move(5); // X
        game_horizontal3.make_move(6); // O
        game_horizontal3.make_move(1); // X
        game_horizontal3.make_move(2); // O
        game_horizontal3.make_move(3); // X
        game_horizontal3.make_move(4); // O
        game_horizontal3.make_move(5); // X
        game_horizontal3.make_move(6); // O
        game_horizontal3.make_move(4); // X
        CHECK(game_horizontal3.check_win() == true); // X deve vencer
    }
    
    SUBCASE("Win Condition Test - Vertical") {
        // Teste 1: Vitória vertical na coluna 1
        Connect4 game_vertical1;
        game_vertical1.make_move(1); // X
        game_vertical1.make_move(2); // O
        game_vertical1.make_move(1); // X
        game_vertical1.make_move(2); // O
        game_vertical1.make_move(1); // X
        game_vertical1.make_move(2); // O
        game_vertical1.make_move(1); // X
        CHECK(game_vertical1.check_win() == true); // X deve vencer

        // Teste 2: Vitória vertical na coluna 4
        Connect4 game_vertical2;
        game_vertical2.make_move(4); // X
        game_vertical2.make_move(1); // O
        game_vertical2.make_move(4); // X
        game_vertical2.make_move(1); // O
        game_vertical2.make_move(4); // X
        game_vertical2.make_move(1); // O
        game_vertical2.make_move(4); // X
        CHECK(game_vertical2.check_win() == true); // X deve vencer

        // Teste 3: Vitória vertical na coluna 7
        Connect4 game_vertical3;
        game_vertical3.make_move(7); // X
        game_vertical3.make_move(1); // O
        game_vertical3.make_move(7); // X
        game_vertical3.make_move(1); // O
        game_vertical3.make_move(7); // X
        game_vertical3.make_move(1); // O
        game_vertical3.make_move(7); // X
        CHECK(game_vertical3.check_win() == true); // X deve vencer
    }

    SUBCASE("Win Condition Test - Diagonal Direita") {
        // Teste 1: Vitória diagonal direita
        Connect4 game_diagonal_right1;
        game_diagonal_right1.make_move(1); // X
        game_diagonal_right1.make_move(2); // O
        game_diagonal_right1.make_move(2); // X
        game_diagonal_right1.make_move(3); // O
        game_diagonal_right1.make_move(3); // X
        game_diagonal_right1.make_move(4); // O
        game_diagonal_right1.make_move(3); // X
        game_diagonal_right1.make_move(4); // O
        game_diagonal_right1.make_move(4); // X
        game_diagonal_right1.make_move(5); // O
        game_diagonal_right1.make_move(4); // X
        CHECK(game_diagonal_right1.check_win() == true); // X deve vencer

        // Teste 2: Vitória diagonal direita
        Connect4 game_diagonal_right2;
        game_diagonal_right2.make_move(2); // X
        game_diagonal_right2.make_move(3); // O
        game_diagonal_right2.make_move(3); // X
        game_diagonal_right2.make_move(4); // O
        game_diagonal_right2.make_move(4); // X
        game_diagonal_right2.make_move(5); // O
        game_diagonal_right2.make_move(4); // X
        game_diagonal_right2.make_move(5); // O
        game_diagonal_right2.make_move(5); // X
        game_diagonal_right2.make_move(6); // O
        game_diagonal_right2.make_move(5); // X
        CHECK(game_diagonal_right2.check_win() == true); // X deve vencer

        // Teste 3: Vitória diagonal direita
        Connect4 game_diagonal_right3;
        game_diagonal_right3.make_move(3); // X
        game_diagonal_right3.make_move(4); // O
        game_diagonal_right3.make_move(4); // X
        game_diagonal_right3.make_move(5); // O
        game_diagonal_right3.make_move(5); // X
        game_diagonal_right3.make_move(6); // O
        game_diagonal_right3.make_move(5); // X
        game_diagonal_right3.make_move(6); // O
        game_diagonal_right3.make_move(6); // X
        game_diagonal_right3.make_move(7); // O
        game_diagonal_right3.make_move(6); // X
        CHECK(game_diagonal_right3.check_win() == true); // X deve vencer
    }

    SUBCASE("Win Condition Test - Diagonal Esquerda") {
        // Teste 1: Vitória diagonal esquerda
        Connect4 game_diagonal_left1;
        game_diagonal_left1.make_move(4); // X
        game_diagonal_left1.make_move(3); // O
        game_diagonal_left1.make_move(3); // X
        game_diagonal_left1.make_move(2); // O
        game_diagonal_left1.make_move(2); // X
        game_diagonal_left1.make_move(1); // O
        game_diagonal_left1.make_move(2); // X
        game_diagonal_left1.make_move(1); // O
        game_diagonal_left1.make_move(1); // X
        game_diagonal_left1.make_move(7); // O
        game_diagonal_left1.make_move(1); // X
        CHECK(game_diagonal_left1.check_win() == true); // X deve vencer

        // Teste 2: Vitória diagonal esquerda
        Connect4 game_diagonal_left2;
        game_diagonal_left2.make_move(5); // X
        game_diagonal_left2.make_move(4); // O
        game_diagonal_left2.make_move(4); // X
        game_diagonal_left2.make_move(3); // O
        game_diagonal_left2.make_move(3); // X
        game_diagonal_left2.make_move(2); // O
        game_diagonal_left2.make_move(3); // X
        game_diagonal_left2.make_move(2); // O
        game_diagonal_left2.make_move(2); // X
        game_diagonal_left2.make_move(7); // O
        game_diagonal_left2.make_move(2); // X
        CHECK(game_diagonal_left2.check_win() == true); // X deve vencer

        // Teste 3: Vitória diagonal esquerda
        Connect4 game_diagonal_left3;
        game_diagonal_left3.make_move(6); // X
        game_diagonal_left3.make_move(5); // O
        game_diagonal_left3.make_move(5); // X
        game_diagonal_left3.make_move(4); // O
        game_diagonal_left3.make_move(4); // X
        game_diagonal_left3.make_move(3); // O
        game_diagonal_left3.make_move(4); // X
        game_diagonal_left3.make_move(3); // O
        game_diagonal_left3.make_move(3); // X
        game_diagonal_left3.make_move(7); // O
        game_diagonal_left3.make_move(3); // X
        CHECK(game_diagonal_left3.check_win() == true); // X deve vencer
    }

    SUBCASE("Board Full Test") {
        Connect4 game_full;
        
        // Verificação antes de completar
        CHECK(game_full.is_board_full() == false);

        // Preenche o tabuleiro completamente
        for (int col = 1; col <= 7; ++col) {
            for (int row = 0; row < 6; ++row) {
                game_full.make_move(col);
            }
        }

        // Tabuleiro deve estar cheio
        CHECK(game_full.is_board_full() == true); 
    }

    


}