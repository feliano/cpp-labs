CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS = -std=c++11 -g -Wall -pedantic

tests: all
	./iterator_test.out

all: iterator_testrunner.cpp
	g++ $(FLAGS) -o iterator_test.out  -I /usr/local/bin/cxxtestgen \iterator_testrunner.cpp

iterator_testrunner.cpp: testtree.cpp
	/usr/local/bin/cxxtestgen --error-printer -o iterator_testrunner.cpp testtree.cpp

clean:
	rm -f *.o *.out
