/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/24/17
Assignment:  CS 162 - Project 2
Description: Header file for input validation function
*/

#ifndef INPUTVAL_H
#define INPUTVAL_H

#include <iostream>
#include <random>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>

using namespace std;

double isDouble();

double doubleRange(double, double  = (unsigned)-1);

int isInt();

int intRange(int,  int = (unsigned)-1);

int randIntRange(int, int);

char isChar();

char isChar2(char, char);


#endif // INPUT H