#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include <map>
#include <list>

class Player {
    private:
        std::string name;
        std::string username;
        std::map<std::string, int> num_win;
        std::map<std::string, int> num_loss;

    public:
        Player();
        Player(std::string name_received, std::string username_received);
        Player(std::string name_received, std::string username_received, std::map<std::string, int> num_win_received, std::map<std::string, int> num_loss_received);

        void set_name(std::string name_received);
        void set_username(std::string username_received);
        void set_num_win(std::string key, int value);
        void set_num_loss(std::string key, int value);
        std::string get_username();
        std::string get_name();
        std::map<std::string, int> get_num_win();
        std::map<std::string, int> get_num_loss();
        
        void print_player();
        void add_win(std::string key);
        void add_loss(std::string key);
        static bool register_player(Player player_received, std::list<Player> &player_list);
        static bool remove_player(std::string username_received, std::list<Player> &player_list);
        static bool compare_username(Player &player1, Player &player2);
        static bool compare_name (Player &player1, Player &player2);
};

#endif