#include <iostream>
#include <string>
using namespace std;


void greet() {
  cout << "Hello world.\n";
}

void greet(string msg) {
  cout << msg << endl;
}

int getOne() {
  return 1;
}

int addOne(int x) {
  return x + 1;
}

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

int multiply(int n, int i) {
  if (i <= 0) return 0;
  return n + multiply (n, i - 1);
}

// 1, 1, 2, 3, 5, 8, 13
int fibonacci(int n) {
  if (n < 2) {
    return n;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n-1);
}
/*
void binToDec(int binary, int i) {
  int decimal = 0;
  if (binary > 0) {
    i++;
    decimal = decimal + binary%2*(2**(i-1))+binToDec(binary/10, i);
  }
  else {
    decimal = decimal + binary%2;
  }
}

*/

int main() {
  /*
  greet();
  greet("The string is king.\n");
  greet("The number is " + to_string(addOne(getOne())));
  int x = 4, y = 8;
  cout << "x: " << x << " y: " << y << endl;
  swap(x,y);
  cout << "x: " << x << " y: " << y << endl;
  */
  cout << "fibonacci : " << fibonacci(3);




  return 0;
}
