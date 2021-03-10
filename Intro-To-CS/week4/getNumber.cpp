// this function gets a number between 1 and 100 from the user.


#include <iostream>
using namespace std;

void getNumber(int &);

int main()
{
	int number;
	
	getNumber(number);

	cout <<"Number is " <<  number << endl;

	return 0;
}

void getNumber(int &num)
{
	cout << "Please enter a number between 1 and 100: \n";
	cin >> num;

	while(num < 1 || num > 100) 
	{
	 cout <<  "That was not a valid number." 
 	      <<  " Please enter a number between 1 and 100.\n";
	 cin >> num;
	}
}
	
