CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 
FLAGS = -std=c++11 -g -Wall -pedantic

tests:
	./complex_test.out

all: complex.o complex_testrunner.cpp
	g++ $(FLAGS) -o complex_test.out  -I /usr/local/bin/cxxtestgen \complex_testrunner.cpp complex.o

complex.o: Complex.cpp
	$(CC) -c $(FLAGS) Complex.cpp -o complex.o

complex_testrunner.cpp: complex.cxxtest.cpp
	/usr/local/bin/cxxtestgen --error-printer -o complex_testrunner.cpp complex.cxxtest.cpp

clean:
	rm -f *.o *.out
