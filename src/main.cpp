#include "Game.hpp"
#include "Player.hpp"
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

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
        player_in.set_username(file_line[0]);
        player_in.set_name(file_line[1]);

        std::string key_in, num_win_in, num_loss_in;
        for (int j = 2; j < 5; j++){
            std::stringstream file_stream(file_line[j]);
            file_stream >> key_in >> num_win_in >> num_loss_in;
            player_in.set_num_win(key_in, stoi(num_win_in));
            player_in.set_num_loss(key_in, stoi(num_loss_in));
        }
        
        player_list.push_back(player_in);
        i = 0;
        }
    }

    file_in.close();

    std::string command;
    std::string name_in, username_in, line_in;
    char extra_space, sort_command;
    bool error = false;

    while(std::cin >> command){
        if (command == "LJ"){
            std::cin >> sort_command;
            if (sort_command == 'A'){
                player_list.sort(Player::compare_username);
            } else if (sort_command == 'N'){
                player_list.sort(Player::compare_name);
            } else {
                std::cout << "Erro: comando inexistente" << std::endl;
                continue;
            }
            std::list<Player>::iterator it;
            for (it = player_list.begin(); it != player_list.end(); it++){
                it->print_player();
            }
            continue;

        } else if (command == "CJ"){
            error = false;
            std::getline(std::cin, line_in);
            std::stringstream stream_in(line_in);
            stream_in >> username_in;
            extra_space = stream_in.get();
            std::getline(stream_in, name_in);
            if (name_in == ""){
                std::cout << "ERRO: dados incorretos" << std::endl;
                continue;
            }
            std::list<Player>::iterator it;
            for (it = player_list.begin(); it != player_list.end(); it++){
                if (it->get_username() == username_in){
                    std::cout << "ERRO: jogador repetido" << std::endl;
                    error = true;
                    continue;
                }
            }
            if (error == false){
                Player new_player(name_in, username_in);
                new_player.register_player(player_list);
                continue;
            }

        } else if (command == "RJ"){
            std::cin >> username_in;
            std::list<Player>::iterator it;
            Player::remove_player(username_in, player_list);
            continue;
        } else if (command == "FS"){
            break;
            
        } else {
            if (error == false){
                std::cout << "ERRO: comando inexistente" << std::endl;
                error = true;
                continue;
            }
        }
    }

    std::ofstream file_out;
    file_out.open("teste");
    if (!file_out.is_open()){
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    std::list<Player>::iterator it;
    for (it = player_list.begin(); it != player_list.end(); it++){
        file_out << it->get_username() << std::endl;
        file_out << it->get_name() << std::endl;
        file_out << "Reversi" << " " << it->get_num_win().find("Reversi")->second << " " << it->get_num_loss().find("Reversi")->second << std::endl;
        file_out << "Lig4" << " " << it->get_num_win().find("Lig4")->second << " " << it->get_num_loss().find("Lig4")->second << std::endl;
        file_out << "Velha" << " " << it->get_num_win().find("Velha")->second << " " << it->get_num_loss().find("Velha")->second << std::endl;
    }

    file_out.close();
}