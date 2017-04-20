#include <cxxtest/TestSuite.h>
#include "chess.h"
#include <fstream>

static int TEST_NUMBER = 0;


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      // SYNOPSIS:
      //   Chess
      //   Queens Placement
      //   Capturing Moves, White: 0, Black: 0
      //   Non-capturing moves
      //   White: 88, Black: 88

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << ".....Q.." << std::endl;
      s << "...q...." << std::endl;
      s << "......Q." << std::endl;
      s << "q......." << std::endl;
      s << ".......Q" << std::endl;
      s << ".q......" << std::endl;
      s << "....Q..." << std::endl;
      s << "..q.....";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 0) {
          std::cout << "White capturingMoves FAILED, expected 0 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 0 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),0);
      TS_ASSERT_EQUALS(v2.size(),0);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 88) {
          std::cout << "White nonCapturingMoves FAILED, expected 88 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 88 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 88) {
          std::cout << "Black nonCapturingMoves FAILED, expected 88 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 88 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),88);
      TS_ASSERT_EQUALS(v4.size(),88);

      /*

      ChessBoard chess;

      std::cout << "board layout: " << std::endl;
      std::ifstream myinput;
      myinput.open("board.txt");
      myinput >> chess;
      myinput.close();

      std::vector<ChessMove> v = chess.capturingMoves(true);

      if (v.size() != 0) {
          std::cout << "White capturingMoves FAILED, expected 0 moves but got " << v.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 0 moves and got " << v.size() << " moves" << std::endl;
      }
  */

    }

    void test2 () {
      // SYNOPSIS:
      //   Capturing Moves
      //   White: 3, Black: 0
      //   Non-capturing move
      //   White: 4, Black: 30


      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "Q..n...r" << std::endl;
      s << "........" << std::endl;
      s << "n.r....." << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 3) {
          std::cout << "White capturingMoves FAILED, expected 3 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 3 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),3);
      TS_ASSERT_EQUALS(v2.size(),0);
    
      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 4) {
          std::cout << "White nonCapturingMoves FAILED, expected 4 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 4 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 30) {
          std::cout << "Black nonCapturingMoves FAILED, expected 30 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 30 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),4);
      TS_ASSERT_EQUALS(v4.size(),30);
      

    }

    void test3 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves
      //   White: 3, Black: 0
      //   Non Capturing
      //   White: 0, Black: 13

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "Kb......" << std::endl;
      s << "nn......" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 3) {
          std::cout << "White capturingMoves FAILED, expected 3 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 3 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),3);
      TS_ASSERT_EQUALS(v2.size(),0);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 0) {
          std::cout << "White nonCapturingMoves FAILED, expected 0 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 0 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 13) {
          std::cout << "Black nonCapturingMoves FAILED, expected 13 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 13 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),0);
      TS_ASSERT_EQUALS(v4.size(),13);

    }


    void test4 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves
      //   White: 2, Black: 0
      //   non capturing:
      //   White: 2, Black: 13 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "R..n...." << std::endl;
      s << "bn......" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 2) {
          std::cout << "White capturingMoves FAILED, expected 2 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 2 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),2);
      TS_ASSERT_EQUALS(v2.size(),0);
    
      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 2) {
          std::cout << "White nonCapturingMoves FAILED, expected 2 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 2 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 13) {
          std::cout << "Black nonCapturingMoves FAILED, expected 13 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 13 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),2);
      TS_ASSERT_EQUALS(v4.size(),13);


    }



    void test5 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves
      //   White: 1, Black: 0
      // non capturing
      // white: 0, black: 13 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "B..n...." << std::endl;
      s << "bn......" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 1) {
          std::cout << "White capturingMoves FAILED, expected 1 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 1 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),1);
      TS_ASSERT_EQUALS(v2.size(),0);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 0) {
          std::cout << "White nonCapturingMoves FAILED, expected 0 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 0 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 13) {
          std::cout << "Black nonCapturingMoves FAILED, expected 13 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 13 moves and got " << v4.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v3.size(),0);
      TS_ASSERT_EQUALS(v4.size(),13);

    }


    void test6 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves
      //   White: 2, Black: 0
      // non capturing moves
      // white: 0, black: 10

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "N..n...." << std::endl;
      s << "bnp....." << std::endl;
      s << ".p......" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........";
      std::cout << s.str() << std::endl;
      s >> chess; 

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 2) {
          std::cout << "White capturingMoves FAILED, expected 2 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 2 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),2);
      TS_ASSERT_EQUALS(v2.size(),0);
    
      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 0) {
          std::cout << "White nonCapturingMoves FAILED, expected 0 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 0 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 10) {
          std::cout << "Black nonCapturingMoves FAILED, expected 10 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 10 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),0);
      TS_ASSERT_EQUALS(v4.size(),10);

    }

    void test7 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves
      //   White: 2, Black: 1
      //   Non-Capturing moves
      //   White: 14, Black: 18  

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "........" << std::endl;
      s << "......p." << std::endl;
      s << ".......R" << std::endl;
      s << "..npn..." << std::endl;
      s << "...P...." << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........";
      std::cout << s.str() << std::endl;
      s >> chess; 

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 2) {
          std::cout << "White capturingMoves FAILED, expected 2 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 2 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 1) {
          std::cout << "Black capturingMoves FAILED, expected 1 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 1 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),2);
      TS_ASSERT_EQUALS(v2.size(),1);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 14) {
          std::cout << "White nonCapturingMoves FAILED, expected 14 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 14 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 18) {
          std::cout << "Black nonCapturingMoves FAILED, expected 18 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 18 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),14);
      TS_ASSERT_EQUALS(v4.size(),18);

    }

    void test8 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves
      //   White: 1, Black: 0
      //   Non-capturing moves
      //   White: 7, Black: 15 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << ".r......" << std::endl;
      s << ".p......" << std::endl;
      s << "...P...n" << std::endl;
      s << "......P." << std::endl;
      s << ".N...B..";
      std::cout << s.str() << std::endl;
      s >> chess; 

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 1) {
          std::cout << "White capturingMoves FAILED, expected 1 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 1 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),1);
      TS_ASSERT_EQUALS(v2.size(),0);
    
      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 7) {
          std::cout << "White nonCapturingMoves FAILED, expected 7 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 7 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 15) {
          std::cout << "Black nonCapturingMoves FAILED, expected 15 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 15 moves and got " << v4.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v3.size(),7);
      TS_ASSERT_EQUALS(v4.size(),15);

    }

    void test9 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves
      //   White: 0, Black: 0

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "rnbqkbnr" << std::endl;
      s << "pppppppp" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "PPPPPPPP" << std::endl;
      s << "RNBQKBNR";
      std::cout << s.str() << std::endl;
      s >> chess; 

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 0) {
          std::cout << "White capturingMoves FAILED, expected 0 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 0 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),0);
      TS_ASSERT_EQUALS(v2.size(),0);
 
      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 20) {
          std::cout << "White nonCapturingMoves FAILED, expected 20 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 20 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 20) {
          std::cout << "Black nonCapturingMoves FAILED, expected 20 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 20 moves and got " << v4.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v3.size(),20);
      TS_ASSERT_EQUALS(v4.size(),20);
    }

    void test10 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves, White bishop strikes pawn
      //   White: 1, Black: 0
      //   Non-capturing moves
      //   White: 28, Black: 21

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "rnbqkbnr" << std::endl;
      s << "p.pppppp" << std::endl;
      s << "........" << std::endl;
      s << ".p......" << std::endl;
      s << "....P..." << std::endl;
      s << "........" << std::endl;
      s << "PPPP.PPP" << std::endl;
      s << "RNBQKBNR";
      std::cout << s.str() << std::endl;
      s >> chess; 

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 1) {
          std::cout << "White capturingMoves FAILED, expected 1 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 1 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),1);
      TS_ASSERT_EQUALS(v2.size(),0);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 28) {
          std::cout << "White nonCapturingMoves FAILED, expected 28 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 28 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 21) {
          std::cout << "Black nonCapturingMoves FAILED, expected 21 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 21 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),28);
      TS_ASSERT_EQUALS(v4.size(),21);
    
    }

    void test11 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves, black pawns: 3 moves, white pawns and knight: 4 moves
      //   White: 4, Black: 3
      //   Non-capturing moves
      //   White: 20, Black: 2 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "........" << std::endl;
      s << ".......p" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << ".....p.." << std::endl;
      s << "Q.P..pp." << std::endl;
      s << ".....PPP" << std::endl;
      s << "......NR";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 4) {
          std::cout << "White capturingMoves FAILED, expected 4 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 4 moves and got " << v1.size() << " moves" << std::endl;
      }


      if (v2.size() != 3) {
          std::cout << "Black capturingMoves FAILED, expected 3 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 3 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),4);
      TS_ASSERT_EQUALS(v2.size(),3);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 20) {
          std::cout << "White nonCapturingMoves FAILED, expected 20 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 20 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 2) {
          std::cout << "Black nonCapturingMoves FAILED, expected 2 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 2 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),20);
      TS_ASSERT_EQUALS(v4.size(), 2);
    }


    void test12 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves, black pawns: 3 moves, white pawns and knight: 4 moves
      //   White: 1, Black: 2
      //   Non-capturing moves
      //   White: 16, Black: 26 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "....k..." << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "....b..." << std::endl;
      s << "........" << std::endl;
      s << "..R..r.." << std::endl;
      s << "........" << std::endl;
      s << "....K...";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 1) {
          std::cout << "White capturingMoves FAILED, expected 1 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 1 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 2) {
          std::cout << "Black capturingMoves FAILED, expected 2 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 2 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),1);
      TS_ASSERT_EQUALS(v2.size(),2);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 16) {
          std::cout << "White nonCapturingMoves FAILED, expected 16 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 16 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 26) {
          std::cout << "Black nonCapturingMoves FAILED, expected 26 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 26 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),16);
      TS_ASSERT_EQUALS(v4.size(),26);
    }

    void test13 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves, black pawns: 3 moves, white pawns and knight: 4 moves
      //   White: 5, Black: 3
      //   Non-capturing moves
      //   White: 36, Black: 4 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << ".......k" << std::endl;
      s << ".......R" << std::endl;
      s << "........" << std::endl;
      s << "....B..." << std::endl;
      s << "........" << std::endl;
      s << ".p.p...R" << std::endl;
      s << "..P....." << std::endl;
      s << "...K....";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 5) {
          std::cout << "White capturingMoves FAILED, expected 5 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 5 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 3) {
          std::cout << "Black capturingMoves FAILED, expected 3 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 3 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),5);
      TS_ASSERT_EQUALS(v2.size(),3);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 36) {
          std::cout << "White nonCapturingMoves FAILED, expected 36 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 36 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 4) {
          std::cout << "Black nonCapturingMoves FAILED, expected 4 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 4 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),36);
      TS_ASSERT_EQUALS(v4.size(),4);
    }

    void test14 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves, black pawns: 3 moves, white pawns and knight: 4 moves
      //   White: 0, Black: 0
      //   Non-capturing moves
      //   White: 84, Black: 84 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "n.N.n.N." << std::endl;
      s << ".n.N.n.N" << std::endl;
      s << "n.N.n.N." << std::endl;
      s << ".n.N.n.N" << std::endl;
      s << "n.N.n.N." << std::endl;
      s << ".n.N.n.N" << std::endl;
      s << "n.N.n.N." << std::endl;
      s << ".n.N.n.N";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 0) {
          std::cout << "White capturingMoves FAILED, expected 0 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 0 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 0) {
          std::cout << "Black capturingMoves FAILED, expected 0 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 0 moves and got " << v2.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v1.size(),0);
      TS_ASSERT_EQUALS(v2.size(),0);

      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 84) {
          std::cout << "White nonCapturingMoves FAILED, expected 84 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 84 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 84) {
          std::cout << "Black nonCapturingMoves FAILED, expected 84 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 84 moves and got " << v4.size() << " moves" << std::endl;
      }


      TS_ASSERT_EQUALS(v3.size(),84);
      TS_ASSERT_EQUALS(v4.size(),84);
    }

    void test15 () {
      // SYNOPSIS:
      //   Chess
      //   Capturing Moves, black pawns: 3 moves, white pawns and knight: 4 moves
      //   White: 2, Black: 2
      //   Non-capturing moves
      //   White: 18, Black: 17 + 7 + 8 

      std::cout << "\n<< TEST: " << ++TEST_NUMBER << " >>" << std::endl;
      
      ChessBoard chess;
      std::stringstream s;
      s << "...q...." << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "........" << std::endl;
      s << "...k...." << std::endl;
      s << "......b." << std::endl;
      s << ".......P" << std::endl;
      s << "...QK...";
      std::cout << s.str() << std::endl;
      s >> chess;

      std::vector<ChessMove> v1 = chess.capturingMoves(true);
      std::vector<ChessMove> v2 = chess.capturingMoves(false);

      if (v1.size() != 2) {
          std::cout << "White capturingMoves FAILED, expected 2 moves but got " << v1.size() << " moves" << std::endl;
      } else {
          std::cout << "White capturingMoves PASSED, expected 2 moves and got " << v1.size() << " moves" << std::endl;
      }

      if (v2.size() != 2) {
          std::cout << "Black capturingMoves FAILED, expected 2 moves but got " << v2.size() << " moves" << std::endl;
      } else {
          std::cout << "Black capturingMoves PASSED, expected 2 moves and got " << v2.size() << " moves" << std::endl;
      }
      
      TS_ASSERT_EQUALS(v1.size(),2);
      TS_ASSERT_EQUALS(v2.size(),2);


      std::cout << "White Capturing Moves: " << std::endl;
      auto it = v1.begin();
      while(it != v1.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }

      std::cout << "Black Capturing Moves: " << std::endl;
      it = v2.begin();
      while(it != v2.end()){
        std::cout << "Capture from: " << it->from_x << ", " << it->from_y 
                  << " to: "          << it->to_x   << ", " << it-> to_y << std::endl;
        ++it;
      }


      std::vector<ChessMove> v3 = chess.nonCapturingMoves(true);
      std::vector<ChessMove> v4 = chess.nonCapturingMoves(false);

      if (v3.size() != 18) {
          std::cout << "White nonCapturingMoves FAILED, expected 18 moves but got " << v3.size() << " moves" << std::endl;
      } else {
          std::cout << "White nonCapturingMoves PASSED, expected 18 moves and got " << v3.size() << " moves" << std::endl;
      }

      if (v4.size() != 32) {
          std::cout << "Black nonCapturingMoves FAILED, expected 32 moves but got " << v4.size() << " moves" << std::endl;
      } else {
          std::cout << "Black nonCapturingMoves PASSED, expected 32 moves and got " << v4.size() << " moves" << std::endl;
      }

      TS_ASSERT_EQUALS(v3.size(),18);
      TS_ASSERT_EQUALS(v4.size(),32);

    }

};