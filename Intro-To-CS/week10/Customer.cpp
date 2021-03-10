/***********************************************************
** Author: Christopher Rico
** Date: 6/6/17
** Description: Implementation file for Customer class.
  Creates a customer object with a unique user ID, possibility for
  premium membership, and a cart that can be assigned product objects
************************************************************/

#include "Customer.hpp"

//constructor for user input. Accepts values for
//Name, account ID, and whether or not a customer is
//a premium member
Customer::Customer(std::string n, std::string a, bool pm)
{
  name = n;
  accountID = a;
  premiumMember = pm;
}

std::string Customer::getAccountID()
{
  return accountID;
}

std::vector<std::string> Customer::getCart()
{
  return cart;
}

//pushes a product object into the customer's cart vector
void Customer::addProductToCart(std::string prod)
{
  cart.push_back(prod);
}

bool Customer::isPremiumMember()
{
  return premiumMember;
}

//empties the customer's cart vector
void Customer::emptyCart()
{
  cart.clear();
}
