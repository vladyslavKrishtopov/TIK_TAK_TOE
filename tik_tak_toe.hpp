#ifndef GAME_H
#define GAME_H
#define GRID_SIZE 3
#define EMPTY ' '
#define CROSS 'x'
#define CIRCLE 'o'

typedef enum Player {
			cross = CROSS,
			circle = CIRCLE
		}Player;

class Game{
	private:
		char field[GRID_SIZE][GRID_SIZE];		

	public:
		Game();
		void printField();
		bool isEmpty(int, int);
		bool makeMove(int, int, Player);
		bool playerWon(Player);
		bool emptySpotsLeft();
		bool gameOver();
};

#endif
