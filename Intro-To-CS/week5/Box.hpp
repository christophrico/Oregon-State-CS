// Box.hpp

/************************************************************
** Author: Christopher Rico
** Date:5/3/17
** Description: Week 5 assignment. Header file for Box class
*************************************************************/

#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
  private:
    double height,width,length;
    
  public:
    //default constructor
    Box()
    {
      height = 1;
      width = 1;
      length = 1;
    }
         
    //constructor for user to set parameters
    Box(double h, double w, double l);
    
    //setters
    void setHeight(double);
    void setWidth(double);
    void setLength(double);
    
    //calculations/mutators?
    double calcVolume();
    double calcSurfaceArea();
};

#endif // BOX H
