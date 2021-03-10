/***********************************************************
** Author: Christopher Rico
** Date: 6/6/17
** Description: Implementation file for Store class.
  Creates virtual store that can have both product objects and
  member objects in inventory and members vectors.
  Users can search the inventory, add items to
  member's carts, and check out member's carts.
************************************************************/

#include "Store.hpp"
#include <iostream>
#include <cctype>

//pushes a pointer to a product object into the store's inventory vector
void Store::addProduct(Product* p)
{
  inventory.push_back (p);
}

//pushes a pointer to a customer object into the store's members vector
void Store::addMember(Customer* c)
{
  members.push_back (c);
}

//allows a pointer to a product to be returned
//by entering a product ID as an argument
Product* Store::getProductFromID(std::string searchProds)
{
  int invNum = inventory.size(); //get size of inventory vector
  int countProd = 0;
  int indexProd = 0;

  //for each item in the inventory
  for (int i = 0; i < invNum; i++)
  {
    //if the the inventory item ID code matches the ID entered
    if ((inventory[i]->getIdCode()) == searchProds)
    {
      indexProd = i; //record the index the item was found at
      countProd++;
    }
  }

  //then if an inventory item was found with a matching ID
  if (countProd != 0)
  //return the pointer to the inventory item that exists at the recorded index
    return inventory[indexProd];
  else
    return NULL;
}

//allows a pointer to a member to be returned
//by entering a member ID as an argument
Customer* Store::getMemberFromID(std::string searchMems)
{
  int memNum = members.size(); //get the size of the members vector
  int countMem = 0;
  int indexMem = 0;

  //for each member in the store
  for (int j = 0; j < memNum; j++)
  {
    //if the member ID code matches the ID entered
    if (members[j]->getAccountID() == searchMems)
    {
      indexMem = j; //record the index the item was found at
      countMem++;
    }
  }

  //then if a member was found with a matching ID
  if (countMem != 0)
    //return the pointer to the member that exists at the recorded index
    return members[indexMem];
  else
    return NULL;
}

//allows searching inventory vector for an inventory item
//by title or description; case-insensitive for first letter of search term
void Store::productSearch(std::string str)
{
  int prodNum = inventory.size(); //get the size of the inventory vector
  std::string strLow = str; //set both strUp and strLow to the input string
  std::string strUp = str;

  strLow[0] = std::tolower(str[0]); //set first letter of strLow to lower case
  strUp[0] = std::toupper(str[0]); //set first letter of strUp to upper case

  //for all items in the inventory
  for (int k = 0; k < prodNum; k++)
  {
    //if strUp, str, or strLow is a sub-string of its title or description
    if (inventory[k]->getDescription().find(str) != std::string::npos ||
        inventory[k]->getTitle().find(str) != std::string::npos ||
        inventory[k]->getDescription().find(strLow) != std::string::npos ||
        inventory[k]->getTitle().find(strLow) != std::string::npos ||
        inventory[k]->getDescription().find(strUp) != std::string::npos ||
        inventory[k]->getTitle().find(strUp) != std::string::npos)
      {
        //print the item ID title, ID code, price, and description
        std::cout << std::endl << std::endl << inventory[k]->getTitle();
        std::cout << std::endl << "ID code: " << inventory[k]->getIdCode();
        std::cout << std::endl << "price: $" << inventory[k]->getPrice();
        std::cout << std::endl << inventory[k]->getDescription();
      }
  }
}

//allows product objects to be added to a specific member's cart
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
  //if member ID doesn't exist, print that the member wasn't found
  if (getMemberFromID(mID) == NULL)
  {
    std::cout << std::endl << "Member #" << mID << " not found.";
  }

  //if product ID doesn't exist, say the product wasn't found
  if (getProductFromID(pID) == NULL)
  {
    std::cout << std::endl << "Product #" << pID << " not found.";
  }

  //if member exists, product exists, and product is in stock
  if (getMemberFromID(mID) != NULL && getProductFromID(pID) != NULL &&
      getProductFromID(pID)->getQuantityAvailable() != 0)
  {
    getMemberFromID(mID)->addProductToCart(pID); //add product to member's cart
  }

  //if the product exists and is just out of stock,
  //print that it's out of stock
  else if (getProductFromID(pID) != NULL &&
           getProductFromID(pID)->getQuantityAvailable() == 0)
  {
    std::cout << std::endl << "Sorry, product #" << pID;
    std::cout << " is currently out of stock.";
  }
}

//allows member to "check out" the items in cart
//sums up item cost and shipping cost, then clears cart
void Store::checkOutMember(std::string mID)
{
  int numCart = 0;
  double subtotal = 0.00,
         shipCost = 0.00,
         total = 0.00;

  //if member ID does not exist, print that it doesn't exist
  if (getMemberFromID(mID) == NULL)
  {
    std::cout << std::endl << "Member #" << mID << " not found.";
  }

  //if member ID exists
  else
  {
    numCart = getMemberFromID(mID)->getCart().size(); //get #of items in cart

    //if the cart is empty, print that there are no items in it
    if (numCart == 0)
    {
      std::cout << std::endl << "There are no items in the cart.";
    }

    //if the member exists and the cart is not empty
    else
    {
      //for all the items in the cart
      for (int g = 0; g < numCart; g++) //for loop begins
      {
        //if the item is out of stock
        if (getProductFromID(getMemberFromID(mID)->
          getCart()[g])->getQuantityAvailable() == 0)
        {
            //print that the id# and title are out of stock
            std::cout << std::endl << "Sorry, product #";
            std::cout << getProductFromID(getMemberFromID(mID)->
                         getCart()[g])->getIdCode();
            std::cout << ", " << "'";
            std::cout << getProductFromID(getMemberFromID(mID)->
                         getCart()[g])->getTitle();
            std::cout <<"', is no longer available.";
        }

          //otherwise for all iems in the cart
        else
        {
          //print the title
          std::cout << std::endl << getProductFromID(getMemberFromID(mID)->
                                    getCart()[g])->getTitle();
          //print the price
          std::cout << " - $" << getProductFromID(getMemberFromID(mID)->
                                 getCart()[g])->getPrice();
          //decrease the item quanitity by one
          getProductFromID(getMemberFromID(mID)->
          getCart()[g])->decreaseQuantity();

          //add the item cost to the cart subtotal
          subtotal += getProductFromID(getMemberFromID(mID)->
                      getCart()[g])->getPrice();
        }
      } //for loop ends

      //if the member is not a premium member, shipping is 7% of the subtotal
      if (!(getMemberFromID(mID)->isPremiumMember()))
        shipCost = (subtotal * .07);

      else
        shipCost = 0;

      //sum up the cart total
      total = shipCost + subtotal;

      //print the cart subtotal, shipping cost, and total to the screen
      std::cout << std::endl << "Subtotal: $" << subtotal;
      std::cout << std::endl << "Shipping Cost: $" << shipCost;
      std::cout << std::endl << "Total: $" << total;

      //clear the member's cart
      getMemberFromID(mID)->emptyCart();
    }
  }
}
