/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/30/17
Assignment:	 CS 162 - Lab 5
Description: Implementation file for rTriangle function. This function
            takes an integer as an argument and recursively calculates its 'triangle number'
            i.e., how many numbers in total would be needed to create a triandle
            with a size of the passed number for its base.

              ex: 5 has a triangle number of 15:
              = = = = =
               = = = =
                = = =
                 = =
                  =
*/

#include "rTriangle.hpp"

int rTriangle(int t)
{
    if (t >= 1)
    {
        return ( rTriangle(t-1) + t );
    }

    else
    {
        return 0;
    }

}
