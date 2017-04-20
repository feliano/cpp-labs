#include "chess.h"

using namespace std;

/**

Chesspiece

*/

bool ChessPiece::capturingMove(int to_x,int to_y){


  int moveType = validMove(to_x,to_y);

  if(moveType == 0){
    return false;
  }else if(moveType == 1){
    return false;
  }else{
    return true;
  }
}

bool ChessPiece::nonCapturingMove(int to_x, int to_y){

  int moveType = validMove(to_x,to_y);

  if(moveType == 0){
    return false;
  }else if(moveType == 1){
    return true;
  }else{
    return false;
  }
}

/**

Chessboard

*/

ChessBoard::ChessBoard() {
  state = Matrix<ChessPiece* >(BOARD_ROW_SIZE,BOARD_ROW_SIZE);
  chessColorMatrix = Matrix<bool>(BOARD_ROW_SIZE,BOARD_ROW_SIZE);
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    for(int j = 0; j<BOARD_ROW_SIZE; ++j){
      state(i,j) = nullptr;
      chessColorMatrix(i,j) = false;
    }
  }
}

ChessBoard::~ChessBoard(){
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    for(int j = 0; j<BOARD_ROW_SIZE; ++j){
      delete state(i,j);
    }
  }
}

bool ChessBoard::is_empty(int x, int y){
    ChessPiece * ptr = state(x,y);
    if(ptr == nullptr){
    	return true;
    }else{
    	return false;
    }
}

bool ChessBoard::piece_color(int x, int y){
	return chessColorMatrix(x,y);
}

std::vector<ChessMove> ChessBoard::capturingMoves(bool isWhite){

	std::vector<ChessMove> v;

	// loop all positions and call capturemoves
	for(int i = 0; i<state.rows();++i){
		for(int j = 0; j<state.cols();++j){
			if(chessColorMatrix(i,j) == isWhite){
				
				ChessPiece * p = state(i,j);
				
				if(p != nullptr){
							
					std::vector<ChessMove> tmp = p->capturingMoves();
					auto cm_it = tmp.begin();
				
					while(cm_it != tmp.end()){		
						v.push_back(*cm_it);
						++cm_it;
					}
				
				}
			}
		}
	}
	return v;
}

std::vector<ChessMove> ChessBoard::nonCapturingMoves(bool isWhite){

	std::vector<ChessMove> v;

	// loop all positions and call capturemoves
	for(int i = 0; i<state.rows();++i){
		for(int j = 0; j<state.cols();++j){
			if(chessColorMatrix(i,j) == isWhite){
				
				ChessPiece * p = state(i,j);

				if(p != nullptr){
				
					std::vector<ChessMove> tmp = p->nonCapturingMoves();
					auto cm_it = tmp.begin();
				
					while(cm_it != tmp.end()){
						v.push_back(*cm_it);
						++cm_it;
					}
				
				}
			}
		}
	}
	return v;
}

void ChessBoard::move_piece(ChessMove chessMove){

	// if piece already placed on board
	if((chessMove.from_x != UNPLACED_PIECE_INDEX) && (chessMove.from_y != UNPLACED_PIECE_INDEX)){
		state(chessMove.from_x,chessMove.from_y) = nullptr;
		chessColorMatrix(chessMove.from_x,chessMove.from_y) = false;
		state(chessMove.to_x,chessMove.to_y) = chessMove.piece;
	}else{
		state(chessMove.to_x,chessMove.to_y) = chessMove.piece;
		chessMove.piece->board = this;
	}

	if(chessMove.piece->_isWhite){
		chessColorMatrix(chessMove.to_x,chessMove.to_y) = true;
	}else{
		chessColorMatrix(chessMove.to_x,chessMove.to_y) = false;
	}

	chessMove.piece->x = chessMove.to_x;
	chessMove.piece->y = chessMove.to_y;

}

/**

Rook Piece

*/

Rook::Rook(bool isWhite) {

    _isWhite = isWhite;
    //std::cout << ((_isWhite == true) ? "White " : "Black ")  << "Rook: " << utfRepresentation() << std::endl;
    x = UNPLACED_PIECE_INDEX;
    y = UNPLACED_PIECE_INDEX;
}

int Rook::validMove(int to_x, int to_y){

    // rook: move along one axis, can't stay at same coords, has to stay inside board
    if((x-to_x != 0) && (y-to_y != 0)){
      // diagonal move, not valid for rook
      return 0;
    }

    if((to_x > BOARD_MAX_INDEX) || (to_y > BOARD_MAX_INDEX)){
      // outside of board
      return 0;
    }

    if((to_x < 0) || (to_y < 0)){
      // outside of board
      return 0;
    }

    if((x == to_x) && (y == to_y)){
      // staying at same coords not valid
      return 0;
    }

    // check if colliding with other piece
    int steps_x = abs(to_x - x);
    int steps_y = abs(to_y - y);
    int steps = 0;

    int dir_x = 0;
    int dir_y = 0;

    if(steps_x > steps_y){
      steps = steps_x;

      if(to_x - x > 0){
	      dir_x = 1;
    	  dir_y = 0;
      }else{
          dir_x = -1;
    	  dir_y = 0;
      }
    }else{
      steps = steps_y;
      if(to_y - y > 0){
	      dir_x = 0;
    	  dir_y = 1;
      }else{
          dir_x = 0;
    	  dir_y = -1;
      }
    }

    for(int i = 1; i<steps; ++i){
      bool is_empty = board->is_empty((x + dir_x * i),(y + dir_y * i));
      if(is_empty == false){
        // target coords blocked by other piece
        return 0;
      }
    }

    // check final space
    bool is_empty = board->is_empty(to_x,to_y); 
    if(is_empty == true){
      return 1;
    }else{
    	if(board->piece_color(to_x,to_y) != _isWhite){
           return 2;
    	}else{
    		return 0; // piece is of same color
    	}
    }

}

char32_t Rook::utfRepresentation(){
    if(_isWhite == true){
      return U'\U00002656';
    }else{
      return U'\U0000265C';
    }
}

char Rook::latin1Representation(){
    if(_isWhite == true){
      return 'R';
    }else{
      return 'r';
    }
}

std::vector<ChessMove> Rook::capturingMoves() {

  std::vector<ChessMove> v = {};

  // check all possible moves along x-axis
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    // skip current position
    if(i != x){

      if(capturingMove(i,y) == true){
        ChessMove cm{x,y,i,y,this};
        v.push_back(cm);
      }
    }
  }

  // check all possible moves along y-axis
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    // skip current position
    if(i != y){
      if(capturingMove(x,i) == true){
        ChessMove cm{x,y,x,i,this};
        v.push_back(cm);
      }
    }
  }

  return v;
}

vector<ChessMove> Rook::nonCapturingMoves() {
  std::vector<ChessMove> v = {};

  // check all possible moves along x-axis
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    // skip current position
    if(i != x){
      if(nonCapturingMove(i,y) == true){
        ChessMove cm{x,y,i,y,this};
        v.push_back(cm);
      }
    }
  }

  // check all possible moves along y-axis
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    // skip current position
    if(i != y){
      if(nonCapturingMove(x,i) == true){
        ChessMove cm{x,y,x,i,this};
        v.push_back(cm);
      }
    }
  }
  return v;
}

/**

Pawn

*/

Pawn::Pawn(bool isWhite){
    _isWhite = isWhite;
    //std::cout << ((_isWhite == true) ? "White " : "Black ")  << "Pawn: " << utfRepresentation() << std::endl;
    x = UNPLACED_PIECE_INDEX;
    y = UNPLACED_PIECE_INDEX;
}

int Pawn::validMove(int to_x, int to_y){
    // pawn: black moves in positive direction and white moves in negative direct

	if(_isWhite == false){

		if((to_y-y) == 1 && (y+1 < BOARD_ROW_SIZE)){
			
			if(to_x-x == -1 && (x-1 >= 0)){
				if(board->is_empty(x-1,y+1)){
					return 0;
				}else if(board->piece_color(x-1,y+1) != _isWhite) {
					return 2;
				}else{
					return 0; // same color invalid move.
				}

			}else if(to_x-x == 1 && ((x+1) < BOARD_ROW_SIZE)){
				if(board->is_empty(x+1,y+1)){
					return 0;
				}else if(board->piece_color(x+1,y+1) != _isWhite){
					return 2;
				}else{
					return 0; // same color;
				}

			}else if(to_x-x == 0){
				if(board->is_empty(x,y+1)){
					return 1;
				}else{
					return 0;
				}

			}else{
				return 0; // invalid
			}

		}else if((to_y-y == 2) && (y == 1)){
			if(to_x-x == 0){
				// check if blocked by other piece
				if(!board->is_empty(x,y+1)){
					return 0;
				}

				// valid, check if occupied.
				if(board->is_empty(x,y+2)){
					return 1; // reachable and empty
				}else {
					return 0; // can't capture straight forward
				}
			}else{
				return 0; // invalid move two steps forward and one to the side is not okay.
			}
		
		}else{
			// move must be in positive y. can be positive and negative x
			return 0;
		}

	}else{
		//is white

		if((to_y-y) == -1 && (y-1 >= 0)){
			
			if(to_x-x == -1 && (x-1 >= 0)){
				if(board->is_empty(x-1,y-1)){
					return 0;
				}else if(board->piece_color(x-1,y-1) != _isWhite){
					return 2;
				}else{
					return 0;
				}

			}else if(to_x-x == 1 && ((x+1) < BOARD_ROW_SIZE)){
				if(board->is_empty(x+1,y-1)){
					return 0;
				}else if(board->piece_color(x+1,y-1) != _isWhite){
					return 2;
				}else{
					return 0;
				}
			}else if(to_x-x == 0){
				if(board->is_empty(x,y-1)){
					return 1;
				}else{
					return 0;
				}

			}else{
				return 0; // invalid
			}

		}else if((to_y-y == -2) && (y == 6)){
			if(to_x-x == 0){
				// check if blocked by other piece
				if(!board->is_empty(x,y-1)){
					return 0;
				}
				// valid, check if occupied.
				if(board->is_empty(x,y-2)){
					return 1; // reachable and empty
				}else {
					return 0; // can't capture straight forward
				}
			}else{
				return 0; // invalid move two steps forward and one to the side is not okay.
			}
		
		}else{
			return 0;
		}
	}
}

char32_t Pawn::utfRepresentation(){
    if(_isWhite == true){
      return U'\U00002659';
    }else{
      return U'\U0000265F';
    }
}

char Pawn::latin1Representation(){
    if(_isWhite == true){
      return 'P';
    }else{
      return 'p';
    }
}

vector<ChessMove> Pawn::capturingMoves() {

  std::vector<ChessMove> v = {};

  if(_isWhite){
  	
  	if(capturingMove(x+1,y-1)){
        ChessMove cm{x,y,x+1,y-1,this};
        v.push_back(cm);
  	}

	if(capturingMove(x-1,y-1)){
        ChessMove cm{x,y,x-1,y-1,this};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y-1)){
        ChessMove cm{x,y,x,y-1,this};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y-2)){
        ChessMove cm{x,y,x,y-2,this};
        v.push_back(cm);
  	}

  }else{
	if(capturingMove(x+1,y+1)){
        ChessMove cm{x,y,x+1,y+1,this};
        v.push_back(cm);
  	}

	if(capturingMove(x-1,y+1)){
        ChessMove cm{x,y,x-1,y+1,this};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y+1)){
        ChessMove cm{x,y,x,y+1,this};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y+2)){
        ChessMove cm{x,y,x,y+2,this};
        v.push_back(cm);
  	}
  }

  return v;
}

vector<ChessMove> Pawn::nonCapturingMoves() {
  std::vector<ChessMove> v = {};

  if(_isWhite){
  	
  	if(nonCapturingMove(x+1,y-1)){
        ChessMove cm{x,y,x+1,y-1,this};
        v.push_back(cm);
  	}

	if(nonCapturingMove(x-1,y-1)){
        ChessMove cm{x,y,x-1,y-1,this};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y-1)){
        ChessMove cm{x,y,x,y-1,this};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y-2)){
        ChessMove cm{x,y,x,y-2,this};
        v.push_back(cm);
  	}

  }else{
	if(nonCapturingMove(x+1,y+1)){
        ChessMove cm{x,y,x+1,y+1,this};
        v.push_back(cm);
  	}

	if(nonCapturingMove(x-1,y+1)){
        ChessMove cm{x,y,x-1,y+1,this};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y+1)){
        ChessMove cm{x,y,x,y+1,this};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y+2)){
        ChessMove cm{x,y,x,y+2,this};
        v.push_back(cm);
  	}
  }

  return v;
}

/**

Knight

*/

Knight::Knight(bool isWhite){
	_isWhite = isWhite;
    //std::cout << ((_isWhite == true) ? "White " : "Black ")  << "Knight: " << utfRepresentation() << std::endl;
    x = UNPLACED_PIECE_INDEX;
    y = UNPLACED_PIECE_INDEX;
}

vector<ChessMove> Knight::capturingMoves(){

  std::vector<ChessMove> v = {};

  if(capturingMove(x+2,y-1)){
    ChessMove cm{x,y,x+2,y-1,this};
    v.push_back(cm);
  }

  if(capturingMove(x+2,y+1)){
    ChessMove cm{x,y,x+2,y+1,this};
    v.push_back(cm);
  }

  if(capturingMove(x-2,y-1)){
    ChessMove cm{x,y,x-2,y-1,this};
    v.push_back(cm);
  }

  if(capturingMove(x-2,y+1)){
    ChessMove cm{x,y,x-2,y+1,this};
    v.push_back(cm);
  }

  if(capturingMove(x+1,y-2)){
    ChessMove cm{x,y,x+1,y-2,this};
    v.push_back(cm);
  }
  if(capturingMove(x-1,y-2)){
    ChessMove cm{x,y,x-1,y-2,this};
    v.push_back(cm);
  }
  if(capturingMove(x+1,y+2)){
    ChessMove cm{x,y,x+1,y+2,this};
    v.push_back(cm);
  }
  if(capturingMove(x-1,y+2)){
    ChessMove cm{x,y,x-1,y+2,this};
    v.push_back(cm);
  }

  return v;



}

vector<ChessMove> Knight::nonCapturingMoves(){

  std::vector<ChessMove> v = {};

  if(nonCapturingMove(x+2,y-1)){
    ChessMove cm{x,y,x+2,y-1,this};
    v.push_back(cm);
  }

  if(nonCapturingMove(x+2,y+1)){
    ChessMove cm{x,y,x+2,y+1,this};
    v.push_back(cm);
  }

  if(nonCapturingMove(x-2,y-1)){
    ChessMove cm{x,y,x-2,y-1,this};
    v.push_back(cm);
  }

  if(nonCapturingMove(x-2,y+1)){
    ChessMove cm{x,y,x-2,y+1,this};
    v.push_back(cm);
  }

  if(nonCapturingMove(x+1,y-2)){
    ChessMove cm{x,y,x+1,y-2,this};
    v.push_back(cm);
  }
  if(nonCapturingMove(x-1,y-2)){
    ChessMove cm{x,y,x-1,y-2,this};
    v.push_back(cm);
  }
  if(nonCapturingMove(x+1,y+2)){
    ChessMove cm{x,y,x+1,y+2,this};
    v.push_back(cm);
  }
  if(nonCapturingMove(x-1,y+2)){
    ChessMove cm{x,y,x-1,y+2,this};
    v.push_back(cm);
  }

  return v;

}

int Knight::validMove(int to_x, int to_y){

	if((to_x > BOARD_MAX_INDEX || to_x < 0) || (to_y > BOARD_MAX_INDEX || to_y < 0)){
		return 0; // outside of board
	}

	if(to_x == x+2){

		if(to_y == y+1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}

		}else if(to_y == y-1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}
		}else{
			return 0;
		}

	}else if(to_x == x-2){

		if(to_y == y+1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}

		}else if(to_y == y-1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}
		}else{
			return 0;
		}

	}else if(to_y == y+2){

		if(to_x == x+1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}

		}else if(to_x == x-1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}
		}else{
			return 0;
		}

	}else if(to_y == y-2){

		if(to_x == x+1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}

		}else if(to_x == x-1){
			if(board->is_empty(to_x,to_y)){
				return 1;
			}else if(board->piece_color(to_x,to_y) != _isWhite){
				return 2;
			}else{
				return 0; // same color
			}
		}else{
			return 0;
		}

	}else{
		return 0;
	}


}

char32_t Knight::utfRepresentation(){
    if(_isWhite == true){
      return U'\U00002658';
    }else{
      return U'\U0000265E';
    }
}

char Knight::latin1Representation(){
    if(_isWhite == true){
      return 'N';
    }else{
      return 'n';
    }

}  


/**

Bishop

*/

Bishop::Bishop(bool isWhite){
	_isWhite = isWhite;
    //std::cout << ((_isWhite == true) ? "White " : "Black ")  << "Bishop: " << utfRepresentation() << std::endl;
    x = UNPLACED_PIECE_INDEX;
    y = UNPLACED_PIECE_INDEX;
}

vector<ChessMove> Bishop::capturingMoves(){

	std::vector<ChessMove> v = {};

	int steps_positive_x = BOARD_MAX_INDEX - x;
	int steps_positive_y = BOARD_MAX_INDEX - y;
	int steps_negative_x = x;
	int steps_negative_y = y;

	// check all 4 directions

	// pos x, pos y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(capturingMove(x+i,y+i)){
			ChessMove cm{x,y,x+i,y+i,this};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(capturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this};
			v.push_back(cm);
		}
	}

	return v;
}

vector<ChessMove> Bishop::nonCapturingMoves(){

	std::vector<ChessMove> v = {};


	int steps_positive_x = BOARD_MAX_INDEX - x;
	int steps_positive_y = BOARD_MAX_INDEX - y;
	int steps_negative_x = x;
	int steps_negative_y = y;

	// check all 4 directions

	// pos x, pos y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(nonCapturingMove(x+i,y+i)){
			ChessMove cm{x,y,x+i,y+i,this};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(nonCapturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this};
			v.push_back(cm);
		}
	}

	return v;
}

int Bishop::validMove(int to_x, int to_y){

	// outside board
	if((to_x < 0 || to_x > BOARD_MAX_INDEX) || (to_y < 0 || to_y > BOARD_MAX_INDEX)){
		return 0;
	}

	// non diagonal move
	if(abs(to_x-x) != abs(to_y-y)){
		return 0;
	}

	// no move
	if(to_x-x == 0 || to_y-y == 0){
		return 0;
	}

	int steps = 0;
	int dir_x = 0;
	int dir_y = 0;

	// find direction of piece
	if(to_x-x > 0){
		dir_x = 1;
	}else{
		dir_x = -1;
	}

	if(to_y-y > 0){
		dir_y = 1;
	}else{
		dir_y = -1;
	}

	// calc number of steps
	if(to_x-x < to_y-y){
		steps = abs(to_x-x);
	}else{
		steps = abs(to_y-y);
	}

	// move piece and check if place is occupied.
	for(int i = 1;i<steps;++i){
		if(board->is_empty(x + dir_x * i, y + dir_y * i ) == false){
			return 0;
		}
	}

	// check final space
	if(board->is_empty(to_x,to_y)){
		return 1;
	}else{
		if(board->piece_color(to_x,to_y) != _isWhite){
			return 2;
		}else{
			return 0;
		}
	}
}

char32_t Bishop::utfRepresentation(){
    if(_isWhite == true){
      return U'\U00002657';
    }else{
      return U'\U0000265D';
    }
}

char Bishop::latin1Representation(){
    if(_isWhite == true){
      return 'B';
    }else{
      return 'b';
    }

}

/**

Queen

*/

Queen::Queen(bool isWhite){
	_isWhite = isWhite;
    //std::cout << ((_isWhite == true) ? "White " : "Black ")  << "Queen: " << utfRepresentation() << std::endl;
    x = UNPLACED_PIECE_INDEX;
    y = UNPLACED_PIECE_INDEX;
}

vector<ChessMove> Queen::capturingMoves(){

	std::vector<ChessMove> v = {};

	int steps_positive_x = BOARD_MAX_INDEX - x;
	int steps_positive_y = BOARD_MAX_INDEX - y;
	int steps_negative_x = x;
	int steps_negative_y = y;

	// check all 8 directions

	// pos x, pos y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(capturingMove(x+i,y+i)){
			ChessMove cm{x,y,x+i,y+i,this};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(capturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this};
			v.push_back(cm);
		}
	}

	// neutral x, neg y
	for(int i = 1; i<=steps_negative_y; ++i){
		if(capturingMove(x,y-i)){
			ChessMove cm{x,y,x,y-i,this};
			v.push_back(cm);
		}
	}

	// neutral x, pos y
	for(int i = 1; i<=steps_positive_y; ++i){
		if(capturingMove(x,y+i)){
			ChessMove cm{x,y,x,y+i,this};
			v.push_back(cm);
		}
	}

	// neutral y, neg x
	for(int i = 1; i<=steps_negative_x; ++i){
		if(capturingMove(x-i,y)){
			ChessMove cm{x,y,x-i,y,this};
			v.push_back(cm);
		}
	}

	// neutral y, pos x
	for(int i = 1; i<=steps_positive_x; ++i){
		if(capturingMove(x+i,y)){
			ChessMove cm{x,y,x+i,y,this};
			v.push_back(cm);
		}
	}

	return v;

}

vector<ChessMove> Queen::nonCapturingMoves(){
	std::vector<ChessMove> v = {};

	int steps_positive_x = BOARD_MAX_INDEX - x;
	int steps_positive_y = BOARD_MAX_INDEX - y;
	int steps_negative_x = x;
	int steps_negative_y = y;

	// check all 8 directions

	// pos x, pos y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(nonCapturingMove(x+i,y+i)){
			ChessMove cm{x,y,x+i,y+i,this};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(nonCapturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this};
			v.push_back(cm);
		}
	}

	// neutral x, neg y
	for(int i = 1; i<=steps_negative_y; ++i){
		if(nonCapturingMove(x,y-i)){
			ChessMove cm{x,y,x,y-i,this};
			v.push_back(cm);
		}
	}

	// neutral x, pos y
	for(int i = 1; i<=steps_positive_y; ++i){
		if(nonCapturingMove(x,y+i)){
			ChessMove cm{x,y,x,y+i,this};
			v.push_back(cm);
		}
	}

	// neutral y, neg x
	for(int i = 1; i<=steps_negative_x; ++i){
		if(nonCapturingMove(x-i,y)){
			ChessMove cm{x,y,x-i,y,this};
			v.push_back(cm);
		}
	}

	// neutral x, pos y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(nonCapturingMove(x+i,y)){
			ChessMove cm{x,y,x+i,y,this};
			v.push_back(cm);
		}
	}

	return v;

}

int Queen::validMove(int to_x, int to_y){

	// outside board
	if((to_x < 0 || to_x > BOARD_MAX_INDEX) || (to_y < 0 || to_y > BOARD_MAX_INDEX)){
		return 0;
	}

	// no move
	if(to_x == x && to_y == y){
		return 0;
	}
	
	int steps = 0;
	int dir_x = 0;
	int dir_y = 0;

	// 8 possible directions
	if(to_x-x > 0){
		dir_x = 1;
	}else if(to_x-x < 0){
		dir_x = -1;
	}else{
		dir_x = 0;
	}
	
	if(to_y-y > 0){
		dir_y = 1;
	}else if(to_y-y < 0){
		dir_y = -1;
	}else{
		dir_y = 0;
	}

	// calc number of steps
	if(abs(to_x-x) > abs(to_y-y)){
		steps = abs(to_x-x);
	}else{
		steps = abs(to_y-y);
	}

	// move piece and check if place is occupied.
	for(int i = 1;i<steps;++i){
		if(board->is_empty(x + dir_x * i, y + dir_y * i ) == false){
			return 0;
		}
	}

	// check final space
	if(board->is_empty(to_x,to_y)){
		return 1;
	}else{
		if(board->piece_color(to_x,to_y) != _isWhite){
			return 2;
		}else{
			return 0;
		}
	}
}

char32_t Queen::utfRepresentation(){
    if(_isWhite == true){
      return U'\U00002655';
    }else{
      return U'\U0000265B';
    }
}

char Queen::latin1Representation(){
    
    if(_isWhite == true){
      return 'Q';
    }else{
      return 'q';
    }

}

/**

King

*/

King::King(bool isWhite){
	_isWhite = isWhite;
    //std::cout << ((_isWhite == true) ? "White " : "Black ")  << "King: " << utfRepresentation() << std::endl;
    x = UNPLACED_PIECE_INDEX;
    y = UNPLACED_PIECE_INDEX;
}

vector<ChessMove> King::capturingMoves(){


	vector<ChessMove> v = {};

	// iterate possible positions starting top left corner	
	int movement_matrix_rows = 3;
	int start_x = x-1;
	int start_y = y-1;

	for(int i = 0;i<movement_matrix_rows;++i){
		for(int j = 0;j<movement_matrix_rows;++j){

			int temp_x = start_x+j;			
			int temp_y = start_y+i;

			if(!(temp_x == x && temp_y == y)){
				if(capturingMove(temp_x,temp_y)){
					ChessMove cm{x,y,temp_x,temp_y,this};
					v.push_back(cm);
				}
			}
		}
	}

	return v;
}

vector<ChessMove> King::nonCapturingMoves(){

	vector<ChessMove> v = {};

	// iterate possible positions starting top left corner	
	int movement_matrix_rows = 3;
	int start_x = x-1;
	int start_y = y-1;

	for(int i = 0;i<movement_matrix_rows;++i){
		for(int j = 0;j<movement_matrix_rows;++j){

			int temp_x = start_x+j;			
			int temp_y = start_y+i;

			if(!(temp_x == x && temp_y == y)){
				if(nonCapturingMove(temp_x,temp_y)){
					ChessMove cm{x,y,temp_x,temp_y,this};
					v.push_back(cm);
				}
			}
		}
	}

	return v;
}

int King::validMove(int to_x, int to_y){

	// no move
	if(to_x == x && to_y == y){
		return 0;
	}

	// outside board
	if((to_x < 0 || to_x >BOARD_MAX_INDEX) || (to_y < 0 || to_y >BOARD_MAX_INDEX)){
		return 0;
	}

	if(abs(to_x-x) != 1 && abs(to_x-x) != 0){
		return 0;
	}

 	if(abs(to_y-y) != 1 && abs(to_y-y) != 0){
		return 0;
	}

	if(board->is_empty(to_x,to_y)){
		return 1;
	}else{
		if(board->piece_color(to_x,to_y) != _isWhite){
			return 2;
		}else{
			return 0;
		}
	}

}

char32_t King::utfRepresentation(){
    if(_isWhite == true){
      return U'\U00002654';
    }else{
      return U'\U0000265A';
    }
}

char King::latin1Representation(){
    if(_isWhite == true){
      return 'K';
    }else{
      return 'k';
    }
}
