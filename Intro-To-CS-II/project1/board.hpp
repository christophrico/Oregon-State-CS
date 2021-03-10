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

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Board
{
private:
    char **squares;
    int xSize,
        ySize;

public:

    //destructor, deletes array
    ~Board();

    //getters
    char getColor(int, int);
    void printBoard();

    //mutators
    void setSize(int, int);
    void setAnt(int, int);
    void changeSquareColor(int, int, char);

};


#endif // BOARD H
