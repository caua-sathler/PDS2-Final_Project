#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include <algorithm>

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

    Player player3("Nome sobrenome", "Apelido2", {{"Reversi", 1}, {"Lig4", 2}, {"Velha", 3}}, {{"Reversi", 4}, {"Lig4", 5}, {"Velha", 6}});
    Player::register_player(player3, player_list);
    CHECK(player3 == player_list.back());

    Player *player4 = new Player("Nome sobrenome", "Apelido3");
    Player::register_player(*player4, player_list);
    CHECK(*player4 == player_list.back());
    delete player4;
}

TEST_CASE("Teste método remove_player")
{
    Player player1, player2("nome", "Apelido1"), player3("nome sobrenome", "Apelido2");
    std::list<Player> player_list = {player1, player2, player3};
    Player::remove_player("", player_list);
    std::list<Player>::iterator it;
    for (it = player_list.begin(); it != player_list.end(); it++)
        if (*it == player1)
            CHECK(false);

    Player::remove_player("Apelido2", player_list);
    for (it = player_list.begin(); it != player_list.end(); it++)
        if (*it == player3)
            CHECK(false);

    Player player4("Nome sobrenome", "Apelido4", {{"Reversi", 1}, {"Lig4", 2}, {"Velha", 3}}, {{"Reversi", 4}, {"Lig4", 5}, {"Velha", 6}});
    player_list.push_back(player4);
    Player::remove_player("Apelido4", player_list);
    for (it = player_list.begin(); it != player_list.end(); it++)
        if (*it == player4)
            CHECK(false);   

    Player *player5 = new Player("nome", "Apelido3");
    player_list.push_back(*player5);
    Player::remove_player("Apelido3", player_list);
    for (it = player_list.begin(); it != player_list.end(); it++)
        if (*it == *player5)
            CHECK(false);
    delete player5;
}

TEST_CASE("Teste método add_win"){
    Player player;
    player.add_win("Reversi");
    player.add_win("Lig4");
    player.add_win("Velha");
    std::map<std::string, int> win_test = {{"Reversi", 1}, {"Lig4", 1}, {"Velha", 1}};
    CHECK(player.get_num_win() == win_test);

    player.set_num_win("Velha", -13);
    player.add_win("Velha");
    win_test["Velha"] = -12;
    CHECK(player.get_num_win() == win_test);

    player.set_num_win("Reversi", 2147483647);
    player.add_win("Reversi");
    win_test["Reversi"] = 2147483648;
    CHECK(player.get_num_win() == win_test);

    player.set_num_win("Lig4", -2147483648);
    player.add_win("Lig4");
    win_test["Lig4"] = -2147483647;
    CHECK(player.get_num_win() == win_test);

    player.add_win("Game");
    CHECK(player.get_num_win() == win_test);
}

TEST_CASE("Teste método add_loss"){
    Player player;
    player.add_loss("Reversi");
    player.add_loss("Lig4");
    player.add_loss("Velha");
    std::map<std::string, int> loss_test = {{"Reversi", 1}, {"Lig4", 1}, {"Velha", 1}};
    CHECK(player.get_num_loss() == loss_test);

    player.set_num_loss("Velha", -13);
    player.add_loss("Velha");
    loss_test["Velha"] = -12;
    CHECK(player.get_num_loss() == loss_test);

    player.set_num_loss("Reversi", 2147483647);
    player.add_loss("Reversi");
    loss_test["Reversi"] = 2147483648;
    CHECK(player.get_num_loss() == loss_test);

    player.set_num_loss("Lig4", -2147483648);
    player.add_loss("Lig4");
    loss_test["Lig4"] = -2147483647;
    CHECK(player.get_num_loss() == loss_test);

    player.add_loss("Game");
    CHECK(player.get_num_loss() == loss_test);
}