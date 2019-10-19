#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include "Product.h"

using std::vector;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::string;
using std::to_string;

// Vendor class object, handles vending machine functions 

class Vendor {
public:
  // Default construct to initialize vendor class object
  Vendor();

  // Constructor to initialize vendor class object with vector of products
  Vendor(vector<Product> products);

  // Constructor to set all private variables
  Vendor(string modelName, string message, unsigned int serialNumber, double balance, vector<Product> products);

  // Return single product
  Product GetProduct(int i);

  // Return products
  vector<Product> GetProducts();

  // Add a Product class object to the Vendor map
  void AddProduct(Product p);

  // Set vending machine message
  void SetMessage(string message);

  // Display message for next inUse while loop iteration
  void DisplayMessage();

  // Displays current product names, quantities and price
  void DisplayProducts();

  // Adds selected product to purchased vector, decrements from vending machine vector
  void Purchase(int i);

  // Returns current user balance
  double GetBalance();

  // Displays receipt of purchased items with subtotals and final total
  void DisplayPurchased();


private:
  string modelName;
  string message;
  unsigned int serialNumber;
  vector<Product> products;
  double balance;
  vector<Product> purchased;

};
