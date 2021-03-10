//stdDev.cpp

/************************************************************
** Author: Christopher Rico
** Date:5/17/17
** Description: Week 7 assignment. stdDev function definition
	Takes two parameters: an array of Person classes and the size
	of the array. Returns the population standard deviation of all
	the ages in the array.
*************************************************************/

#include <iostream>
#include <cmath>
#include "Person.hpp"

using namespace std;

double stdDev(Person arrPeeps[], int peepSize)
{
	double ageSum, //top of the fraction in the stdev formula
	       ageAvg; //average of all the ages of the people objects

    //get the sum of all the ages in the array of person objects
	for (int i = 0; i < peepSize; i++)
	{
		ageAvg += arrPeeps[i].getAge();
	}
	
	//calc the average of the ages
	ageAvg /= peepSize;

	//get the sum of all the (individial age - average age)^2
	//for each person obj in the array
	for (int k = 0; k < peepSize; k++)
	{
		ageSum += pow((arrPeeps[k].getAge() - ageAvg), 2);
	}

	//take the square root to find the population stdev and return it
	return sqrt(ageSum/peepSize);

}

/*
int main()
{
	const int NUM_PEEPS = 7;


	Person testPeeps[NUM_PEEPS] = {Person("B", 50), Person("J", 12.8), Person("C", 10.5), 

						  Person("h", 5.6), Person("r", 8), Person("e", 21), Person("l", 28.2)};

	cout << stdDev(testPeeps, NUM_PEEPS) << endl;

	for(int j = 0; j < NUM_PEEPS; j++)
	{
		cout << testPeeps[j].getName() << endl;
	}

	return 0;
}
*/
