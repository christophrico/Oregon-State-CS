/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/2/17
Assignment:	 CS 162 - Lab 1
Description: Implementation file for determinant function.
			 Takes pointer to an array of pointers, and 
			 an integer to indicate the size of the array
			 as arguments.
			 Calculates the determinant of a 2x2 or 3x3 matrix.
*/

int determinant(int **arr, int arrSize)
{
	double determ = 0;
	//calculate the determinant of a 2x2 array
	if (arrSize == 2)
	{
		determ = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
	}

	//calculate the determinant of a 3x3 array
	if (arrSize == 3)
	{
		determ = (arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1]))) -
				 (arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0]))) +
				 (arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[1][1] * arr[2][0])));
	}

	return determ;
}

