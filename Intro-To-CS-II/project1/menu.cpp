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

int displayMenu()
{
    int userChoice;

    cout << endl << "What would you like to do? Please select a number.";
    cout << endl << endl << "1. Start the program";
    cout << endl << "2. Exit" << endl;

    userChoice = intRange(1,2);

    return userChoice;
}
