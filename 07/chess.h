#include "../05/matrix.h"
#include <iostream>
#include <codecvt>
#include <fstream>
#include <algorithm>    // std::shuffle
#include <random>     // std::default_random_engine

class ChessPiece; // forward declaration to inform others of its existence.

int static const BOARD_ROW_SIZE = 8;
int static const BOARD_MAX_INDEX = 7;
int static const UNPLACED_PIECE_INDEX = -1;
int static const LITERAL_INDEX_OFFSET = 65; // 'A' cast to int is 65, 'H' is 72
int static const INTEGER_INDEX_OFFSET = 49; // '0' cast to int is 49
char static const NO_PROMOTION = 'x'; 
unsigned static const RANDOM_SEED = 310254; // 123456, 892534, 758109, 289348, 345748, 423593, 523977(tests run with this)


struct ChessMove {
    int from_x;
    int from_y;
    int to_x;
    int to_y;

    ChessPiece* piece;   // you can change the position of the chess piece with this pointer. 
    char promoteTo; // specify which piece pawn should be promoted to

    std::string toString();
};

class ChessBoard {
// add additional members or functions of your choice
private:
    Matrix<ChessPiece* > state; // Matrix from lab 5  Matrix
    Matrix<bool> chessColorMatrix; // 0 - black, 1 - white
    bool whiteToPlay_;

    int menu();
    bool load_game(bool newGame);
    void game_loop(bool isAIvsAI);
    ChessMove simple_ai_move(); // first version of the AI
    ChessMove improved_ai_move(bool isBlack); // second version of the AI
    bool user_move();
    bool getTurn(); // returns true if white's turn 
    int numberOfPieces(bool isWhite);
    int potentialMoves(ChessMove cm, bool isWhite, bool isCapturing); 
    ChessPiece * getChessPiece(int x,int y);

public:
    // constructors
    ChessBoard();
    ~ChessBoard();

    void reset_board();
    void start_game();

    bool isStalemate();
    void print_board(bool printAsUTF, std::ostream & out);
    void setTurn(bool whiteToPlay); // TODO remove

    bool is_empty(int x, int y); 
    bool piece_color(int x, int y);
    void move_piece(ChessMove chessMove);
    // calculates number of capturing moves after the current one
    std::vector<ChessMove> capturingMoves(bool isWhite);
    std::vector<ChessMove> nonCapturingMoves(bool isWhite);
};

class ChessPiece {
friend void ChessBoard::move_piece(ChessMove p);
friend void ChessBoard::print_board(bool printAsUTF, std::ostream & out);
friend bool ChessBoard::isStalemate();
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
    //bool isWhite();
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

  board.reset_board();

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

    ++line;
  }

  return board;

}


// files
inline ChessBoard & operator>>(std::ifstream & in, ChessBoard & board){

  board.reset_board();

  std::string str,sub_string;
  // read in the line of input
 
  int line = 0;
  while(line < BOARD_ROW_SIZE){
    std::getline(in,str);
    if(str.empty() && line < 8) throw std::length_error("input rows not matching rows on board");
    if(str.empty()) break;

    if(str.length() > BOARD_ROW_SIZE){
      throw std::length_error("row length in input exceeds board limit");
    }

    if(str.length() < BOARD_ROW_SIZE){
      throw std::length_error("input rows not matching rows on board");
    }


    for(int i = 0; i<str.length();++i){
    
      if(str[i] == 'r') {
        Rook* ptr = new Rook(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'R') {
        Rook* ptr = new Rook(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'p') {
        if(line == 0 || line == BOARD_MAX_INDEX) throw std::invalid_argument("invalid placement of black pawn");
        Pawn* ptr = new Pawn(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'P') {
        if(line == 0 || line == BOARD_MAX_INDEX) throw std::invalid_argument("invalid placement of white pawn");
        Pawn* ptr = new Pawn(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'n') {
        Knight* ptr = new Knight(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'N') {
        Knight* ptr = new Knight(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'b') {
        Bishop* ptr = new Bishop(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'B') {
        Bishop* ptr = new Bishop(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'q') {
        Queen* ptr = new Queen(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'Q') {
        Queen* ptr = new Queen(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'k') {
        King* ptr = new King(false);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == 'K') {
        King* ptr = new King(true);
        ChessMove chessMove{-1,-1,i,line,ptr};
        board.move_piece(chessMove);
      }else if(str[i] == '.'){
        // do nothing

      }else{
        throw std::invalid_argument("character input not matching any known chess piece...");
      }
    }
    ++line;
  }

    // read who's turn it is
    std::getline(in,str);

    if(str.empty()) throw std::length_error("need to specify which color that should start");
    if(str.length() > 1) throw std::invalid_argument("starting color must be specified with either 0 or 1");
    if(str[0] == '0'){
      board.setTurn(false);
    }else if(str[0] == '1'){
      board.setTurn(true);
    }else{
      throw std::invalid_argument("starting color must be specified with either 0 or 1");
    }

    return board;
}

