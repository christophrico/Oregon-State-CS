/*
Name:		     Christopher Rico
OSU ID:		    933239746
Date:		     8/6/17
Assignment:	 CS 162 - Project 3
Description: fantasyGame class. Contains pointers to two creature objects.
             Asks user to select the characters for each player, then fights them
             until one has run out of health. Then asks user whether they would
             like to play again

            Compile with inputVal.cpp menu.cpp fantasygame.cppcreature.cpp vamp.cpp
            barbarian.cpp blueman.cpp medusa.cpp harry.cpp

*/

#include "fantasygame.hpp"

// constructor, sets pointers to nullptr, rounds to 1
{
    p1 = nullptr;
    p2 = nullptr;

    rounds = 1;
}

/*****************************************************************************
 ** Description: Asks user to choose the two creatures to compete, sets
 *               pointers to correct objects
 ****************************************************************************/
void FantasyGame::chooseCreatures()
{
    int userChoice1,
        userChoice2;

    //display menu, get and validate user choices
    gameMenu();

    cout << endl << "Player 1, enter your choice: ";
    userChoice1 = intRange(1,5);
    cout << "Player 2: ";
    userChoice2 = intRange(1,5);

    //assign player 1 a creature
    switch(userChoice1)
    {
       case 1: p1 = new Vampire();
            break;
       case 2: p1 = new Barbarian();
            break;
       case 3: p1 = new BlueMan();
            break;
       case 4: p1 = new Medusa();
            break;
       case 5: p1 = new Harry();
            break;
    }

    //assign player 2 a creature
    switch(userChoice2)
    {
       case 1: p2 = new Vampire();
            break;
       case 2: p2 = new Barbarian();
            break;
       case 3: p2 = new BlueMan();
            break;
       case 4: p2 = new Medusa();
            break;
       case 5: p2 = new Harry();
            break;
    }

    //display creature choices to users
    cout << endl << "Player 1 chooses " << p1->getName();
    cout << " and Player 2 chooses " << p2->getName() <<".";
}


/*****************************************************************************
 ** Description: Compares the two opponent creatures, prints details,
 *               then swaps and compares again
 **              NOTE: intended to be used after creatures selected
 ** Parameters: attacker = pointer to creature attacking
 **             defender = pointer to creature defending.
 ****************************************************************************/
void FantasyGame::faceOff(Creature* attacker, Creature* defender)
{
    //for keeping track of attack, defense, damage, and specials
    int attPoint, defPoint, damPoint;
    string specialAtt, specialDef;

    //print header
    cout << endl << endl << endl << "**************************  ROUND "
         << rounds << "  **************************";

    //gives each character a turn to be the attacker and defender
    for (int i=0; i<2; i++)
    {
        //first ensure both characters have life left before making them fight
        if ( (attacker->getStrength() > 0) && (defender->getStrength() > 0) )
        {
            //reset special strings
            specialAtt = "";
            specialDef = "";

            //attacker attacks, record attack roll
            attPoint = attacker->attack(specialAtt);
            //defender defends against attack, record defense roll
            defPoint = defender->defend(attPoint, specialDef, damPoint);


            //print attacker details
            if (turn == 0 && i == 0)
                cout << endl << "P1:";
            else if (turn == 0 && i == 1)
                cout << endl << "P2:";
            else if (turn == 1 && i == 0)
                cout << endl << "P2:";
            else if (turn == 1 && i == 1)
                cout << endl << "P1:";

            //attack roll
            cout << endl << attacker->getName() << " attacks with a force of "
                 << attPoint << ".";
            //if special attacks were used, print them
            if (specialAtt != "")
                cout << endl << attacker->getName() << " used " << specialAtt << ".";



            //print out defender details
            if (turn == 0 && i == 0)
                cout << endl << "P2:";
            else if (turn == 0 && i == 1)
                cout << endl << "P1:";
            else if (turn == 1 && i == 0)
                cout << endl << "P1:";
            else if (turn == 1 && i == 1)
                cout << endl << "P2:";

            //armor and defense roll
            cout << endl << defender->getName() << " defends with a force of "
                 << defPoint << " and an armor of " << defender->getArmor() << ".";

            //if special defenses were used, print them
            if (specialDef != "")
                cout << endl << defender->getName() << specialDef;

            //total damage taken
            if (damPoint <= 0)
              cout << endl << "No damage taken this move.";
            else
              cout << endl << damPoint << " damage taken this move.";


            //switch the attacker/defender and go again
            swap(attacker, defender);
        }

         cout << endl;
    }

}

/*****************************************************************************
 ** Description: Prints each player's strengths.
 ****************************************************************************/
  void FantasyGame::printStrength()
  {
    cout << endl << p1->getName() << ": " << p1->getStrength();
    cout << endl << p2->getName() << ": " << p2->getStrength();
  }

/*****************************************************************************
 ** Description: Runs gameplay for the correct number of rounds:
 *               Calls creature select class,
 *               Continues having characters swap turns attacking/defending until
 *               one has no strength left, prints points, then displays winner
 ****************************************************************************/
void FantasyGame::play()
{
    //choose creature to attack first
    turn = randIntRange(0,1);
    //have players choose their creatures
    chooseCreatures();

    //print strength points at beginning
    cout << endl << endl << "--- Beginning Strengths ---";
    printStrength();


    //display which player attacks first
    switch (turn)
    {
        case 0: cout << endl << endl << "Player 1 attacks first!";
            break;
        case 1: cout << endl << endl << "Player 2 attacks first!";
            break;
    }


    //as long as both creatures have strength, fight!
    do
    {
        //if turns is 0, p1 attacks first, otherwise p2 attacks first
        switch (turn)
        {
            case 0: faceOff(p1, p2);
                break;
            case 1: faceOff(p2, p1);
                break;
        }

        //print strength points after round
        cout << endl << "--- Strengths after round " << rounds << " ---";
        printStrength();

        rounds++;

    } while ( (p1->getStrength() > 0) && (p2->getStrength() > 0) );


    //print who won game
    //player 1 wins
    if ( p1->getStrength() > p2->getStrength() )
        cout << endl << endl << "Player 1 wins with " << p1->getName() << "!";

    //player 2 wins
    else if ( p1->getStrength() < p2->getStrength() )
        cout << endl << endl << "Player 2 wins with " << p2->getName() << "!";

    //if nobody wins, it's a draw
    else
        cout << endl << endl << "The game was a draw.";


    //prep for the next round
    rounds = 1;
    delete p1;
    delete p2;
}
