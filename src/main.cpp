#include "Player.hpp"
#include "Reversi.hpp"
#include "Tic_tac_toe.hpp"
#include "Connect4.hpp"
#include <limits>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

/**
* @brief Procura se há um jogador específico existe na lista.
* @param player_list Lista que registra todos os jogadores.
* @param user_name Nome do jogador a ser procurado.
* @return O endereço de memória do jogador caso seja encontrado, 
* 'nullptr' caso contrário.
*/
Player *find_player_in_list(std::list<Player> &player_list, const std::string &user_name)
{
    for (auto &player : player_list)
    {
        if (player.get_username() == user_name)
            return &player;
    }
    return nullptr;
}


/**
 * @brief Função principal que gerencia os comandos do sistema de jogadores e execução de jogos.
 * 
 * Realiza operações como listar, cadastrar e remover jogadores, além de permitir a execução dos jogos Reversi, Lig4 (Connect4) e Velha (Tic Tac Toe).
 */
int main()
{
    std::ifstream file_in;
    file_in.open("/home/leonardo/PDS2-Final_Project/teste");
    if (!file_in.is_open())
    {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    std::list<Player> player_list;
    read_register_file(player_list, file_in);

    file_in.close();

    std::string command;
    std::string name_in, username_in;
    bool error = false;

    // Loop principal que processa os comandos do usuário
    while (std::cin >> command)
    {
        if (command == "LJ")
        {
            // Listar jogadores ordenados por nome ou username
            char sort_command;
            std::cin >> sort_command;
            if (sort_command == 'A')
                player_list.sort(Player::compare_username);
            else if (sort_command == 'N')
                player_list.sort(Player::compare_name);
            else
            {
                std::cout << "ERRO: comando inexistente" << std::endl;
                continue;
            }
            std::list<Player>::iterator it;
            for (it = player_list.begin(); it != player_list.end(); it++)
                it->print_player();

            continue;
        }
        else if (command == "CJ")
        {
            // Cadastrar um novo jogador
            std::string line_in;
            std::getline(std::cin, line_in);
            std::stringstream stream_in(line_in);
            stream_in >> username_in;
            stream_in.ignore();
            std::getline(stream_in, name_in);
            if (name_in == "")
            {
                std::cout << "ERRO: dados incorretos" << std::endl;
                continue;
            }
            Player new_player(name_in, username_in);
            if (Player::register_player(new_player, player_list) == true)
                std::cout << "Jogador " << new_player.get_username() << " cadastrado com sucesso" << std::endl;
            else
                std::cout << "ERRO: jogador repetido" << std::endl;
            continue;
        }
        else if (command == "RJ")
        {
            // Remover um jogador existente
            std::cin >> username_in;
            if (Player::remove_player(username_in, player_list) == true)
                std::cout << "Jogador " << username_in << " removido com sucesso" << std::endl;
            else
                std::cout << "ERRO: jogador inexistente" << std::endl;
            continue;
        }
        else if (command == "EP")
        {   
            // Iniciar um jogo entre dois jogadores
            char game;
            std::string username_player1, username_player2;

            try
            {
                std::cin >> game;
                if (game != 'R' && game != 'V' && game != 'L')
                {
                    throw std::invalid_argument("Entrada inválida, jogos disponíveis: R, V e L");
                }

                std::cin >> username_player1 >> username_player2;
                Player *player1 = find_player_in_list(player_list, username_player1);
                Player *player2 = find_player_in_list(player_list, username_player2);

                if (player1 == nullptr)
                    throw std::invalid_argument("ERRO: jogador " + username_player1 + " inexistente");

                else if (player2 == nullptr)
                    throw std::invalid_argument("ERRO: jogador " + username_player2 + " inexistente");
                
                // Inicialização do jogo com base no tipo selecionado
                if (game == 'R')
                {
                    Reversi reversi_game;
                    char player_piece = 'X';
                    char opponent_piece = 'O';

                    while (true)
                    {
                        int x, y;
                        bool is_there_movement_for_player = reversi_game.is_there_valid_move_for_player(player_piece);
                        bool someone_won = reversi_game.check_win(is_there_movement_for_player, player_piece);
                        reversi_game.print_reversi_board();
                        std::cout << "X: " << reversi_game.get_num_pieces_player_X() << " " << "O: "
                                  << reversi_game.get_num_pieces_player_O() << std::endl;

                        if (someone_won)
                        {
                            reversi_game.register_win_and_loss(player1, player2);

                            if (reversi_game.get_num_pieces_player_X() > reversi_game.get_num_pieces_player_O())
                                std::cout << username_player1 << " ganhou!" << std::endl;

                            else if (reversi_game.get_num_pieces_player_X() < reversi_game.get_num_pieces_player_O())
                                std::cout << username_player2 << " ganhou!" << std::endl;

                            else
                                std::cout << "Houve empate!" << std::endl;

                            break;
                        }
                        else if (is_there_movement_for_player && !someone_won)
                        {
                            if (player_piece == 'X')
                                std::cout << username_player1 << " " << "[X]" << ": " << std::ends;
                            else
                                std::cout << username_player2 << " " << "[O]" << ": " << std::ends;

                            try {
                               
                                if (!(std::cin >> x )) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    throw std::invalid_argument("Entrada inválida. Por favor forneça dois números inteiros.");
                                }

                                if(!(std::cin >> y)){
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    throw std::invalid_argument("Entrada inválida, vez passada para o oponente");
                                }
                                
                                if (!reversi_game.process_move({x, y}, player_piece)) {
                                    throw std::invalid_argument("Jogada inválida, vez passada para o oponente.");
                                }

                            } 
                            catch (const std::invalid_argument &e) {
                            
                                std::cout << "Error: " << e.what() << std::endl;
                            }

                            player_piece = reversi_game.switch_players(player_piece);
                            opponent_piece = reversi_game.switch_players(opponent_piece);

                        }
                        else if (!is_there_movement_for_player && !someone_won)
                        {
                            player_piece = reversi_game.switch_players(player_piece);
                            opponent_piece = reversi_game.switch_players(opponent_piece);
                            std::cout << "Não há jogadas válidas, vez passada para o oponente" << std::endl;
                        }
                    }
                }
                else if (game == 'L')  
                {
                    Connect4 connect4_game;
                    bool game_over = false;

                    while (!game_over)
                    {
                        int column;
                        connect4_game.print_game_board();
                        char current_player = connect4_game.get_current_player();

                        std::cout << "Turno de jogador <" << current_player << ">:" << std::endl;
        
                        try {
                            if (!(std::cin >> column)) 
                            {
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                throw std::invalid_argument("Entrada inválida. Por favor, insira um número inteiro.");
                            }

                            if (!connect4_game.is_valid_move(column)) 
                            {
                                throw std::out_of_range("Movimento inválido!");
                            }
                            
                            connect4_game.make_move(column);
                                
                            if (connect4_game.check_win()) 
                            {
                                connect4_game.print_game_board();
                                if (current_player == 'X') 
                                {
                                    player1->add_win("Lig4");
                                    player2->add_loss("Lig4");
                                    std::cout << "Parabéns, " << username_player1 << "! Você venceu!" << std::endl;
                                } 
                                else 
                                {
                                    player2->add_win("Lig4");
                                    player1->add_loss("Lig4");
                                    std::cout << "Parabéns, " << username_player2 << "! Você venceu!" << std::endl;
                                }
                                game_over = true; 
                            } 
                            else if (connect4_game.is_board_full()) 
                            {
                                std::cout << "O jogo terminou em empate!" << std::endl;
                                game_over = true;
                            }
                        } 
                        catch (const std::out_of_range& e) 
                        {
                            std::cout << "Erro: " << e.what() << std::endl;
                        } 
                        catch (const std::runtime_error& e) 
                        {
                            std::cout << "Erro: " << e.what() << std::endl;
                        } 
                        catch (const std::invalid_argument& e) 
                        {
                            std::cout << "Erro: " << e.what() << std::endl;
                        }
                        connect4_game.set_current_player((current_player == 'X') ? 'O' : 'X');

                    }
                }
                else if (game == 'V')
                {
                    Tic_tac_toe tic_tac_toe_game;
                    int x, y;

                    std::cout << username_player1 << " is X and " << username_player2 << " is O" << std::endl;

                    while (true)
                    {
                        if (tic_tac_toe_game.check_tic_tac_toe_win() != 'F')
                        {
                            tic_tac_toe_game.print_tic_tac_toe_board();
                            std::cout << username_player1 << " won!" << std::endl;
                            player1->add_win("Velha");
                            player2->add_loss("Velha");
                            break;
                        }

                        if (tic_tac_toe_game.check_tie())
                        {
                            std::cout << "Draw! The board is full" << std::endl;
                            break;
                        }

                        std::cout << "Player " << tic_tac_toe_game.get_current_player() << " turn:" << std::endl;
                        tic_tac_toe_game.print_tic_tac_toe_board();

                        try
                        {
                            if (!(std::cin >> x >> y))
                                throw std::invalid_argument("Invalid input. Please enter two integers for your move");
                        }

                        catch (const std::invalid_argument &e)
                        {
                            std::cerr << "Error: " << e.what() << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }

                        tic_tac_toe_game.make_move(x, y);
                    }
                }
            }
            catch (std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (command == "FS")
            break;

        else
        {
            if (error == false)
            {
                std::cout << "ERRO: comando inexistente" << std::endl;
                error = true;
                continue;
            }
        }
    }
    
    // Escrita do arquivo de registro atualizado
    std::ofstream file_out;
    file_out.open("teste");
    if (!file_out.is_open())
    {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    write_register_file(player_list, file_out);

    file_out.close();

    return 0;
}