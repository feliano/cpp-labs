#include <cxxtest/TestSuite.h>
#include "matrix.h"
#include <fstream>

static int TEST_ID = 0;

class MyTestSuite : public CxxTest::TestSuite {
  public:

    void test1 () {
    	// SYNOPSIS:
    	// default constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<bool> mat;
		TS_ASSERT_EQUALS(mat.rows(),0);
        TS_ASSERT_EQUALS(mat.cols(),0);
    }

    void test2 () {
    	// SYNOPSIS:
    	// normal constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<bool> mat(3,4);
		mat(1,1) = 0;
		TS_ASSERT_EQUALS(mat(1,1),0);
		TS_ASSERT_EQUALS(mat.rows(),3);
		TS_ASSERT_EQUALS(mat.cols(),4);
    }

    void test3 () {
    	// SYNOPSIS:
    	// explicit square constructor
    	// Matrix(bool size);
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<bool> mat(3);
		mat(2,2) = 1;
		TS_ASSERT_EQUALS(mat(2,2),1);
		TS_ASSERT_EQUALS(mat.rows(),3);
		TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test4 () {
    	// SYNOPSIS:
    	// copy constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<bool> mat(3,4);

		mat(1,1) = 0;
		Matrix<bool> mat2 = mat;
		TS_ASSERT_EQUALS(mat2(1,1),0);
		TS_ASSERT_EQUALS(mat2.rows(),3);
		TS_ASSERT_EQUALS(mat2.cols(),4);
    }

    void test5 () {
    	// SYNOPSIS:
    	// copy constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<bool> mat(3,4);
		mat(1,1) = 0;
		Matrix<bool> mat2 = mat;
		TS_ASSERT_EQUALS(mat2(1,1),0);
		TS_ASSERT_EQUALS(mat2.rows(),3);
		TS_ASSERT_EQUALS(mat2.cols(),4);
    }

    void test6 () {
    	// SYNOPSIS:
    	// init list construction
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<bool> mat = {1,0,1,0,1,0,1,0,1};
		TS_ASSERT_EQUALS(mat(1,1),1);
		TS_ASSERT_EQUALS(mat.rows(),3);
		TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test7 () {
    	// SYNOPSIS:
    	// move constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<bool> mat = {1,0,1,0,1,0,1,0,1};
		Matrix<bool> mat2(std::move(mat));
		TS_ASSERT_EQUALS(mat2(1,1),1);
		TS_ASSERT_EQUALS(mat2.rows(),3);
		TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test8 () {
        // SYNOPSIS:
        // move assignment operator
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {1,0,1,0,1,0,1,0,1};
        Matrix<bool> mat2;
        mat2 = std::move(mat);
        TS_ASSERT_EQUALS(mat2(1,1),1);
        TS_ASSERT_EQUALS(mat2.rows(),3);
        TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test9 () {
        // SYNOPSIS:
        // copy assignment operator
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {1,0,1,0,1,0,1,0,1};
        Matrix<bool> mat2;
        mat2 = mat;
        TS_ASSERT_EQUALS(mat2(1,1),1);
        TS_ASSERT_EQUALS(mat2.rows(),3);
        TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test10 () {
        // SYNOPSIS:
        // operator()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {1,0,1,0,1,0,1,0,1};
        TS_ASSERT_EQUALS(mat(2,2),1);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test11 () {
        // SYNOPSIS:
        // operator+=
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {1,0,1,0,1,0,1,0,1};
        Matrix<bool> mat2 = {1,0,1,0,1,0,1,0,1};
        mat &= mat2;

        TS_ASSERT_EQUALS(mat(2,2),1);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);


        Matrix<bool> mat3 = {1,1,0,0};

        try{
            mat&=mat3;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown: " << e.what() << std::endl;
        }

    }

    void test12 () {
        // SYNOPSIS:
        // operator^=  xor
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {1,0,1,0,1,0,1,0,1};
        Matrix<bool> mat2 = {1,1,1,1,1,1,1,0,1};
        std::cout <<" checkpoint 1" << std::endl;

        mat ^= mat2;

        std::cout << "OPERATOR OUT: " << mat(0,0) << std::endl;
        TS_ASSERT_EQUALS(mat(0,0),0);
        TS_ASSERT_EQUALS(mat(1,0),1);
        TS_ASSERT_EQUALS(mat(2,0),0);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);

        Matrix<bool> mat3 = {1,1,1,1};
        try{
            mat^=mat3;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }


    void test13 () {
        // SYNOPSIS:
        // operator|=   or
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {0,0,1,1,0,0,1,0,1};
        Matrix<bool> mat2 = {1,1,0,0,0,1,0,0,1};
        mat |= mat2;

        std::cout << "OPEARAOR OUT: " << mat(0,0) << std::endl;
        TS_ASSERT_EQUALS(mat(0,0),1);
        TS_ASSERT_EQUALS(mat(1,1),0);
        TS_ASSERT_EQUALS(mat(2,2),1);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);

        Matrix<bool> mat3 = {1,1,0,1};        
        try{
            mat |=mat3;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }

    void test14 () {
        // SYNOPSIS:
        // operator&
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat  = {0,0,1,0,1,0,1,0,1};
        Matrix<bool> mat2 = {1,1,0,0,1,1,1,0,1};
        Matrix<bool> mat3 = mat & mat2;

        TS_ASSERT_EQUALS(mat3(0,0),0);
        TS_ASSERT_EQUALS(mat3(1,1),1);
        TS_ASSERT_EQUALS(mat3(2,2),1);
        TS_ASSERT_EQUALS(mat3.rows(),3);
        TS_ASSERT_EQUALS(mat3.cols(),3);
      
        Matrix<bool> mat4 = {0,1,0,0};

        try{
            mat3 & mat4;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }

    void test15 () {
        // SYNOPSIS:
        // operator*
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat  = {0,0,1,0,1,0,1,0,1};
        Matrix<bool> mat2 = {1,1,0,0,1,1,1,0,1};
        Matrix<bool> mat3 = mat ^ mat2;

        TS_ASSERT_EQUALS(mat3(0,0),1);
        TS_ASSERT_EQUALS(mat3(1,1),0);
        TS_ASSERT_EQUALS(mat3(2,2),0);
        TS_ASSERT_EQUALS(mat3.rows(),3);
        TS_ASSERT_EQUALS(mat3.cols(),3);
      
        Matrix<bool> mat4 = {0,0,1,1};

        try{
            mat3 ^ mat4;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }

    void test16 () {
        // SYNOPSIS:
        // operator|
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat  = {0,0,1,1,0,0,1,0,1};
        Matrix<bool> mat2 = {1,1,0,1,0,1,1,0,1};
        Matrix<bool> mat3 = mat | mat2;

        TS_ASSERT_EQUALS(mat3(0,0),1);
        TS_ASSERT_EQUALS(mat3(1,1),0);
        TS_ASSERT_EQUALS(mat3(2,2),1);
        TS_ASSERT_EQUALS(mat3.rows(),3);
        TS_ASSERT_EQUALS(mat3.cols(),3);
      
        Matrix<bool> mat4 = {1,1,1,0};

        try{
            mat3 | mat4;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }

    void test17 () {
        // SYNOPSIS:
        // reset()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {0,0,1,1,1,0,1,0,1};
        mat.reset();

        TS_ASSERT_EQUALS(mat(0,0),0);
        TS_ASSERT_EQUALS(mat(1,1),0);
        TS_ASSERT_EQUALS(mat(2,2),0);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test18 () {
        // SYNOPSIS:
        // transpose()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 0;
        mat(1,0) = 1;
        mat(1,1) = 0;
        mat(2,0) = 1;
        mat(2,1) = 0;
        
        Matrix<bool> mat2 = mat.transpose();

        TS_ASSERT_EQUALS(mat2(0,0),1);
        TS_ASSERT_EQUALS(mat2(0,1),1);
        TS_ASSERT_EQUALS(mat2(0,2),1);
        TS_ASSERT_EQUALS(mat2(1,0),0);
        TS_ASSERT_EQUALS(mat2(1,1),0);
        TS_ASSERT_EQUALS(mat2(1,2),0);
        TS_ASSERT_EQUALS(mat2.rows(),2);
        TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test19 () {
        // SYNOPSIS:
        // insert_row()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 0;
        mat(1,0) = 1;
        mat(1,1) = 0;
        mat(2,0) = 1;
        mat(2,1) = 0;
        
        mat.insert_row(1);
        TS_ASSERT_EQUALS(mat(1,0),0);
        TS_ASSERT_EQUALS(mat(1,1),0);
        TS_ASSERT_EQUALS(mat(2,0),1);
        TS_ASSERT_EQUALS(mat(2,1),0);
        TS_ASSERT_EQUALS(mat.rows(),4);
        TS_ASSERT_EQUALS(mat.cols(),2);
    }

    void test20 () {
        // SYNOPSIS:
        // append_row()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 0;
        mat(1,0) = 1;
        mat(1,1) = 0;
        mat(2,0) = 1;
        mat(2,1) = 0;
        
        mat.append_row(1);
        TS_ASSERT_EQUALS(mat(2,0),0);
        TS_ASSERT_EQUALS(mat(2,1),0);
        TS_ASSERT_EQUALS(mat.rows(),4);
        TS_ASSERT_EQUALS(mat.cols(),2);
    }


    void test21 () {
        // SYNOPSIS:
        // remove_row()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 0;
        mat(1,0) = 1;
        mat(1,1) = 0;
        mat(2,0) = 1;
        mat(2,1) = 0;
        
        mat.remove_row(1);
        TS_ASSERT_EQUALS(mat(1,0),1);
        TS_ASSERT_EQUALS(mat(1,1),0);
        TS_ASSERT_EQUALS(mat.rows(),2);
        TS_ASSERT_EQUALS(mat.cols(),2);
    }

    void test22 () {
        // SYNOPSIS:
        // insert_column()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 0;
        mat(1,0) = 1;
        mat(1,1) = 0;
        mat(2,0) = 1;
        mat(2,1) = 0;
        
        mat.insert_column(1);
        TS_ASSERT_EQUALS(mat(0,1),0);
        TS_ASSERT_EQUALS(mat(1,1),0);
        TS_ASSERT_EQUALS(mat(2,1),0);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test23 () {
        // SYNOPSIS:
        // append_column()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 0;
        mat(1,0) = 1;
        mat(1,1) = 0;
        mat(2,0) = 1;
        mat(2,1) = 0;

        mat.append_column(1);
        TS_ASSERT_EQUALS(mat(0,2),0);
        TS_ASSERT_EQUALS(mat(1,2),0);
        TS_ASSERT_EQUALS(mat(2,2),0);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test24 () {
        // SYNOPSIS:
        // remove_column()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 0;
        mat(1,0) = 1;
        mat(1,1) = 0;
        mat(2,0) = 1;
        mat(2,1) = 0;
        
        std::cout << "innan: \n" << mat << std::endl;

        mat.remove_column(1);
        TS_ASSERT_EQUALS(mat(0,0),1);
        TS_ASSERT_EQUALS(mat(1,0),1);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),1);
    }

    void test25 () {
        // SYNOPSIS:
        // identity()
        // Matrix

        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        
        
        Matrix<bool> mat = identity<bool>(3);

        TS_ASSERT_EQUALS(mat(0,0),1);
        TS_ASSERT_EQUALS(mat(0,1),0);
        TS_ASSERT_EQUALS(mat(0,2),0);
        TS_ASSERT_EQUALS(mat(1,0),0);
        TS_ASSERT_EQUALS(mat(1,1),1);
        TS_ASSERT_EQUALS(mat(1,2),0);
        TS_ASSERT_EQUALS(mat(2,0),0);
        TS_ASSERT_EQUALS(mat(2,1),0);
        TS_ASSERT_EQUALS(mat(2,2),1);

        std::cout << mat << std::endl;

        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);


    }

    void test26 () {
        // SYNOPSIS:
        // friend std::ifstream& operator>> (std::ifstream& in, Matrix<T>& mat)
        // input from file
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        
        Matrix<bool> mat;
        std::ifstream myinput;
        myinput.open("matrix.txt");
        myinput >> mat;
        myinput.close();

        std::cout << mat << std::endl;

        TS_ASSERT_EQUALS(mat(0,0),0);
        TS_ASSERT_EQUALS(mat(0,1),0);
        TS_ASSERT_EQUALS(mat(0,2),0);
        TS_ASSERT_EQUALS(mat(0,3),0);
        TS_ASSERT_EQUALS(mat(1,0),1);
        TS_ASSERT_EQUALS(mat(1,1),0);
        TS_ASSERT_EQUALS(mat(1,2),0);
        TS_ASSERT_EQUALS(mat(1,3),0);
        TS_ASSERT_EQUALS(mat(2,0),1);
        TS_ASSERT_EQUALS(mat(2,1),0);
        TS_ASSERT_EQUALS(mat(2,2),0);
        TS_ASSERT_EQUALS(mat(2,3),1);

        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),4);

        try{
            Matrix<bool> mat2;
            std::ifstream myinput2;
            myinput2.open("matrix2.txt");
            myinput2 >> mat2;
            myinput2.close();
            TS_FAIL("Should throw parse error");
        }catch(std::exception& e){
            std::cout << "correctly thrown exception: " << e.what() << std::endl;
        }


    }

    void test27 () {
        // SYNOPSIS:
        // friend std::istream& operator>> (std::istream& in, Matrix<T>& mat){
        // normal input
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat;
        std::string str = "101;010;";
        std::istringstream iss (str);
        iss >> mat;

        std::cout << mat << std::endl;

        TS_ASSERT_EQUALS(mat(0,0),1);
        TS_ASSERT_EQUALS(mat(0,1),0);
        TS_ASSERT_EQUALS(mat(0,2),1);
        TS_ASSERT_EQUALS(mat(1,0),0);
        TS_ASSERT_EQUALS(mat(1,1),1);
        TS_ASSERT_EQUALS(mat(1,2),0);

        TS_ASSERT_EQUALS(mat.rows(),2);
        TS_ASSERT_EQUALS(mat.cols(),3);

        try{
            Matrix<bool> mat2;
            std::string str2 = "125 320 51owg2; 7g50 333 200";
            std::istringstream iss2 (str2);            
            iss2 >> mat2;
            TS_FAIL("SHOULD throw parse error");
        }catch(std::exception& e){
            std::cout << "correctly thrown parse exception: " << e.what() << std::endl;
        }

    }

    void test28 () {
        // SYNOPSIS:
        // ostringstream
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {0,0,1,0,1,0,1,0,1};
        std::ostringstream s;
        s << mat;

        std::cout << mat(2,2) << std::endl;

        TS_ASSERT_EQUALS(s.str(),"0 0 1 \n0 1 0 \n1 0 1 ");

    }

    void test29 () {
        // SYNOPSIS:
        // ostringstream
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<bool> mat = {0,0,1,0,1,0,1,1,1};
        std::ostringstream s;
        s << mat;

        TS_ASSERT_EQUALS(s.str(),"0 0 1 \n0 1 0 \n1 1 1 ");
    }




};