/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 8/6/17
Assignment:	 CS 162 - Project 3
Description: Implementation file for displayMenu function.
             Displays menu, takes user input as integer, and
             returns integer

			 Compile with inputVal.cpp,
*/

#include "menu.hpp"


int displayGameMenu()
{
    cout << endl << endl << "1. Look around you.";
    cout << endl << "2. Move to an adjacent space.";
    cout << endl << "3. Print your list of items.";
    cout << endl << "4. Print your remaining steps.";
    cout << endl << "5. Print a map.";
    cout << endl << "6. Quit the game." << endl;

    return intRange(1,6);
}
