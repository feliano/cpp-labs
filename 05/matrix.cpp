// m x n  - m rows n columns
#include "matrix.h"
#include <fstream>
	// methods

int main(){
	
	Matrix<int> mat5;
    std::ifstream myinput;
    myinput.open("matrix.txt");
    myinput >> mat5;
    myinput.close();
	
	std::cout << "mat5: " << std::endl;
	std::cout << mat5 << std::endl;

	Matrix<int> mat3 = identity<int>(3);
	Matrix<int> mat4(3,1);

	mat4(0,0) = 10;
	mat4(1,0) = 11;
	mat4(2,0) = 12;

	std::cout << "nuovo mat4: " << std::endl;
	std::cout << mat4 << std::endl;

	Matrix<int> a = {1,2,3,4,5,6,7,8,9};
	std::cout << a << std::endl;

	// mat7(2,2);
	/*
	unsigned int b = 5;
	auto a = identity<int>(b);
	std::cout << "non ancora mat6: " << std::endl;
	std::cout << a << std::endl;
	*/

	/*
	mat8-=identity<int>(3);
	std::cout << "nuovo mat8: " << std::endl;
	std::cout << mat8 << std::endl;
	*/

	return 0;
}