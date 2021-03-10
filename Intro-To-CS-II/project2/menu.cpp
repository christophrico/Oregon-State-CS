/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/24/17
Assignment:	 CS 162 - Project 2
Description: Implementation file for displayMenu function.
             Displays menu, takes user input as integer, and
             returns integer

			 Compile with inputVal.cpp
*/

#include "menu.hpp"

//displays main menu for client code, returns int of user choice
int displayMenu()
{
    int userChoice;

    cout << endl << "What would you like to do? Please select a number.";
    cout << endl << "1. Display your shopping list";
    cout << endl << "2. Add items to your shopping list or update an existing item";
    cout << endl << "3. Remove an item from your shopping list";
    cout << endl << "4. Exit the program" << endl;

    userChoice = intRange(1,4);

    return userChoice;
}

//displays menu for update item method, returns int of user choice
int displayMenu2()
{
    int itemChoice;

    cout << endl << " Now you're in the item edit menu. What would you like to do?";
    cout << endl << " 1. Edit item name";
    cout << endl << " 2. Edit item unit";
    cout << endl << " 3. Edit quanity";
    cout << endl << " 4. Edit price per unit";
    cout << endl << " 5. Print item info";
    cout << endl << " 6. Go back to main menu";
    cout << endl << " ";

    itemChoice = intRange(1,6);

    return itemChoice;
}
