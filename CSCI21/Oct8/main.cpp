#include <iostream>
#include <string>
#include <array>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::array;
using std::vector;
using std::toupper;

int main () {

  // Containers

  /*

  string s = "hello";

  cout << s[0] << endl;
  cout << s.at(0) << endl;

  int numbers[10];
  array<int,10> betterNumbers;

  cout << numbers[0] << endl;
  cout << betterNumbers[0] << endl;

  // Invalid!   numbers.at(1) = 10;
  cout << betterNumbers.size() << endl;

  vector<double> temps;
  vector<char> letters;
  vector<string> messages;

  temps.push_back(1.92);
  //cout << temps.size() << endl;
  temps[0] = 3.5;
  //cout << temps.at(0) << endl;
  temps.push_back(3.14);
  temps.push_back(7.77);

  for (int i = 0; i < messages.size(); i++) {
    cout << messages[i] << endl;
  }


  for(char c : s) {
    cout << c;
  }
  cout << endl;

  messages.push_back("greetings");
  messages.push_back("something in the vector");
  messages.push_back("OH YA");

  for (string& m : messages) {
    cout << m << endl;
    //m = toupper(m);
  }

  for (auto& c : s) {
    c = toupper(c);
    cout << c;
  }
  cout << endl;

  for (auto c: s) {
    cout << c;
  }
  */

  bool lohi = false;

  int x, y;
  x = 5;
  y = 10;

  cout << if(lohi) !(x > y);



  return 0;
}
