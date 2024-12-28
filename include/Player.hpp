#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include <map>

class Player {
    private:
        std::string name;
        std::string username;
        std::map<std::string, int> num_win;
        std::map<std::string, int> num_loss;

    public:
        void register_player(std::string name_received, std::string username_received);
        void remove_player();
        void print_player();
};

#endif