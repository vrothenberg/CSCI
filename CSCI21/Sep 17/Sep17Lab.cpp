// Lab 4 -- C++ (re)fresher, pt 4
//
// Programmer name: Vince Rothenberg
// Date completed: Sep 17 2019

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <string>
using std::ios;
using std::string;
using std::stringstream;

struct Item {
  string name;
  double price;
  unsigned int quantity;
};

// Initialize an Item with values for its fields.
void initItem(Item &i, string name, double price, unsigned int quantity) {
  i.name = name;
  i.price = price;
  i.quantity = quantity;
}

// Compute the total value of an item (price * quantity)
double totalValue(const Item &i) {
  return i.price * i.quantity;

}

// Reduce the quantity of an Item.
// If amount > Item.quantity, set Item.quantity to 0.
void reduceQuantity(Item &i, unsigned int amount) {
  if (amount > i.quantity) {
    i.quantity = 0;
  } else {
    i.quantity -= amount;
  }

}

// Increase the quantity of an Item.
void increaseQuantity(Item &i, unsigned int amount) {
  i.quantity += amount;
}

// Example: "Apples (price: $0.99, quantity: 3)"
// Use the "magic formula" to format the price.
string toString(const Item &i) {
  stringstream strout;
  strout.setf(ios::fixed);
  strout.setf(ios::showpoint);
  strout.precision(2);
  strout << i.name << " (price: $" << i.price << ", quantity: " << i.quantity << ")";
  return strout.str();
}

/*
 * Unit test.
 */

TEST_CASE("struct and helper functions") {
  Item a;
  initItem(a, "Apples", 0.99, 10);
  CHECK(a.name == "Apples");
  CHECK(a.price == 0.99);
  CHECK(a.quantity == 10);
  CHECK(totalValue(a) == 9.90);
  reduceQuantity(a, 1);
  CHECK(a.quantity == 9);
  reduceQuantity(a, 100);
  CHECK(a.quantity == 0);
  increaseQuantity(a, 5);
  CHECK(a.quantity == 5);
  CHECK(toString(a) == "Apples (price: $0.99, quantity: 5)");

}
