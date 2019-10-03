#include "Product.h"

// Default constructor, initializes with default values
Product::Product() {
  this->name = "Nameless";
  this->price = 0.00;
  this->quantity = 0;
}

// Initialize a product with provided values
Product::Product(string name, double price, unsigned int quantity) {
  if (name.length() > 20) {
    this->name = name.substr(0, 20);
  }
  this->name = name;
  if (price < 0.0) {
    price = 0.0;
  }
  this->price = price;
  if (quantity < 0) {
    quantity = 0;
  }
  this->quantity = quantity;
}

// Decreases quantity of product by 1
void Product::decrement() {
  if (quantity > 0) {
    this->quantity--;
  }
}

// Increases quantity of product by 1
void Product::increment() {
  this->quantity++;
}

// Returns product name
string Product::GetName() {
  return this->name;
}

// Returns product quantity
unsigned int Product::GetQuantity() {
  return this->quantity;
}

// Sets product quantity
void Product::SetQuantity(int i) {
  this->quantity = i;
}

// Returns product price
double Product::GetPrice() {
  return this->price;
}
