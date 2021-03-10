/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/23/17
Assignment:  CS 162 - Project 2
Description: Client code for shopping list program. Presents a menu for users to
             choose between several ways to interact with their shopping list.
             Continues looping to this menu until the user chooses to quit.
             Compile with menu.cpp, list.cpp, inputVal.cpp and item.cpp.
*/

#include "menu.hpp"
#include "list.hpp"

int main()
{
    List myList;
    int userChoice;

    //ask what user wants to do
    //and call the appropriate function from myList
    do
    {
        userChoice = displayMenu();

        switch(userChoice)
        {
            case 1: myList.display();
                break;
            case 2: myList.addItem();
                break;
            case 3: myList.removeItem();
                break;
        }
    } while (userChoice != 4);


    cout << endl << "Have fun shopping!" << endl;

    return 0;
}
