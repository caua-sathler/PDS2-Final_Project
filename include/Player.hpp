#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include <map>

class Player {
    private:
        std::string name;
        std::string username;
        std::map<char, int> num_win;
        std::map<char, int> num_loss;

    public:
        Player(std::string name_received, std::string username_received, std::map<char, int> num_win_received, std::map<char, int> num_loss_received);
        void register_player(std::string name_received, std::string username_received);
        void remove_player();
        void print_player();
};

#endif