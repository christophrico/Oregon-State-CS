//Car.hpp

//this is the implementation file for the car class

#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
	int year, speed;
	std::string make;

public:
	//constructor
	Car(int, std::string);

	//getters
	int getYear();
	int getSpeed();
	std::string getMake();

	//mutators
	void gas();
	void brake();

}; 
#endif  //CAR H
