/*
Name:		     Christopher Rico
OSU ID:		   933239746
Date:        8/16/17
Assignment:	 CS 162 - Final project
Description: Implementation file for art functions. These functions print out
             different art for the Burning Man game.
             Compile with inputVal.cpp, player.cpp, space. cpp, deepplaya.cpp,
             distrikt.cpp, man.cpp, nineoclock.cpp, rv.cpp, temple.cpp

*/

#include "art.hpp"


//prints out a gigantic man and the beginning instructions to the game
void beginningArt()
{

    cout << endl << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMM~MMMMMMMMMMMMMMMMMMMMMMMMMMMMM+MMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMM?MMMMMMMMMMMMMMMMMMMMMMMMM?MMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMM`MMMMMMMMMMD MMMMMMMMMMM,MMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM`MMMMMMM``=M=  MMMMMMM`8MMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM7 NMM= `MMMMMMM  =MMN`IMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM `MMD`:NMMMMMMN MMM  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM `MMM`ZMMMMMZ`MMM `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM` MMM `MMM``MMM  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN` MMM``M  MMM` ~MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  `MMM  `MMM```MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMD `MMMM MMMM  NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`  MMMMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMI `MMMMMMM  7MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM ``MMMMM` `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`  MMMMM`  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   MMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`  MMMMM  `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   MMMMM`  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`  MMMMM  `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   MMMMM  `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO `OMMMMMO `OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  `MMMMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM` `MMMMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`  MMMMMMMMM  ,MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM`  MMMMMMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM` MMMMMMMMMMM` 8MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   MMMMMMMMMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM` MMMMMMMMMMMMM` MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM, ~MMMMMMMMMMMMM= `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMMMMM` MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM``NMMMMMMMMMMMMMMMM `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMM``MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM `MMMMMMMMMMMMMMMMMMM `MMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM`MMMMMMMMMMMMMMMMMMMMM IMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMM OMMMMMMMMMMMMMMMMMMMMM8`MMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMZ`MMMMMMMMMMMMMMMMMMMMMMM`OMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMMMMMMMMMMM`MMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMM`MMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMM=MMMMMMMMMMMMMMMMMMMMMMMMMMMMM+MMMMMMMMMMMMMMMMMMMMMMMMM \n";
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;

    cout << endl << endl
         << ")'(________)'(________)'(____Welcome to Burning Man!____)'(________)'(________)'(";
    cout << endl << endl << "After a wild night out on the Playa, you've woken up.";
    cout << endl << "You made it back to your RV, but OH NO! Your favorite fur vest has gone missing!";
    cout << endl << "Your goal is to find it before tonight!";
    cout << endl << endl << "You have 300 steps to take, so use them wisely. Watch out for Dust Storms, too.";
    cout << endl << "Ready, Set, LET'S GET WEIRD!";
}


//prints out a banner that tells the user they won
void winnerArt()
{
  cout << endl << "   __   __  _______  __   __        _     _  ___   __    _    __   __   __  \n";
  cout << "  |  | |  ||       ||  | |  |      | | _ | ||   | |  |  | |  |  | |  | |  | \n";
  cout << "  |  |_|  ||   _   ||  | |  |      | || || ||   | |   |_| |  |  | |  | |  | \n";
  cout << "  |       ||  | |  ||  |_|  |      |       ||   | |       |  |  | |  | |  | \n";
  cout << "  |_     _||  |_|  ||       |      |       ||   | |  _    |  |__| |__| |__| \n";
  cout << "    |   |  |       ||       |      |   _   ||   | | | |   |   __   __   __  \n";
  cout << "    |___|  |_______||_______|      |__| |__||___| |_|  |__|  |__| |__| |__| \n";

}

//prints out 50 lines of 'dust' over and over to let user know they were caught in a dust storm
void dustStormArt()
{
    for(int i = 0; i < 50; i++)
      cout << "DUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUSTDUST" << endl;

     cout << endl << "You got caught in a dust storm! You lost 50 steps trying to find your way out.";
}

//prints out a poor quality map of the game space
void mapArt()
{
    cout <<  endl << ")’( )’( )’( )’( )’( )’( )’(  BLACK ROCK CITY, NEVADA  )’( )’( )’( )’( )’( )’( )’(";
    cout << endl;
    cout << endl;
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
    cout << "```````````````````````````` DEEP PLAYA ````````````````````````````````````````\n";
    cout << "``````````````````````````&```````&```````&`````````````````````````````````````\n";
    cout << "`````````````````````&```````````````````````&``````````````````````````````````\n";
    cout << "``````````````````&```````````````&`````````````````````````````````````````````\n";
    cout << "`````````````````````````````````````````````````&``````````````````````````````\n";
    cout << "```````````````&```````````````````&````````````````````````````````````````````\n";
    cout << "```````````````````````````````````````````````````&````````````````````````````\n";
    cout << "`````````````&`````````````````````&````````````````````````````````````````````\n";
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
    cout << "```````` THE MAN ``````````````````&`````````````````&``````````````````````````\n";
    cout << "``````````````````&`````````````````````````````````````````````````````````````\n";
    cout << "````````````&````````&`````````````&``````````````````&`````````````````````````\n";
    cout << "````````````````````````&```````````````````````````````````````````````````````\n";
    cout << "````````````&``````````````` THE TEMPLE `&``&``&``&`` YOUR RV ``````````````````\n";
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
    cout << "````````````&```````````````````&````````````````````````&``````````````````````\n";
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
    cout << "````````````&````````````````&````````````````````````````&`````````````````````\n";
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
    cout << "`````````````&``````````&````````````````````````````````&``````````````````````\n";
    cout << "````````````````````&```````````````````````````````````````````````````````````\n";
    cout << "````````` DISTRIKT `````````````````````````````````````&```````````````````````\n";
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
    cout << "`````````````````&````````````````````````````````````&`````````````````````````\n";
    cout << "````````````````````&```````````````````````````````&```````````````````````````\n";
    cout << "`````````````````````````&````  9 O'CLOCK PLAZA ````````````````````````````````\n";
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
    cout << "````````````````````````````````````````````````````````````````````````````````\n";
}
