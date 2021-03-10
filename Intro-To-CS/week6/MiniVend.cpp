//MiniVend.cpp

 /************************************************************
** Author: Christopher Rico
** Date:5/9/17
** Description: Week 6 assignment. Implementation file for MiniVend class.
  Takes five arguments: four VendSlot objects, and a double (starting cash amount).
  Has three get functions: getMoney, numEmptySlots, valueOfSnacks
  Has one mutator function: buySnack.
  Has one private member function: checkSlot.
*************************************************************/

#include "MiniVend.hpp"

//user-defined parameter constructor
MiniVend::MiniVend(VendSlot vs0_in, VendSlot vs1_in, VendSlot vs2_in, 
					VendSlot vs3_in, double startCash)
{
	vs0 = vs0_in;
	vs1 = vs1_in;
	vs2 = vs2_in;
	vs3 = vs3_in;

	cashOnHand = startCash;
}

//this function returns the total amount of cash on hand in the machine
double MiniVend::getMoney()
{
	return cashOnHand;
}

//this function returns the number of slots (or vs) that have 0 snacks left
int MiniVend::numEmptySlots()
{
	int emptySlots = 0;

	for (int i=0; i<=3; i++)
	{
		if(!checkSlot(i))
			emptySlots++;
	}
	return emptySlots;
}

//this function returns the total value of snacks in the machine
double MiniVend::valueOfSnacks()
{
	return (vs0.getAmount()*(vs0.getSnack().getPrice()) +  //adds up product of 
			vs1.getAmount()*(vs1.getSnack().getPrice()) +  //# of each snack and its price
			vs2.getAmount()*(vs2.getSnack().getPrice()) +
			vs3.getAmount()*(vs3.getSnack().getPrice()) );
}

//this function decrements the amount of a snack and increases the
//total value by the amount of the snack bought
void MiniVend::buySnack(int slotNum)
{
	if (slotNum == 0 && checkSlot(slotNum)) //if there are not 0 snacks
		{
			cashOnHand += vs0.getSnack().getPrice();  //add the price of one snack 
								            //to cash on hand
			vs0.decrementAmount();			//and subtract one snack from inventory		
		}

	if (slotNum == 1 && checkSlot(slotNum)) //repeat for each slot
		{
			cashOnHand += vs1.getSnack().getPrice();  
			vs1.decrementAmount();					
		}	

	if (slotNum == 2 && checkSlot(slotNum)) //repeat for each slot
		{
			cashOnHand += vs2.getSnack().getPrice();  
			vs2.decrementAmount();					
		}

	if (slotNum == 3 && checkSlot(slotNum)) //repeat for each slot
		{
			cashOnHand += vs3.getSnack().getPrice();  
			vs3.decrementAmount();					
		}
}

//checks to see if slot has 0 snacks left
bool MiniVend::checkSlot(int slotToCheck)
{
	if (slotToCheck == 0 && vs0.getAmount() == 0) //one case for each slot
		return false; //if 0, returns false

	if (slotToCheck == 1 && vs1.getAmount() == 0) //repeat for each slot
		return false;

	if (slotToCheck == 2 && vs2.getAmount() == 0)
		return false;
	
	if (slotToCheck == 3 && vs3.getAmount() == 0)
		return false;

	else 
		return true;	
}
