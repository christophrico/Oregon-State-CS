/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/23/17
Assignment:	 CS 162 - Lab 4
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
    cout << endl << "1. Print information about OSU buildings";
    cout << endl << "2. Print information about people at OSU";
    cout << endl << "3. Choose a person at OSU to do work";
    cout << endl << "4. Exit the program" << endl;

    userChoice = intRange(1,4);

    return userChoice;
}
