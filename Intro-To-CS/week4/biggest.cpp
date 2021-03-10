// Function that receives three numbers and returns the biggest of the three.

#include <iostream>
using namespace std;

int biggest(int, int, int);

int main()
{
	int numOne,numTwo,numThree, largestNum;

	cout << "Please enter three integers: \n";
	cin >> numOne >> numTwo >> numThree;

	largestNum = biggest(numOne, numTwo, numThree);

	cout << "The biggest of these is " << largestNum << endl;
	
	return 0;
}

int biggest(int a, int b, int c)
{
	int largest = a;
	
	if(b > largest)
	  largest = b;

	if (c > largest)
	  largest = c;

	return largest;
}
