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

#include "menu.hpp"
#include "inputVal.hpp"
#include "ant.hpp"

#include <unistd.h>
#include <stdlib.h>

int main()
{
    const double TIME_DELAY = 1; //use this to change pause time between frames
    int antMoves,
        boardXSize,
        boardYSize,
        antStartX,
        antStartY;

    cout << endl << "Welcome to Langton's Ant!";

    //display menu and get user choice
    while (displayMenu() != 2)
    {
      //if user wants to play the game, ask for
      //board size, how many moves, and start loc of ant
      //use posInt() and intRange() to validate entries

      cout << endl << "Great! Let's begin.";
      cout << endl << "Enter the size of the board you you would like:";
      cout << endl << "No larger than 80 x 80 is best.";

      cout << endl << "Rows: ";
      boardXSize = intRange(1, 80);

      cout << "Columns: ";
      boardYSize = intRange(1, 80);

      cout << endl << "Enter the number of moves you would like the ant to make:" << endl;
      antMoves = posInt();

      cout << endl << "Enter where you would like the ant to start:";
      cout << endl << "**EXTRA CREDIT**";
      cout << endl << "If you would like the ant to start at a random point, enter -1.";

      //validate that ant start coordinates are within the board size
      cout << endl << "X: ";
      antStartX = intRange(-1, (boardXSize-1));
      cout << "Y: ";
      antStartY = intRange(-1, (boardYSize-1));

      //generate random start coordinates if requested
      if (antStartX < 0)
        antStartX = randIntRange(0, (boardXSize-1));

      if (antStartY < 0)
        antStartY = randIntRange(0, (boardYSize-1));



      //create ant object
      Ant gary(antStartX, antStartY, boardXSize, boardYSize);

      //move ant and print board as many times as the user specified
      for(int i = 0; i <= antMoves; i++)
      {
          cout << endl << "Move #" << i << " of " << antMoves;
          gary.moveAnt();

          //pause for a few seconds between board prints
          sleep(TIME_DELAY);
      }


      cout << endl << "That was fun!" << endl << endl;

    }

    //if user wants to exit, display a good-bye message
    cout << endl << "Goodbye! Thanks for playing. :)" << endl;

    return 0;
}
