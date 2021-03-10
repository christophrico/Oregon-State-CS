/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: client code for fantasy game program. Creates fantasyGame object,
             asks user if they would like to play or exit, and hands off gameplay
             to fantasyGame
             compile with inputVal.cpp menu.cpp fantasygame.cppcreature.cpp vamp.cpp
             barbarian.cpp blueman.cpp medusa.cpp harry.cpp

*/

#include "menu.hpp"
#include "fantasygame.hpp"

FantasyGame fG;
int userChoice;

int main()
{

    cout << endl << "Welcome to Super Smash Fantasy Brawl!";
    //as long as user doesn't want to exit, continue playing games
    do
    {
        userChoice = displayMenu();

        //if user wants to play, hand off game to fantasy object
        if (userChoice == 1)
        {
            fG.play();
        }

    }while(userChoice != 2);

    cout << endl << "Have a lovely day!" << endl;

    return 0;
}
