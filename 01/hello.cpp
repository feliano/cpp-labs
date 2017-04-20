#include <iostream>

#include "hello.h"

void hello (const char * name, int count) {
	// TODO
	std::cout << "Hello,";
	for(int i = 0;i<count; ++i){	
		std::cout << " " << name;	
	}
	std::cout << "!" << std::endl;
}

std::pair<const char *, int> parse_args (int argc, char * argv[]) {

  // two few arguments
  if(argc < 2){
  	return std::make_pair("world",1);
  }
  
  // only first argument, one time
  if(argc == 2) {
  	return std::make_pair(argv[1],1);
  }

  if(argc > 3){
  	// error too many argumnents
  	std::cerr << "error: Too many arguments!" << std::endl;
  	return std::make_pair("FAIL",-1);
  }

  // check second argument to see if it's an int
  int length = 0;
  char* cnt = argv[2];
  while(*(cnt +length) != '\0'){
  	if(*(cnt + length) < '0' || *(cnt+length) > '9'){
  		// fail not an integer
  		std::cerr << "error: 2nd argument must be an integral greater than zero!" << std::endl;
  		return std::make_pair("FAIL",-1);
  	}
  	length++;
  }

  // check if second argument is zero
  if(*argv[2] == '0'){
  	return std::make_pair("fail",-1);
  }

  return std::make_pair(argv[1], atoi(argv[2]));
}
