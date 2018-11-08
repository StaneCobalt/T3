#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

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

void printBoard();
void checkBoard();
void makeMove();

char positions[9] = {'-','-','-','-','-','-','-','-','-'};
char aiChar;
char playerChar;

int main(int argc, char** argv){
	srand(time(0));
	const std::string title = "\n -------------------------\n| Tic-Tac-Toe |\n -------------------------\n\n";
	bool gameOver = false;
	int input = 0;
	clearScreen();
	std::cout << title << "\n Choose X or O: ";
	std::cin >> playerChar;
	aiChar = (playerChar == 'x' || playerChar == 'X') ? 'O' : 'X';
	
	while(!gameOver){
		clearScreen();
		std::cout << title;
		printBoard();
		std::cout << "Make a move by selecting a space (1-9): ";
		std::cin >> input;
		positions[input] = playerChar;
		makeMove();
	}
	
	return 0;
}

void printBoard(){
	std::string s(11,' ');
	for(int i = 0; i < 9; i+=3){
		s = " ";
		s.append(positions[i]);
		s += " | ";
		s.append(positions[i+1]);
		s += " | ";
		s.append(positions[i+2]);

		if(i <= 3)
			std::cout << "---|---|---";
	}
	std::cout << std::endl;
}

void checkBoard(){
	//checks if the player or ai has won
}

void makeMove(){
	int randomSpace;
	bool taken = true;
	while(taken){
		randomSpace = (rand()%9);
		if(positions[randomSpace] == '-')
			taken = false;
	}
	positions[randomSpace] = aiChar;
}
