/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Implementation file for NineOClock derived class. Creates gamespace
             where user can interact with a bike stand to get a bike key.

             Compile with: space.cpp, pack.cpp, inputVal.cpp

*/

#include "nineoclock.hpp"

//constructor, sets name and ID number
NineOClock::NineOClock() : Space()
{
     name = "The 9 o'clock plaza";
     ID = 1;
}

NineOClock::~NineOClock()
{}

//returns number of steps between this space and space passed as parameter
int NineOClock::getSteps(Space* nextSpace)
{
    int stepID = nextSpace->getID();

    switch(stepID)
    {
        case 3: return 15;
            break;
        case 5: return 30;
            break;
    }
}

// user can interact with a bike shop to get the key to a bike
void NineOClock::interact(Pack* stuff)
{
    char nineChoice;

    cout << endl << "To your left is a dusty bike shop!";
    cout << endl << "They might have the key for your bike lock. Want to ask? Y/N: ";

    //get and validate user input
    nineChoice = isChar2('Y','N');
    //if user wants to interact
    if (nineChoice == 'Y')
    {
        cout << endl << "They have it! Would you like to take the key with you? Y/N: ";

        nineChoice = isChar2('Y','N');
        //if user wants the key, it's added to his pack
        if (nineChoice == 'Y')
        {
            stuff->addItem("Key");
        }
    }
}
