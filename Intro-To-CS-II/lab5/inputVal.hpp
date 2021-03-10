/****************************************************************************** 
 ** Program Name: inputVal.hpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Header file for input validation functions.
               
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
#include <random>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
#include <sstream>

using namespace std;


/*********************************
 ** Double validation functions
 *********************************/
double isDouble();
double doubleRange(double, double  = ((unsigned)-1));
double randDoubRange(double, double);


/********************************
 ** Integer validation functions
 *********************************/
int isInt();
int intRange(int,  int = ((unsigned)-1));
int randIntRange(int, int);


/**********************************
 ** Character validation functions
 **********************************/
char isChar();
char isChar2(char, char);
char isChar4(char c1, char c2, char c3, char c4);

#endif // INPUT H