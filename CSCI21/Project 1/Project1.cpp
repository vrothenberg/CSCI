#include "rang.hpp"
#include "CinReader.h"
#include "Product.h"
#include "Vendor.h"

#include <iostream>
#include <string>

using std::to_string;

using namespace std;

void ClearScreen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
};

int main () {
  bool inUse = true;
  CinReader read;
  string readCharString = "eE";
  Vendor vend;

  vend.AddProduct(Product("Carbonated Sugar", 1.00, 10));
  vend.AddProduct(Product("Nutrient Bar", 2.00, 10));
  vend.AddProduct(Product("Tasty Orbs", 1.50, 15));
  vend.AddProduct(Product("Deltoidos", 1.75, 10));
  vend.AddProduct(Product("Dihydrogen Monoxide", 5.00, 1));

  for (int i = 0; i < vend.GetProducts().size(); i++) {
    int x = i+1;
    char c = x+48;
    readCharString += c;
  }


  while(inUse) {
    ClearScreen();
    printf("%10s\n\n", "Vending Machine");
    printf("Current Balance: $%2.2f \n\n", vend.GetBalance());
    vend.DisplayProducts();
    cout << "\n[E] to Exit\n\n";
    vend.DisplayMessage();
    cout << "\nEnter choice: ";

    char choice = toupper(read.readChar(readCharString));

    if (choice == 'E') {
      // Exit selected, receipt displayed
      ClearScreen();
      vend.DisplayPurchased();
      inUse = false;
    } else {
      // Item selected
      int option = choice - 48;
      vend.Purchase(option);
    }
  }
  return 0;
}
