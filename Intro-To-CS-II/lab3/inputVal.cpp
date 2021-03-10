/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/16/17
Assignment:  CS 162 - Lab 3
Description: Implementation file for input validation function.
             Contains functions to check:
            -If input is integer
            -If input is integer within range
            -Generate integer within range
            -If input is a char value
            -If input is one of two char values
*/

#include "inputVal.hpp"

//check for an integer value, return if valid
int isInt()
{
    int intInput;

    //as long as the input cannot be inputted to an integer value, ask for re-entry
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> intInput))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter an whole number." << endl;

        //clear the input stream
        cin.clear();
        cin.ignore((unsigned)-1, '\n');

    }

    //clear the input stream for the next value
    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return an integer (even if a double was given)
    return intInput;
}

//check for a value between user-specified range. Takes low, high end
//of range as parameters and returns integer if valid.
int intRange(int low, int high)
{
    int rangeIn;

    //as long as the user value isn't between range specified
    //or isn't an integer, ask for a new value
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> rangeIn) || (rangeIn < low || rangeIn > high))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter a whole number between ";
        cout << low << " and " << high << endl;

        cin.clear();
        cin.ignore((unsigned)-1, '\n');

    }

    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return an integer
    return rangeIn;
}

//check that an integer is positive
int posInt()
{
    int posInput;

    //as long as the user value isn't positive
    //or isn't an integer, ask for a new value
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> posInput) || (posInput < 1))
    {
      cout << endl << "That is not valid!";
      cout << endl << "Please enter a positive integer." << endl;

      cin.clear();
      cin.ignore((unsigned)-1, '\n');
    }

    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    return posInput;
}

//returns random integer within range
//https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
int randIntRange(int lowRand, int highRand)
{
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distr (lowRand, highRand);

  return distr(eng);
}

//check for a char, return if valid
char isChar()
{
    char charInput;

    cin.get(charInput);

    //as long as the input cannot be inputted to an char value, ask for re-entry
    while (!isalpha(charInput))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter a character A-Z." << endl;

        //clear the input stream
        cin.clear();
        cin.ignore(100, '\n');

        //get next char
        cin.get(charInput);
    }

    //clear the input stream for the next value
    cin.clear();
    cin.ignore();

    //return an char
    return charInput;
}

//check for one of two chars, return if valid
char isChar2(char c1, char c2)
{
    char char2Input;

    cin.get(char2Input);

    //as long as the input cannot be inputted to an char value, ask for re-entry
    while (char2Input != c1 && char2Input != c2)
    {
        cout << "That is not valid!";
        cout << endl << "Please enter either " << c1 << " or " << c2 << endl;

        //clear the input stream
        cin.clear();
        cin.ignore(100, '\n');

        //get next char
        cin.get(char2Input);
    }

    //clear the input stream for the next value
    cin.clear();
    cin.ignore();

    //return an char
    return char2Input;
}
