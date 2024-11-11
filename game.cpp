#include "tik_tak_toe.hpp"
#include <iostream>

int main(){
    std::cout << "Game started!\n";
    Game game = Game();
    Game::Player player = Game::cross;
    while(!game.gameOver()){
        game.printField();
        std::cout << "Player [" << (char)player << "] make move\n";
        int row, column;
        do{
            if(!std::cin){
                std::cin.clear();
                std::cin.ignore(40,'\n');
            }
	        std::cout << "Enter row: ";
            std::cin >> row;
            if(std::cin){
                std::cout << "Enter column: ";
                std::cin >> column;
            }
	    } while (!std::cin && row > -1 && column > -1 && row < game.getSize() && column < game.getSize());
	if(game.makeMove(row, column, player)){
            if(game.playerWon(player)){
                std::cout << "Player [" << (char)player << "] won!!!\n";
            } else if (!game.emptySpotsLeft()){
                std::cout << "Game Ended With a Draw!!!\n";
            }
            player = player == Game::cross ? Game::circle : Game::cross;
        }
    }

    std::cout << "App terminated normally\n";
}
