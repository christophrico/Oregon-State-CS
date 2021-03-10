/*
Name:		       Christopher Rico
OSU ID:		     933239746
Date:		       8/16/17
Assignment:	   CS 162 - Final Project
Description:   Implementation file for Distrikt derived class.
               This creates a game space where user can 'dance' by solving math problems

               Compile with: space.cpp, inputVal.cpp, pack.cpp

*/

#include "distrikt.hpp"

//constructor, sets name and ID number
Distrikt::Distrikt() : Space()
{
    name = "Distrikt";
    ID = 3;
}

Distrikt::~Distrikt()
{}

//returns number of steps between this space and space passed as parameter
int Distrikt::getSteps(Space* nextSpace)
{
    int stepID = nextSpace->getID();

    switch(stepID)
    {
        case 1: return 15;
            break;
        case 4: return 20;
            break;
        case 6: return 40;
            break;
    }
}

//allows user to interact with the space by 'dancing' or solving math problems
void Distrikt::interact(Pack* stuff)
{
    char playChoice;
    int danceMove, move1, move2, moveAnsw;

    cout << endl << endl << "Nice! You made it to the coolest day party on the Playa.";
    cout << endl << "This is the perfect place to show off your dance moves. Wanna dance? Y/N: ";

    //get and validate user input
    playChoice = isChar2('Y','N');
    //if user wants to dance
    if (playChoice == 'Y')
    {
        cout << endl << "All right! To dance, you must correctly solve the math problem displayed.";
        cout << endl << "Ready? Go!";

        //as long as user doesn't give correct answer, continue generating random math problems to solve
        while (danceMove != moveAnsw)
        {
            move1 = randIntRange(-5, 15);
            move2 = randIntRange(-12, 10);
            moveAnsw = move1+move2;

            cout << endl << move1 << " + " << move2 << " = ?" << endl;

            danceMove = isInt();

            if (danceMove != moveAnsw)
                cout << endl << "Aww, gotta work on those moves. Try again!";
        }


        cout << endl << "Cool moves bro! You caught someone's eye. Want to say hi? Y/N: ";

        //get and validate user input
        playChoice = isChar2('Y','N');
        if (playChoice == 'Y')
        {
            cout << endl << "He remembers meeting you last night!";
            cout << endl << "And that you had your fur vest on while you were at the Man.";
        }
    }

    //if user doesn't want to dance
    else
    {
      cout << endl << "Fine, nothing wrong with chilling. Let's go to the bar!";
      cout << endl << "The bartender just made watermelon margaritas. Want one? Y/N: ";

      playChoice = isChar2('Y','N');
      if (playChoice == 'Y')
      {
        stuff->addItem("Margarita");
        cout << endl << "Mmm, frosty and delicious!";
      }
    }
}
