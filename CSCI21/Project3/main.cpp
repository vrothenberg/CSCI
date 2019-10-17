#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;

int main() {

  string s = "C";
  string delim = " ";
  int pos;
  string op;
  string blah;

  vector<string> opLine;

  while (pos != -1) {
    cout << s << endl;
    pos = s.find(delim);
    op = s.substr(0,pos);
    opLine.push_back(op);
    cout << "OP: " << op << endl;
    s = s.substr(pos+delim.size());
    /*
    cout << s << ", s.size(): " << s.size() << ", pos: " <<  pos << ", pos + delim: " << pos+delim.size() << endl;
    cout << "PROCEED\n";
    cin >> blah;
    */

  }



  return 0;
}
