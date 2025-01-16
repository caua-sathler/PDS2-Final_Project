#include "Player.hpp"
#include "Reversi.hpp"
#include <limits>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
 
int main() {
    std::ifstream file_in;
    try {
    file_in.open("teste");
    if (!file_in.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo");
    
    } catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }

    std::list<Player> player_list;
    read_register_file(player_list, file_in);

    file_in.close();

    std::string command;

    while(true){
        try {
            std::cin >> command;
            if (command == "LJ"){
            char sort_command;
            try{
                std::cin >> sort_command;
                if (sort_command == 'A')
                    player_list.sort(Player::compare_username);
                else if (sort_command == 'N')
                    player_list.sort(Player::compare_name);
                else {
                    throw std::invalid_argument("ERRO: comando inexistente");
                }
                std::list<Player>::iterator it;
                for (it = player_list.begin(); it != player_list.end(); it++){
                    it->print_player();
                }
                continue;
            } catch(std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
            } else if (command == "CJ"){
                std::string line_in, username_in, name_in;
                try {
                    std::getline(std::cin, line_in);
                    std::stringstream stream_in(line_in);
                    stream_in >> username_in;
                    stream_in.ignore();
                    std::getline(stream_in, name_in);
                    if (name_in == "" || username_in == "")
                        throw std::invalid_argument("ERRO: dados incorretos, escreva o apelido e o nome do jogador");

                    Player new_player(name_in, username_in);
                    try {
                        Player::register_player(new_player, player_list);
                        std::cout << "Jogador " << new_player.get_username() << " cadastrado com sucesso" << std::endl;
                    }
                    catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        continue;
                    }
                    continue;
                } catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                
            } else if (command == "RJ"){
                std::string name_in, username_in;
                try {
                    std::cin >> username_in;
                    if (username_in == "")
                        throw std::invalid_argument("ERRO: dados incorretos, escreva o apelido do jogador");
                    try {
                        Player::remove_player(username_in, player_list);
                        std::cout << "Jogador " << username_in << " removido com sucesso" << std::endl;
                    }
                    catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        continue;
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }

            }else if(command == "EP"){
                char game;
                std::string username_player1, username_player2, line_in;
                
                try {
                    std::getline(std::cin, line_in);
                    std::stringstream stream_in(line_in);
                    stream_in >> game >> username_player1 >> username_player2;

                    if (game != 'R' && game != 'V' && game != 'L')
                        throw std::invalid_argument("ERRO: dados incorretos, selecione um dos jogos disponíveis");
                    else if (username_player1 == "" || username_player2 == "")
                        throw std::invalid_argument("ERRO: dados incorretos, escreva o apelido dos dois jogadores");
                    
                    Player *player1 = Player::find_player_in_list(player_list, username_player1);
                    Player *player2 = Player::find_player_in_list(player_list, username_player2);
                    
                    if(game == 'R'){
                        Reversi reversi_game;

                        char player_piece = 'X';
                        char opponent_piece = 'O';

                        while (true)
                        {
                            int x, y;

                            bool is_there_movement_for_player = reversi_game.is_there_valid_move_for_player(player_piece);
                            bool someone_won = reversi_game.check_win
                            (is_there_movement_for_player, player_piece);
                            reversi_game.print_reversi_board();
                            std::cout<<"X: "<<reversi_game.get_num_pieces_player_X()<<" "<<"O: "<<reversi_game.get_num_pieces_player_O()<<std::endl;                    

                            if (someone_won)
                            {
                                reversi_game.register_win_and_loss(player1, player2);

                                if(reversi_game.get_num_pieces_player_X() > reversi_game.get_num_pieces_player_O()){
                                    std::cout<<username_player1<< " ganhou!"<<std::endl;
                                }else if(reversi_game.get_num_pieces_player_X() < reversi_game.get_num_pieces_player_O()){
                                    std::cout<<username_player2<< " ganhou!"<<std::endl;
                                }else{
                                    std::cout<<"Houve empate!"<<std::endl;
                                }
                                break;
                            }
                            else if (is_there_movement_for_player && !someone_won)
                            {

                                if(player_piece == 'X'){
                                    std::cout<<username_player1<<" "<<"[X]"<<": "<<std::ends;
                                }else{
                                    std::cout<<username_player2<<" "<<"[O]"<<": "<<std::ends;
                                }

                                if (!(std::cin >> x >> y))
                                {
                                    std::cout << "Invalid input. Please enter two integers for your move.\n";
                                    std::cin.clear();                
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    continue; 
                                }
                                if(!reversi_game.process_move({x, y}, player_piece)){
                                    std::cout<<"Movimento Inválida, vez passada para o oponente"<<std::endl;
                                }

                                player_piece = reversi_game.switch_players(player_piece);
                                opponent_piece = reversi_game.switch_players(opponent_piece);
                            }
                            else if (!is_there_movement_for_player && !someone_won)
                            {
                                player_piece = reversi_game.switch_players(player_piece);
                                opponent_piece = reversi_game.switch_players(opponent_piece);
                                std::cout<<"Não há jogadas válida, vez passada para o oponent"<<std::endl;
                            }
                        }
                    }
                } catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            } else if (command == "FS"){
                break;

            } else {
                throw std::invalid_argument("ERRO: comando inexiste");
            }

        } catch(std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::ofstream file_out;
    try {
    file_out.open("teste");
    if (!file_out.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo");
    
    } catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    write_register_file(player_list, file_out);

    file_out.close();
}
