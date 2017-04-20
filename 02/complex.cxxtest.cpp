#pragma once
#include <cxxtest/TestSuite.h>
#include "Complex.h"

static int TEST_NUMBER = 0;

using namespace myLib;


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      // SYNOPSIS:
      //   COMPLEX ADDITION
      //   REAL PART SHOULD BE 4 AND IMAG 6

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      double const real = 2;
      double const imag = 3;

      Complex c(real,imag);
      Complex d(real,imag);
      Complex e(-real+1,-imag+1);

      Complex res = c + d + e;

      //Complex res2 = Complex(1.0,3.0);
      Complex res2;
      res2 = Complex(1.0,3.0);

      TS_ASSERT_EQUALS(res.real(), 3);
      TS_ASSERT_EQUALS(res.imag(), 4);
    }

    void test2 () {
      // SYNOPSIS:
      //   COMPLEX SUBTRACTION
      //   REAL PART SHOULD BE 1.0 AND IMAG 2.0

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex c(2.0);
      Complex d(1.0,1.0);
      Complex e(2.0,3.0);

      Complex res = c - d - e;

      TS_ASSERT_EQUALS(res.real(), -1.0);
      TS_ASSERT_EQUALS(res.imag(), -4.0);
    }

    void test3 () {

      // SYNOPSIS:
      //   COMPLEX MULTIPLICATION + Copy constructor
      //   REAL PART SHOULD BE -7.0 AND IMAG 22.0

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex c(2.0,3.0);
      Complex d(4.0,5.0);

      Complex e = d;
      Complex res = c * e;
    
      TS_ASSERT_EQUALS(res.real(), -7.0);
      TS_ASSERT_EQUALS(res.imag(), 22.0);
    }

    void test4 () {

      // SYNOPSIS:
      //   COMPLEX DIVISION
      //   REAL PART SHOULD BE 1.0 AND IMAG 1.0

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex c(4.0,2.0);
      Complex d(3.0,-1.0);

      Complex res = c / d;

      TS_ASSERT_EQUALS(res.real(), 1.0);
      TS_ASSERT_EQUALS(res.imag(), 1.0);
    }

    void test5 () {
      // SYNOPSIS:
      // Default Constructor

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex x;

      TS_ASSERT_EQUALS(x.real(), 0.0);
      TS_ASSERT_EQUALS(x.imag(), 0.0);
    }

    void test6 () {
      // SYNOPSIS:
      // addition of complex and normal number
      // + user defined literal _i

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex c = 2 + 5.0_i;

      TS_ASSERT_EQUALS(c.real(), 2.0);
      TS_ASSERT_EQUALS(c.imag(), 5.0);
    }

    void test7 () {
      // SYNOPSIS:
      // Testing operators -= and user defined literals _i

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex c = 3 + 5.0_i;

      c -= 5 + 1.0_i * Complex(5,3); // 5i - 3 // 2+5i

      TS_ASSERT_EQUALS(c.real(), 1.0);
      TS_ASSERT_EQUALS(c.imag(), 0.0);
    }

    void test8 () {
      // SYNOPSIS
      // Testing print of Complex objects, output stream

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      std::ostringstream stream;
      stream << Complex(6,6) / 6;
      std::string str = stream.str();
      const char* output2 = str.c_str();

      const char output[] = "(1,1)";

      TS_ASSERT_SAME_DATA(output,output2,6);
    }

    void test9 () {
      // SYNOPSIS
      // Testing input of Complex objects, input stream

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;


      // ERROR CASES - THESE SHOULD NOT WORK
      
      // empty string
      try{
        Complex x;
        std::istringstream stream("");
        stream >> x;
        TS_FAIL("Empty string should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // input non numerical character - throws exception
      try{
        Complex x;
        std::istringstream stream("1a");
        stream >> x;
        TS_FAIL("'a' as input should throw exception!");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // only minus sign in string
      try{
        Complex x;
        std::istringstream stream("-");
        stream >> x;
        TS_FAIL("only '-' as input should throw exception!");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // '(' should be first character
      try{
        Complex x;
        std::istringstream stream("1(1,2)");
        stream >> x;
        TS_FAIL("First char is not '(' - should throw exception!");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // ')' should be last character
      try{
        Complex x;
        std::istringstream stream("(1,2)1");
        stream >> x;
        TS_FAIL("Last char is not ')' - should throw exception!");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // double opening parentheses
      try{
        Complex x;
        std::istringstream stream("((1,2)");
        stream >> x;
        TS_FAIL("Too many '(' should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // double closing parentheses
      try{
        Complex x;
        std::istringstream stream("(1,2))");
        stream >> x;
        TS_FAIL("Too many ')' should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // double comma
      try{
        Complex x;
        std::istringstream stream("(1,,2)");
        stream >> x;
        TS_FAIL("Too many ',' should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // - sign in real part
      try{
        Complex x;
        std::istringstream stream("(-,2)");
        stream >> x;
        TS_FAIL("Only '-' in real part - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // - sign in imag part
      try{
        Complex x;
        std::istringstream stream("(1,-)");
        stream >> x;
        TS_FAIL("Only '-' in imag part - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // empty string in real part
      try{
        Complex x;
        std::istringstream stream("(,1)");
        stream >> x;
        TS_FAIL("Empty string in real part - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // empty string in imag part
      try{
        Complex x;
        std::istringstream stream("(2,)");
        stream >> x;
        TS_FAIL("Empty string in imag part - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // bad string in real part
      try{
        Complex x;
        std::istringstream stream("(ab,2.0)");
        stream >> x;
        TS_FAIL("string not numerical in real part - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // bad string in real part
      try{
        Complex x;
        std::istringstream stream("(ab,2.0)");
        stream >> x;
        TS_FAIL("string not numerical in real part - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // bad string in imag part
      try{
        Complex x;
        std::istringstream stream("(2.0,ab)");
        stream >> x;
        TS_FAIL("string not numerical in imag part - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // missing comma
      try{
        Complex x;
        std::istringstream stream("(2.0 3.0)");
        stream >> x;
        TS_FAIL("Missing comma remaining string not numerical - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // missing opening parenthesis
      try{
        Complex x;
        std::istringstream stream("3,3)");
        stream >> x;
        TS_FAIL("Missing opening parenthesis remaining string not numerical - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // missing closing parenthesis
      try{
        Complex x;
        std::istringstream stream("(3,3");
        stream >> x;
        TS_FAIL("Missing closing parenthesis remaining string not numerical - should throw exception");
      }catch(std::exception& e){
        std::cout << "Correctly thrown exception: " << e.what() << std::endl;
      }

      // CORRECT CASES - THESE SHOULD WORK
      // 'real' '(real,imag)'
      try{
        Complex x;
        std::istringstream stream("1");
        stream >> x;
        TS_ASSERT_EQUALS(x.real(),1);
        TS_ASSERT_EQUALS(x.imag(),0);
      }catch(std::exception& e){
        TS_FAIL("Exception should not have been thrown");
      }

      try{
        Complex x;
        std::istringstream stream("1.25");
        stream >> x;
        TS_ASSERT_EQUALS(x.real(),1.25);
        TS_ASSERT_EQUALS(x.imag(),0);
      }catch(std::exception& e){
        TS_FAIL("Exception should not have been thrown");
      }

      try{
        Complex x;
        std::istringstream stream("(17,3)");
        stream >> x;
        TS_ASSERT_EQUALS(x.real(),17);
        TS_ASSERT_EQUALS(x.imag(),3);
      }catch(std::exception& e){
        TS_FAIL("Exception should not have been thrown");
      }

      try{
        Complex x;
        std::istringstream stream("(1,1.25)");
        stream >> x;
        TS_ASSERT_EQUALS(x.real(),1);
        TS_ASSERT_EQUALS(x.imag(),1.25);
      }catch(std::exception& e){
        TS_FAIL("Exception should not have been thrown");
      }

      try{
        Complex x;
        std::istringstream stream("(10.6,8.7)");
        stream >> x;
        TS_ASSERT_EQUALS(x.real(),10.6);
        TS_ASSERT_EQUALS(x.imag(),8.7);
      }catch(std::exception& e){
        TS_FAIL("Exception should not have been thrown");
      }

      // TODO: ADD MINUS CASES!!
      try{
        Complex x;
        std::istringstream stream("-10.6");
        stream >> x;
        TS_ASSERT_EQUALS(x.real(),-10.6);
        TS_ASSERT_EQUALS(x.imag(),0);
      }catch(std::exception& e){
        TS_FAIL("Exception should not have been thrown");
      }

      try{
        Complex x;
        std::istringstream stream("(-10.6,-8.7)");
        stream >> x;
        TS_ASSERT_EQUALS(x.real(),-10.6);
        TS_ASSERT_EQUALS(x.imag(),-8.7);
      }catch(std::exception& e){
        TS_FAIL("Exception should not have been thrown");
      }
    }

    void test10 () {
      // SYNOPSIS:
      // Chaining operator=

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(3.0,2.0);
      Complex b(5.0,1.0);
      Complex c;

      c = b = a;

      TS_ASSERT_EQUALS(c.real(), 3.0);
      TS_ASSERT_EQUALS(c.imag(), 2.0);
    }

    void test11 () {
      // SYNOPSIS:
      // operator+= 
      // real part should be 8 and imag part 3

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(3.0,2.0);
      Complex b(5.0,1.0);
      a += b;

      TS_ASSERT_EQUALS(a.real(), 8.0);
      TS_ASSERT_EQUALS(a.imag(), 3.0);
    }

    void test12 () {
      // SYNOPSIS:
      // operator-= 
      // real part should be -2 and imag part -1

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(3.0,2.0);
      Complex b(5.0,1.0);
      a -= b;

      TS_ASSERT_EQUALS(a.real(), -2.0);
      TS_ASSERT_EQUALS(a.imag(), 1.0);
    }

    void test13() {
      // SYNOPSIS:
      // operator*= and real + imag non-member functions
      // real part should be 13 and imag part 13

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(3.0,2.0);
      Complex b(5.0,1.0);
      a *= b;  

      TS_ASSERT_EQUALS(real(a), 13.0);
      TS_ASSERT_EQUALS(imag(a), 13.0);
    }

    void test14() {
      // SYNOPSIS:
      // operator/= 
      // real part should be -1 and imag part -1

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(4.0,2.0);
      Complex b(3.0,-1.0);
      a /= b;

      TS_ASSERT_EQUALS(a.real(), 1.0);
      TS_ASSERT_EQUALS(a.imag(), 1.0);
    }

    void test15() {
      // SYNOPSIS:
      // operator==

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(4.0,2.0);
      Complex b(3.0,-1.0);
      Complex c(4.0,2.0);

      bool res1 = a==b;
      bool res2 = a==c;

      TS_ASSERT_EQUALS(res1,false);
      TS_ASSERT_EQUALS(res2,true);
    }

    void test16() {
      // SYNOPSIS:
      // operator!=

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(4.0,2.0);
      Complex b(3.0,-1.0);
      Complex c(4.0,2.0);

      bool res1 = a!=b;
      bool res2 = a!=c;

      TS_ASSERT_EQUALS(res1,true);
      TS_ASSERT_EQUALS(res2,false);
    }    

    void test17() {
      // SYNOPSIS:
      // non-member function abs()
      // absolute value should be 5

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(3.0,4.0);
      double abs_val = abs(a);
      TS_ASSERT_EQUALS(abs_val,5.0);
      Complex b(0.0,0.0);
      TS_ASSERT_EQUALS(abs(b),0.0);
    }

    void test18() {
      // SYNOPSIS:
      // Test division by zero

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(4.0,2.0);
      Complex b;
      try{
        a /= b;
        TS_FAIL("Division by zero should throw error");
      }catch (std::exception& e){
        std::cout << "Correct Error: " << e.what() << std::endl;
      }
    }

    void test19() {
      // SYNOPSIS:
      // Test division by zero

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(4.0,2.0);
      Complex b;
      try{
        a / b;
        TS_FAIL("Division by zero should throw error");
      }catch (std::exception& e){
        std::cout << "Correct Error: " << e.what() << std::endl;
      }
    }

    void test20() {
      // SYNOPSIS:
      // Chaining operator+ operator-
      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(2.0,3.0);
      Complex b(9);
      Complex c = a + b - 2 + 2_i * 1.0;

      TS_ASSERT_EQUALS(real(c),9.0);
      TS_ASSERT_EQUALS(imag(c),5.0);
    }

    void test21() {
      // SYNOPSIS
      // Chaining operator* operator/

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(18.0,27.0);
      Complex b(9);
      Complex c = a * b / 2_i;


      TS_ASSERT_EQUALS(real(c),121.5);
      TS_ASSERT_EQUALS(imag(c),-81.0);
    }

    void test22() {

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(10,5);
      Complex c(0,0);
      Complex b = c;


      b += a + Complex(10.3,0.4) - 2.1_i;

      TS_ASSERT_EQUALS(real(b),20.3);

      TS_ASSERT_LESS_THAN(imag(b),3.3001);
      TS_ASSERT_LESS_THAN(3.2999,imag(b));
    }

    void test23() {

      // SYNOPSIS
      // Unary operator-
      // real and imag should be -10, -5


      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex a(10,5);

      TS_ASSERT_EQUALS(real(-a),-10);
      TS_ASSERT_EQUALS(imag(-a),-5);
    }

    void test24() {

      // SYNOPSIS
      // Unary operator+
      // real and imag should be 11, 3
      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;

      Complex c(2.0,4.1), d;
      Complex e(1.0,-3.0);

      //Complex res = c + d + e;
      std::cout << "here" << std::endl;
      //Complex res2 = Complex(1.0,3.0);

      std::cout << "here2" << std::endl;
      Complex a(11,3);

      TS_ASSERT_EQUALS(real(+a),11);
      TS_ASSERT_EQUALS(imag(+a),3);
    }


};