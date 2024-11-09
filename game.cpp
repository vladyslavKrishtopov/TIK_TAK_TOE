#include "tik_tak_toe.hpp"
#include <iostream>

int main(){
    std::cout << "Game started!\n";
    Game game = Game();
    Player player = cross;
    while(!game.gameOver()){
        game.printField();
        std::cout << "Player [" << (char)player << "] make move\n";
        int row, column;
        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;
        if(game.makeMove(row, column, player)){
            if(game.playerWon(player)){
                std::cout << "Player [" << (char)player << "] won!!!\n";
            } else if (!game.emptySpotsLeft()){
                std::cout << "Game Ended With a Draw!!!\n";
            }
            player = player==cross ? circle : cross;
        }
    }

    std::cout << "App terminated normally\n";
}