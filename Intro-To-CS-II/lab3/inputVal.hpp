/*
Name:        Christopher Rico
OSU ID:      933239746
Date:        7/9/17
Assignment:  CS 162 - Lab 2
Description: Header file for input validation function
*/

#ifndef INPUTVAL_H
#define INPUTVAL_H

#include <iostream>
#include <random>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

double isDouble();

int isInt();

int posInt();

int randIntRange(int, int);

int intRange(int, int);

char isChar();

char isChar2(char, char);


#endif // INPUT H
