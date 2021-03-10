#include "Car.hpp"
#include <iostream>

using namespace std;


int main()
{
	Car vroom(1989, "poop");

	vroom.gas();
	cout << vroom.getSpeed() << endl;
	vroom.gas();
	cout << vroom.getSpeed() << endl;
	vroom.gas();
	cout << vroom.getSpeed() << endl;
	vroom.gas();
	cout << vroom.getSpeed() << endl;
	vroom.gas();
	cout << vroom.getSpeed() << endl;

	vroom.brake();
	cout << vroom.getSpeed() << endl;
	vroom.brake();
	cout << vroom.getSpeed() << endl;
	vroom.brake();
	cout << vroom.getSpeed() << endl;
	vroom.brake();
	cout << vroom.getSpeed() << endl;
	vroom.brake();
	cout << vroom.getSpeed() << endl;

	cout <<"The year of this car is " << vroom.getYear() << endl;
	cout <<"And the make is " << vroom.getMake() << endl;

	return 0;
}
