/******************************************************************************
 ** Author:       Christopher Rico
 ** Date:         8/6/2017
 ** Description:  Header file for input validation functions.
                  Also contains #include statements for all needed libraries

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

#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

#include <iostream>
#include <string>
#include <iomanip>

#include <random>
#include <algorithm>
#include <climits>
#include <cfloat>

#include <ctype.h>

using namespace std;


/*********************************
 ** Double validation functions
 *********************************/
double isDouble();
double doubleRange(double, double  = DBL_MAX);
double randDoubRange(double, double);


/********************************
 ** Integer validation functions
 *********************************/
int isInt();
int intRange(int = 0,  int = INT_MAX);
int randIntRange(int, int);


/**********************************
 ** Character validation functions
 **********************************/
char isChar();
char isChar2(char, char);
char isChar4(char c1, char c2, char c3, char c4);

#endif // INPUT H
