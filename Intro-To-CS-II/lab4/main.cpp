/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/23/17
Assignment:  CS 162 - Lab 4
Description: Client code for OSU information system. Asks user if he would like to
             Display OSU buildings, display OSU people, or choose a person to do work.
             Loops menu until user chooses to exit.
             Compile with university.cpp, inputVal.cpp, menu.cpp, person.cpp
             instructor.cpp student.cpp
*/

#include "menu.hpp"
#include "university.hpp"

int main()
{
    University oregonstate;
    int userChoice;

    //ask what user wants to do
    //and call the appropriate function from myList
    do
    {
        userChoice = displayMenu();

        switch(userChoice)
        {
            case 1: oregonstate.printBldgs();
                break;
            case 2: oregonstate.printPpl();
                break;
            case 3: oregonstate.chooseWork();
                break;
        }

    } while (userChoice != 4);


    cout << endl << "Remember kids, stay in school!" << endl;

    return 0;
}
