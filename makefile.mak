CC = g++ $(CCFLAGS)

CCFLAGS = -std=c++11

all: t3

t3: main.o t3.o
	$(CC) main.o t3.o -o t3.exe

main.o: src/main.cpp include/t3.h
	$(CC) -c src/main.cpp

t3.o: src/t3.cpp include/t3.h
	$(CC) -c src/t3.cpp
