#include <iostream>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;

int main(){
  cout.setf(std::ios::showpoint|std::ios::fixed);
  cout.precision(10);

  long double const kPI = 3.1415926535;
  cout << kPI;

  cout << "Hullo";

  return 0;
}
