/****************************************************************************** 
 ** Program Name: rock.cpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Implementation file for the rock class.
 *               
 *****************************************************************************/
 
 #include "rock.hpp"
 
 /***************************************************************************** 
 ** Description: Constructors
 ****************************************************************************/
 Rock::Rock() : Tool()
 {
     type = 'r';
 }
 
 Rock::Rock(double s) : Tool(s)
 {
     type = 'r';
 }
 
 /***************************************************************************** 
 ** Description: Virtual Destructor. Doesn't need to do anything, just needs
 **              to be virtual.
 ****************************************************************************/
 Rock::~Rock()
 {
 }
 
 /***************************************************************************** 
 ** Description: Fight function, compares 2 tol objects' strengths
 *               returns -1 if lose, 1 if win, 0 if draw
 ****************************************************************************/
 int Rock::fight(Tool *competitor)
 {  
     double rockStrength = strength;
     double competitorStrength = competitor->getStrength();
     char competitorType = competitor->getType();
     
     
     //if competitor is scissors, strength is doubled
     if (competitorType == 's')
     {
         rockStrength *= 2;
     }
     
     //if competitor is paper, strength is halved
     else if (competitorType == 'p')
     {
         rockStrength /= 2.0;
     }
     
    //if competitor is rock, strength is unchanged
    
    
    //compare competitor's strength to rockStrength
    //if competitor is stronger, return -1
    if (competitorStrength > rockStrength)
    {
        return -1;
    }
    
    //if competitor is weaker, return 1
    else if (competitorStrength < rockStrength)
    {
        return 1;
    }
    
    //if a draw, return 0
    else
    {
        return 0;
    }
    
 }