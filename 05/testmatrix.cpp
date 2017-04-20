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
		Matrix<int> mat;
		TS_ASSERT_EQUALS(mat.rows(),0);
        TS_ASSERT_EQUALS(mat.cols(),0);
    }

    void test2 () {
    	// SYNOPSIS:
    	// normal constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<int> mat(3,4);
		mat(1,1) = 10;
		TS_ASSERT_EQUALS(mat(1,1),10);
		TS_ASSERT_EQUALS(mat.rows(),3);
		TS_ASSERT_EQUALS(mat.cols(),4);
    }

    void test3 () {
    	// SYNOPSIS:
    	// explicit square constructor
    	// Matrix(int size);
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<int> mat(3);
		mat(2,2) = 11;
		TS_ASSERT_EQUALS(mat(2,2),11);
		TS_ASSERT_EQUALS(mat.rows(),3);
		TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test4 () {
    	// SYNOPSIS:
    	// copy constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<int> mat(3,4);
		mat(1,1) = 10;
		Matrix<int> mat2 = mat;
		TS_ASSERT_EQUALS(mat2(1,1),10);
		TS_ASSERT_EQUALS(mat2.rows(),3);
		TS_ASSERT_EQUALS(mat2.cols(),4);
    }

    void test5 () {
    	// SYNOPSIS:
    	// copy constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<int> mat(3,4);
		mat(1,1) = 10;
		Matrix<int> mat2 = mat;
		TS_ASSERT_EQUALS(mat2(1,1),10);
		TS_ASSERT_EQUALS(mat2.rows(),3);
		TS_ASSERT_EQUALS(mat2.cols(),4);
    }

    void test6 () {
    	// SYNOPSIS:
    	// init list construction
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<int> mat = {1,2,3,4,5,6,7,8,9};
		TS_ASSERT_EQUALS(mat(1,1),5);
		TS_ASSERT_EQUALS(mat.rows(),3);
		TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test7 () {
    	// SYNOPSIS:
    	// move constructor
    	// Matrix
    	std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
		Matrix<int> mat = {1,2,3,4,5,6,7,8,9};
		Matrix<int> mat2(std::move(mat));
		TS_ASSERT_EQUALS(mat2(1,1),5);
		TS_ASSERT_EQUALS(mat2.rows(),3);
		TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test8 () {
        // SYNOPSIS:
        // move assignment operator
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {1,2,3,4,5,6,7,8,9};
        Matrix<int> mat2;
        mat2 = std::move(mat);
        TS_ASSERT_EQUALS(mat2(1,1),5);
        TS_ASSERT_EQUALS(mat2.rows(),3);
        TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test9 () {
        // SYNOPSIS:
        // copy assignment operator
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {1,2,3,4,5,6,7,8,9};
        Matrix<int> mat2;
        mat2 = mat;
        TS_ASSERT_EQUALS(mat2(1,1),5);
        TS_ASSERT_EQUALS(mat2.rows(),3);
        TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test10 () {
        // SYNOPSIS:
        // operator()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {1,2,3,4,5,6,7,8,9};
        TS_ASSERT_EQUALS(mat(2,2),9);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test11 () {
        // SYNOPSIS:
        // operator+=
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {1,2,3,4,5,6,7,8,9};
        Matrix<int> mat2 = {1,2,3,4,5,6,7,8,9};
        mat += mat2;

        TS_ASSERT_EQUALS(mat(2,2),18);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);


        Matrix<int> mat3 = {1,2,3,4};

        try{
            mat+=mat3;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown: " << e.what() << std::endl;
        }

    }

    void test12 () {
        // SYNOPSIS:
        // operator*=
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {1,2,3,4,5,6,7,8,9};
        Matrix<int> mat2 = {1,2,3,4,5,6,7,8,9};
        mat *= mat2;

        std::cout << "OPEARAOR OUT: " << mat(0,0) << std::endl;
        TS_ASSERT_EQUALS(mat(0,0),30);
        TS_ASSERT_EQUALS(mat(1,1),81);
        TS_ASSERT_EQUALS(mat(2,2),150);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);

        Matrix<int> mat3 = {1,2,3,4};
        try{
            mat*=mat3;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }

    void test13 () {
        // SYNOPSIS:
        // operator-=
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {10,12,13,14,15,16,17,18,19};
        Matrix<int> mat2 = {3,3,4,6,7,9,10,8,9};
        mat -= mat2;

        std::cout << "OPEARAOR OUT: " << mat(0,0) << std::endl;
        TS_ASSERT_EQUALS(mat(0,0),7);
        TS_ASSERT_EQUALS(mat(1,1),8);
        TS_ASSERT_EQUALS(mat(2,2),10);
        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);

        Matrix<int> mat3 = {1,2,3,4};        
        try{
            mat -=mat3;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }

    void test14 () {
        // SYNOPSIS:
        // operator+
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {10,12,13,14,15,16,17,18,19};
        Matrix<int> mat2 = {3,3,4,6,7,9,10,8,9};
        Matrix<int> mat3 = mat + mat2;

        TS_ASSERT_EQUALS(mat3(0,0),13);
        TS_ASSERT_EQUALS(mat3(1,1),22);
        TS_ASSERT_EQUALS(mat3(2,2),28);
        TS_ASSERT_EQUALS(mat3.rows(),3);
        TS_ASSERT_EQUALS(mat3.cols(),3);
      
        Matrix<int> mat4 = {3,3,4,6};

        try{
            mat3 + mat4;
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
        Matrix<int> mat = {10,12,13,14,15,16,17,18,19};
        Matrix<int> mat2 = {3,3,4,6,7,9,10,8,9};
        Matrix<int> mat3 = mat * mat2;

        TS_ASSERT_EQUALS(mat3(0,0),232);
        TS_ASSERT_EQUALS(mat3(1,1),275);
        TS_ASSERT_EQUALS(mat3(2,2),401);
        TS_ASSERT_EQUALS(mat3.rows(),3);
        TS_ASSERT_EQUALS(mat3.cols(),3);
      
        Matrix<int> mat4 = {3,3,4,6};

        try{
            mat3 * mat4;
            TS_FAIL("Should throw dimension mismatch exception");
        }catch(std::exception& e){
            std::cout << "Correctly thrown " << e.what() << std::endl;
        }
    }

    void test16 () {
        // SYNOPSIS:
        // operator-
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {10,12,13,14,15,16,17,18,19};
        Matrix<int> mat2 = {3,3,4,6,7,9,10,8,9};
        Matrix<int> mat3 = mat - mat2;

        TS_ASSERT_EQUALS(mat3(0,0),7);
        TS_ASSERT_EQUALS(mat3(1,1),8);
        TS_ASSERT_EQUALS(mat3(2,2),10);
        TS_ASSERT_EQUALS(mat3.rows(),3);
        TS_ASSERT_EQUALS(mat3.cols(),3);
      
        Matrix<int> mat4 = {3,3,4,6};

        try{
            mat3 - mat4;
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
        Matrix<int> mat = {10,12,13,14,15,16,17,18,19};
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
        Matrix<int> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 2;
        mat(1,0) = 3;
        mat(1,1) = 4;
        mat(2,0) = 5;
        mat(2,1) = 6;
        
        Matrix<int> mat2 = mat.transpose();

        TS_ASSERT_EQUALS(mat2(0,0),1);
        TS_ASSERT_EQUALS(mat2(0,1),3);
        TS_ASSERT_EQUALS(mat2(0,2),5);
        TS_ASSERT_EQUALS(mat2(1,0),2);
        TS_ASSERT_EQUALS(mat2(1,1),4);
        TS_ASSERT_EQUALS(mat2(1,2),6);
        TS_ASSERT_EQUALS(mat2.rows(),2);
        TS_ASSERT_EQUALS(mat2.cols(),3);
    }

    void test19 () {
        // SYNOPSIS:
        // insert_row()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 2;
        mat(1,0) = 3;
        mat(1,1) = 4;
        mat(2,0) = 5;
        mat(2,1) = 6;
        
        mat.insert_row(1);
        TS_ASSERT_EQUALS(mat(1,0),0);
        TS_ASSERT_EQUALS(mat(1,1),0);
        TS_ASSERT_EQUALS(mat(2,0),3);
        TS_ASSERT_EQUALS(mat(2,1),4);
        TS_ASSERT_EQUALS(mat.rows(),4);
        TS_ASSERT_EQUALS(mat.cols(),2);
    }

    void test20 () {
        // SYNOPSIS:
        // append_row()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 2;
        mat(1,0) = 3;
        mat(1,1) = 4;
        mat(2,0) = 5;
        mat(2,1) = 6;
        
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
        Matrix<int> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 2;
        mat(1,0) = 3;
        mat(1,1) = 4;
        mat(2,0) = 5;
        mat(2,1) = 6;
        
        mat.remove_row(1);
        TS_ASSERT_EQUALS(mat(1,0),5);
        TS_ASSERT_EQUALS(mat(1,1),6);
        TS_ASSERT_EQUALS(mat.rows(),2);
        TS_ASSERT_EQUALS(mat.cols(),2);
    }

    void test22 () {
        // SYNOPSIS:
        // insert_column()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 2;
        mat(1,0) = 3;
        mat(1,1) = 4;
        mat(2,0) = 5;
        mat(2,1) = 6;
        
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
        Matrix<int> mat(3,2);
        mat(0,0) = 1;
        mat(0,1) = 2;
        mat(1,0) = 3;
        mat(1,1) = 4;
        mat(2,0) = 5;
        mat(2,1) = 6;
        
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
        Matrix<int> mat(2,3);
        mat(0,0) = 1;
        mat(0,1) = 2;
        mat(0,2) = 3;
        mat(1,0) = 4;
        mat(1,1) = 5;
        mat(1,2) = 6;
        
        mat.remove_column(1);
        TS_ASSERT_EQUALS(mat(0,1),3);
        TS_ASSERT_EQUALS(mat(1,1),6);
        TS_ASSERT_EQUALS(mat.rows(),2);
        TS_ASSERT_EQUALS(mat.cols(),2);
    }

    void test25 () {
        // SYNOPSIS:
        // identity()
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = identity<int>(3);

        TS_ASSERT_EQUALS(mat(0,0),1);
        TS_ASSERT_EQUALS(mat(0,1),0);
        TS_ASSERT_EQUALS(mat(0,2),0);
        TS_ASSERT_EQUALS(mat(1,0),0);
        TS_ASSERT_EQUALS(mat(1,1),1);
        TS_ASSERT_EQUALS(mat(1,2),0);
        TS_ASSERT_EQUALS(mat(2,0),0);
        TS_ASSERT_EQUALS(mat(2,1),0);
        TS_ASSERT_EQUALS(mat(2,2),1);

        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),3);
    }

    void test26 () {
        // SYNOPSIS:
        // friend std::ifstream& operator>> (std::ifstream& in, Matrix<T>& mat)
        // input from file
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        

        Matrix<int> mat;
        std::ifstream myinput;
        myinput.open("matrix.txt");
        myinput >> mat;
        myinput.close();

        std::cout << mat << std::endl;

        TS_ASSERT_EQUALS(mat(0,0),1);
        TS_ASSERT_EQUALS(mat(0,1),2);
        TS_ASSERT_EQUALS(mat(0,2),3);
        TS_ASSERT_EQUALS(mat(0,3),4);
        TS_ASSERT_EQUALS(mat(1,0),5);
        TS_ASSERT_EQUALS(mat(1,1),6);
        TS_ASSERT_EQUALS(mat(1,2),7);
        TS_ASSERT_EQUALS(mat(1,3),8);
        TS_ASSERT_EQUALS(mat(2,0),9);
        TS_ASSERT_EQUALS(mat(2,1),10);
        TS_ASSERT_EQUALS(mat(2,2),11);
        TS_ASSERT_EQUALS(mat(2,3),12);

        TS_ASSERT_EQUALS(mat.rows(),3);
        TS_ASSERT_EQUALS(mat.cols(),4);

        try{
            Matrix<int> mat2;
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
        Matrix<int> mat;
        std::string str = "125 320 512; 750 333 200";
        std::istringstream iss (str);
        iss >> mat;
        std::cout << mat << std::endl;

        TS_ASSERT_EQUALS(mat(0,0),125);
        TS_ASSERT_EQUALS(mat(0,1),320);
        TS_ASSERT_EQUALS(mat(0,2),512);
        TS_ASSERT_EQUALS(mat(1,0),750);
        TS_ASSERT_EQUALS(mat(1,1),333);
        TS_ASSERT_EQUALS(mat(1,2),200);

        TS_ASSERT_EQUALS(mat.rows(),2);
        TS_ASSERT_EQUALS(mat.cols(),3);
        
        try{
            Matrix<int> mat2;
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
        Matrix<int> mat = {10,12,13,14,15,16,17,18,19};
        std::ostringstream s;
        s << mat;

        TS_ASSERT_EQUALS(s.str(),"  10  12  13\n  14  15  16\n  17  18  19\n");

    }

    void test29 () {
        // SYNOPSIS:
        // ostringstream
        // Matrix
        std::cout << "\n<<" << " TEST: " << ++TEST_ID << " >>" << std::endl;
        Matrix<int> mat = {10,12,13,14,15,16,17,18,19};
        std::ostringstream s;
        s << mat;

        TS_ASSERT_EQUALS(s.str(),"  10  12  13\n  14  15  16\n  17  18  19\n");

    }





};