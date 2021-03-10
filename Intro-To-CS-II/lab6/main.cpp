/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Lab 6
Description: Client code for doubly linked circular list. Gives user a menu of options
            Compile with inputVal.cpp, menu.cpp, queue.cpp

*/

#include "menu.hpp"
#include "queue.hpp"

Queue q1;
int userChoice;

int main()
{

    cout << endl << "Let's play with queues.";
    //as long as user doesn't want to exit, continue looping through the menu
    do
    {
        userChoice = displayMenu();

        switch(userChoice)
        {
            case 1: q1.addBack();
                break;
            case 2: q1.printFront();
                break;
            case 3: q1.removeFront();
                break;
            case 4: q1.printQueue();
                break;
        }


    }while(userChoice != 5);

    cout << endl << "Have a lovely day!" << endl;

    return 0;
}
