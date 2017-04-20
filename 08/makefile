CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS = -std=c++11 -g -Wall -pedantic

tests: all
	./matrix_test.out

all: matrix_testrunner.cpp
	g++ $(FLAGS) -o matrix_test.out  -I /usr/local/bin/cxxtestgen \matrix_testrunner.cpp

matrix_testrunner.cpp: testmatrix.cpp matrix.h
	/usr/local/bin/cxxtestgen --error-printer -o matrix_testrunner.cpp testmatrix.cpp


clean:
	rm -f *.o *.out
