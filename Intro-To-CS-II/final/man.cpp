/*
Name:		       Christopher Rico
OSU ID:		     933239746
Date:		       8/16/17
Assignment:	  CS 162 - Final Project
Description:  Implementation file for Man derived class. Creates a game space where
              User can interact with a wheel of fortune to win sunscreen.

              Compile with : space.cpp, inputVal.cpp, pack.cpp

*/

#include "man.hpp"

//constructor, sets name and ID
Man::Man() : Space()
{
    name = "The Man";
    ID = 4;
}

Man::~Man()
{}

//returns the distance between this space and the space passed in as parameter
int Man::getSteps(Space* nextSpace)
{
    int stepID = nextSpace->getID();
    int dustStorm = randIntRange(1,3);

    //random chance the user experiences a dust storm,
    //which takes 50 steps away instead of prescribed amount
    if (dustStorm > 1)
    {
        switch(stepID)
        {
            case 2: return 10;
                break;
            case 3: return 20;
                break;
            case 6: return 10;
                break;
        }
    }

    else
    {
        dustStormArt();
        return 50;
    }
}

// user can interact with this space by spinning a wheel of fortune. 50/50 chance he will win
//if he wins, Sunscreen is added to his pack
void Man::interact(Pack* stuff)
{
    char spinChoice;
    int spinWin;

    cout << endl << "Ooh look, here's a wheel of fortune. Wanna spin it? Y/N: ";

    //get and validate user input
    spinChoice = isChar2('Y','N');
    //if user wants to play
    if (spinChoice == 'Y')
    {
        cout << endl << "All right! Let's spin! ";

        //generate random number to simulate 'spin'
        spinWin = randIntRange(0,5);
        cout << endl << endl << "Spinning the wheel...";

        //even number wins
        if (spinWin % 2 == 0)
        {
            //sunscreen is added to user's pack
            cout << endl << "You win a bottle of sunscreen!";
            stuff->addItem("Sunscreen");
        }

        //if you don't win, gotta try again
        else
          cout << endl << "Bummer! Looks like you didn't win anything. Choose 1 to play again.";
    }
}
