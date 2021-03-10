 /***********************************************************
** Author: Christopher Rico
** Date: 6/6/17
** Description: Implementation file for Product class.
  creates product object with a title, ID number, description,
  price, and quantity available.
************************************************************/

# include "Product.hpp"

//constructor for user input. Takes a product's ID, its title,
//its description, its price, and how many of it are available
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
  idCode = id;
  title = t;
  description = d;
  price = p;
  quantityAvailable = qa;
}

std::string Product::getIdCode()
{
  return idCode;
}

std::string Product::getTitle()
{
  return title;
}

std::string Product::getDescription()
{
  return description;
}

double Product::getPrice()
{
  return price;
}

int Product::getQuantityAvailable()
{
  return quantityAvailable;
}

//reduces product availablity by one
void Product::decreaseQuantity()
{
  quantityAvailable--;
}
