## Lab 7

#### How is pawn promotion implemented?
A field is added to the chessmove struct to specify char to promote to.

The user may specify either bishop, rook, knight or queen by adding in parentheses after the move e.g. A2-A1 (Q)
If input is bad the user will have to try again.

move_piece then checks if the character is a pawn and of which color. If the pawn reaches the opposite side of the board it will 
remove the pawn and freeing up that piece's allocated memory. The newly specified piece will then be allocated and placed where the pawn was.  


#### What added funtionality or state did you add to the classes from the previous assignement?

In ChessMove:
```
char promoteTo; // specify which piece pawn should be promoted to  
std::string toString();  
```

In ChessBoard:

```
private:

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

void reset_board();
void start_game();

bool isStalemate();
void print_board(bool printAsUTF, std::ostream & out);
void setTurn(bool whiteToPlay); // TODO remove

bool is_empty(int x, int y); 
bool piece_color(int x, int y);
```

In ChessPiece:
``` 
friend void ChessBoard::print_board(bool printAsUTF, std::ostream & out);
friend bool ChessBoard::isStalemate();
```  

#### What functionality or state did you not find any use of from the previous assignement?
I made use of everything from the last lab.

#### Error handling is usually implemented with exceptions, state or with return values (functions returning false/nullptr/0 on error). Which is better in your solution? Motivate.
I think that it depends on where in the program it's done. But generally for errors I prefer using exceptions as that indicates some sort of faulty behaviour and especially when handling user input. 

Return values are quite useful to indicate which path the program should follow. So if I know what the possible errors are I would use could return values, but if the error is beyond my control like user input I prefer exceptions.

So I would say a mix is probably the best in this assignment.

#### What is dynamic binding?
Opposite of static binding. The program doesn't know at compile time which address and function will be called, it performs a lookup at runtime instead. This is what virtual methods are dependent on.

#### What code changes would you have to do to implement this assignment without using dynamic binding?
The functions taking a ChessPiece would have to be changed as it would no longer be possible to pass a pointer of, for example a rook and have it call that subclass's function.

The program would have to be redesigned so that all subclasses would have it's own version of a function and not use one generic function.



