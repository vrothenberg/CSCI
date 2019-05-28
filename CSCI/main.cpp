#include <iostream>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;

int saveThePrisoner(int n, int m, int s) {

  return s + ((m % n) - 1);


}

int main(){
  /*
  cout.setf(std::ios::showpoint|std::ios::fixed);
  cout.precision(10);

  long double const kPI = 3.1415926535;
  cout << kPI;

  cout << "Hullo";
  */
  cout << saveThePrisoner(999999999, 29010, 1);

  return 0;
}
