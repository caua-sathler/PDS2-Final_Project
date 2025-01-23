#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include <map>
#include <list>

/**
 * @file Player.hpp
 * @brief Gerencia informações e ações relacionadas a jogadores.
 * 
 * Define a estrutura de dados e métodos para representar jogadores,
 * incluindo estatísticas, registros e funcionalidades associadas.
 */

/**
 * @class Player
 * @brief Representa um jogador com informações pessoais e estatísticas.
 * 
 * Oferece métodos para gerenciar dados como nome, username, vitórias e derrotas,
 * além de funcionalidades estáticas para manipular listas de jogadores.
 */
class Player {
    private:
        std::string name; /**< Nome do jogador. */
        std::string username; /**< Nome de usuário do jogador. */
        std::map<std::string, int> num_win; /**< Número de vitórias por jogo. */
        std::map<std::string, int> num_loss; /**< Número de derrotas por jogo. */

    public:
        /**
        * @brief Construtor padrão que inicializa o jogador com valores vazios e estatísticas zeradas.
        */
        Player();

        /**
        * @brief Construtor que inicializa o jogador com nome e username, mantendo estatísticas zeradas.
        * @param name_received Nome do jogador.
        * @param username_received Nome de usuário.
        */
        Player(std::string name_received, std::string username_received);
        

        /**
        * @brief Construtor que inicializa o jogador com nome, username e estatísticas recebidas.
        * @param name_received Nome do jogador.
        * @param username_received Nome de usuário.
        * @param num_win_received Mapa de vitórias por jogo.
        * @param num_loss_received Mapa de derrotas por jogo.
        */
        Player(std::string name_received, std::string username_received, 
               std::map<std::string, int> num_win_received, std::map<std::string, int> num_loss_received);


        /**
         * @brief Define o nome do jogador.
         * @param name_received Nome do jogador.
         */
        void set_name(std::string name_received);


        /**
         * @brief Define o nome de usuário.
         * @param username_received Nome de usuário.
         */
        void set_username(std::string username_received);


        /**
         * @brief Atualiza o número de vitórias para um jogo.
         * @param key Nome do jogo.
         * @param value Número de vitórias.
         */
        void set_num_win(std::string key, int value);


        /**
         * @brief Atualiza o número de derrotas para um jogo.
         * @param key Nome do jogo.
         * @param value Número de derrotas.
         */
        void set_num_loss(std::string key, int value);


        /**
         * @brief Retorna o nome de usuário.
         * @return Nome de usuário do jogador.
         */
        std::string get_username();


        /**
         * @brief Retorna o nome do jogador.
         * @return Nome do jogador.
         */
        std::string get_name();


        /**
         * @brief Retorna o mapa de vitórias por jogo.
         * @return Mapa com o número de vitórias.
         */
        std::map<std::string, int> get_num_win();


        /**
         * @brief Retorna o mapa de derrotas por jogo.
         * @return Mapa com o número de derrotas.
         */
        std::map<std::string, int> get_num_loss();


        /**
         * @brief Imprime as informações do jogador.
         */
        void print_player();


        /**
         * @brief Adiciona uma vitória ao jogador em um jogo específico.
         * @param key Nome do jogo.
         */
        void add_win(std::string key);


        /**
         * @brief Adiciona uma derrota ao jogador em um jogo específico.
         * @param key Nome do jogo.
         */
        void add_loss(std::string key);


        /**
         * @brief Registra um jogador em uma lista de jogadores.
         * @param player_received Jogador a ser registrado.
         * @param player_list Lista onde o jogador será registrado.
         * @return `true` se o registro for bem-sucedido, `false` caso contrário.
         */
        static bool register_player(Player player_received, std::list<Player> &player_list);


        /**
         * @brief Remove um jogador da lista de jogadores.
         * @param username_received Nome de usuário do jogador a ser removido.
         * @param player_list Lista de onde o jogador será removido.
         * @return `true` se a remoção for bem-sucedida, `false` caso contrário.
         */
        static bool remove_player(std::string username_received, std::list<Player> &player_list);


        /**
         * @brief Compara o username de dois jogadores.
         * @param player1 Primeiro jogador.
         * @param player2 Segundo jogador.
         * @return `true` se os usernames forem iguais, `false` caso contrário.
         */
        static bool compare_username(Player &player1, Player &player2);


        /**
         * @brief Compara o nome de dois jogadores.
         * @param player1 Primeiro jogador.
         * @param player2 Segundo jogador.
         * @return `true` se os nomes forem iguais, `false` caso contrário.
         */
        static bool compare_name(Player &player1, Player &player2);
};

/**
 * @brief Lê os dados de registro de jogadores a partir de um arquivo.
 * @param player_list Lista de jogadores a ser preenchida.
 * @param file_in Arquivo de entrada contendo os registros.
 */
void read_register_file(std::list<Player> &player_list, std::ifstream &file_in);


/**
 * @brief Escreve os dados de registro de jogadores em um arquivo.
 * @param player_list Lista de jogadores a ser registrada.
 * @param file_out Arquivo de saída para armazenar os registros.
 */
void write_register_file(std::list<Player> &player_list, std::ofstream &file_out);

#endif
