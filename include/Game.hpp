#ifndef GAME_H
#define GAME_H

class Game{
    private:
        int num_rows;
        int num_columns;
        char** game_board = nullptr;
    public:
        Game(int num_rows_received, int num_columns_received);
        void create_game_board();
        void print_game_board();
        ~Game();
};

#endif