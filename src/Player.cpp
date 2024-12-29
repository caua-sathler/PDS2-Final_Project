#include "Player.hpp"
#include <iostream>
#include <map>

Player::Player(): Player("", "", {} , {}) {};

Player::Player(std::string name_received, std::string username_received, std::map<char, int> num_win_received, std::map<char, int> num_loss_received):
   name(name_received), username(username_received), num_win(num_win_received), num_loss(num_loss_received) {};

void Player::set_name(std::string name_received){
    this->name = name_received;
}    

void Player::set_username(std::string username_received){
    this->username = username_received;
}

void Player::set_num_win(char key, int value){
    this->num_win.insert_or_assign(key, value);
}

void Player::set_num_loss(char key, int value){
    this->num_loss.insert_or_assign(key,value);
}

void Player::register_player(std::string name_received, std::string username_received){

}

void Player::remove_player(){

}

void Player::print_player(){
    std::cout << this->username << " " << this->name << std::endl;
    std::cout << "REVERSI" << "\t" << "- V: " << this->num_win.find('R')->second << " D: " << this->num_loss.find('R')->second << std::endl;
    std::cout << "LIG4" << "\t" << "- V: " << this->num_win.find('L')->second << " D: " << this->num_loss.find('L')->second << std::endl;
    std::cout << "VELHA" << "\t" << "- V: " << this->num_win.find('V')->second << " D: " << this->num_loss.find('V')->second << std::endl;
}