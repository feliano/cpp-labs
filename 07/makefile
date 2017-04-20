CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS = -std=c++11 -g -Wall -pedantic

game: all
	./game.out

all: chess.o game.o
	g++ $(FLAGS) -o game.out game.o chess.o

game.o: game.cpp chess.o
	$(CC) -c $(FLAGS) game.cpp -o game.o

chess.o: chess.cpp chess.h
	$(CC) -c $(FLAGS) chess.cpp -o chess.o

clean:
	rm -f *.o *.out
