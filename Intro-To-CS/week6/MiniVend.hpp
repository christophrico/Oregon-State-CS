//MiniVend.hpp

 /************************************************************
** Author: Christopher Rico
** Date:5/9/17
** Description: Week 6 assignment. Header file for MiniVend class.
*************************************************************/

#ifndef MINIVEND_H
#define MINIVEND_H

#include "VendSlot.hpp"

class MiniVend
{
private:
	VendSlot vs0, vs1, vs2, vs3;
	double cashOnHand;

	//checker, just for internal use
	bool checkSlot(int);

public:
	//constructor
	MiniVend(VendSlot, VendSlot, VendSlot, VendSlot, double);

	//getters
	double getMoney();
	int numEmptySlots();
	double valueOfSnacks();

	//mutator
	void buySnack(int);

};

#endif // MINIVEND H
