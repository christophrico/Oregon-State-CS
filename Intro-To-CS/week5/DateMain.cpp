//DatemMin.cpp

#include <iostream>
#include "Date.hpp"

using namespace std;

int main()
{

	Date myBirthday(23, 11, 1989);

	int yourBdayYear, yourBdayMonth, yourBdayDay;

	cout << "Enter your bitrhday year " << endl;
	cin >> yourBdayYear;
	cout << "\n Enter your birthday month as a number " << endl;
	cin >> yourBdayMonth;
	cout << "\n Enter your birthday date " << endl;
	cin >> yourBdayDay;

	Date yourBirthday(yourBdayDay, yourBdayMonth, yourBdayYear);

	cout << "My birthday is "; 
	myBirthday.getShortDate();
	cout << endl;
	cout << "Which can also be written as ";
	myBirthday.getUSLongDate();
	cout << "or ";
	myBirthday.getEULongDate();
	cout << endl;

	cout << "Your birthday is ";
	yourBirthday.getShortDate();
	cout << endl;
	cout << "Which can also be written as ";
	yourBirthday.getUSLongDate();
	cout << "or ";
	yourBirthday.getEULongDate();
	cout << endl;

	return 0;
}
