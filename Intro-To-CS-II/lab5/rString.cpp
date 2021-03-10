/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/30/17
Assignment:	 CS 162 - Lab 5
Description: Implemetation file for rString function. This function takes a string
             as its argument and recursively prints the string in reverse to the screen
*/

#include "rString.hpp"

void rString(string s)
{

    //if string has no characters, print newline
    if (s.length() == 0)
    {
        cout << "\n";

    }

    //otherwise
    else
    {
        //print the last character in the string
        cout << ( s[s.length()-1] );

        //erase the last character in the string
        s.erase( (s.length()-1), 1 );

        //pass the string back to rString to repeat
        rString(s);
    }

    return;
}
