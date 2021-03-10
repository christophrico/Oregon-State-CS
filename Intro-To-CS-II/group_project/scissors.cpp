/****************************************************************************** 
 ** Program Name: scissors.cpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Implementation file for scissors class.
 *****************************************************************************/

#include "scissors.hpp"

/***************************************************************************** 
 ** Description: Constructors
 ****************************************************************************/
 Scissors::Scissors() : Tool()
 {
     type = 's';
 }
 
 Scissors::Scissors(double s) : Tool(s)
 {
     type = 's';
 }
 
/***************************************************************************** 
 ** Description: Virtual Destructor. Doesn't need to do anything, just needs
 **              to be virtual.
 ****************************************************************************/
 Scissors::~Scissors()
 {
 }
 
  /***************************************************************************** 
 ** Description: Fight function, compares 2 tol objects' strengths
 *               returns -1 if lose, 1 if win, 0 if draw
 ****************************************************************************/
 int Scissors::fight(Tool *competitor)
 {  
     double scissorStrength = strength;
     double competitorStrength = competitor->getStrength(); 
     char competitorType = competitor->getType();
     
     
     //if competitor is paper, strength is doubled
     if (competitorType == 'p')
     {
         scissorStrength *= 2;
     }
     
     //if competitor is paper, strength is halved
     else if (competitorType == 'r')
     {
         scissorStrength /= 2.0;
     }
     
    //if competitor is rock, strength is unchanged
    
    
    //compare competitor's strength to rockStrength
    //if competitor is stronger, return -1
    if (competitorStrength > scissorStrength)
    {
        return -1;
    }
    
    //if competitor is weaker, return 1
    else if (competitorStrength < scissorStrength)
    {
        return 1;
    }
    
    //if a draw, return 0
    else
    {
        return 0;
    }
    
 }