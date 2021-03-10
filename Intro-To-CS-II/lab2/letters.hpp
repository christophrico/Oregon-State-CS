/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/2/17
Assignment:	 CS 162 - Project 1
Description: Client code for matrix assignment. Asks user to select
			 a 2x2 or 3x3 matrix, then allocates the array for the
			 matrix. Calls a function to fill the matrix,
			 then another function to get the determinate of the
			 matrix. Then, it de-allocates the array.

			 Compile with readMatrix.cpp, determinate.cpp
*/

#ifndef LETTERS_H
#define LETTERS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

void count_letters(ifstream &, int*);

void output_letters(ofstream &, int*);

#endif // LETTERS H
