/***********************************************************
** Author: Christopher Rico
** Date: 5/22/17
** Description: repeatArray program. Takes a reference to a pointer 
to a dynamically allocated array, doubles it, then copies the values
into the array twice.
************************************************************/

#include <iostream>

using namespace std;

void repeatArray(double *&array, int arrSize)
{
	//define new array with twice the capacity as old array
	double *doubleArray = new double[(arrSize*2)];

	for(int i = 0; i<arrSize; i++)
	{
		//copy in  first set of old array values
		doubleArray[i] = array[i];
		
		//copy in  second set of old array values
		doubleArray[(i + arrSize)] = array[i];  
	}

	//un-point old array pointer from old array
	delete []array;
	
	//point old array pointer at new array
	array = doubleArray;

	//set new array pointer equal to null
	doubleArray = NULL;

}


int main()
{	
	const int START = 5;
	double *myArray = new double[START];

	cout << "Values before running repeatArray:" << endl;	
		
	for(int a = 0; a<START; a++)
	{	
		myArray[a] = (a+2)/1.5;
		cout << myArray[a] << endl;
	}

	repeatArray(myArray, START);
	
	cout << endl << "Values after" << endl;

	for (int b = 0; b<(START*2); b++)
	{
		cout << myArray[b] << endl;
	}

	delete []myArray;
	
	return 0;
}

