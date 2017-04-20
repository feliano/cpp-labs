## Lab 6

#### The code relies on virtual functions. Could the code have been written without virtual functions?
Just removing virtual wouldn't work since we have a few places where we depend on late binding of virtual functions.
Without virtual ChessPiece * will call the base class implementation of its functions, with virtual it looks up the correct
function of the derived class in the virtual table. 

You can still implement this without using 'virtual' but the solutions would most likely not be as neat. One solution would be to store all the
specific pieces in different arrays and store the position within them. Then one could loop through all lists with pieces to see if moves are valid or not.
This is not a very efficient solution! Polymorphism is kinda nice.

#### Capturingmove calls a protected virtual function but is not virtual in it self. Noncapturingmoves/Capturingmoves are public virtual functions. What is your opinion of that design difference. Write your own thoughts.

Capturingmove doesn't have to be overridden by derived classes so I see no problem with it not being virtual. The other two are dependent on which derived class it is so making them virtual is important. 

Capturingmove could actually have been private as well since it's not being called by any functions outside the object

#### Should ChessPiece have been an abstract class?
I think so yes, since making it abstract forces derivation. An object of type chesspiece shouldn't be allowed.

#### What do you think of the general design of this code? What could be improved?
Takes a while to comprehend. A bit redundant in some places, capturingmove() is not really necessary.

Chesspiece could use an accessor for the isWhite member variable. This would remove the need for an extra matrix storing only colors.

latin- and utf8-representation functions could be public. quite useless at the moment. One could imagine wanting to use a getter for printing the board.

Other ways to modify the private variables of the chesspiece from the outside, now only possible with move_piece function. Could have used accessors but at the same
time this would break a bit of the encapsulation. 

Accessing a chesspiece via a function in chessboard class could also be nice but note the same issue of encapsulation as above.

Looking at the names of the functions it's pretty unclear what each one does, at least it takes a bit longer figuring it out. What's the difference
between validmove and capturingmove? Clearer distinction of roles or better names could be good.

#### What was most difficult to do in this assignement?
Getting started and figuring out the code design
