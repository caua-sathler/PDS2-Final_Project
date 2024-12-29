#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>
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

        player_in.set_num_win(file_line[2][0], file_line[2][2] - '0');
        player_in.set_num_win(file_line[3][0], file_line[3][2] - '0');
        player_in.set_num_win(file_line[4][0], file_line[4][2] - '0');
        
        player_in.set_num_loss(file_line[2][0], file_line[2][4] - '0');
        player_in.set_num_loss(file_line[3][0], file_line[3][4] - '0');
        player_in.set_num_loss(file_line[4][0], file_line[4][4] - '0');
        
        player_list.push_back(player_in);
        i = 0;
        }
    }
    
    file_in.close();
}