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

//displays main menu for client code, returns int of user choice
int displayMenu()
{

    cout << endl << endl << "What would you like to do? Please select a number.";
    cout << endl << "1. Brawl!";
    cout << endl << "2. Exit" << endl;
    
    //validate user's response before returning
    return intRange(1,2);
}

//displays a menu of characters for the user to choose from
void gameMenu()
{
    int userChoice;
    
    cout << endl << "Pick two warriors to face off in an epic battle: ";
    cout << endl << "1. Vampire";
    cout << endl << "2. Barbarian";
    cout << endl << "3. Blue Men";
    cout << endl << "4. Medusa";
    cout << endl << "5. Harry Potter" << endl;
    
}