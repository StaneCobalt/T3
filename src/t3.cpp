#include "../include/t3.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

bool t3::getGameOver() { 
	return this->gameOver; 
}

bool t3::getWon() { 
	return this->won; 
}

std::string t3::getPosition(int n){
	if(n > 0 && n < 9)
		return this->positions[n];
	return " ";
}

void t3::setPosition(bool isPlayer, int n){
	this->positions[n] = (isPlayer) ? this->player : this->ai;
}

void t3::printBoard(){
	std::string s(11,' ');
	for(int i = 0; i < this->size; i+=3){
		s = " " + this->positions[i] + " | " + this->positions[i+1] + 
			" | " + this->positions[i+2] + "\n";
		std::cout << s;
		if(i <= 3)
			std::cout << "---|---|---\n";
	}
	std::cout << std::endl;
}

void t3::checkBoard(){
	//checks if the player or ai has won
	/*	0 1 2
		3 4 5
		6 7 8 */
	if ((positions[0] == player && positions[1] == player && positions[2] == player) ||
		(positions[0] == player && positions[3] == player && positions[6] == player) ||
		(positions[0] == player && positions[4] == player && positions[8] == player) ||
		(positions[3] == player && positions[4] == player && positions[5] == player) ||
		(positions[6] == player && positions[7] == player && positions[8] == player) ||
		(positions[1] == player && positions[4] == player && positions[7] == player) ||
		(positions[2] == player && positions[5] == player && positions[8] == player) ||
		(positions[2] == player && positions[4] == player && positions[6] == player)) {	
		this->won = true;
		this->gameOver = true;
	}
	else if((positions[0] == ai && positions[1] == ai && positions[2] == ai) ||
		(positions[0] == ai && positions[3] == ai && positions[6] == ai) ||
		(positions[0] == ai && positions[4] == ai && positions[8] == ai) ||
		(positions[3] == ai && positions[4] == ai && positions[5] == ai) ||
		(positions[6] == ai && positions[7] == ai && positions[8] == ai) ||
		(positions[1] == ai && positions[4] == ai && positions[7] == ai) ||
		(positions[2] == ai && positions[5] == ai && positions[8] == ai) ||
		(positions[2] == ai && positions[4] == ai && positions[6] == ai)) {
		this->won = false;
		this->gameOver = true;
	}
	else{
		bool fullBoard = true;
		for(short i = 0; i < size; i++){
			if(this->positions[i] == this->empty)
				fullBoard = false;
		}
		if(fullBoard){
			this->won = false;
			this->gameOver = true;
		}
	}
}

void t3::makeMove(){
	int randomSpace;
	bool taken = true;
	while(taken){
		randomSpace = (rand() % 9);
		if(positions[randomSpace] == this->empty)
			taken = false;
	}
	setPosition(false, randomSpace);
}

bool t3::spotTaken(int n) {
	return this->positions[n] == player || 
			this->positions[n] == ai;
}
