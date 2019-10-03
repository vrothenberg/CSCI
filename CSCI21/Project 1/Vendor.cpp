#include "Vendor.h"
#include "Product.h"

// Default construct to initialize vendor class object
Vendor::Vendor() {
  this->modelName = "VenCo 9001";
  this->message = "Exchange currency for products.\nCONSUME. CONSUME. CONSUME.";
  this->serialNumber = 1337;
  this->balance = 10.00;
}

// Constructor to initialize vendor class object with vector of products
Vendor::Vendor(vector<Product> products) {
  for (int i = 0; i < products.size(); i++) {
    this->AddProduct(products[i]);
  }
}

// Constructor to set all private variables
Vendor::Vendor(string modelName, string message, unsigned int serialNumber, double balance, vector<Product> products) {
  this->modelName = modelName;
  this->message = message;
  this->serialNumber = serialNumber;
  this->balance = balance;
  this->products = products;
}

// Return single product
Product Vendor::GetProduct(int i) {
  return this->products[i];
}

// Return products
vector<Product> Vendor::GetProducts() {
  return this->products;
}

// Add a Product class object to the Vendor map
void Vendor::AddProduct(Product p) {
  this->products.push_back(p);
}

// Set vending machine message
void Vendor::SetMessage(string message) {
  this->message = message;
}

// Display message for next inUse while loop iteration
void Vendor::DisplayMessage() {
  cout << this->message << endl;
}

// Displays current product names, quantities and price
void Vendor::DisplayProducts() {
  printf("%s %-15s %10s %10s \n\n", "Option", "Item", "Price", "Quantity");
  for (int i = 0; i < this->products.size(); i++) {
    printf("[%d]    %-20s $%2.2f %10d \n", i+1, products[i].GetName().c_str(), products[i].GetPrice(), products[i].GetQuantity());
  }
}

// Returns current user balance
double Vendor::GetBalance() {
  return this->balance;
}

// Adds selected product to purchased vector, decrements from vending machine vector
void Vendor::Purchase(int option) {
  int i = option - 1;
  if (i >= 0 && i < products.size()) {
    Product p = this->GetProduct(i);
    if (p.GetQuantity() > 0 ) {
      if (this->balance - p.GetPrice() >= 0) {
        // Purchase
        this->balance -= p.GetPrice();

        // Check if product in purchased
        bool pushed = false;
        for (int i = 0; i < purchased.size(); i++) {
          if (purchased[i].GetName() == p.GetName()) {
            // Add to existing purchased vector
            pushed = true;
            purchased[i].increment();
          }
        }
        // Product not yet purchased
        if (pushed == false) {
          Product p1 = Product(p.GetName(), p.GetPrice(), 1);
          purchased.push_back(p1);
        }

        products[i].decrement();
        stringstream strout;
        strout.setf(ios::fixed);
        strout.setf(ios::showpoint);
        strout.precision(2);
        strout << "You purchased " << p.GetName() << " for $" << p.GetPrice();
        this->SetMessage(strout.str());
      } else {
        SetMessage("Insufficient funds.\n");
      }
    } else {
      SetMessage("Out of Stock.\n");
    }
  } else {
    // Invalid - shouldn't ever be here
    SetMessage("ERROR!  Invalid option\n");
  }
}

// Displays receipt of purchased items with subtotals and final total
void Vendor::DisplayPurchased() {
  double total = 0.0;
  cout << "Receipt\n\n";
  cout << setw(20) << left << "Item" << setw(10) << " Price" << setw(10) << "Quantity"
       << setw(10) << "Subtotal\n\n";
  for (int i = 0; i < this->purchased.size(); i++) {

    double subtotal = purchased[i].GetQuantity() * purchased[i].GetPrice();
    total += subtotal;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << setw(20) << left << purchased[i].GetName() <<  " $" << setw(8) << purchased[i].GetPrice()
         << setw(10) << purchased[i].GetQuantity()
         << "$" << setw(10) << subtotal << endl;
  }

  cout << "\nTotal" << setw(36) << right << "$" << total << endl;
}
