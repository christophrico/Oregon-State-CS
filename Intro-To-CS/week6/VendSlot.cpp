// VendSlot.cpp

 #include "VendSlot.hpp"

 //user-defined parameter constructor
 VendSlot::VendSlot(Snack snackIn, int numOfSnacks)
 {
 	VendSnack = snackIn; 

 	snackAmt = numOfSnacks;
 }

 //getters
 Snack VendSlot::getSnack()
 {
 	return VendSnack;
 }

//returns the number of snacks on hand
int VendSlot::getAmount()
{
	return snackAmt; 
}

//mutator. decrements the number of snacks by one each time it's called.
void VendSlot::decrementAmount()
{
	snackAmt--;
}
