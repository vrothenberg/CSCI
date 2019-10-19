#pragma once

#include <sstream>
#include <string>
#include <iomanip>
using std::ios;
using std::string;
using std::stringstream;
using std::setw;

// Product class object for each item to be purchased

class Product {
public:
  // Default constructor
  // Initialize a product with default values of name "Nameless", price $0.00, and quantity 0.
  Product();

  // Initialize a product with provided values
  Product(string name, double price, unsigned int quantity);

  // Decreases quantity of product by 1
  void decrement();

  // Increases quantity of product by 1
  void increment();

  // Returns name
  string GetName();

  // Returns quantity
  unsigned int GetQuantity();

  // Sets quantity of product
  void SetQuantity(int i);

  // Returns price
  double GetPrice();

  // Returns string of product using stringtream -- Deprecated
  string toString();

private:
  string name;
  double price;
  unsigned int quantity;
};
