#include <iostream>
#include "tik_tak_toe.hpp"

Game::Game(){
	for ( int i = 0; i < GRID_SIZE; i++){
		for ( int j = 0; j < GRID_SIZE; j++){
			field[i][j] = EMPTY;
		}
	}
}

void Game::printField(){
	std::cout << "  ";
	for ( int i = 0; i < GRID_SIZE; i++) {std::cout << i << " ";}
	std::cout << '\n';
	for ( int i = 0; i < GRID_SIZE; i++){
		std::cout<< i << " ";
		for ( int j = 0; j < GRID_SIZE; j++){
			std::cout << field[i][j] << " ";
		}
		std::cout << '\n';
	}
}

bool Game::isEmpty(int row, int column){
	return field[row][column] == EMPTY;
}

bool Game::makeMove(int row, int column, Player player){
	bool moveDone = false;
	if(isEmpty(row, column)){
		field[row][column] = player;
		moveDone = true;
	}
	return moveDone;
}

int Game::getSize(){ return GRID_SIZE; }

bool Game::playerWon(Player player){
	bool result;
	

	// checking if there are three in line horizontaly
	for(int i = 0; i < GRID_SIZE; i++){

		result = true;

		for(int j = 0; j < GRID_SIZE; j++){
			if(field[i][j] != player){
				result = false;
			}
		}
		
		if(result){ return result; }

	}
	
	// checking if there are three in line verticaly
	for(int j = 0; j < GRID_SIZE; j++){
	
		result = true;

		for( int i = 0; i < GRID_SIZE; i++){
			if(field[i][j] != player){
				result = false;
			}
		}

		if(result){ return result; }
	}

	// cheking if there are three in line from top left to bottom right 
	result = true;
	for(int i = 0; i < GRID_SIZE; i++){
		if(field[i][i] != player){
			result = false;
		}
	}
	if(result){ return result; }


	// cheking if there are three in line from top right to bottom left
	result = true;
	for(int i = GRID_SIZE-1; i >= 0; i--){
		if(field[i][i] != player){
			result = false;
		}
	} 

	return result;
}

bool Game::emptySpotsLeft(){
	bool result = false;
	for(int i = 0; i < GRID_SIZE; i++){
		for ( int j = 0; j < GRID_SIZE; j++){
			if(field[i][j] == EMPTY){
				result = true;
			}
		}
	}
	return result;
}

bool Game::gameOver(){
	bool result = false;
	

	result = result || playerWon(cross);
	result = result || playerWon(circle);
	result = result || !emptySpotsLeft();
	


	return result;
}
