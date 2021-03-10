/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Implementation file for temple derived class. Creates gamespace where
             user can interact with another character and offer suncreen in
             exchange for a light-up earring which is necessary to win the game.

             Compile with: space.cpp, pack.cpp, inputVal.cpp

*/

#include "temple.hpp"

//constructor, sets name and ID number
Temple::Temple() : Space()
{
     name = "The Temple";
     ID = 6;
}

Temple::~Temple()
{}

//returns the distance between this space and the space passed in as parameter
int Temple::getSteps(Space* nextSpace)
{
    int stepID = nextSpace->getID();
    int dustStorm = randIntRange(1,8);

  //random chance the user experiences a dust storm,
  //which takes 50 steps away instead of prescribed amount
  if (dustStorm > 4)
  {
      switch(stepID)
      {
          case 2: return 10;
              break;
          case 3: return 40;
              break;
          case 4: return 10;
              break;
          case 5: return 20;
              break;
      }
  }

  else
  {
    dustStormArt();
    return 50;
  }
}

// user can interact with another person who needs sunscreen.
// THIS IS NECESSARY TO WIN THE GAME
void Temple::interact(Pack* stuff)
{
    char sunChoice;

    cout << endl << "Over to your left, someone forgot to wear clothes...";
    cout << endl << "It's gonna be a sunny day.";

    //if you have sunscreen, you can offer it to the person
    if (stuff->searchItems("Sunscreen"))
    {
        cout << endl << "Offer them some suncreen? Y/N: ";

        //get and validate user input
        sunChoice = isChar2('Y','N');
        //if you offer them sunscreen
        if (sunChoice == 'Y')
        {
            cout << endl << "That was so nice of you!";
            cout << endl << "As a token of gratitude, they offer you a light-up earring.";
            cout << endl << "Do you want to accept it? Y/N: ";

            //if you want to accept, you get an earring which you need in order to trade
            //for your vest to win the game
            sunChoice = isChar2 ('Y','N');
            if (sunChoice == 'Y')
                stuff->tradeItem("Earring", "Sunscreen");


            cout << endl << "They inform you that a lost-and-found booth is in the Deep Playa.";
            cout << endl << "Maybe your Fur Vest is there!";
        }
    }

    //if you don't have sunscreen
    else
    {
        cout << endl << "After asking them where their clothes are, they tell you there's";
        cout << endl << "a lost-and-found booth in the Deep Playa! Maybe your Fur Vest is there!";
    }
}
