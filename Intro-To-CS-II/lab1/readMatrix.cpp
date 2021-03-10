/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/2/17
Assignment:	 CS 162 - Lab 1
Description: Implementation file for readMatrix function.
			Takes pointer to an array of pointers, and 
			 an integer to indicate the size of the array
			 as arguments.
			 Asks user to input 4 or 9 integers, and
			 validates input using isInt function.
			 
			 Compile with inputVal.cpp
*/

#include "inputVal.hpp"
#include "readMatrix.hpp"
#include <cmath>

void readMatrix(int **arr, int arraySize)
{

	cout << endl << "Now you will enter " << (pow(arraySize, 2)) << " values." << endl;
	
	//step through the array one elment at a time
	for (int row = 0; row < arraySize; row++)
	{
		for (int col = 0; col < arraySize; col++)
		{	
			//use isInt to validate that each entry
			//is actually a double number
			//and get user input into the array
			arr[row][col] = isInt();
		}
	}
}
