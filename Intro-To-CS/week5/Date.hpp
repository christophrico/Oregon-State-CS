//Date.hpp

#ifndef DATE_HP
#define DATE_HP

#include <iostream>
using std::string;


class Date
{
private:
	int month, day, year;

	bool checkDate(int, int);
	bool checkMonth(int);
	string convertMonth(int);

public:
	// default constructor
	Date()
	{
		month = 1;
		day = 1;
		year = 2001;
	}

	//constructor for user to set parameters
	Date(int, int, int);

	//getters
	void getShortDate();
	void getUSLongDate();
	void getEULongDate();
};

#endif // DATE H
