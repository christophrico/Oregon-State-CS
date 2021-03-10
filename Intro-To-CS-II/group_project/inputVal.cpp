/****************************************************************************** 
 ** Program Name: inputVal.cpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Implementation file for input validation functions.
 
             Contains functions to check:
            -If input is a double
            -If input is a double within range
            -Random double within range
            
            -If input is integer
            -If input is integer within range
            -Random integer within range
            
            -If input is a char
            -If input is one of two chars
            -If input is one of four chars
*****************************************************************************/

#include "inputVal.hpp"


/******************************** 
 ** Double validation functions
 ********************************/
//check if input is a double value, return if valid
double isDouble()
{
    double dubInput;

    //as long as the input cannot be inputted to a double value, ask for re-entry
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> dubInput))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter a number: ";

        //clear the input stream
        cin.clear();
        cin.ignore((unsigned)-1, '\n');

    }

    //clear the input stream for the next value
    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return an integer (even if a double was given)
    return dubInput;
}

//check for a double value between user-specified range. Takes low, high end
//of range as parameters and returns double if valid.
//to check for a positive double, only pass '0' as an argument
double doubleRange(double low, double high)
{
    double dubRangeIn;

    //as long as the user value isn't between range specified
    //or isn't an integer, ask for a new value
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> dubRangeIn) || (dubRangeIn < low || dubRangeIn > high))
    {
        cout << "That is not valid!";
        
        if (high < ((unsigned) -1))
        {
            cout << endl << "Please enter a number between ";
            cout << low << " and " << high << ": ";
        }
        
        else
        {
            cout << endl << "Please enter a positive number: ";
        }

        cin.clear();
        cin.ignore((unsigned)-1, '\n');

    }

    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return an integer
    return dubRangeIn;
}

//returns random double within parameter range
//https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
double randDoubRange(double lowD, double hiD)
{
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> distr (lowD, hiD);

  return distr(gen);
}



/******************************** 
 ** Integer validation functions
 ********************************/
//check if input is an integer value, return if valid
int isInt()
{
    int intInput;

    //as long as the input cannot be inputted to an integer value, ask for re-entry
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> intInput))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter an whole number: ";

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

//check for an int value between user-specified range. Takes low, high end
//of range as parameters and returns integer if valid.
//to check for a positive integer, only pass '0' as an argument
int intRange(int low, int high)
{
    int rangeIn;

    //as long as the user value isn't between range specified
    //or isn't an integer, ask for a new value
    //http://www.dreamincode.net/forums/topic/236133-validate-user-input-c/
    while (!(cin >> rangeIn) || (rangeIn < low || rangeIn > high))
    {
        if (high < ((unsigned) -1))
        {
            cout << endl << "Please enter a whole number between ";
            cout << low << " and " << high << ": ";
        }
        
        else
        {
            cout << endl << "Please enter a positive whole number: ";
        }

        cin.clear();
        cin.ignore((unsigned)-1, '\n');

    }

    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return an integer
    return rangeIn;
}

//returns random integer within parameter range
//https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
int randIntRange(int lowRand, int highRand)
{
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distr (lowRand, highRand);

  return distr(eng);
}



/**********************************
 ** Character validation functions
 **********************************/
//check if input is a char, return if valid
char isChar()
{
    char charInput;

    cin.get(charInput);

    //as long as the input cannot be inputted to an char value, ask for re-entry
    while (!isalpha(charInput))
    {
        cout << "That is not valid!";
        cout << endl << "Please enter a character A-Z: ";

        //clear the input stream
        cin.clear();
        cin.ignore((unsigned)-1, '\n');

        //get next char
        cin.get(charInput);
    }

    //clear the input stream for the next value
    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return an char
    return charInput;
}

//check is input is one of two chars, return char if valid
char isChar2(char c1, char c2)
{
    char char2Input;

    cin >> char2Input ;

    //as long as the input cannot be inputted to an char value, ask for re-entry
    while (char2Input != c1 && char2Input != c2)
    {
        cout << endl << "That is not valid!";
        cout << endl << "Please enter either " << c1 << " or " << c2 << ": ";

        //clear the input stream
        cin.clear();
        cin.ignore((unsigned)-1, '\n');

        //get next char
        cin >> char2Input;
    }

    //clear the input stream for the next value
    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return a char
    return char2Input;
}

//check if input is one of 4 characters, return char if valid
char isChar4(char c1, char c2, char c3, char c4)
{
    char char4Input;

    cin >> char4Input;

    //as long as the input cannot be inputted to an char value, ask for re-entry
    while (char4Input != c1 && char4Input != c2 && char4Input != c3 && char4Input != c4)
    {
        cout << endl << "That is not valid!";
        cout << endl << "Please enter either " << c1 << ", " << c2 << ", "
                     << c3 << ", or " << c4 << ": ";

        //clear the input stream
        cin.clear();
        cin.ignore((unsigned)-1, '\n');

        //get next char
        cin >> char4Input;
    }

    //clear the input stream for the next value
    cin.clear();
    cin.ignore((unsigned)-1, '\n');

    //return a char
    return char4Input;
}