#include <iostream>
#include <string>

using namespace std;

struct Box {
  float weight;
  string contents;
  static int created;
  static int destroyed;

  Box() {
    created++;
    cerr << created << " boxes created" << endl;
  }
  Box(const Box& b) {
    created++;
    cerr << created << " boxes (copy) created\n";}
  ~Box() {
    destroyed++;
    cerr << destroyed << " boxes destroyed" << endl;
  }
};

void printBox(Box b) {
  cout << "Box being printed\n";
}

int Box::created = 0;
int Box::destroyed = 0;

int main() {
  /*
  string* pStr(nullptr); // Uninitialized pointer
  pStr = new string("apple"); // Dynamic
  string str;   // Static
  if (pStr != nullptr) {
    cout << "pStr not a null pointer\n";
  } else {
    cout << "It's totes a null pointer\n";
  }
  cout << pStr->at(0);
  delete pStr;
  pStr = nullptr;

  pStr = new string[10];  // Dynamic array of 10 strings
  delete[] pStr;
  pStr = nullptr;
  */


  Box b1;
  Box* pBox(nullptr);

  printBox(b1);

  pBox = new Box;
  printBox(*pBox);
  delete pBox;
  pBox = nullptr;

  return 0;
}
