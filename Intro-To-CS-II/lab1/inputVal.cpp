/*
Name: Christopher Rico
OSU ID: 933239746
Date: 7/2/17
Assignment: CS 162 - Lab 1
Description: Implementation file for input validation function.
            Contains two functions for retrieving input from 
            a user and checking to see if input is an integer
            or a double value, respectively.
*/

#include <iostream>
#include <string>

using namespace std;

//check for a double value
double isDouble()
{
    double dubInput;
    
    //as long as the user value
    //cannot be inputted to an double value
    //ask for a new value
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> dubInput))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter a number.";
        
        cin.clear();
        cin.ignore((unsigned)-1, '\n');
        
        cin >> dubInput; 
    }
    
    //clear the input stream for the next value
    cin.clear();
    cin.ignore((unsigned)-1, '\n');
    
    //return the double value
    return dubInput;
    
}


//check for an integer value
int isInt()
{   
    int intInput;
    
    //as long as the user value
    //cannot be inputted to an integer value
    //ask for a new value
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> intInput))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter an whole number." << endl;
        
        //clear the input stream
        cin.clear();
        cin.ignore((unsigned)-1, '\n');
        
        cin >> intInput;
    }
    
    //clear the input stream for the next value
    cin.clear();
    cin.ignore((unsigned)-1, '\n');
    
    //return an integer (even if a double was given)
    return intInput;
    
}