//Name: Vince Rothenberg
//August 28 2019
//CSCI 21 Lab 1

#include <iostream>
using namespace std;

int main() {

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  int x = 0;

  cout << "Enter an integer: ";
  cin >> x;
  cout << "Your number: " << x << endl;

  string sentence;
  cout << "Enter a sentence\n";
  cin.ignore(256, '\n');
  getline(cin, sentence);

  cout << "Your sentence : " << sentence << endl;

  bool truth = true;
  char a = 'A';
  int i = 1;
  float pi = 3.14159;
  string s = "a string of chars";

  int result = (i * 2) + (3 / 4.0) - 1;

  cout << "The truth is " << (truth ? "true" : "false") << endl;
  cout << "The char is " << a << endl;
  cout << "Pi is " << pi << endl;
  cout << "Tau is " << (pi * 2) << endl;

  float r = ((pi + 1.0) / 2.718) - 2.0 ;

  cout << "Random float is " << r << endl;
  cout << "The string is " << s << endl;







  return 0;
}
