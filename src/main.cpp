#include "Player.hpp"
#include "Reversi.hpp"
#include "Tic_tac_toe.hpp"
#include "Connect4.hpp"
#include <limits>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

/**
 * @brief Encontra um jogador na lista pelo seu username.
 * 
 * @param player_list Lista de jogadores.
 * @param user_name Username do jogador a ser encontrado.
 * @return Ponteiro para o jogador encontrado ou nullptr se não encontrado.
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
 * @brief Função principal do programa.
 * 
 * Controla a interação com o usuário, gerencia os comandos e executa os jogos.
 * 
 * Comandos suportados:
 * - `LJ`: Lista jogadores (ordenados por username ou nome).
 * - `CJ`: Cadastra um novo jogador.
 * - `RJ`: Remove um jogador.
 * - `EP`: Executa uma partida de um dos jogos.
 * - `FS`: Salva os dados e encerra o programa.
 */
int main()
{
    // Abre o arquivo de entrada contendo os dados dos jogadores
    std::ifstream file_in;
    file_in.open("/mnt/c/Users/55319/Desktop/Visual Studio Code/PDSII-Trabalho/PDS2-Final_Project/PDS2-Final_Project/teste.txt");
    if (!file_in.is_open())
    {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    // Lê os dados dos jogadores
    std::list<Player> player_list;
    read_register_file(player_list, file_in);
    file_in.close();

    std::string command;
    std::string name_in, username_in;
    bool error = false;

    // Loop principal para leitura de comandos
    while (std::cin >> command)
    {
        if (command == "LJ")
        {
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

            for (auto &player : player_list)
                player.print_player();
            continue;
        }
        else if (command == "CJ")
        {
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
            if (Player::register_player(new_player, player_list))
                std::cout << "Jogador " << new_player.get_username() << " cadastrado com sucesso" << std::endl;
            else
                std::cout << "ERRO: jogador repetido" << std::endl;
            continue;
        }
        else if (command == "RJ")
        {
            std::cin >> username_in;
            if (Player::remove_player(username_in, player_list))
                std::cout << "Jogador " << username_in << " removido com sucesso" << std::endl;
            else
                std::cout << "ERRO: jogador inexistente" << std::endl;
            continue;
        }
        else if (command == "EP")
        {
            char game;
            std::string username_player1, username_player2;

            try
            {
                std::cin >> game;
                if (game != 'R' && game != 'V' && game != 'L')
                    throw std::invalid_argument("Entrada inválida, jogos disponíveis: R, V e L");

                std::cin >> username_player1 >> username_player2;
                Player *player1 = find_player_in_list(player_list, username_player1);
                Player *player2 = find_player_in_list(player_list, username_player2);

                if (player1 == nullptr)
                    throw std::invalid_argument("ERRO: jogador " + username_player1 + " inexistente");

                if (player2 == nullptr)
                    throw std::invalid_argument("ERRO: jogador " + username_player2 + " inexistente");

                if (game == 'R')
                {
                    Reversi reversi_game;
                    char player_piece = 'X';

                    while (true)
                    {
                        reversi_game.print_reversi_board();
                        std::cout << "X: " << reversi_game.get_num_pieces_player_X() << " "
                                  << "O: " << reversi_game.get_num_pieces_player_O() << std::endl;

                        if (reversi_game.check_win(reversi_game.is_there_valid_move_for_player(player_piece), player_piece))
                        {
                            reversi_game.register_win_and_loss(player1, player2);
                            std::cout << (reversi_game.get_num_pieces_player_X() > reversi_game.get_num_pieces_player_O() ? username_player1 : username_player2) << " ganhou!" << std::endl;
                            break;
                        }

                        std::cout << username_player1 << " [X]: " << std::endl;
                        int x, y;
                        std::cin >> x >> y;

                        if (!reversi_game.process_move({x, y}, player_piece))
                        {
                            std::cout << "Jogada inválida!" << std::endl;
                            continue;
                        }

                        player_piece = reversi_game.switch_players(player_piece);
                    }
                }
                else if (game == 'L')
                {
                    Connect4 connect4_game;
                    while (true)
                    {
                        connect4_game.print_game_board();
                        int column;
                        std::cout << "Jogador " << connect4_game.get_current_player() << " escolha uma coluna: ";
                        std::cin >> column;

                        if (connect4_game.is_valid_move(column))
                        {
                            connect4_game.make_move(column);

                            if (connect4_game.check_win())
                            {
                                std::cout << "Jogador " << connect4_game.get_current_player() << " venceu!" << std::endl;
                                break;
                            }

                            if (connect4_game.is_board_full())
                            {
                                std::cout << "Empate!" << std::endl;
                                break;
                            }

                            connect4_game.set_current_player(connect4_game.get_current_player() == 'X' ? 'O' : 'X');
                        }
                        else
                            std::cout << "Movimento inválido." << std::endl;
                    }
                }
                else if (game == 'V')
                {
                    Tic_tac_toe tic_tac_toe_game;
                    while (true)
                    {
                        tic_tac_toe_game.print_tic_tac_toe_board();
                        int x, y;
                        std::cout << "Jogador " << tic_tac_toe_game.get_current_player() << " escolha uma jogada: ";
                        std::cin >> x >> y;
                        tic_tac_toe_game.make_move(x, y);

                        if (tic_tac_toe_game.check_tic_tac_toe_win() != 'F')
                        {
                            std::cout << "Jogador " << tic_tac_toe_game.get_current_player() << " venceu!" << std::endl;
                            break;
                        }

                        if (tic_tac_toe_game.check_tie())
                        {
                            std::cout << "Empate!" << std::endl;
                            break;
                        }
                    }
                }
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (command == "FS")
            break;
        else
        {
            if (!error)
            {
                std::cout << "ERRO: comando inexistente" << std::endl;
                error = true;
            }
        }
    }

    // Salva os dados dos jogadores no arquivo de saída
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
