//Car.cpp

//this is the implementation file for the car class

#include "Car.hpp"

Car:: Car(int yearIn, std::string makeIn)
{
	year = yearIn;
	make = makeIn;
	speed = 5;
}

std::string Car::getMake()
{
	return make;
}

int Car::getYear()
{
	return year;
}

int Car::getSpeed()
{
	return speed;
}

void Car::gas()
{
	speed+=5;
}

void Car::brake()
{
	speed-=5;
}
