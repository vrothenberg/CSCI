#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main () {
  /*
  string one = "Hello !";
  one.insert(6, "World");
  cout << one << endl;
  //one.erase(5, 6);
  one.replace(6, 5, "Nameless");
  cout << one << endl;
  int pos = one.find("nameless");
  if(pos == -1) cout << "Not found." << endl;
  int location = one.find_first_of("aeiou");
  cout << "First vowel location " << location << endl;
  int nlocation = one.find_first_not_of("elH");
  cout << "First not of " << nlocation << endl;
  */

  string str = "HELLO";
  cout << str.substr(0,8) << endl;

  str.insert(2, "LLL");
  cout << str << endl;

  //str.replace(0, 3, "_\n__");
  cout << str << endl;

  cout << str.find("EL") << endl;
  cout << str.find("el") << endl;

  if(str.find("VINCE") != string::npos) cout << "FOUND IT!\n";
  else cout << "FAIL!\n";




  return 0;
}
