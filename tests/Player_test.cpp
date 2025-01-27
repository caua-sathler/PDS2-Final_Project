#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include <iostream>

TEST_CASE("Teste método register_player")
{
    std::list<Player> player_list;
    Player player1;
    Player::register_player(player1, player_list);
    CHECK(player1 == player_list.back());

    player1.set_username("Apelido"); player1.set_name("Nome");
    player1.set_num_loss("Reversi", -1); player1.set_num_loss("Lig4", 2); player1.set_num_loss("Velha", -3);
    player1.set_num_win("Reversi", 6); player1.set_num_win("Lig4", -5); player1.set_num_win("Velha", 4);
    Player::register_player(player1, player_list);
    CHECK(player1 == player_list.back());

    Player player2("Nome sobrenome", "Apelido1");
    Player::register_player(player2, player_list);
    CHECK(player2 == player_list.back());

    std::map<std::string, int> win = {{"Reversi", 1}, {"Lig4", 2}, {"Velha", 3}}, 
                               loss = {{"Reversi", 4}, {"Lig4", 5}, {"Velha", 6}};
    Player player3("Nome sobrenome", "Apelido2", win, loss);
    Player::register_player(player3, player_list);
    CHECK(player3 == player_list.back());

    Player *player4 = new Player("Nome sobrenome", "Apelido3");
    Player::register_player(*player4, player_list);
    CHECK(*player4 == player_list.back());
    delete player4;
}

