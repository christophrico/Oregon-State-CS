/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Lab 6
Description: Implementation file for displayMenu function.
             Displays menu, takes user input as integer, and
             returns integer

			 Compile with inputVal.cpp
*/

#include "menu.hpp"

//displays main menu for client code, returns int of user choice
int displayMenu()
{

    cout << endl << endl << "What would you like to do? Please select a number.";
    cout << endl << "1. Enter a value to be added to the queue";
    cout << endl << "2. Display first node (front) value";
    cout << endl << "3. Remove first node (front) value";
    cout << endl << "4. Display the queue contents";
    cout << endl << "5. Exit" << endl;

    //validate user's response before returning
    return intRange(1,5);
}
