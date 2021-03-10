/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Client code for final project.
             Compile with: inputVal.cpp, menu.cpp, player.cpp, space.cpp
                           art.cpp, deepplaya.cpp, distrikt.cpp, man.cpp,
                           nineoclock.cpp, pack.cpp, rv.cpp, temple.cpp

PLAYER: You MUST get the sunscreen at the man and the light up earring at the temple
        in order to win.

*/

#include "player.hpp"

int userChoice;

int main()
{
    //instantiate player object and hand off gameplay to it
    Player lego;

    lego.playGame();

    return 0;

}
