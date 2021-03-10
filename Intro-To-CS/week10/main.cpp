#include "Store.hpp"
#include <iostream>
#include <string>

int main()
{
  std::string searchIn;

  Store chrisMart;

  Customer john("john", "jrico", true);
  Customer nancy("nancy", "nsmith", false);

  Product bottle("2631", "Hydro flask", "30 fl oz vaccuum insulated water bottle", 32.58, 0);
  Product frog("707", "buddha frog", "2 foot tall cement frog in zen position", 190.10, 3);
  Product orange("831", "orange", "Round fruit thing that tastes good.", 1.90, 10);

  chrisMart.addMember(&nancy);
  chrisMart.addMember(&john);

  chrisMart.addProduct(&bottle);
  chrisMart.addProduct(&frog);
  chrisMart.addProduct(&orange);

  std::cout << std::endl << "Welcome to ChrisMart!";
  std::cout << std::endl << "Would you like to search for a product?" << std::endl;

  while (searchIn != "No")
  {
    std::cout << std::endl <<  std::endl << "Please enter your search term, or 'No' to end search." << std::endl;
    std::cin >> searchIn;

    chrisMart.productSearch(searchIn);
  }

  std::cout << std::endl << std::endl << "Let's try to check out a customer who doesn't exist.";
  chrisMart.checkOutMember("boomCup");

  std::cout << std::endl << std::endl << "Now John is adding things to his cart.";
  chrisMart.addProductToMemberCart("72", "jrico");
  chrisMart.addProductToMemberCart("2631", "jrico");
  chrisMart.addProductToMemberCart("707", "jrico");
  chrisMart.addProductToMemberCart("707", "jrico");
  chrisMart.addProductToMemberCart("831", "jrico");

  std::cout << std::endl << std::endl << "Now John is checking out.";
  chrisMart.checkOutMember("jrico");

  std::cout << std::endl << std::endl << "Now we check John's cart to see if cartEmpty worked.";
  chrisMart.checkOutMember("jrico");

  std::cout << std::endl << std::endl << "Now Nancy is adding things to her cart.";
  chrisMart.addProductToMemberCart("2631", "nsmith");
  chrisMart.addProductToMemberCart("707", "nsmith");
  chrisMart.addProductToMemberCart("707", "nsmith");
  chrisMart.addProductToMemberCart("831", "nsmith");

  std::cout << std::endl << std::endl << "Now Nancy is checking out.";
  chrisMart.checkOutMember("nsmith");

  std::cout << std::endl << std::endl << "Now we check Nancy's cart.";
  chrisMart.checkOutMember("nsmith");

  return 0;
}
