#include "chess.h"

// 		std::next_permutation(vec.begin(),vec.end());		




/*
std::string moveToString(ChessMove cm){

	std::string str = "";

	char from_x = (char) (cm.from_x+LITERAL_INDEX_OFFSET);
	char from_y = (char) (cm.from_y+INTEGER_INDEX_OFFSET);
	char to_x   = (char) (cm.to_x+LITERAL_INDEX_OFFSET);
	char to_y   = (char) (cm.to_y+INTEGER_INDEX_OFFSET);

	str += from_x;
	str += from_y;
	str += '-';
	str += to_x;
	str += to_y;

	return str;
}
*/

/*
ChessMove simple_ai_move(ChessBoard * board){
	
	// check if capturing moves, random if multiple
	std::vector<ChessMove> v1 = board->capturingMoves(false);
	std::vector<ChessMove> v2 = board->nonCapturingMoves(false);

	if(v1.size() != 0){
		//unsigned SEED = 911206;
		//unsigned SEED = 971616;	
		std::srand(std::time(0));
		std::random_shuffle(v1.begin(), v1.end());		
		//std::shuffle(v1.begin(),v1.end(),std::default_random_engine(SEED));
		board->move_piece(v1[0]);
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
		board->move_piece(v2[0]);
		//std::cout << moveToString(v2[0]) << std::endl;
		return v2[0];
	}

	return v2[0];
}
*/

/*
ChessMove improved_ai_move(ChessBoard * board, bool isBlack){

	//bool isWhite = false;
	ChessMove cm;

	int opponentCapturingMoves = board->capturingMoves(isBlack).size();
	std::vector<ChessMove> blackCapturingMoves = board->capturingMoves(!isBlack);
	std::vector<ChessMove> blackNonCapturingMoves = board->nonCapturingMoves(!isBlack);

	if(blackCapturingMoves.size() == 0 && blackNonCapturingMoves.size() == 0){
		std::cout << "no moves possible" << std::endl;
		return cm;
	}

	int numberPotentialMoves = 0;
	if(blackCapturingMoves.size() != 0){

		// check for every move if number of opponents capturing moves increases
		auto it = blackCapturingMoves.begin();
		while(it != blackCapturingMoves.end()){
			int moves = board->potentialMoves(it->to_x,it->to_y,isBlack,true);
			if(moves > numberPotentialMoves){
				cm = *it;
				numberPotentialMoves = moves;
			}
			++it;
		}
	
		if(numberPotentialMoves > opponentCapturingMoves){
			board->move_piece(cm);
			std::cout << cm.toString() << std::endl;
			return cm;
		}else{
			// select random capturing
			//unsigned SEED = 911206;
			//unsigned SEED = 971616;
			//std::shuffle(blackCapturingMoves.begin(),blackCapturingMoves.end(),std::default_random_engine(SEED));
			std::srand(std::time(0));
			std::random_shuffle(blackCapturingMoves.begin(), blackCapturingMoves.end());	
			board->move_piece(blackCapturingMoves[0]);
			//std::cout << moveToString(blackCapturingMoves[0]) << std::endl;
			return blackCapturingMoves[0];
		}
	}

	numberPotentialMoves = 0;
	if(blackNonCapturingMoves.size() != 0){

		auto it = blackNonCapturingMoves.begin();
		while(it != blackNonCapturingMoves.end()){
			// change colorMatrix temporarily to count moves after capture
		
			int moves = board->potentialMoves(it->to_x,it->to_y,isBlack,false);

			if(moves > numberPotentialMoves){
				cm = *it;
				numberPotentialMoves = moves;
			}
			++it;
		}

		if(numberPotentialMoves > 0){
			board->move_piece(blackNonCapturingMoves[0]);
			//std::cout << moveToString(blackNonCapturingMoves[0]) << std::endl;
			return blackNonCapturingMoves[0];
		}else{
			// select random noncapturing game...
			// unsigned SEED = 911206;
			// unsigned SEED = 971616;
			std::srand(std::time(0));
			std::random_shuffle(blackNonCapturingMoves.begin(), blackNonCapturingMoves.end());	
			//std::shuffle(blackNonCapturingMoves.begin(),blackNonCapturingMoves.end(),std::default_random_engine(SEED));
			board->move_piece(blackNonCapturingMoves[0]);
			//std::cout << moveToString(blackNonCapturingMoves[0]) << std::endl;
			return blackNonCapturingMoves[0];
		}
	}

	std::cout << "ERROR: NO POSSIBLE MOVE" << std::endl;
	return cm;
}
*/

// A - H corresponds to 65-72
// Example of valid input A1-A2
/*
bool user_move(ChessBoard * board){

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
		board->print_board(false,std::cout);
		return false;
	}

	if(input[0] == 'L' && input.length() == 1){
		board->print_board(true,std::cout);
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

	ChessPiece * piece = board->getChessPiece(from_x,from_y);
	if(piece == nullptr){
		std::cout << "No piece at position, try again" << std::endl;
		return false;
	}

	if(board->piece_color(from_x,from_y) == false){
		std::cout << "Can't move opponent's (black) pieces" << std::endl;
		return false;
	}

	if(board->piece_color(from_x,from_y) == board->piece_color(to_x,to_y)){
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
			board->move_piece(cm);
		}else{
			ChessMove cm{from_x,from_y,to_x,to_y,piece,NO_PROMOTION};
			board->move_piece(cm);
		}
	}else if(piece->nonCapturingMove(to_x,to_y)){

		// only allowed if there are no possible captures
		if(board->capturingMoves(true).size() > 0){
			std::cout << "Capturing is compulsory, try again" << std::endl;
			return false; 
		}

		if(input.length() == 9){
			ChessMove cm{from_x,from_y,to_x,to_y,piece,input[7]};
			board->move_piece(cm);
		}else{
			ChessMove cm{from_x,from_y,to_x,to_y,piece,NO_PROMOTION};
			board->move_piece(cm);
		}
	}else{
		std::cout << "Invalid move, try again" << std::endl;
		return false;
	}
	return true;

}
*/


/*
void game_loop(ChessBoard * board, bool isAIvsAI){

	// ask for input as long as no winner.
	// check_winner();
	// user move -- check that there are moves possible
	// ai_move

	std::ofstream myfile;
	if(isAIvsAI){
		myfile.open("aigame.txt");
		board->print_board(false,myfile);
	}

	bool start = true; // game just started or resumed from loaded state
	int round = 0;
	while(true){

		if(round == 5){
			if(isAIvsAI){
				board->print_board(false,myfile);
			}
			if(isAIvsAI){
				myfile << "white pieces: " << board->numberOfPieces(true) << std::endl;
				myfile << "black pieces: " << board->numberOfPieces(false) << std::endl;	
			}else{
				std::cout << "white pieces: " << board->numberOfPieces(true) << std::endl;
				std::cout << "black pieces: " << board->numberOfPieces(false) << std::endl;	
			}
		}

		if(board->capturingMoves(true).size() == 0 && board->nonCapturingMoves(true).size() == 0){
		
			if(isAIvsAI){
				myfile << "\nNo moves left for White " << std::endl;
				board->print_board(false,myfile);
				myfile << "White pieces: " << board->numberOfPieces(true) << std::endl;
				myfile << "Black pieces: " << board->numberOfPieces(false) << std::endl;
				myfile << ((board->numberOfPieces(true) <= board->numberOfPieces(false)) ? "White Wins!" : "Black Wins!") << std::endl;
				break;
			}else{
				std::cout << "No moves left for White " << std::endl;
				board->print_board(true,std::cout);
				std::cout << "White pieces: " << board->numberOfPieces(true) << std::endl;
				std::cout << "Black pieces: " << board->numberOfPieces(false) << std::endl;
				std::cout << ((board->numberOfPieces(true) <= board->numberOfPieces(false)) ? "White Wins!" : "Black Wins!") << std::endl;
				break;
			}
		}

		// white's move of round
		if(start==false || board->getTurn() == true){
			if(isAIvsAI){
				ChessMove cm = board->improved_ai_move(false);
				myfile << cm.toString() << "   ";
			}else{
				while(board->user_move() == false);
			}
		}
		start = false;


		if(board->capturingMoves(false).size() == 0 && board->nonCapturingMoves(false).size() == 0){
			if(isAIvsAI){
				myfile << "\nNo moves left for Black " << std::endl;
				board->print_board(true,myfile);
				myfile << "White pieces: " << board->numberOfPieces(true) << std::endl;
				myfile << "Black pieces: " << board->numberOfPieces(false) << std::endl;
				myfile << ((board->numberOfPieces(false) <= board->numberOfPieces(true)) ? "Black Wins!" : "White Wins!") << std::endl;
				break;
			}else{
				std::cout << "No moves left for Black " << std::endl;
				board->print_board(true,std::cout);
				std::cout << "White pieces: " << board->numberOfPieces(true) << std::endl;
				std::cout << "Black pieces: " << board->numberOfPieces(false) << std::endl;
				std::cout << ((board->numberOfPieces(false) <= board->numberOfPieces(true)) ? "Black Wins!" : "White Wins!") << std::endl;
				break;
			}
		}

		// black's move of round
		if(isAIvsAI){
			ChessMove cm = board->simple_ai_move();
			myfile << cm.toString() << "\n";
		}else{
			ChessMove cm = board->improved_ai_move(true);
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

}

ChessBoard * load_game(bool newGame){

	// create board and stuff
	if(newGame){
		// create new board
		ChessBoard * board = new ChessBoard();

		std::stringstream s;
		s << "rnbqkbnr" << std::endl;
		s << "pppppppp" << std::endl;
		s << "........" << std::endl;
		s << "........" << std::endl;
		s << "........" << std::endl;
		s << "........" << std::endl;
		s << "PPPPPPPP" << std::endl;
		s << "RNBQKBNR";
		s >> *board;

		return board;
	}else{
		// load game from file
		ChessBoard * board = new ChessBoard();

		std::ifstream myinput;
		myinput.open("board.txt");
		try{
			myinput >> *board;
		}catch(std::exception& e){
			std::cout << "Error loading board: " << e.what() << std::endl;
			delete board;
			return nullptr;
		}
		myinput.close();
		return board;
	}
}

int menu(){
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
*/

int main(){

	ChessBoard * board = new ChessBoard();
	board->start_game();
	delete board;
	
	/*
	std::cout << "Chess Game" << std::endl;
	ChessBoard * board = nullptr;

	int choice = 0;
	while((choice = menu()) !=  0){
		if(choice == 1){
			board = load_game(true);
			if(board != nullptr){
				board->print_board(true,std::cout);
				game_loop(board,false);				
			}
		}else if(choice == 2){
			board = load_game(false);
			if(board != nullptr){
				board->print_board(true,std::cout);
				game_loop(board,false);
			}
		}else if(choice == 3){
			board = load_game(true);
			if(board != nullptr){
				//board->print_board(true,std::cout);
				game_loop(board,true);				
			}
		}else if(choice == 4){
			board = load_game(false);
			if(board != nullptr){
				//board->print_board(true,std::cout);
				game_loop(board,true);
			}
		}else{
			break;
		}
	}

	delete board;
	return 0;
	*/


}
