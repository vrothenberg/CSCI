#include <iostream>
using namespace std;

/*
Sandwich Program

bool whiteBread
bool withMayo
bool withMustard
bool withLettuce
bool withTomato
bool ham
bool turkey
bool wholeWheat


Map each bool to a single bit in a byte
xxxx_xxxx
*/

#define BREAD_WHITE 0x01
#define BREAD_WHEAT 0x02
#define MEAT_HAM    0x04
#define MEAT_TURKEY 0x08
#define LETTUCE     0x10
#define TOMATO      0x20
#define MAYO        0x40
#define MUSTARD     0x80

// Compile time constants, don't use RAM

void printSandwich(int sandwich) {
  cout << "Sandwich with ->";
  if (sandwich & BREAD_WHITE) {
    cout << " white bread";
  }
  if (sandwich & BREAD_WHEAT) {
    cout << " wheat bread";
  }
  if (sandwich & MEAT_HAM) {
    cout << " ham";
  }
  if (sandwich & MEAT_TURKEY) {
    cout << " turkey";
  }
  if (sandwich & LETTUCE) {
    cout << " lettuce";
  }
  if (sandwich & TOMATO) {
    cout << " tomato";
  }
  if (sandwich & MAYO) {
    cout << " mayo";
  }
  if (sandwich & MUSTARD) {
    cout << " mustard";
  }
  cout << endl;

}

int main () {
  int mySandwich(0);

  mySandwich = mySandwich | BREAD_WHITE;
  mySandwich = mySandwich | MUSTARD;
  mySandwich = mySandwich | MEAT_HAM;
  cout << "hex: " << std::hex << mySandwich << endl;
  printSandwich(mySandwich);

  int yourSandwich(0);
  yourSandwich = yourSandwich | BREAD_WHEAT | MEAT_HAM | MEAT_TURKEY;
  yourSandwich |= MAYO | LETTUCE | TOMATO;
  printSandwich(yourSandwich);

  int bizarroSandwich = ~yourSandwich;
  printSandwich(bizarroSandwich);

  int nothingSandwich = yourSandwich ^ yourSandwich;
  printSandwich(nothingSandwich);

  int leftySandwich = yourSandwich << 2;
  printSandwich(leftySandwich);

  int rightySandwich = yourSandwich >> 4;
  printSandwich(rightySandwich);




  return 0;
}
