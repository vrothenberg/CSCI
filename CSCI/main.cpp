#include <iostream>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;

int saveThePrisoner(int n, int m, int s) {

  return s + ((m % n) - 1);


}

int GCD(int i, int j) {
  int k = i % j;
  if (k == 0) return j;
  return GCD(j,k);
}

int Fib(int n)  {
  if (n == 1 || n == 2) {
    return 1;
  }
  return Fib(n-1) + Fib(n-2);
}

int FibSum(int n) {
  if (n == 1) return 1;
  return Fib(n) + FibSum(n-1);
}

int ExpSum(int n) {
  if (n == 1) {
    return 1;
  }
  return pow(2,n-1) + ExpSum(n-1);
}

int ToySales(int n) {
  return 495000*pow(0.9, n-1);
}

int main(){
  /*
  cout.setf(std::ios::showpoint|std::ios::fixed);
  cout.precision(10);

  long double const kPI = 3.1415926535;
  cout << kPI;

  cout << "Hullo";
  */
  //cout << saveThePrisoner(999999999, 29010, 1);

  int totalSales = 0;

  for (int i = 1; i <= 6; i++) {
    totalSales += ToySales(i);
    cout << "Year " << i << ": " << totalSales << endl;
  }

  //cout << ToySales(0);


  return 0;
}
