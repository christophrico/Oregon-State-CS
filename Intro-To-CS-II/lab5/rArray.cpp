/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/30/17
Assignment:	 CS 162 - Lab 5
Description: Implementation code for rArray function.
            Takes a pointer to an array of doubles and the size of the array
            as arguments, and recursively calculates the sum of the array elements
*/

#include "rArray.hpp"

double rArray(double* arrayIn, int idx)
{
    if (idx < 0)
    {
        return 0;
    }

    //count backwards through the array, summing as you go
    else
    {
        return ( arrayIn[idx] + rArray(arrayIn, idx-1) );
    }
}
