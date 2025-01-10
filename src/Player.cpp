#include "Player.hpp"
#include <string.h>
#include <bits/stdc++.h>


Player::Player(): 
    Player("", "", {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}} , {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}}) {};

Player::Player(std::string name_received, std::string username_received): 
    Player(name_received, username_received, {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}} , {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}}) {};

Player::Player(std::string name_received, std::string username_received, std::map<std::string, int> num_win_received, std::map<std::string, int> num_loss_received):
   name(name_received), username(username_received), num_win(num_win_received), num_loss(num_loss_received) {};

void Player::set_name(std::string name_received){
    this->name = name_received;
}    

void Player::set_username(std::string username_received){
    this->username = username_received;
}

void Player::set_num_win(std::string key, int value){
    std::map<std::string, int>::iterator it = this->num_win.find(key);
    if (it == this->num_win.end())
        this->num_win.insert({key, value});
    else
        it->second = value;
}

void Player::set_num_loss(std::string key, int value){
    std::map<std::string, int>::iterator it = this->num_loss.find(key);
    if (it == this->num_loss.end())
        this->num_loss.insert({key, value});
    else
        it->second = value;
}

std::string Player::get_username(){
    return this->username;
}

std::string Player::get_name(){
    return this->name;
}

std::map<std::string, int> Player::get_num_win(){
    return this->num_win;
}

std::map<std::string, int> Player::get_num_loss(){
    return this->num_loss;
}

void Player::add_win(std::string key){
    std::map<std::string, int>::iterator it = this->num_win.find(key);
    if (it != this->num_win.end())
        it->second++;
}

void Player::add_loss(std::string key){
    std::map<std::string, int>::iterator it = this->num_loss.find(key);
    if (it != this->num_loss.end())
        it->second++;
}

void Player::print_player(){
    std::cout << this->username << " " << this->name << std::endl;
    std::cout << "REVERSI" << "\t" << "- V: " << this->num_win.find("Reversi")->second << " D: " << this->num_loss.find("Reversi")->second << std::endl;
    std::cout << "LIG4" << "\t" << "- V: " << this->num_win.find("Lig4")->second << " D: " << this->num_loss.find("Lig4")->second << std::endl;
    std::cout << "VELHA" << "\t" << "- V: " << this->num_win.find("Velha")->second << " D: " << this->num_loss.find("Velha")->second << std::endl;
}

bool Player::register_player(Player player_received, std::list<Player> &player_list){
    std::list<Player>::iterator it;
    for (it = player_list.begin(); it != player_list.end(); it++){
        if (it->get_username() == player_received.get_username()){
            return false;
        }
    }
    player_list.push_back(player_received);
    return true;
}

bool Player::remove_player(std::string username_received, std::list<Player> &player_list){
    std::list<Player>::iterator it;
    for (it = player_list.begin(); it != player_list.end(); it++){
        if (it->get_username() == username_received){
            it = player_list.erase(it);
            return true;
        }
    }
    return false;
}

bool Player::compare_username(Player &player1, Player &player2){
    for (unsigned int i = 0; (i < player1.get_username().size()) && (i < player2.get_username().size()); i++){
        if (tolower(player1.get_username()[i]) < tolower(player2.get_username()[i]))
            return true;
        else if (tolower(player1.get_username()[i]) > tolower(player2.get_username()[i]))
            return false;
    }
    return player1.get_username().size() < player2.get_username().size();
}

bool Player::compare_name(Player &player1, Player &player2){
    for (unsigned int i = 0; (i < player1.get_name().size()) && (i < player2.get_name().size()); i++){
        if (tolower(player1.get_name()[i]) < tolower(player2.get_name()[i]))
            return true;
        else if (tolower(player1.get_name()[i]) > tolower(player2.get_name()[i]))
            return false;
    }
    return player1.get_name().size() < player2.get_name().size();
}

void read_register_file(std::list<Player> &player_list, std::ifstream &file_in) {
    std::string file_line[5];
    Player player_in;
    int i = 0;
    while (getline(file_in, file_line[i])) {
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
}

void write_register_file(std::list<Player> &player_list, std::ofstream &file_out){
    std::list<Player>::iterator it;
    for (it = player_list.begin(); it != player_list.end(); it++){
        file_out << it->get_username() << std::endl;
        file_out << it->get_name() << std::endl;
        file_out << "Reversi" << " " << it->get_num_win().find("Reversi")->second << " " << it->get_num_loss().find("Reversi")->second << std::endl;
        file_out << "Lig4" << " " << it->get_num_win().find("Lig4")->second << " " << it->get_num_loss().find("Lig4")->second << std::endl;
        file_out << "Velha" << " " << it->get_num_win().find("Velha")->second << " " << it->get_num_loss().find("Velha")->second << std::endl;
    }
}