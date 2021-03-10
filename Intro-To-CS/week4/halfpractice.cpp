/* this is a program to play with the made-up half function*/

#include <iostream>
using namespace std;

void display(int, double, char);

int main()
{
	int age = 45;
	double income = 45000;
	char initial = 'C';

	display(age, income, initial);

	return 0;
}

void display(int arg1, double arg2, char arg3)
{
	cout << "Here are the values: "
	     << arg1 << " " << arg2 << " " << arg3 << endl;

}
