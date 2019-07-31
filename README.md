<a href="https://www.codefactor.io/repository/github/stanecobalt/mine-sweeper"><img src="https://www.codefactor.io/repository/github/stanecobalt/t3/badge" alt="CodeFactor" /></a>

# T3
A Tic-Tac-Toe game done console style.

This is a fun project done just to do something in C++.
The AI isn't very smart, it just selects an open space at random, so the game is fairly beatable.

<img src="img/gameplay.gif" width="50%" />

## How to Play
Make sure you have gcc installed. MinGW is a good option if you don't have gcc already.

Run the following command: `g++ -std=c++11 src/main.cpp src/t3.cpp -o t3.exe`

Alternatively, if you have cmake installed you can just run: `make all`

Then run `t3.exe` to begin playing.

After that, just type in a number 0 through 8 to select a space to place your X. 
