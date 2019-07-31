#include "../include/t3.h"

bool t3::getGameOver() {
	return this->gameOver;
}

bool t3::getWon() {
	return this->won;
}

std::string t3::getPosition(int n) {
	return (n > 0 && n < 9) ? this->positions[n] : " ";
}

void t3::setPosition(bool isPlayer, int n) {
	this->positions[n] = (isPlayer) ? this->player : this->ai;
}

bool t3::spotTaken(int n) {
	return (this->positions[n] == player || this->positions[n] == ai);
}

void t3::printBoard() {
	std::string s(11,' ');
	for (int i = 0; i < this->size; i+=3) {
		s = " " + this->positions[i] + " | " + this->positions[i+1] + 
			" | " + this->positions[i+2] + "\n";
		std::cout << s;
		if (i <= 3)
			std::cout << "---|---|---\n";
	}
	std::cout << std::endl;
}

bool t3::isGameWon(std::string character) {
	//checks if the player or ai has won
	std::string winningPositions[8][3] = {
			{ positions[0], positions[1], positions[2] },
			{ positions[0], positions[3], positions[6] },
			{ positions[0], positions[4], positions[8] },
			{ positions[3], positions[4], positions[5] },
			{ positions[6], positions[7], positions[8] },
			{ positions[1], positions[4], positions[7] },
			{ positions[2], positions[5], positions[8] },
			{ positions[2], positions[4], positions[6] }
	};

	unsigned match3 = 0;
	for (unsigned i = 0; i < 8; i++) {
		for (unsigned j = 0; j < 3; j++) {
			if (winningPositions[i][j] == character)
				match3++;

			if (match3 >= 3) {
				this->won = (character == player);
				return true;
			}
		}
		match3 = 0;
	}
	return false;
}

bool t3::isFullBoard() {
	for (unsigned i = 0; i < size; i++)
		if (this->positions[i] == this->empty)
			return false;
	return true;
}

void t3::checkBoard() {
	// checks if the game has been won by a player or if the board is full
	this->gameOver = (isGameWon(player) || isGameWon(ai));
	if (!this->gameOver && isFullBoard()) {
		this->won = false;
		this->gameOver = true;
	}
}

void t3::makeMove() {
	int randomSpace;
	bool taken = true;
	while (taken) {
		randomSpace = (rand() % 9);
		if (positions[randomSpace] == this->empty)
			taken = false;
	}
	setPosition(false, randomSpace);
}
