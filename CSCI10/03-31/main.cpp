#include <cstdint>
#include <iostream>

using namespace std;



int main () {
  //uint8_t num1 = 0;
  int8_t num1 = -128;

  string junk;
  while(true) {
    cout << int(num1) << endl;
    num1++;

    cout << "press enter to continue";
    getline(cin, junk);
  }


  return 0;
}
