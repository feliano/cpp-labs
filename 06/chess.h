#include "../05/matrix.h"
#include <iostream>

class ChessPiece; // forward declaration to inform others of its existence.

int static const BOARD_ROW_SIZE = 8;
int static const BOARD_MAX_INDEX = 7;
int static const UNPLACED_PIECE_INDEX = -1;

struct ChessMove {
    int from_x;
    int from_y;
    int to_x;
    int to_y;

    ChessPiece* piece;   // you can change the position of the chess piece with this pointer. 
};

class ChessBoard {
// add additional members or functions of your choice
private:
    Matrix<ChessPiece* > state; // Matrix from lab 5  Matrix
    Matrix<bool> chessColorMatrix; // 0 - black, 1 - white
public:
    // constructors
    ChessBoard();
    ~ChessBoard();

    bool is_empty(int x, int y);
    bool piece_color(int x, int y);
    void move_piece(ChessMove chessMove);
    std::vector<ChessMove> capturingMoves(bool isWhite);
    std::vector<ChessMove> nonCapturingMoves(bool isWhite);
};

class ChessPiece {
friend void ChessBoard::move_piece(ChessMove p);
protected:
    bool _isWhite;
    ChessBoard* board;

    /**
     * Returns 0 if target square is unreachable.
     * Returns 1 if target square is reachable and empty.
     * Returns 2 if move captures a piece.
     */
    int x,y;
    virtual int validMove(int to_x, int to_y){return 0;};
    virtual char32_t utfRepresentation(){return U'\U0000265C';};
    virtual char latin1Representation(){return 'r';};

public:
    virtual ~ChessPiece(){}
    /**
     * Checks if this move is valid for this piece and captures
     * a piece of the opposite color.
     */
    bool capturingMove(int to_x, int to_y);
    /**
     * Checks if this move is valid but does not capture a piece.
     */
    bool nonCapturingMove(int to_x, int to_y);
    virtual std::vector<ChessMove> capturingMoves() {
      std::vector<ChessMove> v = {};
      return v;}
    virtual std::vector<ChessMove> nonCapturingMoves() {
      std::vector<ChessMove> v = {};
      return v;
    };
};

// ChessPieces
class Rook : public ChessPiece{

public:
  explicit Rook(bool isWhite);
  virtual std::vector<ChessMove> capturingMoves();
  virtual std::vector<ChessMove> nonCapturingMoves();
protected:
  virtual int validMove(int to_x, int to_y);
  virtual char32_t utfRepresentation();
  virtual char latin1Representation();  
};

class Pawn : public ChessPiece{

public:
  explicit Pawn(bool isWhite);
  virtual std::vector<ChessMove> capturingMoves();
  virtual std::vector<ChessMove> nonCapturingMoves();
protected:
  virtual int validMove(int to_x, int to_y);
  virtual char32_t utfRepresentation();
  virtual char latin1Representation();  
};

class Knight : public ChessPiece{

public:
  explicit Knight(bool isWhite);
  virtual std::vector<ChessMove> capturingMoves();
  virtual std::vector<ChessMove> nonCapturingMoves();
protected:
  virtual int validMove(int to_x, int to_y);
  virtual char32_t utfRepresentation();
  virtual char latin1Representation();  
};

class Bishop : public ChessPiece{

public:
  explicit Bishop(bool isWhite);
  virtual std::vector<ChessMove> capturingMoves();
  virtual std::vector<ChessMove> nonCapturingMoves();
protected:
  virtual int validMove(int to_x, int to_y);
  virtual char32_t utfRepresentation();
  virtual char latin1Representation();  
};

class Queen : public ChessPiece{

public:
  explicit Queen(bool isWhite);
  virtual std::vector<ChessMove> capturingMoves();
  virtual std::vector<ChessMove> nonCapturingMoves();
protected:
  virtual int validMove(int to_x, int to_y);
  virtual char32_t utfRepresentation();
  virtual char latin1Representation();  
};

class King : public ChessPiece{

public:
  explicit King(bool isWhite);
  virtual std::vector<ChessMove> capturingMoves();
  virtual std::vector<ChessMove> nonCapturingMoves();
protected:
  virtual int validMove(int to_x, int to_y);
  virtual char32_t utfRepresentation();
  virtual char latin1Representation();  
};

/**

Input Operator

*/
inline ChessBoard & operator>>(std::istream & in, ChessBoard & board){

  std::string str,sub_string;
  // read in the line of input
 
  int line = 0;
  while(true){
    std::getline(in,str);
    if(line == BOARD_ROW_SIZE){
      break;
    } 

    for(int i = 0; i<str.length();++i){
    
      if(str[i] == 'r') {
        Rook* ptr = new Rook(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'R') {
        Rook* ptr = new Rook(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'p') {
        Pawn* ptr = new Pawn(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'P') {
        Pawn* ptr = new Pawn(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'n') {
        Knight* ptr = new Knight(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'N') {
        Knight* ptr = new Knight(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'b') {
        Bishop* ptr = new Bishop(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'B') {
        Bishop* ptr = new Bishop(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'q') {
        Queen* ptr = new Queen(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'Q') {
        Queen* ptr = new Queen(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'k') {
        King* ptr = new King(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }

      if(str[i] == 'K') {
        King* ptr = new King(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }
    }

    line++;
  }

  return board;

}



/*
// files
inline ChessBoard & operator>>(std::istream & in, ChessBoard & board){

  std::cout << "INPUT STREAM" << std::endl;
  std::string str,sub_string;
  // read in the line of input
 
  int line = 0;
  while(true){
    std::getline(in,str);
    if(str.empty()) break;

    for(int i = 0; i<str.length();++i){
    
  if(str[i] == 'r') {
    Rook* ptr = new Rook(false);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'R') {
    Rook* ptr = new Rook(true);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'p') {
    Pawn* ptr = new Pawn(false);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'P') {
    Pawn* ptr = new Pawn(true);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'n') {
    Knight* ptr = new Knight(false);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'N') {
    Knight* ptr = new Knight(true);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'b') {
    Bishop* ptr = new Bishop(false);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'B') {
    Bishop* ptr = new Bishop(true);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'q') {
    Queen* ptr = new Queen(false);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'Q') {
    Queen* ptr = new Queen(true);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'k') {
    King* ptr = new King(false);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

  if(str[i] == 'K') {
    King* ptr = new King(true);
    ChessMove chessMove{-1,-1,i,line,ptr};
    board.move_piece(chessMove);
  }

    }
    line++;
    std::cout << str << std::endl;   
  }
  return board;
}
*/

