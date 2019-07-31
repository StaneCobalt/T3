#ifndef T3
#define T3

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class t3 {
	private:
		static const int size = 9;
		const std::string empty = "-";
		std::string positions[size];
		std::string ai, player;
		bool gameOver, won;

	public:
		t3() {
			for (short i = 0; i < size; i++)
				positions[i] = this->empty;
			this->ai = "O";
			this->player = "X";
			this->won = false;
			this->gameOver = false;
		}
		bool getGameOver();
		bool getWon();
		std::string getPosition(int n);
		void setPosition(bool isPlayer, int n);
		void printBoard();
		bool isGameWon(std::string character);
		bool isFullBoard();
		void checkBoard();
		void makeMove();
		bool spotTaken(int n);
};

#endif
