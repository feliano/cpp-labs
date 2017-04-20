#include "chess.h"
#include <fstream>

using namespace std;

int main() {

	cout << "tjena" << endl; 
	ChessBoard board;

	cout << "board layout: " << endl;

	std::ifstream myinput;
    myinput.open("board.txt");
    myinput >> board;
    myinput.close();


//	cin >> board;

	Rook r(false);

	cout << U'\u2656' << endl;
	cout << "\u2656" << endl; // works actually
	cout << "\U0000265C" << endl;
	cout << U'\U0000265C' << endl;

	return 0;
}