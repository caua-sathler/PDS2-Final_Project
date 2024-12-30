#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <map>
#include <list>

int main() {
    std::ifstream file_in;
    file_in.open("teste");
    if (!file_in.is_open()){
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    std::string file_line[5];
    std::list<Player> player_list;
    Player player_in;
    
    int i = 0;
    while (getline(file_in,file_line[i]) ) {
        i++;
        if (i == 5) { 
        player_in.set_name(file_line[0]);
        player_in.set_username(file_line[1]);

        std::string key_in, num_win_in, num_loss_in;
        for (int j = 2; j < 5; j++){
            std::stringstream ss(file_line[j]);
            ss >> key_in >> num_win_in >> num_loss_in;
            player_in.set_num_win(key_in, stoi(num_win_in));
            player_in.set_num_loss(key_in, stoi(num_loss_in));
        }
        
        player_list.push_back(player_in);
        i = 0;
        }
    }

    file_in.close();

    std::string command;
    std::string name_in, username_in;
    while(std::cin >> command){
        if (command == "LJ"){
            std::list<Player>::iterator it;
            for (it = player_list.begin(); it != player_list.end(); it++){
                it->print_player();
            }
            continue;
        } else if (command == "CJ"){
            std::cin >> username_in >> name_in;
            player_in.register_player(name_in, username_in);
            player_list.push_back(player_in);
            std::cout << "Jogador " << username_in << " cadastrado com sucesso" << std::endl;
        } else if (command == "FS"){
            break;
        }
    }

}