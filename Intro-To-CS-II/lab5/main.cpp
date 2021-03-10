/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/30/17
Assignment:	 CS 162 - Lab 5
Description: Client code for recursion assignment. Displays menu asking user
             which recursinve function they would like to use

			 Compile with inputVal.cpp, menu.cpp, rArray.cpp, rString.cpp,
			               rTriangle.cpp
*/

#include "menu.hpp"
#include "rTriangle.hpp"
#include "rString.hpp"
#include "rArray.hpp"

int userChoice,
    triangleNum,
    arrayN;
double *sumArray;
string stringRev;


int main()
{
    //as long as user doesn't want to exit, ask which function they would like
    do
    {
        userChoice = displayMenu();

        //if user wants to reverse a string
        if (userChoice == 1)
        {
            cout << endl << "Please enter a text string: " << endl;
            getline(cin, stringRev);

            cout << endl << "Your string reversed is:" << endl;
            rString(stringRev);
        }


        //if user wants to input an array and reverse it
        else if (userChoice == 2)
        {
            cout << endl << "How many numbers would you like to sum up?" << endl;
            arrayN = intRange(1,100);
            cout << endl << "Please enter " << arrayN << " numbers." << endl;

            sumArray = new double[arrayN];

            //get user input into the array, validate
            for (int i = 0; i < arrayN; i++)
            {
                sumArray[i] = isDouble();
            }

            //print results
            cout << endl << "The sum of these numbers is "
                 << rArray(sumArray, arrayN) << endl;


            delete []sumArray;
            sumArray = nullptr;
        }


        //if user wants to calculate the triangle number of a number
        else if(userChoice == 3)
        {
            cout << endl << "Please enter a positive integer: " << endl;
            triangleNum = intRange(1,1000);


            cout << endl << "The triangle number for " << triangleNum
                 << " is " << rTriangle(triangleNum) << endl;
        }

    }while(userChoice != 4);


    cout << endl << "Have a lovely day!" << endl;

    return 0;
}
