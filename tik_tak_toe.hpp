#ifndef GAME_H
#define GAME_H

class Game{
	private:
		const static int GRID_SIZE = 3;
		const static char EMPTY = ' ';
		const static char CROSS = 'x';
		const static char CIRCLE = 'o';
		char field[GRID_SIZE][GRID_SIZE];		

	public:

		typedef enum Player {
			cross = CROSS,
			circle = CIRCLE
		}Player;

		Game();
		void printField();
		int getSize();
		bool isEmpty(int, int);
		bool makeMove(int, int, Player);
		bool playerWon(Player);
		bool emptySpotsLeft();
		bool gameOver();
};

#endif
