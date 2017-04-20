## Board Tests

### AI vs. AI games

#### New Games

White has improved AI, black doesn't  

Game: winner (white pieces - black pieces)  

SEED: 123456  
Game 1: white wins (0-12)  
SEED: 892534  
Game 2: white wins (1-9)  
SEED: 758109  
Game 3: white wins (0-8)  
SEED: 289348  
Game 4: white wins (0-12)  
SEED: 345748  
Game 5: white wins (0-4)  
SEED: 423593  
Game 6: white wins (0-9)  
SEED: 523977  
Game 7: white wins (0-7)  
SEED: 310254  
Game 8: white wins (0-7)  

### Check that game is working with fewer pieces

#### Game 1

Checked and working
```
. . . . . . . . 
. . . . p . . r 
. . . . . . . . 
P . . . . . . . 
. . P . . . . . 
. . . . . . . p 
. . . . . . K . 
. . . . Q . . . 
E8-E2   H6-G7
E2-H2   G7-G8
C5-C4   G8-C4
H2-F4   C4-F4
A4-A3   F4-F8
. . . . . . . . 
. . . . . . . . 
P . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . q . . 
white pieces: 1
black pieces: 1
A3-A2   F8-B8
A2-A1   B8-E8
A1-E5   E8-E5

No moves left for White 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . q . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
White pieces: 0
Black pieces: 1
White Wins!
```

#### Game 2

Checked and working
```
. . b . . . . . 
. . . . p . . . 
. . . . . . . . 
. . B . . . . . 
P . . . . . . . 
. . . . . . . p 
. . . . . . . . 
. . . . Q . . . 
E8-E2   C1-E3
E2-E3   H6-H7
C4-G8   H7-G8
E3-G5   G8-G5
A5-A4   G5-E5
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
P . . . . . . . 
. . . . q . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
white pieces: 1
black pieces: 1
A4-A3   E5-E6
A3-A2   E6-A2

No moves left for White 
. . . . . . . . 
q . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
White pieces: 0
Black pieces: 1
White Wins!
```

#### Game 3

Checked and working
```
. . . . . . . . 
. . . . . P . . 
q . . . . . . . 
. . N . . . b . 
. p . . r . . . 
. . . . . . . . 
. R . . . p . . 
. . . . . . . . 
B7-B5   E5-B5
C4-A3   G4-F5
A3-B5   F5-H7
B5-D6   H7-G8
D6-F7   G8-F7
. . . . . . . . 
. . . . . P . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . b . . 
. . . . . . . . 
white pieces: 1
black pieces: 1
F2-F1   F7-G6
F1-D3   G6-D3

No moves left for White 
. . . . . . . . 
. . . . . . . . 
. . . b . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
White pieces: 0
Black pieces: 1
White Wins!
```

#### Game 4

Checked and working
```
. . . . . . . . 
. R . . . p . . 
. . p . . . . . 
. . . . . . . . 
. . . . N . . . 
. . . . . . . . 
. . q . p . . B 
. . . . . . . . 
B2-F2   C7-E5
F2-E2   E5-E2
H7-E4   E2-E4

No moves left for White 
. . . . . . . . 
. . . . . . . . 
. . p . . . . . 
. . . . q . . . 
. . . . . . . . 
. . . . . . . . 
. . . . p . . . 
. . . . . . . . 
White pieces: 0
Black pieces: 3
White Wins!
```

#### Game 5

Checked and working

```
. . . . . . . . 
R . . p p p . . 
. . . . . . . . 
. . p . . . . r 
. . . . . . . . 
. . . . . . . . 
. . P . . P P B 
. . . . . . . . 
A2-D2   H4-H7
D2-E2   H7-G7
E2-F2   G7-F7
F2-F7   C4-C5
F7-D7   C5-C6
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . p . . . . . 
. . P R . . . . 
. . . . . . . . 
white pieces: 2
black pieces: 1
D7-F7   
No moves left for Black 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . p . . . . . 
. . P . . R . . 
. . . . . . . . 
White pieces: 2
Black pieces: 1
Black Wins!
```


### IMPROVED_AI_MOVE

#### White Queen should strike pawn diagonally, will force black queen to capture white queen.

Game Output:
```
. . . . . . . . 
. . p . . . q . 
. . . . . . . . 
Q . . . . p . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
r . . . . . . . 
A4-C2   G2-C2

No moves left for White 
. . . . . . . . 
. . q . . . . . 
. . . . . . . . 
. . . . . p . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
r . . . . . . . 
White pieces: 0
Black pieces: 3
White Wins!
```

#### White queen should strike black rook. Forces black queen to capture white queen.

Game output:
```
. . . . . . . . 
. . p . . . . . 
. . . . . . . . 
Q . . . . p . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
r . . q . . . . 
A4-A8   D8-A8

No moves left for White 
. . . . . . . . 
. . p . . . . . 
. . . . . . . . 
. . . . . p . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
q . . . . . . . 
White pieces: 0
Black pieces: 3
White Wins!
```

#### White Rook should choose to capture black pawn above it to force black rook to capture it

```
. . . . . . . . 
. . . . . P . . 
. . . . . . . . 
. . . . . . . . 
. p . . r . . . 
. . . . . . . . 
. R . . . p . . 
. . . . . . . . 
B7-B5   E5-B5
F2-F1   B5-C5
F1-F7   C5-B5
F7-H5   B5-H5

No moves left for White 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . r 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
White pieces: 0
Black pieces: 1
White Wins!
```

#### Non capture move: White Pawn in front of queen should take one step forward to force capture.

Game output:
```
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . P P P . 
. P p . . . . . 
. . . . . . . . 
. . P P . . . . 
. . . Q . . . . 
D7-D6   C5-D6
C7-D6   
No moves left for Black 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . P P P . 
. P . . . . . . 
. . . P . . . . 
. . . . . . . . 
. . . Q . . . . 
White pieces: 6
Black pieces: 0
Black Wins!
```

#### White knight should move itself to D3 so that black pawn is forced to capture it

```
. . . . . . . . 
. . . . p . . . 
. . . . . . . . 
. . . . . . . . 
. . N . . . . . 
. . . . . . . . 
P P P . . P P P 
. . . Q . . . . 
C5-D3   E2-D3
D8-D3   
No moves left for Black 
. . . . . . . . 
. . . . . . . . 
. . . Q . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
P P P . . P P P 
. . . . . . . . 
White pieces: 7
Black pieces: 0
Black Wins!
```

### END_GAME

#### White Rook must take black pawn which causes black to be stalemated and black wins (less pieces)

```
. . . . . . . . 
. . . . p . . . 
. . . . R . . . 
. . . . . . . . 
. p . . . . . . 
. P . . . . . . 
. . . . . . . . 
. . . . . . . . 
E3-E2   
No moves left for Black 
. . . . . . . . 
. . . . R . . . 
. . . . . . . . 
. . . . . . . . 
. p . . . . . . 
. P . . . . . . 
. . . . . . . . 
. . . . . . . . 
White pieces: 2
Black pieces: 1
Black Wins!
```

#### Rook must strike pawn in front of it and then pawn which places itself on the same row. 

```
. . . . . . . . 
. . . . . P . . 
. . . . . . . . 
. . . . . p . . 
. p . . . . . . 
. . . . . . . . 
. R . . . . . . 
. . . . . . . . 
B7-B5   F4-F5
B5-F5   
No moves left for Black 
. . . . . . . . 
. . . . . P . . 
. . . . . . . . 
. . . . . . . . 
. . . . . R . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
White pieces: 2
Black pieces: 0
Black Wins!
```

#### Rook must strike pawn and black won't be able to move which will end the game.

```
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. p . . . . . . 
. p R . . . . . 
. . . . . . . . 
. . . . . . . . 
C6-B6   
No moves left for Black 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. p . . . . . . 
. R . . . . . . 
. . . . . . . . 
. . . . . . . . 
White pieces: 1
Black pieces: 1
Black Wins!
```


### BISHOP_STANDOFF

When only two bishops remain they must be standing on squares of the same color

#### After the two moves (including one capture) a stalemate is correctly identified.

B.......
........
........
........
........
B.b.....
........
........
1

Game output: 
```
B . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
B . b . . . . . 
. . . . . . . . 
. . . . . . . . 
A6-B7   C6-B7
```

#### Stalemate before any move
```
..B.....
........
........
........
........
....b...
........
........
1

Game output:

. . B . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . b . . . 
. . . . . . . . 
. . . . . . . . 
``` 
#### Stalemate after p has been captured

```
..B.....
........
........
........
........
.p..b...
........
........
1

. . B . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. . . . . . . . 
. p . . b . . . 
. . . . . . . . 
. . . . . . . . 
C1-E3   E6-F7
E3-B6 
```


### BAD_INPUT

#### Pawns placed on line 1 or 8 

``` 
.....p..
........
........
..p....r
........
........
..P..PPB
........
1

Error loading board: invalid placement of black pawn
```


```
........
........
........
..p....r
........
........
..P..PPB
.....P..
1

Error loading board: invalid placement of white pawn
```

#### Number of pieces in input exceeds row size

```
........
........
........
..p....r
........
........
..P..PPB.
.....P...
1

Error loading board: row length in input exceeds board limit
```

#### input shorter than row size

```
........
........
........
..p....r
........
........
..P..PP
.....P..
1

Error loading board: input rows not matching rows on board
```

#### number of rows not matching board

```
........
........
........
..p....r
........
........
..P..PP.
1

Error loading board: input rows not matching rows on board
```

#### bad chars
```
........
........
........
..p....r
........
._......
..P..PP.
.....P..
1

Error loading board: character input not matching any known chess piece...
``` 

#### bad char for starting color

```
........
........
........
..p....r
........
........
..P..PP.
........
q

Error loading board: starting color must be specified with either 0 or 1
```

#### starting color unspecified

```
........
........
........
..p....r
........
........
..P..PP.
........

Error loading board: starting color must be specified with either 0 or 1
```


