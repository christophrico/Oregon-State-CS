/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/16/17
Assignment:	 CS 162 - Lab 3
Description: Implementation file for displayMenu function.
             Displays menu, takes user input as integer, and
             returns integer

			 Compile with inputVal.cpp,
*/

#include "menu.hpp"

int displayMenu()
{
    int userChoice;

    cout << endl << "What would you like to do? Please select a number.";
    cout << endl << endl << "1. Play War!";
    cout << endl << "2. Exit" << endl;

    userChoice = intRange(1,2);

    return userChoice;
}
