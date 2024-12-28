#include "Player.hpp"
#include <iostream>


Player::Player(std::string name_received, std::string username_received, std::map<char, int> num_win_received, std::map<char, int> num_loss_received):
   name(name_received), username(username_received), num_win(num_win_received), num_loss(num_loss_received) {};

void Player::register_player(std::string name_received, std::string username_received){
}

void Player::remove_player(){
}

void Player::print_player(){
}