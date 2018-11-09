#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "t3.h"

#ifdef _WIN32
	void clearScreen(){
		system("CLS");
	}

#elif _APPLE_
	void clearScreen(){
		system("clear");
	}

#elif _linux_
	void clearScreen(){
		system("clear & clear");
	}

#else
	void clearScreen(){
		std::cout << "\n";
	}
	
#endif

int main(int argc, char** argv){
	srand(time(0));
	const std::string title = "\n -------------\n| Tic-Tac-Toe |\n -------------\n\n";
	int input = 0;
	t3 ticTacToe;

	while(!ticTacToe.getGameOver()){
		clearScreen();
		std::cout << title;
		ticTacToe.printBoard();
		std::cout << "Make a move by selecting a space (0-8): ";
		std::cin >> input;
		if(ticTacToe.spotTaken(input)){
			while(ticTacToe.spotTaken(input)){
				std::cout << "\nSpot taken. Try again: ";
				std::cin >> input;
			}
		}
		ticTacToe.setPosition(true, input);
		ticTacToe.checkBoard();
		if(ticTacToe.getGameOver())
			break;
		else {
			ticTacToe.makeMove();
			ticTacToe.checkBoard();
		}
	}

	clearScreen();
	std::cout << title;
	ticTacToe.printBoard();
	if(ticTacToe.getWon()){
		std::cout << "Congratulations! You won!\n";
	} else {
		std::cout << "Game Over. Try again.\n";
	}
	
	system("pause");

	return 0;
}
