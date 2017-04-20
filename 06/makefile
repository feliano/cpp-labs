CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS = -std=c++11 -g -Wall -pedantic

tests:
	./chess_test.out

all: chess.o chess_testrunner.cpp
	g++ $(FLAGS) -o chess_test.out  -I /usr/local/bin/cxxtestgen \chess_testrunner.cpp chess.o

chess.o: chess.cpp
	$(CC) -c $(FLAGS) chess.cpp -o chess.o

chess_testrunner.cpp: chess.cxxtest.cpp
	/usr/local/bin/cxxtestgen --error-printer -o chess_testrunner.cpp chess.cxxtest.cpp

clean:
	rm -f *.o *.out
