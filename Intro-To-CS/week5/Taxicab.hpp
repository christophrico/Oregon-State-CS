//Taxicab.hpp

/******************************************************************
** Author: Christopher Rico
** Date:5/3/17
** Description: Week 5 assignment. Header file for Taxicab class
*******************************************************************/

#ifndef TAXICAB_H
#define TAXICAB_H

#include <iostream>

class Taxicab
{
  private:
    int x, y, totalDist;
    
  public:
    //default constructor
    Taxicab()
    {
      x = 0;
      y = 0;
      totalDist = 0;
    }
    
    //constructor for user to set parameters
    Taxicab(int, int);
    
    //getters
    int getXCoord();
    int getYCoord();
    int getDistanceTraveled();
    
    //mutators
    void moveX(int);
    void moveY(int);
};

#endif //TAXICAB H