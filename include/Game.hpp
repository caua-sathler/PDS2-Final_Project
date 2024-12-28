#ifndef GAME_H
#define GAME_H

class Game {
    protected:
        int num_rows;
        int num_columns;
        char** game_board = nullptr;

    public:
        Game(int num_rows_received, int num_columns_received);
        void create_game_board();
        void print_game_board() const;
        virtual bool is_valid_move() const = 0;
        virtual bool is_move_inside_board(int x, int y) const;
        virtual void make_move() = 0;
        virtual void check_win() const = 0;
        ~Game();
};

#endif