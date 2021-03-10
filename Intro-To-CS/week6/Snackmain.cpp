//Snackmain.cpp

#include <iostream>
#include "MiniVend.hpp"

using namespace std;

int main()
{
	string userSnack;
	double userPrice, startVal;
	int userCal, snackNum, userChoice;

	cout << "Please enter the name of your snack: " << endl;
	cin >> userSnack;
	cout << "Enter the price: " << endl;
	cin >> userPrice;
	cout << "Enter the calories: " << endl;
	cin >> userCal;
	cout << "Enter the number in inventory: " << endl;
	cin >> snackNum;
	cout << "Enter the starting value in your machine: " << endl;
	cin >> startVal; 

	Snack snack1(userSnack, userPrice, userCal);
	Snack snack2("beer", 5.50, 180);
	Snack snack3("poop", 1.25, 2);

	VendSlot userSlot0;
	VendSlot userSlot1(snack1, snackNum);
	VendSlot userSlot2(snack2, 0);
	VendSlot userSlot3(snack3, 1);

	MiniVend office(userSlot0, userSlot1, userSlot2, userSlot3, startVal);


	cout << endl;
	cout << "The machine has this much money : " << endl;
	cout << office.getMoney() << endl;
	cout << "and the value of the snacks is: " << endl;
	cout << office.valueOfSnacks() << endl;
	cout << "and this many empty slots: " << endl;
	cout << office.numEmptySlots() << endl;

	cout << "Which snack would you like to buy? " << endl;
	cin >> userChoice;

	office.buySnack(userChoice);
	office.buySnack(1);

	cout << endl;
	cout << "We also bought a " << userSlot1.getSnack().getName() << endl;

	cout << "The machine has this much money : " << endl;
	cout << office.getMoney() << endl;
	cout << "and the value of the snacks is: " << endl;
	cout << office.valueOfSnacks() << endl;
	cout << "and this many empty slots: " << endl;
	cout << office.numEmptySlots() << endl;


	return 0;
}
