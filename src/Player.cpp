#include "Player.hpp"
#include <string.h>

Player::Player(): Player("", "", {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}} , {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}}) {};

Player::Player(std::string name_received, std::string username_received, std::map<std::string, int> num_win_received, std::map<std::string, int> num_loss_received):
   name(name_received), username(username_received), num_win(num_win_received), num_loss(num_loss_received) {};

void Player::set_name(std::string name_received){
    this->name = name_received;
}    

void Player::set_username(std::string username_received){
    this->username = username_received;
}

void Player::set_num_win(std::string key, int value){
    this->num_win.insert_or_assign(key, value);
}

void Player::set_num_loss(std::string key, int value){
    this->num_loss.insert_or_assign(key,value);
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


void Player::register_player(std::string name_received, std::string username_received){
    this->name = name_received;
    this->username = username_received;
    this->num_win = {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}};
    this->num_loss = {{"Reversi", 0}, {"Lig4", 0}, {"Velha", 0}};
}

void Player::remove_player(std::string username_received, std::list<Player> &player_list){
    std::list<Player>::iterator it;
    for (it = player_list.begin(); it != player_list.end(); it++){
        if (it->get_username() == username_received){
            it = player_list.erase(it);
            std::cout << "Jogador " << username_received << " removido com sucesso" << std::endl;
            return;
        }
    }
    std::cout << "ERRO: jogador inexistente" << std::endl;
    return;
}

void Player::print_player(){
    std::cout << this->username << " " << this->name << std::endl;
    std::cout << "REVERSI" << "\t" << "- V: " << this->num_win.find("Reversi")->second << " D: " << this->num_loss.find("Reversi")->second << std::endl;
    std::cout << "LIG4" << "\t" << "- V: " << this->num_win.find("Lig4")->second << " D: " << this->num_loss.find("Lig4")->second << std::endl;
    std::cout << "VELHA" << "\t" << "- V: " << this->num_win.find("Velha")->second << " D: " << this->num_loss.find("Velha")->second << std::endl;
}

bool Player::compare_username(Player &player1,Player &player2){
    for (unsigned int i = 0; (i < player1.get_username().size()) && (i < player2.get_username().size()); i++){
        if (tolower(player1.get_username()[i]) < tolower(player2.get_username()[i]))
            return true;
        else if (tolower(player1.get_username()[i]) > tolower(player2.get_username()[i]))
            return false;
    }
    return player1.get_username().size() < player2.get_username().size();
}

bool Player::compare_name(Player &player1,Player &player2){
    for (unsigned int i = 0; (i < player1.get_name().size()) && (i < player2.get_name().size()); i++){
        if (tolower(player1.get_name()[i]) < tolower(player2.get_name()[i]))
            return true;
        else if (tolower(player1.get_name()[i]) > tolower(player2.get_name()[i]))
            return false;
    }
    return player1.get_name().size() < player2.get_name().size();
}