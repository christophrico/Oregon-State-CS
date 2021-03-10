/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Implementation file for RV derived class. Creates gamespace
             where user begins. User can also collect a bike here to cut steps
             taken in half, but must have a bike key.

            Compile with: space.cpp, pack.cpp, inputVal.cpp

*/

#include "rv.hpp"

//constructor, sets name and ID number
RV::RV() : Space()
{
    name = "Your RV";
    ID = 5;
}

RV::~RV()
{}

//returns number of steps between this space and space passed as parameter
int RV::getSteps(Space* nextSpace)
{
    int stepID = nextSpace->getID();;

    switch(stepID)
    {
        case 1: return 30;
            break;
        case 2: return 60;
            break;
        case 6: return 20;
            break;
    }
}


// allows user to interact with RV. If user has key, he can collect a bike
void RV::interact(Pack* stuff)
{
    char bikeChoice;

    cout << endl << "Over here! It's a bike. Using a bike allows you to take half as many steps!";
    cout << endl << "You'll need a key to unlock it, though.";
    cout << endl << "Do you want to try to use it? Y/N: ";

    //get and validate user input
    bikeChoice = isChar2('Y','N');
    if (bikeChoice == 'Y')
    {
      //if you have the key
      if (stuff->searchItems("Key"))
      {
          //add the bike to your items
          stuff->addItem("Bike");
          cout << endl << endl << "Sweet! Bike unlocked and added to items!";
      }

      //if you don't have the key, tell user where to find it
      else
      {
          cout << endl << endl << "Oh no! Looks like your key went missing.";
          cout << endl << "You'll have to find one at the bike shop at the 9 O'Clock plaza.";
      }
    }
}
