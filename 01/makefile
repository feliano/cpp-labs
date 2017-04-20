CC    = g++
#CC   = clang++-3.6 -L /usr/lib/gcc/x86_64-linux-gnu/4.8 -I /usr/include/x86_64-linux-gnu/c++/4.8 -I /usr/include/c++/4.8 

FLAGS = -std=c++11 -g -Wall -pedantic


run: /usr/local/bin/cxxtestgen --error-printer -o simple_testrunner.cpp simple.cxxtest.cpp

simple_test.out: simple_testrunner.cpp count_if_followed_by.o
	$(CC) -I /usr/local/bin/cxxtestgen \simple_testrunner.cpp count_if_followed_by.o

count_if_followed_by.o: count_if_followed_by.cpp
	$(CC) $(FLAGS) -c count_if_followed_by.cpp



clean:
	rm -f *.o *.out





g++ -std=c++11 -g -Wall -I /usr/local/bin/cxxtestgen \complex_testrunner.cpp complex.o