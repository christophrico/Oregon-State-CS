/*
Name:		       Christopher Rico
OSU ID:		     933239746
Date:		       8/16/17
Assignment:	   CS 162 - Final Project
Description:   Implementation file for player class. This class implements the
               Burning Man adventure game. Allows user to move through a unviverse
               of linked spaces.

               Compile with: art.cpp, inpuVal.cpp, menu.cpp, space.cpp,
                             deepplaya.cpp, distrikt.cpp, man.cpp, nineoclock.cpp
                             rv.cpp, temple.cpp, pack.cpp

*/

#include "player.hpp"

// constructor, creates linked space, steps remaining to 300, and current space to 'RV'
// also instantiates a Pack item for user's objects
Player::Player()
{
    stepsRemaining = 300;
    fannypack = new Pack();

    //create new space objects
    dis = new Distrikt();
    dp = new DeepPlaya();
    noc = new NineOClock();
    man = new Man();
    rv = new RV();
    tem = new Temple();

    //point each at the correct space objects at N,S,E,W to create linked space
    //distrikt
    dis->setAdj(man, noc, tem, nullptr);
    //deep playa
    dp->setAdj(nullptr, tem, rv, man);
    //nine o clock
    noc->setAdj(dis, nullptr, rv, nullptr);
    //the man
    man->setAdj(dp, dis, tem, nullptr);
    //rv
    rv->setAdj(dp, noc, nullptr, tem);
    //temple
    tem->setAdj(dp, dis, rv, man);

    //set current space
    currentSpace = rv;
}

//destructor, deletes dynamic objects and the Pack object
Player::~Player()
{
    delete dis;
    delete dp;
    delete noc;
    delete man;
    delete rv;
    delete tem;

    delete fannypack;
}

// prints the number of steps the user has remaining before losing
void Player::printSteps()
{
    cout << endl << "You have " << stepsRemaining << " steps remaining.";
}

// gives character choice of adjacent spaces to move to, set current space to
// chosen space, then decrements number of steps remaining
void Player::moveSpace()
{
    Space* holdMe = currentSpace;

    char nextSpace,
         adjN = '~',
         adjS = '~',
         adjE = '~',
         adjW = '~';


    //if the adjacent space is not null, print out its name and allow user to select it
    //to the north
    if (currentSpace->toN() != nullptr)
    {
        adjN = 'N';
        cout << endl << (currentSpace->toN()) -> getName()
             << " is North. Enter 'N' to go there.";
    }
    //to the south
    if (currentSpace->toS() != nullptr)
    {
        adjS = 'S';
        cout << endl << (currentSpace->toS()) -> getName()
             << " is South. Enter 'S' to go there.";
    }
    //to the east
    if (currentSpace->toE() != nullptr)
    {
        adjE = 'E';
        cout << endl << (currentSpace->toE()) -> getName()
             << " is East. Enter 'E' to go there.";
    }
    //to the west
    if (currentSpace->toW() != nullptr)
    {
        adjW = 'W';
        cout << endl << (currentSpace->toW()) -> getName()
             << " is West. Enter 'W' to go there.";
    }


    cout << endl;
    //get and validate user input
    nextSpace = isChar4(adjN, adjS, adjE, adjW);
    //assign user chosen space to current space
    switch (nextSpace)
    {
        case 'N': currentSpace = currentSpace->toN();
            break;
        case 'S': currentSpace = currentSpace->toS();
            break;
        case 'E': currentSpace = currentSpace->toE();
            break;
        case 'W': currentSpace = currentSpace->toW();
            break;
    }


    //subtract the correct number of steps to the step counter
    //if user has a bike, the steps get cut in half
    if (fannypack->searchItems("Bike"))
        stepsRemaining -= ( currentSpace->getSteps(holdMe) / 2 );
    else
        stepsRemaining -= currentSpace->getSteps(holdMe);

    cout << endl << "You are now at " << currentSpace->getName() << "!";


    holdMe = nullptr;
}

// implements gameplay by presenting the user with a menu to make choices
// continues looping through this until user chooses to quit, steps run out, or user wins
void Player::playGame()
{
    int gameChoice;

    //print intro and art
    beginningArt();

    do
    {
        //show the game menu and let user decide what they would like to do
        gameChoice = displayGameMenu();

        switch (gameChoice)
        {
            case 1: currentSpace->interact(fannypack);
                break;
            case 2: moveSpace();
                break;
            case 3: fannypack->printItems();
                break;
            case 4: printSteps();
                break;
            case 5: mapArt();
                break;
        }
  //keep looping as long as user doesn't have the vest, has steps, and doesn't want to exit
  }while ((!fannypack->searchItems("Vest")) && stepsRemaining > 0 && gameChoice != 6);


    //if user runs out of steps, he loses
    if (stepsRemaining <= 0)
        cout << endl << endl << "NO! You ran out of steps. Try using the bike next time!" << endl;
    //if user finds the vest, he wins! print the win banner
    else if (fannypack->searchItems("Vest"))
        winnerArt();
    //if user quits, game ends
    else
        cout << endl << "See you in the dust." << endl;

}
