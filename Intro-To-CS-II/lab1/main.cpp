/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/2/17
Assignment:	 CS 162 - Lab 1
Description: Client code for matrix assignment. Asks user to select
			 a 2x2 or 3x3 matrix, then allocates the array for the 
			 matrix. Calls a function to fill the matrix,
			 then another function to get the determinate of the
			 matrix. Then, it de-allocates the array.
			 
			 Compile with readMatrix.cpp, determinate.cpp
*/

#include "determinant.hpp"
#include "readMatrix.hpp"

int main()
{
	int userChoice, **myArray;

	cout << "Hello! This program will calculate " << endl;
	cout << "the determinant of a square matrix. " << endl << endl;
	cout << "Please enter a 2 to choose a 2x2 matrix " << endl;
	cout << "or a 3 to choose a 3x3 matrix." << endl;

	cin >> userChoice;
	
	//using input validation to check if input is 2 or 3
	//don't continue until user enters a 2 or a 3
	while (!(userChoice == 2 || userChoice == 3))
	{
		cout << endl << "That was not a valid choice." << endl << endl;
		cout << "Please enter a 2 to choose a 2x2 matrix " << endl;
		cout << "or a 3 to choose a 3x3 matrix." << endl;

		cin >> userChoice;
	}
	
	//assign myArray to a dynamically allocated
	//array of pointers
	myArray = new int*[userChoice];
	
	for (int i = 0; i < userChoice; i++)
		myArray[i] = new int[userChoice];
			
	
	//pass pointer to array and array size
	//to readMatrix() so it can be populated
	readMatrix(myArray, userChoice);

	//print the matrix
	cout << endl;
	for (int row = 0; row < userChoice; row++)
	{
		for (int col = 0; col < userChoice; col++)
			cout << myArray[row][col] << " ";

		cout << endl;
	}

	//display the determinant by calling determinant()
	cout << endl << "The determinant of this matrix is ";
	cout << determinant(myArray, userChoice) << endl;

	
	//free memory set aside for myArray
	for (int k = 0; k < userChoice; k++)
		delete myArray[k];
	
	delete []myArray;

	return 0;
}