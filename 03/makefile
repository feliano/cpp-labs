CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS = -std=c++11 -g -Wall -pedantic

tests:
	./bintree_test.out

all: bintree.o bintree_testrunner.cpp
	g++ $(FLAGS) -o bintree_test.out  -I /usr/local/bin/cxxtestgen \bintree_testrunner.cpp bintree.o

bintree.o: bintree.cpp
	$(CC) -c $(FLAGS) bintree.cpp -o bintree.o

bintree_testrunner.cpp: testtree.cpp
	/usr/local/bin/cxxtestgen --error-printer -o bintree_testrunner.cpp testtree.cpp


clean:
	rm -f *.o *.out
