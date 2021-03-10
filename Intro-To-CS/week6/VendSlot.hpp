// VendSlot.hpp

 /************************************************************
** Author: Christopher Rico
** Date:5/9/17
** Description: Week 6 assignment. Header file for VendSlot class.
 The default name for a Snack is "VendSnack"
*************************************************************/

#ifndef VENDSLOT_H
#define VENDSLOT_H

#include "Snack.hpp" 

class VendSlot
{
private:
	Snack VendSnack; //default Snack object
	int snackAmt; //# of snacks on hand

public:
	//default constructor
	VendSlot()
	{
		snackAmt = 5;
	}

	//constructor for user input
	VendSlot(Snack, int);

	//getters
	Snack getSnack(); 
	int getAmount();

	//mutator, reduces snack amount by 1
	void decrementAmount();
};

#endif // VENDSLOT H
