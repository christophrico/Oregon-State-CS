// date.cpp

#include "Date.hpp"
using std::string;
using std::cout;
using std::endl;

//user-defined parameter constructor
Date::Date(int d, int m, int y)
{
	if(checkDate(d, m))
		day = d;
	else 
		day = 1;

	if(checkMonth(m))
		month = m;
	else 
 		month = 1;
 	
 	if(y > 0) 
 		year = y;
 	else
 		year = 2001;
}

//checks to see if an integer date, month pair is valid
bool Date::checkDate(int dToCheck, int mToCheck)
{
	if(mToCheck == 1 && dToCheck > 31)
		return false;
	if(mToCheck == 2 && dToCheck > 29)
		return false;
	if(mToCheck == 3 && dToCheck > 31)
		return false;
	if(mToCheck == 4 && dToCheck > 30)
		return false;
	if(mToCheck == 5 && dToCheck > 31)
		return false;
	if(mToCheck == 6 && dToCheck > 30)
		return false;
	if(mToCheck == 7 && dToCheck > 31)
		return false;
	if(mToCheck == 8 && dToCheck > 31)
		return false;
	if(mToCheck == 9 && dToCheck > 30)
		return false;
	if(mToCheck == 10 && dToCheck > 31)
		return false;
	if(mToCheck == 11 && dToCheck > 30)
		return false;
	if(mToCheck == 12 && dToCheck > 31)
		return false;
	else
		return true;
}

//checks to see if an integer month is valid
bool Date::checkMonth(int monthCheck)
{
	if(monthCheck > 12)
		return false;
	else
		return true;
}

//converts an integer month to a string month name
string Date::convertMonth(int intMonth)
{
	switch (intMonth)
	{
		case 1: return "January";
			break;
		case 2: return "February";
			break;				
		case 3: return "March";
			break;
		case 4: return "April";
			break;
		case 5: return "May";
			break;
		case 6: return "June";
			break;
		case 7: return "July";
			break;
		case 8: return "August";
			break;
		case 9: return "September";
			break;
		case 10: return "October";
			break;
		case 11: return "November";
			break;
		default: return "December";
			break;
	}
}

//returns a date in integers in format m/d/y
void Date::getShortDate()
{
	cout << month << "/" << day <<  "/" <<  year << endl;

}

//returns a date in format Month D, Y
void Date::getUSLongDate()
{
	cout << convertMonth(month) <<  " " << day <<  ", " << year << endl;

}

//returns a date in format d Month y
void Date::getEULongDate()
{
	cout << day <<  " " << convertMonth(month) << " " << year << endl;
 
}
