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
    char extra_space;
    bool error = false;
    while(std::cin >> command){
        if (command == "LJ"){
            std::list<Player>::iterator it;
            for (it = player_list.begin(); it != player_list.end(); it++){
                it->print_player();
            }
            continue;
        } else if (command == "CJ"){
            error = false;
            std::cin >> username_in;
            extra_space = std::getchar();
            std::getline(std::cin, name_in);
            std::list<Player>::iterator it;
            for (it = player_list.begin(); it != player_list.end(); it++){
                if (it->get_username() == username_in){
                    std::cout << "ERRO: jogador repetido" << std::endl;
                    error = true;
                }
            }
            if (error == false){
                player_in.register_player(name_in, username_in);
                player_list.push_back(player_in);
                std::cout << "Jogador " << username_in << " cadastrado com sucesso" << std::endl;
                continue;
            }
        } else if (command == "RJ"){
            std::cin >> username_in;
            std::list<Player>::iterator it;
            for (it = player_list.begin(); it != player_list.end(); it++){
                if (it->get_username() == username_in){
                    it = player_list.erase(it);
                    std::cout << "Jogador " << username_in << " removido com sucesso" << std::endl;
                }
            }
            continue;
        }
        else if (command == "FS"){
            break;
        } else {
            if (error == false){
                std::cout << "ERRO: comando inexistente" << std::endl;
                error = true;
                continue;
            }
        }
    }

}