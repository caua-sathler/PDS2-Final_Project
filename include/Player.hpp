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
        Player();
        Player(std::string name_received, std::string username_received, std::map<std::string, int> num_win_received, std::map<std::string, int> num_loss_received);

        void set_name(std::string name_received);
        void set_username(std::string username_received);
        void set_num_win(std::string key, int value);
        void set_num_loss(std::string key, int value);
        std::string get_username();
        
        void register_player(std::string name_received, std::string username_received);
        void remove_player();
        void print_player();
};

#endif