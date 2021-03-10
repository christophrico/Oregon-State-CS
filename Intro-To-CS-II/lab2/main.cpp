/*
Name:		 Christopher Rico
OSU ID:		 933239746
Date:		 7/2/17
Assignment:	 CS 162 - Project 1
			 Compile with readMatrix.cpp, determinate.cpp
*/

#include "menu.hpp"
#include "letters.hpp"

int main()
{

    string inputFileName;
    ifstream ifs;
    int letters[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    cout << "Hello! Welcome to letter counter." << endl;

    //display menu, ask if user wants to start program
    while (displayMenu() != 2)
    {
        cout << "What is the name of the file you would like to open?" << endl;
        cin >> inputFileName;

        //try to open the file
        ifs.open(inputFileName.c_str(), ios::in);

        //if it doesn't work, ask for another name and try again
        if(!ifs)
        {
          cout << endl << inputFileName << " could not be opened.";
          return 1;
        }
        //count the frequency of each letter in a paragraph
        //then ask user for the filename to save this data to

        count_letters(ifs, letters);

        cout << endl << "file now closing";
        ifs.close();
    }

    //ask user if they would like to go again
    //if not, end program
    cout << endl << "Goodbye! Have a lovely day :)" << endl;

    return 0;
}
