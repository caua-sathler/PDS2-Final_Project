#include "Tic_tac_toe.hpp"
#include <iostream>

int main() {
    tic_tac_toe jogo;
    int x, y;
    bool win = false;

    while (!win) {

        if(jogo.check_win(win) != 'F') {
            break;
            std::cout << "Fim" << std::endl;
        }

        std::cin >> x >> y;
        jogo.make_move(x, y);

    } 

    return 0;
}
