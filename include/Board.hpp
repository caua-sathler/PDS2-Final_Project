#ifndef BOARD_H
#define BOARD_H
#include <memory>

class Board {
    private:
        int num_rows;
        int num_columns;
        std::unique_ptr<std::unique_ptr<char[]>[]> game_board = nullptr;

    public:
        void set_space(int row, int column, char value); 
        char get_space(int row, int column) const;
        void set_game_board(char **board);
        Board(int num_rows_received, int num_columns_received);
        void print_game_board() const;
        bool is_move_inside_board(int x, int y) const;
        bool is_space_free(int x, int y) const;
};

#endif