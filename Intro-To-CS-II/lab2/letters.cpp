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

#include "letters.hpp"

void count_letters(ifstream &fileIn, int* lets)
{
  char ch;

  //read first character in file
  ch = fileIn.get();
  ch = toupper(ch);

    //for each paragraph, read the letters
    while (ch != EOF)
    {
      //increment letter counter for each letter read
      switch (ch)
      {
        case 'A': lets[0]++;
          break;
        case 'B': lets[1]++;
          break;
        case 'C': lets[2]++;
          break;
        case 'D': lets[3]++;
          break;
        case 'E': lets[4]++;
          break;
        case 'F': lets[5]++;
          break;
        case 'G': lets[6]++;
          break;
        case 'H': lets[7]++;
          break;
        case 'I': lets[8]++;
          break;
        case 'J': lets[9]++;
          break;
        case 'K': lets[10]++;
          break;
        case 'L': lets[11]++;
          break;
        case 'M': lets[12]++;
          break;
        case 'N': lets[13]++;
          break;
        case 'O': lets[14]++;
          break;
        case 'P': lets[15]++;
          break;
        case 'Q': lets[16]++;
          break;
        case 'R': lets[17]++;
          break;
        case 'S': lets[18]++;
          break;
        case 'T': lets[19]++;
          break;
        case 'U': lets[20]++;
          break;
        case 'V': lets[21]++;
          break;
        case 'W': lets[22]++;
          break;
        case 'X': lets[23]++;
          break;
        case 'Y': lets[24]++;
          break;
        case 'Z': lets[25]++;
          break;

      }
      //get next letter in fileIn
      ch = fileIn.get();
      ch = toupper(ch);
    }

    for(int i = 0; i<26 ; i++)
    {
      cout << (char)('A' + i) << ": " << lets[i] << endl;
    }

    //call output_letters at end of each paragraph
    //output_letters(fileIn, lets);

  cout << endl << "end of file.";
  //at end of file, go back to main
  return;
}

/*void output_letters(ofstream &, int*)
{

}
*/
