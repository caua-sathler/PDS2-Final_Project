#include "Reversi.hpp"
#include <iostream>

using namespace std;

int main() {
    Reversi reversi1;
    if(reversi1.is_valid_move(1,8,'O')==false){
        cout<<"Jogada inválida"<<endl;
    }
    
    if(reversi1.is_valid_move(2,8,'X')==false){
        cout<<"Jogada inválida"<<endl;
    }
    if(reversi1.is_valid_move(4,9,'X')==false){
        cout<<"Jogada inválida"<<endl;
    }
}