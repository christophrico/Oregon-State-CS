/****************************************************************************** 
 ** Program Name: paper.cpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Implementation file for the paper class.
 *               
 *****************************************************************************/
 
 #include "paper.hpp"
 
 
/***************************************************************************** 
 ** Description: Constructors
 ****************************************************************************/
 Paper::Paper() : Tool()
 {
     type = 'p';
 }
 
 Paper::Paper(double s) : Tool(s)
 {
     type = 'p';
 }

/***************************************************************************** 
 ** Description: Virtual Destructor. Doesn't need to do anything, just needs
 **              to be virtual.
 ****************************************************************************/
 Paper::~Paper()
 {
 }
 
  /***************************************************************************** 
 ** Description: Fight function, compares 2 tol objects' strengths
 *               returns -1 if lose, 1 if win, 0 if draw
 ****************************************************************************/
 int Paper::fight(Tool *competitor)
 {  
     double paperStrength = strength;
     double competitorStrength = competitor->getStrength(); 
     char competitorType = competitor->getType();
     
     
     //if competitor is rock, strength is doubled
     if (competitorType == 'r')
     {
         paperStrength *= 2;
     }
     
     //if competitor is scissors, strength is halved
     else if (competitorType == 's')
     {
         paperStrength /= 2.0;
     }
     
    //if competitor is paper, strength is unchanged
    
    
    //compare competitor's strength to rockStrength
    //if competitor is stronger, return -1
    if (competitorStrength > paperStrength)
    {
        return -1;
    }
    
    //if competitor is weaker, return 1
    else if (competitorStrength < paperStrength)
    {
        return 1;
    }
    
    //if a draw, return 0
    else
    {
        return 0;
    }
    
 }