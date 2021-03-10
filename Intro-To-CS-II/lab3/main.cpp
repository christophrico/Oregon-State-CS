/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Main program for war dice assignment. Presents user with a menu,
            then once user chooses to play game, hands game play on to game object.
            Asks user to play game again until user chooses to quit.
*/

#include "menu.hpp"
#include "game.hpp"


int main()
{
    Game game1;

    //as long as uses chooses to play game
    while (displayMenu() != 2)
    {
      //hand game play off to game object.
      game1.playGame();
    }

    cout << endl << "Thanks for playing. Next stop, Vegas!" << endl;

    return 0;
}
