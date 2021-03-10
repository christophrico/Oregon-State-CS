/****************************************************************************** 
 ** Program Name: rpsgame.hpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Header file for rpsgame class.
*****************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "inputVal.hpp"
#include "tool.hpp"
#include "paper.hpp"
#include "scissors.hpp"
#include "rock.hpp"

class RPSGame{
private:
    Tool* human;
    Tool* computer;
    
    // Game win trackers
    int humanWins;
    int computerWins;
    int ties;

    // Function to return outcome of the fight.
    //  h = human win
    //  c = computer win
    //  t = tie
    char compareTools(Tool* human, Tool* computer);
    
    // Function to decide what the computer will choose
    Tool* chooseCompTool(double rS, double pS, double sS);

public:
    // Constructor
    RPSGame();
    
    // Function to play the game:
    //   Should call compareTools on each loop 
    //   after gathering human inputs
    void playGame();

};
#endif // RPSGAME_HPP