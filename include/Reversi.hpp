#include "Game.hpp"
#include "Player.hpp"
#ifndef REVERSI_H
#define REVERSI_H
#include <array>
#include <list>

/**
 * @file Reversi.hpp
 * @brief Implementa o jogo Reversi, baseado na classe genérica Game.
 * 
 * Contém as regras e ações específicas do jogo Reversi.
 */

/**
 * @class Reversi
 * @brief Gerencia as regras e funcionalidades do jogo Reversi.
 * 
 * Herda de Game e adiciona métodos específicos para o funcionamento
 * do jogo Reversi, como validação de jogadas, captura de peças e verificação de vitória.
 */

class Reversi : public Game {
    private:
        int num_pieces_player_X; /**< Número de peças do jogador X. */
        int num_pieces_player_O; /**< Número de peças do jogador O. */

    public:
        /**
        * @brief Construtor padrão do jogo Reversi. Inicializa o tabuleiro padrão do Reversi,
        * além de iniciar cada jogador com 2 de suas respectivas peças.
        */
        Reversi();


        /**
        * @brief Retorna o número de peças do jogador X.
        * @return Número de peças do jogador X.
        */
        int get_num_pieces_player_X();


        /**
        * @brief Retorna o número de peças do jogador O.
        * @return Número de peças do jogador O.
        */
        int get_num_pieces_player_O();


        /**
         * @brief Define manualmente o número de peças do jogador X.
         * 
         * Essa função foi criada unicamente para possibilitar os testes de outras funções
         * da classe Reversi. Por isso, sua utilização se restringe ao diretório /tests/.
         */
        void set_num_pieces_player_X(int x);


        /**
         * @brief Define manualmente o número de peças do jogador O.
         * 
         * Essa função foi criada unicamente para possibilitar os testes de outras funções
         * da classe Reversi. Por isso, sua utilização se restringe ao diretório /tests/.
         */
        void set_num_pieces_player_O(int x);


        /**
         * @brief Retorna o tabuleiro de Reversi completo.
         * 
         * Essa função foi declarada na classe Reversi unicamente para possibilitar os testes
         * de outras funções da classe. Por isso, sua utilização se restringe ao diretório /tests/.
         */
        Board& get_game_board();


        /**
        * @brief Inicializa o tabuleiro com as peças centrais do Reversi.
        */
        void start_reversi_board();


        /**
        * @brief Verifica se há peças do jogador na direção especificada.
        * @param player_piece Tipo de peça do jogador.
        * @param direction Direção a ser verificada.
        * @param adjacent_square Posição adjacente inicial.
        * @return `true` se houver peças na direção, `false` caso contrário.
        */
        bool is_there_player_piece_at_the_direction(const char player_piece, const std::array<int, 2>& direction, 
            std::array<int, 2> adjacent_square) const;


        /**
        * @brief Verifica se há alguma direção que captura peças do oponente.
        * @param move_coordinates Coordenadas do movimento.
        * @param player_piece_type Tipo de peça do jogador.
        * @return `true` se houver direção válida, `false` caso contrário.
        */   
        bool is_there_direction_that_captures_opponent(const std::array<int, 2> &move_coordinates, char player_piece_type);
            

        /**
        * @brief Verifica se uma posição no tabuleiro está livre.
        * @param x Linha da posição.
        * @param y Coluna da posição.
        * @return `true` se a posição estiver livre, `false` caso contrário.
        */
        bool is_space_free_reversi(int x, int y) const;
            

        /**
        * @brief Verifica se uma jogada específica é válida.
        * @param move_coordinates Coordenadas do movimento.
        * @param player_piece_type Tipo de peça do jogador.
        * @return `true` se a jogada for válida, `false` caso contrário.
        */
        bool is_valid_move(std::array<int, 2>& move_coordinates, char player_piece_type);


        /**
        * @brief Verifica se há uma jogada válida para o jogador.
        * @param player_piece Tipo de peça do jogador.
        * @return `true` se houver jogada válida, `false` caso contrário.
        */  
        bool is_there_valid_move_for_player(char player_piece);
        

        /**
        * @brief Verifica se o jogo tem vencedor considerando as jogadas restantes.
        * @param is_there_move_for_player Indica se há jogadas válidas para o jogador.
        * @param opponent_piece Tipo de peça do oponente.
        * @return `true` se houver vencedor, `false` caso contrário.
        */
        bool check_win(bool is_there_move_for_player, char opponent_piece);


        /**
        * @brief Captura peças do oponente em uma direção específica.
        * @param directions Direção onde as peças serão capturadas.
        * @param move_coordinates Coordenadas do movimento.
        * @param player_piece Tipo de peça do jogador.
        */
        void flip_pieces(std::array<int, 2> directions, std::array<int, 2> move_coordinates, char player_piece);
            

        /**
        * @brief Controla o número de peças dos jogadores após uma jogada.
        * @param num_pieces_flipped Número de peças capturadas.
        * @param player_piece Tipo de peça do jogador.
        */
        void control_num_pieces_players(int num_pieces_flipped, char player_piece);
            

        /**
        * @brief Realiza a jogada do jogador atual.
        * @param move_coordinates Coordenadas do movimento.
        * @param player_piece Tipo de peça do jogador.
        * @param directions_to_capture_opponents Direções para capturar peças.
        */
        void make_move(std::array<int, 2> move_coordinates, char player_piece, std::list<std::array<int, 2>>& directions_to_capture_opponents);
        

        /**
        * @brief Encontra todas as direções válidas para capturar peças do oponente.
        * @param move_coordinates Coordenadas do movimento.
        * @param player_piece Tipo de peça do jogador.
        * @param directions_to_capture_opponents Lista de direções válidas.
        */
        void find_all_directions_to_make_move(std::array<int, 2>& move_coordinates, char player_piece, std::list<std::array<int, 2>>&directions_to_capture_opponents);
            

        /**
        * @brief Processa uma jogada e verifica sua validade.
        * @param move_coordinates Coordenadas do movimento.
        * @param player_piece_type Tipo de peça do jogador.
        * @return `true` se a jogada for válida e processada, `false` caso contrário.
        */
        bool process_move(std::array<int, 2> move_coordinates, char player_piece_type);


        /**
        * @brief Registra vitória e derrota dos jogadores.
        * @param player1 Jogador 1.
        * @param player2 Jogador 2.
        */
        void register_win_and_loss(Player *player1, Player *player2);


        /**
        * @brief Destrutor do jogo Reversi.
        */
        ~Reversi();

        /**
        * @brief Função declarada somente para fins de sobregarga.
        */
        bool is_valid_move() const override;

        /**
        * @brief Função declarada somente para fins de sobregarga.
        */
        bool check_win() override;

        /**
        * @brief Função declarada somente para fins de sobregarga.
        */
        void make_move() override;
};

#endif