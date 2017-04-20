#include "chess.h"

using namespace std;

/**

ChessMove

*/

std::string ChessMove::toString(){

  std::string str = "";

  /*
  char from_x = (char) (cm.from_x+LITERAL_INDEX_OFFSET);
  char from_y = (char) (cm.from_y+INTEGER_INDEX_OFFSET);
  char to_x   = (char) (cm.to_x+LITERAL_INDEX_OFFSET);
  char to_y   = (char) (cm.to_y+INTEGER_INDEX_OFFSET);
  */

  str += (char) (from_x + LITERAL_INDEX_OFFSET);
  str += (char) (from_y + INTEGER_INDEX_OFFSET);
  str += '-';
  str += (char) (to_x + LITERAL_INDEX_OFFSET);
  str += (char) (to_y + INTEGER_INDEX_OFFSET);


  // TODO print pawn promotion

  return str;
}



/**

Chesspiece

*/
bool ChessPiece::isWhite(){
  return _isWhite;
}

std::vector<ChessPiece*> ChessBoard::getChessPieces(bool isWhite){
  std::vector<ChessPiece*> vec = {};
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    for(int j = 0; j<BOARD_ROW_SIZE; ++j){
      if(state(i,j) != nullptr && chessColorMatrix(i,j) != isWhite){
        vec.push_back(state(i,j));
      }    
    }
  }
  return vec;
}

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
  whiteToPlay_ = true;
}

ChessBoard::~ChessBoard(){
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    for(int j = 0; j<BOARD_ROW_SIZE; ++j){
      delete state(i,j);
    }
  }
}

ChessMove ChessBoard::simple_ai_move(){
  
  // check if capturing moves, random if multiple
  std::vector<ChessMove> v1 = capturingMoves(false);
  std::vector<ChessMove> v2 = nonCapturingMoves(false);

  if(v1.size() != 0){
    //unsigned SEED = 911206;
    //unsigned SEED = 971616; 
    std::srand(std::time(0));
    std::random_shuffle(v1.begin(), v1.end());    
    //std::shuffle(v1.begin(),v1.end(),std::default_random_engine(SEED));
    move_piece(v1[0]);
    //std::cout << moveToString(v1[0]) << std::endl;
    return v1[0];
  }

  // otherwise randomly select from noncapturing
  if(v2.size() != 0){
    //unsigned SEED = 911206;
    //unsigned SEED = 971616;
    //std::shuffle(v2.begin(),v2.end(),std::default_random_engine(SEED));
    std::srand(std::time(0));
    std::random_shuffle(v2.begin(),v2.end());   
    move_piece(v2[0]);
    //std::cout << moveToString(v2[0]) << std::endl;
    return v2[0];
  }

  return v2[0];
}

ChessMove ChessBoard::improved_ai_move(bool isBlack){

  //bool isWhite = false;
  ChessMove cm;

  int opponentCapturingMoves = capturingMoves(isBlack).size();
  std::cout << "capturing moves: " << opponentCapturingMoves << std::endl;
  std::vector<ChessMove> blackCapturingMoves = capturingMoves(!isBlack);
  std::vector<ChessMove> blackNonCapturingMoves = nonCapturingMoves(!isBlack);

  if(blackCapturingMoves.size() == 0 && blackNonCapturingMoves.size() == 0){
    std::cout << "no moves possible" << std::endl;
    return cm;
  }

  int numberPotentialMoves = 0;
  if(blackCapturingMoves.size() != 0){

    // check for every move if number of opponents capturing moves increases
    auto it = blackCapturingMoves.begin();
    std::vector<chessMove> v;
    while(it != blackCapturingMoves.end()){
      int moves = potentialMoves(it->to_x,it->to_y,isBlack,true);
      std::cout << "moves" << moves << std::endl;

      // WORK IN PROGRESS
      
      if(moves == 1){
        v.push_back(*it);
      }

      // UNTIL HERE

      // TODO this region should be removed?
      if(moves > numberPotentialMoves){
        cm = *it;
        numberPotentialMoves = moves;
      }
      ++it;
    }

    // WORK IN PROGRESS
    
    int best_move_index = 0;
    int capturing_moves = 0;
    int count = 0;
    auto m_it = v.begin();
    while(m_it != v.end()){

      int temp_count = 0;
      for(int i = 0;i<v.size();++i){
        if(i != count){
          if(v[i].to_x == m_it->to_x && v[i].to_y == m_it->to_y){
            ++temp_count;
          }
        }
      }

      if(temp_count > capturing_moves){
        best_move_index = count;
        capturing_moves = temp_count;
      }

      ++count;
      ++it;
    }

    // UNTIL HERE



    std::cout << "number potential capturing moves by capture: " << numberPotentialMoves << std::endl;


    if(numberPotentialMoves > opponentCapturingMoves){
      move_piece(cm);
      std::cout << cm.toString() << std::endl;
      return cm;
    }else{
      // select random capturing
      //unsigned SEED = 911206;
      //unsigned SEED = 971616;
      //std::shuffle(blackCapturingMoves.begin(),blackCapturingMoves.end(),std::default_random_engine(SEED));
      std::srand(std::time(0));
      std::random_shuffle(blackCapturingMoves.begin(), blackCapturingMoves.end());  
      move_piece(blackCapturingMoves[0]);
      //std::cout << moveToString(blackCapturingMoves[0]) << std::endl;
      return blackCapturingMoves[0];
    }
  }

  numberPotentialMoves = 0;
  if(blackNonCapturingMoves.size() != 0){

    auto it = blackNonCapturingMoves.begin();
    while(it != blackNonCapturingMoves.end()){
      // change colorMatrix temporarily to count moves after capture
    
      int moves = potentialMoves(it->to_x,it->to_y,isBlack,false);
      std::cout << "moves: " << moves << std::endl;
      if(moves > numberPotentialMoves){
        cm = *it;
        numberPotentialMoves = moves;
      }
      ++it;
    }
    std::cout << "number potential capturing moves by nocapture: " << numberPotentialMoves << std::endl;

    if(numberPotentialMoves > 0){
      move_piece(blackNonCapturingMoves[0]);
      //std::cout << moveToString(blackNonCapturingMoves[0]) << std::endl;
      return blackNonCapturingMoves[0];
    }else{
      // select random noncapturing game...
      // unsigned SEED = 911206;
      // unsigned SEED = 971616;
      std::srand(std::time(0));
      std::random_shuffle(blackNonCapturingMoves.begin(), blackNonCapturingMoves.end());  
      //std::shuffle(blackNonCapturingMoves.begin(),blackNonCapturingMoves.end(),std::default_random_engine(SEED));
      move_piece(blackNonCapturingMoves[0]);
      //std::cout << moveToString(blackNonCapturingMoves[0]) << std::endl;
      return blackNonCapturingMoves[0];
    }
  }

  std::cout << "ERROR: NO POSSIBLE MOVE" << std::endl;
  return cm;
}

// A - H corresponds to 65-72
// Example of valid input A1-A2
bool ChessBoard::user_move(){

  std::string input;
  std::cout << "> ";
  while(input.length() == 0){
    std::getline(std::cin, input);
  }
  
  // parse input
  int from_x = 0;
  int from_y = 0;
  int to_x = 0;
  int to_y = 0;

  if(input[0] == 'l' && input.length() == 1){
    print_board(false,std::cout);
    return false;
  }

  if(input[0] == 'L' && input.length() == 1){
    print_board(true,std::cout);
    return false;
  }


  if(input.length() != 5 && input.length() != 9){
    std::cout << "bad input" << std::endl;
    return false;
  }

  if((int) input[0] >= 65 && (int) input[0] <= 72){
    from_x = ((int) input[0]) - LITERAL_INDEX_OFFSET;     
  }else{
    // failed parsing
    return false;
  }

  if(input[1] > '0' && input[1] <= '8'){
    from_y = ((int) input[1]) - INTEGER_INDEX_OFFSET;
  }else{
    return false;
  }

  if(input[2] != '-'){
    return false;
  }

  if((int) input[3] >= 65 && (int) input[3] <= 72){
    to_x = ((int) input[3]) - LITERAL_INDEX_OFFSET;
  }else{
    // failed parsing try again
    return false;
  }

  if(input[4] > '0' && input[4] <= '8'){
    to_y = ((int) input[4]) - INTEGER_INDEX_OFFSET;
  }else{
    return false;
  }

  ChessPiece * piece = getChessPiece(from_x,from_y);
  if(piece == nullptr){
    std::cout << "No piece at position, try again" << std::endl;
    return false;
  }

  if(piece_color(from_x,from_y) == false){
    std::cout << "Can't move opponent's (black) pieces" << std::endl;
    return false;
  }

  if(piece_color(from_x,from_y) == piece_color(to_x,to_y)){
    std::cout << "Can't capture piece of same color" << std::endl;
    return false;
  }

  // Parsing promotion choice
  if(input.length() == 9){
    if(input[6] != '('){
      std::cout << "missing opening parenthesis, input[7]" << std::endl;
      return false;
    }

    // TODO: CHECK FOR COLORS
    std::string pieces = "QqBbRrNn";
    std::size_t found = pieces.find(input[7]);
    if(found == std::string::npos){
      std::cout << "invalid promotion" << std::endl;
      return false;
    }

    if(input[8] != ')'){
      std::cout << "missing closing parenthesis" << std::endl;
      return false;
    }
  }

  // check validity of moves
  if(piece->capturingMove(to_x,to_y)){
    std::cout << "Capturing" << std::endl;
    if(input.length() == 9){
      ChessMove cm{from_x,from_y,to_x,to_y,piece,input[7]};
      move_piece(cm);
    }else{
      ChessMove cm{from_x,from_y,to_x,to_y,piece,NO_PROMOTION};
      move_piece(cm);
    }
  }else if(piece->nonCapturingMove(to_x,to_y)){

    // only allowed if there are no possible captures
    if(capturingMoves(true).size() > 0){
      std::cout << "Capturing is compulsory, try again" << std::endl;
      return false; 
    }

    if(input.length() == 9){
      ChessMove cm{from_x,from_y,to_x,to_y,piece,input[7]};
      move_piece(cm);
    }else{
      ChessMove cm{from_x,from_y,to_x,to_y,piece,NO_PROMOTION};
      move_piece(cm);
    }
  }else{
    std::cout << "Invalid move, try again" << std::endl;
    return false;
  }
  return true;

}

void ChessBoard::reset_board(){

  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    for(int j = 0; j<BOARD_ROW_SIZE; ++j){
      delete state(i,j);
      state(i,j) = nullptr;
      chessColorMatrix(i,j) = false;
    }
  }
  whiteToPlay_ = true;

}

int ChessBoard::menu(){
  std::cout << "1 - New Game \n" 
        << "2 - Load Game\n"
        << "3 - AI 1 vs. AI 2 New Game\n"
        << "4 - AI 1 vs. AI 2 Load Game\n"
        << "0 - Quit" 
        << std::endl;
  int choice = 0;
  std::cout << "Choice: ";
  std::cin >> choice;
  return choice;
}

void ChessBoard::game_loop(bool isAIvsAI){

  // ask for input as long as no winner.
  // check_winner();
  // user move -- check that there are moves possible
  // ai_move

  std::ofstream myfile;
  if(isAIvsAI){
    myfile.open("aigame.txt");
    print_board(false,myfile);
  }

  bool start = true; // game just started or resumed from loaded state
  int round = 0;
  while(true){

    if(round == 5){
      if(isAIvsAI){
        print_board(false,myfile);
      }
      if(isAIvsAI){
        myfile << "white pieces: " << numberOfPieces(true) << std::endl;
        myfile << "black pieces: " << numberOfPieces(false) << std::endl;  
      }else{
        std::cout << "white pieces: " << numberOfPieces(true) << std::endl;
        std::cout << "black pieces: " << numberOfPieces(false) << std::endl; 
      }
    }

    if(capturingMoves(true).size() == 0 && nonCapturingMoves(true).size() == 0){
    
      if(isAIvsAI){
        myfile << "\nNo moves left for White " << std::endl;
        print_board(false,myfile);
        myfile << "White pieces: " << numberOfPieces(true) << std::endl;
        myfile << "Black pieces: " << numberOfPieces(false) << std::endl;
        myfile << ((numberOfPieces(true) <= numberOfPieces(false)) ? "White Wins!" : "Black Wins!") << std::endl;
        break;
      }else{
        std::cout << "No moves left for White " << std::endl;
        print_board(true,std::cout);
        std::cout << "White pieces: " << numberOfPieces(true) << std::endl;
        std::cout << "Black pieces: " << numberOfPieces(false) << std::endl;
        std::cout << ((numberOfPieces(true) <= numberOfPieces(false)) ? "White Wins!" : "Black Wins!") << std::endl;
        break;
      }
    }

    // white's move of round
    if(start==false || getTurn() == true){
      if(isAIvsAI){
        ChessMove cm = improved_ai_move(false);
        myfile << cm.toString() << "   ";
      }else{
        while(user_move() == false);
      }
    }
    start = false;


    if(capturingMoves(false).size() == 0 && nonCapturingMoves(false).size() == 0){
      if(isAIvsAI){
        myfile << "\nNo moves left for Black " << std::endl;
        print_board(true,myfile);
        myfile << "White pieces: " << numberOfPieces(true) << std::endl;
        myfile << "Black pieces: " << numberOfPieces(false) << std::endl;
        myfile << ((numberOfPieces(false) <= numberOfPieces(true)) ? "Black Wins!" : "White Wins!") << std::endl;
        break;
      }else{
        std::cout << "No moves left for Black " << std::endl;
        print_board(true,std::cout);
        std::cout << "White pieces: " << numberOfPieces(true) << std::endl;
        std::cout << "Black pieces: " << numberOfPieces(false) << std::endl;
        std::cout << ((numberOfPieces(false) <= numberOfPieces(true)) ? "Black Wins!" : "White Wins!") << std::endl;
        break;
      }
    }

    // black's move of round
    if(isAIvsAI){
      ChessMove cm = simple_ai_move();
      myfile << cm.toString() << "\n";
    }else{
      ChessMove cm = improved_ai_move(true);
      std::cout << cm.toString() << std::endl;
    }

    if(round >= 5){
      round = 0;
    }
    ++round;

  }

  if(isAIvsAI){
    myfile.close();
  }

  //reset_board();
}

bool ChessBoard::load_game(bool newGame){

  // create board and stuff
  if(newGame){
    // create new board

    std::stringstream s;
    s << "rnbqkbnr" << std::endl;
    s << "pppppppp" << std::endl;
    s << "........" << std::endl;
    s << "........" << std::endl;
    s << "........" << std::endl;
    s << "........" << std::endl;
    s << "PPPPPPPP" << std::endl;
    s << "RNBQKBNR";
    s >> *this;

    return true;

  }else{
    // load game from file

    std::ifstream myinput;
    myinput.open("board.txt");
    try{
      myinput >> *this;
    }catch(std::exception& e){
      std::cout << "Error loading board: " << e.what() << std::endl;
      return false;
    }
    myinput.close();
    return true;
  }
}

void ChessBoard::start_game(){
  std::cout << "Chess Game" << std::endl;
  int choice = 0;
  while((choice = menu()) !=  0){
    if(choice == 1){
      bool isLoaded = load_game(true);
      if(isLoaded){
        print_board(true,std::cout);
        game_loop(false);
        //reset_board();      
      }
    }else if(choice == 2){
      bool isLoaded = load_game(false);
      if(isLoaded){
        print_board(true,std::cout);
        game_loop(false);
        //reset_board();
      }
    }else if(choice == 3){
      bool isLoaded = load_game(true);
      if(isLoaded){
        //print_board(true,std::cout);
        game_loop(true);        
        //reset_board();
      }
    }else if(choice == 4){
      bool isLoaded = load_game(false);
      if(isLoaded){
        //print_board(true,std::cout);
        game_loop(true);
        //reset_board();
      }
    }else{
      break;
    }
  }
}

int ChessBoard::potentialMoves(int x, int y, bool isWhite, bool isCapturing){
  
  std::vector<ChessMove> vec;
  // change color temporarily to count potential captures
  if(isCapturing){
    chessColorMatrix(x,y) = !isWhite;
    std::cout << "YEAH BOY" << std::endl;
    vec = capturingMoves(isWhite);
    std::vector<ChessMove> temp = capturingMoves(!isWhite);
    std::cout << "SIZE OF THIS SHIT: " << vec.size() << std::endl;
    chessColorMatrix(x,y) = isWhite;
  }else{
    ChessPiece * pawn = new Pawn(!isWhite); // could be any temp piece
    ChessMove cm{-1,-1,x,y,pawn,NO_PROMOTION};
    move_piece(cm);
    vec = capturingMoves(isWhite);
    //std::cout << "AND OF THIS SHIT: " << vec.size() << std::endl;

    // TEST
    auto it = vec.begin();
    std::cout << "non cap forcing moves: " << std::endl;
    while(it != vec.end()){

      std::cout << it->from_x << ", " << it->from_y << "   " << it->to_x << ", " << it->to_y << std::endl; 

      ++it;
    }


    cm  = {x,y,-1,-1,pawn,NO_PROMOTION};
    move_piece(cm);
    delete pawn;
  }

  return vec.size();
}

int ChessBoard::numberOfPieces(bool isWhite){

  int count = 0;

  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    for(int j = 0; j<BOARD_ROW_SIZE; ++j){
      if(state(i,j) != nullptr && chessColorMatrix(i,j) == isWhite){
        ++count;
      }    
    }
  }

  return count;
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

ChessPiece * ChessBoard::getChessPiece(int x,int y){
  return state(x,y);
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

void ChessBoard::print_board(bool printAsUTF,std::ostream & out){

  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv32;
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    for(int j = 0;j < BOARD_ROW_SIZE; ++j){

      ChessPiece * p = state(j,i);
      if(printAsUTF && p != nullptr){
        //std::cout << p->_isWhite;
        out << conv32.to_bytes(p->utfRepresentation()) << " ";
        //std::cout << conv32.to_bytes(p->utfRepresentation()) << " ";
        //std::cout << p->utfRepresentation() << " ";
      }else if(p != nullptr){
        out << p->latin1Representation() << " ";
      }else{
        out << ". ";
      }
    }
    out << std::endl;
  }
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


void ChessBoard::setTurn(bool whiteToPlay){
  whiteToPlay_ = whiteToPlay;
}

bool ChessBoard::getTurn(){
  return whiteToPlay_;
}


void ChessBoard::move_piece(ChessMove chessMove){

  bool isWhite = chessMove.piece->_isWhite;

	// if piece already placed on board
	if((chessMove.from_x != UNPLACED_PIECE_INDEX) && (chessMove.from_y != UNPLACED_PIECE_INDEX)){
		
    state(chessMove.from_x,chessMove.from_y) = nullptr;
		chessColorMatrix(chessMove.from_x,chessMove.from_y) = false;
    if(chessMove.to_x != UNPLACED_PIECE_INDEX && chessMove.to_y != UNPLACED_PIECE_INDEX){
      delete state(chessMove.to_x,chessMove.to_y); // freeing up memory before being captured

      // check if pawn and if it should be promoted
      if(chessMove.piece->latin1Representation() == 'p' && chessMove.to_y == BOARD_MAX_INDEX){
        // black pawn reach other side
        ChessPiece * piece = nullptr;
        if(chessMove.promoteTo == 'b'){
          piece = new Bishop(false);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }else if(chessMove.promoteTo == 'n'){
          piece = new Knight(false);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }else if(chessMove.promoteTo == 'r'){
          piece = new Rook(false);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }else{
          // queen
          piece = new Queen(false);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }
        piece->board = this;
        piece->x = chessMove.to_x;
        piece->y = chessMove.to_y;
        chessColorMatrix(chessMove.to_x,chessMove.to_y) = false;
        delete chessMove.piece;

      }else if(chessMove.piece->latin1Representation() == 'P' && chessMove.to_y == 0){
        //white
        ChessPiece * piece = nullptr;
        if(chessMove.promoteTo == 'B'){
          piece = new Bishop(true);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }else if(chessMove.promoteTo == 'N'){
          piece = new Knight(true);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }else if(chessMove.promoteTo == 'R'){
          piece = new Rook(true);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }else{
          // queen
          piece = new Queen(true);
          state(chessMove.to_x,chessMove.to_y) = piece;
        }
        piece->board = this;
        piece->x = chessMove.to_x;
        piece->y = chessMove.to_y;
        chessColorMatrix(chessMove.to_x,chessMove.to_y) = true;
        delete chessMove.piece;
      }else{
        // no promotion 
        state(chessMove.to_x,chessMove.to_y) = chessMove.piece;
        chessMove.piece->x = chessMove.to_x;
        chessMove.piece->y = chessMove.to_y;
      }
    }
	}else{
		state(chessMove.to_x,chessMove.to_y) = chessMove.piece;
		chessMove.piece->board = this;
    chessMove.piece->x = chessMove.to_x;
    chessMove.piece->y = chessMove.to_y;
	}

  if(chessMove.to_x != UNPLACED_PIECE_INDEX && chessMove.to_y != UNPLACED_PIECE_INDEX){
  	if(isWhite){
  		chessColorMatrix(chessMove.to_x,chessMove.to_y) = true;
  	}else{
  		chessColorMatrix(chessMove.to_x,chessMove.to_y) = false;
  	}
  }

  /*
	chessMove.piece->x = chessMove.to_x;
	chessMove.piece->y = chessMove.to_y;
  */
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
        ChessMove cm{x,y,i,y,this,NO_PROMOTION};
        v.push_back(cm);
      }
    }
  }

  // check all possible moves along y-axis
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    // skip current position
    if(i != y){
      if(capturingMove(x,i) == true){
        ChessMove cm{x,y,x,i,this,NO_PROMOTION};
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
        ChessMove cm{x,y,i,y,this,NO_PROMOTION};
        v.push_back(cm);
      }
    }
  }

  // check all possible moves along y-axis
  for(int i = 0; i<BOARD_ROW_SIZE; ++i){
    // skip current position
    if(i != y){
      if(nonCapturingMove(x,i) == true){
        ChessMove cm{x,y,x,i,this,NO_PROMOTION};
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
        ChessMove cm{x,y,x+1,y-1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

	if(capturingMove(x-1,y-1)){
        ChessMove cm{x,y,x-1,y-1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y-1)){
        ChessMove cm{x,y,x,y-1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y-2)){
        ChessMove cm{x,y,x,y-2,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  }else{
	if(capturingMove(x+1,y+1)){
        ChessMove cm{x,y,x+1,y+1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

	if(capturingMove(x-1,y+1)){
        ChessMove cm{x,y,x-1,y+1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y+1)){
        ChessMove cm{x,y,x,y+1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(capturingMove(x,y+2)){
        ChessMove cm{x,y,x,y+2,this,NO_PROMOTION};
        v.push_back(cm);
  	}
  }

  return v;
}

vector<ChessMove> Pawn::nonCapturingMoves() {
  std::vector<ChessMove> v = {};

  if(_isWhite){
  	
  	if(nonCapturingMove(x+1,y-1)){
        ChessMove cm{x,y,x+1,y-1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

	if(nonCapturingMove(x-1,y-1)){
        ChessMove cm{x,y,x-1,y-1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y-1)){
        ChessMove cm{x,y,x,y-1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y-2)){
        ChessMove cm{x,y,x,y-2,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  }else{
	if(nonCapturingMove(x+1,y+1)){
        ChessMove cm{x,y,x+1,y+1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

	if(nonCapturingMove(x-1,y+1)){
        ChessMove cm{x,y,x-1,y+1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y+1)){
        ChessMove cm{x,y,x,y+1,this,NO_PROMOTION};
        v.push_back(cm);
  	}

  	if(nonCapturingMove(x,y+2)){
        ChessMove cm{x,y,x,y+2,this,NO_PROMOTION};
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
    ChessMove cm{x,y,x+2,y-1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(capturingMove(x+2,y+1)){
    ChessMove cm{x,y,x+2,y+1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(capturingMove(x-2,y-1)){
    ChessMove cm{x,y,x-2,y-1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(capturingMove(x-2,y+1)){
    ChessMove cm{x,y,x-2,y+1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(capturingMove(x+1,y-2)){
    ChessMove cm{x,y,x+1,y-2,this,NO_PROMOTION};
    v.push_back(cm);
  }
  if(capturingMove(x-1,y-2)){
    ChessMove cm{x,y,x-1,y-2,this,NO_PROMOTION};
    v.push_back(cm);
  }
  if(capturingMove(x+1,y+2)){
    ChessMove cm{x,y,x+1,y+2,this,NO_PROMOTION};
    v.push_back(cm);
  }
  if(capturingMove(x-1,y+2)){
    ChessMove cm{x,y,x-1,y+2,this,NO_PROMOTION};
    v.push_back(cm);
  }

  return v;
}

vector<ChessMove> Knight::nonCapturingMoves(){

  std::vector<ChessMove> v = {};

  if(nonCapturingMove(x+2,y-1)){
    ChessMove cm{x,y,x+2,y-1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(nonCapturingMove(x+2,y+1)){
    ChessMove cm{x,y,x+2,y+1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(nonCapturingMove(x-2,y-1)){
    ChessMove cm{x,y,x-2,y-1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(nonCapturingMove(x-2,y+1)){
    ChessMove cm{x,y,x-2,y+1,this,NO_PROMOTION};
    v.push_back(cm);
  }

  if(nonCapturingMove(x+1,y-2)){
    ChessMove cm{x,y,x+1,y-2,this,NO_PROMOTION};
    v.push_back(cm);
  }
  if(nonCapturingMove(x-1,y-2)){
    ChessMove cm{x,y,x-1,y-2,this,NO_PROMOTION};
    v.push_back(cm);
  }
  if(nonCapturingMove(x+1,y+2)){
    ChessMove cm{x,y,x+1,y+2,this,NO_PROMOTION};
    v.push_back(cm);
  }
  if(nonCapturingMove(x-1,y+2)){
    ChessMove cm{x,y,x-1,y+2,this,NO_PROMOTION};
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
			ChessMove cm{x,y,x+i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(capturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this,NO_PROMOTION};
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
			ChessMove cm{x,y,x+i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(nonCapturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this,NO_PROMOTION};
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
			ChessMove cm{x,y,x+i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(capturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(capturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral x, neg y
	for(int i = 1; i<=steps_negative_y; ++i){
    if(capturingMove(x,y-i)){
			ChessMove cm{x,y,x,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral x, pos y
	for(int i = 1; i<=steps_positive_y; ++i){
		if(capturingMove(x,y+i)){
			ChessMove cm{x,y,x,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral y, neg x
	for(int i = 1; i<=steps_negative_x; ++i){
		if(capturingMove(x-i,y)){
			ChessMove cm{x,y,x-i,y,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral y, pos x
	for(int i = 1; i<=steps_positive_x; ++i){
		if(capturingMove(x+i,y)){
			ChessMove cm{x,y,x+i,y,this,NO_PROMOTION};
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
			ChessMove cm{x,y,x+i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// pos x, neg y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x+i,y-i)){
			ChessMove cm{x,y,x+i,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, pos y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_positive_y){
			break;
		}

		if(nonCapturingMove(x-i,y+i)){
			ChessMove cm{x,y,x-i,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neg x, neg y
	for(int i = 1; i<=steps_negative_x; ++i){
		if(i > steps_negative_y){
			break;
		}

		if(nonCapturingMove(x-i,y-i)){
			ChessMove cm{x,y,x-i,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral x, neg y
	for(int i = 1; i<=steps_negative_y; ++i){
		if(nonCapturingMove(x,y-i)){
			ChessMove cm{x,y,x,y-i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral x, pos y
	for(int i = 1; i<=steps_positive_y; ++i){
		if(nonCapturingMove(x,y+i)){
			ChessMove cm{x,y,x,y+i,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral y, neg x
	for(int i = 1; i<=steps_negative_x; ++i){
		if(nonCapturingMove(x-i,y)){
			ChessMove cm{x,y,x-i,y,this,NO_PROMOTION};
			v.push_back(cm);
		}
	}

	// neutral x, pos y
	for(int i = 1; i<=steps_positive_x; ++i){
		if(nonCapturingMove(x+i,y)){
			ChessMove cm{x,y,x+i,y,this,NO_PROMOTION};
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
					ChessMove cm{x,y,temp_x,temp_y,this,NO_PROMOTION};
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
					ChessMove cm{x,y,temp_x,temp_y,this,NO_PROMOTION};
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
