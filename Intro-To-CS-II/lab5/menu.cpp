/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/30/17
Assignment:	 CS 162 - Lab 5
Description: Implementation file for displayMenu function.
             Displays menu, takes user input as integer, and
             returns integer

			 Compile with inputVal.cpp,
*/

#include "menu.hpp"

//displays main menu for client code, returns int of user choice
int displayMenu()
{
    int userChoice;

    cout << endl << "What would you like to do? Please select a number.";
    cout << endl << "1. Reverse a text string";
    cout << endl << "2. Calculate the sum of an array of numbers";
    cout << endl << "3. Calculate the trianglar number for n";
    cout << endl << "4. Exit the program" << endl;

    userChoice = intRange(1,4);

    return userChoice;
}
