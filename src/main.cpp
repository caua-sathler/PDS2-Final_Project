#include "Player.hpp"
#include "Reversi.hpp"
#include <limits>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

//lidar com exceção
Player* find_player_in_list(std::list<Player>& player_list, const std::string& user_name) {
    for (auto& player : player_list) {
        if (player.get_username() == user_name) {
            return &player;
        }
    }
    return nullptr;
}

int main() {
}