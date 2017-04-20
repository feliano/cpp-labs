#include <iostream>
#include "math.h"

int main(){

	unsigned long long int a = 10;
	uint64_t b = 11;
	std::cout << sizeof(a) << std::endl;
	std::cout << sizeof(unsigned long long int) << std::endl;
	std::cout << 100 % (sizeof(uint64_t) * 8) << std::endl;

	std::cout << ceil(100.0f / (sizeof(uint64_t) * 8)) << std::endl;



	return 0;
}