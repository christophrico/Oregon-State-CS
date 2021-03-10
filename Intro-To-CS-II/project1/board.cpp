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

#include "board.hpp"

//destructor, deletes array
Board::~Board()
{
  for (int k = 0; k < xSize; ++k)
  {
    delete [] squares[k];
  }

  delete []squares;
}

//returns color of a square
char Board::getColor(int gcX, int gcY)
{
    return squares[gcX][gcY];
}

//prints the board to the screen
void Board::printBoard()
{
  cout << endl;

  //print lines on top of board
  cout << "  ";

  for (int topRow = 0; topRow < ySize; topRow++)
  {
    cout << "- ";
  }
  cout << endl;

  //print board contents, including | on sides
  for (int row = 0; row < xSize; row++)
  {
    cout << "|";

    for (int col = 0; col < ySize; col++)
      cout << squares[row][col] << " ";

    cout << "|";
    cout << endl;
  }

  //print lines on bottom of board
  cout << "  ";

  for (int botRow = 0; botRow < ySize; botRow++)
  {
    cout << "- ";
  }
  cout << endl;
}

//allows for board size to be allocated
//and initialized with white squares
void Board::setSize(int xS, int yS)
{
  //save values for use in printBoard and destructor
  xSize = xS;
  ySize = yS;

  //create new array, assign it to array variable
  squares = new char*[xS];

  //create array of pointers to arrays
  for (int i = 0; i < xS; i++)
  {
    squares[i] = new char[yS];
  }

  //fill it with white cells
  for (int row = 0; row < xS; row++)
   {
     for (int col = 0; col < yS; col++)
     {
       squares[row][col] = ' ';
     }
   }
 }

//allows for ant loc to be changed
void Board::setAnt(int saX, int saY)
{
    squares[saX][saY] = '@';
}

//flips color of square, removes ant from square
void Board::changeSquareColor(int csX, int csY, char CSQ)
{
    if (CSQ == ' ')
        squares[csX][csY] = '#';

    else if (CSQ == '#')
        squares[csX][csY] = ' ';

}
