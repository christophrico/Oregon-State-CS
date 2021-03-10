/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/2/17
Assignment:	 CS 162 - Project 1
Description: Client code for matrix assignment. Asks user to select
			 a 2x2 or 3x3 matrix, then allocates the array for the
			 matrix. Calls a function to fill the matrix,
			 then another function to get the determinate of the
			 matrix. Then, it de-allocates the array.

			 Compile with readMatrix.cpp, determinate.cpp
*/

#ifndef ANT_H
#define ANT_H

#include "board.hpp"

class Ant
{
private:
    //variables
    int antX,
        antY,
        boardX,
        boardY;

    char currentSquareCol = ' ',
         currentAntDir = 'N',
         nextSquareCol,
         nextAntDir;

    //board object
    Board antBoard;

    //private functions for in-class use
    char calcNextDirection(char, char);
    int calcNextX(int, char);
    int calcNextY(int, char);

public:
    //constructor for user input of ant loc and board size
    Ant(int, int, int, int);

   //mutator; moves ant to proper square
   //and prints the screen
    void moveAnt();

};

#endif // ANT H
