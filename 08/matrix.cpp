	/*
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
	*/

// m x n  - m rows n columns
#include "matrix.h"
#include <fstream>
	// methods

int main(){

	Matrix<bool> mat5;
	
    std::ifstream myinput;
    myinput.open("matrix.txt");
    myinput >> mat5;
    myinput.close();

    std::cout << mat5 << std::endl;

    //mat5.remove_column(3);

    std::cout << "inserted:" << std::endl;
    std::cout << mat5 << std::endl;

    //mat5.reset();

	std::cout << "reset:" << std::endl;
    std::cout << mat5 << std::endl;

	std::cout << "transpose:" << std::endl;
    std::cout << mat5.transpose() << std::endl;
    mat5 = mat5.transpose();
	

	Matrix<bool> mat3(5,4);
	mat3(1,1) = true;
	mat3(1,4) = true;
	mat3(2,3) = true;

	Matrix<bool> mat4 = mat5 ^ mat3;
	std::cout << "transpose:" << std::endl;
    std::cout << mat4 << std::endl;

	Matrix<bool> mat6 = {1,0,1,1,0,0,1,0,1};
	std::cout << mat6 << std::endl;

    /*
    try{
	   	std::cin >> mat4;
	    std::cout << mat4 << std::endl;

    }catch(std::exception& e){
    	std::cout << e.what() << std::endl;
    }
	*/

    //mat3 = (std::move(mat5));


	/*
	Matrix<bool> mat(4,4);
	mat(2,2) = true;
	mat(3,3) = true;
	mat(3,3) = false;
	mat(3,3) = false;

	const Matrix<bool> mat2(3,3);
	std::cout << mat << std::endl;

	*/

	return 0;
}