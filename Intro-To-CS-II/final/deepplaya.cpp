/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:		     8/16/17
Assignment:	 CS 162 - Final Project
Description: Implementation file for Deep Playa derived class.
             Creates a space that the user may interact with a lost-and-found booth

             Compile with: space.cpp, pack.cpp, inputVal.cpp
*/

#include "deepplaya.hpp"

//constructor, sets name and ID number
DeepPlaya::DeepPlaya() : Space()
{
    name = "Deep Playa";
    ID = 2;
}

DeepPlaya::~DeepPlaya()
{}


//returns the distance between this space and the space passed in as parameter
int DeepPlaya::getSteps(Space* nextSpace)
{
    int stepID = nextSpace->getID();
    int dustStorm = randIntRange(1,5);

    //random chance the user experiences a dust storm,
    //which takes 50 steps away instead of prescribed amount
    if (dustStorm > 2)
    {
      switch(stepID)
      {
          case 4: return 10;
              break;
          case 5: return 60;
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

//pure virtual interact function, allows user to interact with a lost-and-found booth
void DeepPlaya::interact(Pack* stuff)
{
    char boothChoice;
    int boothTrade;

    cout << endl << "Look over there! There's a lost-and-found booth. Maybe they have your vest!";
    cout << endl << "Talk to them? Y/N: ";

    //get and validate user input
    boothChoice = isChar2('Y','N');
    //if user wants to interact with the booth
    if (boothChoice == 'Y')
    {
        //display the items at the booth
        cout << endl << endl << "There are several items at the booth:";
        cout << endl << "1. Bunny Ears";
        cout << endl << "2. Pack of bacon";
        cout << endl << "3. Bike Light";
        cout << endl << "4. Fur Vest";

        cout << endl << endl << "In order to get your item back, you'll need to trade a light-up earring.";

        //if you have an earring in your pack
        if (stuff->searchItems("Earring"))
        {
            cout << endl << "Offer them your earring? Y/N: ";

            //get and validate user input
            boothChoice = isChar2('Y','N');
            //if you want to trade the earring
            if (boothChoice == 'Y')
            {
               //get and validate user input for trade
               cout << endl << "Which item would you like to trade for? Pick a number: ";
               boothTrade = intRange(1,4);

               switch(boothTrade)
               {
                    case 1: stuff->tradeItem("Bunny ears","Earring");
                        break;
                    case 2: stuff->tradeItem("Bacon","Earring");
                        break;
                    case 3: stuff->tradeItem("Bike light","Earring");
                        break;
                    case 4: stuff->tradeItem("Vest","Earring");
                        break;
               }
            }
        }

        //if you don't have an earring in your pack
        else
        {
            cout << endl << "Looks like you don't have a light-up earring!";
            cout << endl << "People at the Temple tend to be very friendly and well-lit.";
        }
    }
}
