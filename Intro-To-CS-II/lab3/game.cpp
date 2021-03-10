/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Implementation file for game class.
             Contains only one public method, playGame.
             
             Asks users what kind of die (loaded/standard), how many sides for each die,
             and how many rounds they would like to play. Dynamically allocates 2
             die or loaded die objects, then compares rolls for designated number
             of turns. Then, prints die types and sides, roll counts, and
             final score to screen.

             Compile with main.cpp, die.cpp, LoadedDie.cpp, inputVal.cpp
*/

#include "game.hpp"

//constructor, initializes player scores to 0
Game::Game()
{
    player1Score = player2Score = 0;
}

//controls game play for correct number of rounds.
//asks user for die sides and type, number of rounds, and creates die objects
void Game::playGame()
{
    //get player 1 stats
    cout << endl << "Player 1, pick your die: ";
    cout << endl << "Die type: enter 'l' for loaded or 's' for standard. ";
    player1Type = isChar2('l', 's');
    cout << "Die sides: enter between " << MIN_SIDES << " and " << MAX_SIDES << " ";
    player1Sides = intRange(MIN_SIDES, MAX_SIDES);

    //get player 2 stats
    cout << endl << endl << "Player 2, pick your die: ";
    cout << endl << "Die type: enter 'l' for loaded or 's' for standard. ";
    player2Type = isChar2('l', 's');
    cout << "Die sides: enter between " << MIN_SIDES << " and " << MAX_SIDES << " ";
    player2Sides = intRange(MIN_SIDES, MAX_SIDES);

    //get number of rounds
    cout << endl << "How many rounds would you like to play? ";
    rounds = posInt();


    //create 2d array to hold scores
    makeArray();

    //initialize player 1 die obj
    if (player1Type == 'l')
    {
      d1 = new LoadedDie(player1Sides);
    }
    else
      d1 = new Die(player1Sides);

    //initialize player 2 die obj
    if (player2Type =='l')
        d2 = new LoadedDie(player2Sides);
    else
        d2 = new Die(player2Sides);


    //roll dice for j number of turns, get user scores
    for(int j = 0; j<rounds; j++)
    {
        compDie(j);
    }

    //print results
    printGame();

    return;
}

//calls each die, records scores in score array, and increments winner's score
//takes round number (starting with 0) as argument
void Game::compDie(int r)
{
    //roll each die to get a result, record results
    results[0][r] = d1->roll();
    results[1][r] = d2->roll();

    //increment winner's score
    if (results[0][r] > results[1][r])
        player1Score++;

    else if (results[0][r] < results[1][r])
        player2Score++;

    return;
}

//prints out game statistics once game is through
void Game::printGame()
{
    cout << endl << "!!! RESULTS !!!";
    cout << endl << "----------------";

    //print player 1 die type
    if (player1Type == 's')
    {
        cout << endl << "Player One's die was standard and had "
             << player1Sides << " sides.";
    }
    else
    {
        cout << endl << "Player One's die was loaded and had "
             << player1Sides << " sides.";
    }

    //print player 2 die type
    if (player2Type == 's')
    {
        cout << endl << "Player Two's die was standard and had "
             << player2Sides << " sides.";
    }
    else
    {
        cout << endl << "Player Two's die was loaded and had "
             << player2Sides << " sides.";
    }


    //print roll numbers
    cout << endl << endl << "Numbers rolled per round:";
    cout << endl << "Player 1 | Player 2";
    cout << endl << setw(2) << " __________________" << endl;

    for (int i = 0; i<rounds; i++)
    {
        cout << setw(5) << results[0][i] << "    |    ";
        cout << results[1][i] << endl;
    }


    //print final scores
    cout << endl << "Player One's final score is " << player1Score;
    cout << endl << "Player Two's final score is " << player2Score;


    //print winner or if game is draw
    if (player1Score > player2Score)
        cout << endl << endl << "Player One wins!" << endl;

    if (player1Score < player2Score)
        cout << endl << endl << "Player Two wins!" << endl;

    else if(player1Score == player2Score)
        cout << endl << endl << "The game was a draw." << endl;

    return;
}

//creates 2D array to fit correct number of game rounds
void Game::makeArray()
{
  //create new array, assign it to array variable
  results = new int*[2];

  //create array of pointers to arrays
  for (int i = 0; i < 2; i++)
  {
    results[i] = new int[rounds];
  }

  //initialize array to 0
  for (int e = 0; e < rounds; e++)
  {
      results[0][e] = results[1][e] = 0;
  }

  return;
}

//destroys 2d array and die objects at end of game
Game::~Game()
{
    for (int k = 0; k < 2; k++)
    {
        delete [] results[k];
    }

    //delete all dynamic objects
    delete []results;
    delete d1;
    delete d2;
}
