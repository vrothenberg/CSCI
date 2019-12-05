#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::vector;
using std::ostringstream;

void Print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}

bool Parse(vector<int>& v, int i) {
  if (v[i] == 1) {
    // Add
    v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
    return true;
  }
  else if (v[i] == 2) {
    // Multiply
    v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
    return true;
  } else if (v[i] == 3) {
    // Halt
    return false;

  }
  return false;
}

void IntcodeLoop(vector<int>& v) {
  int i = 0;
  while(Parse(v, i)) {
    i += 4;
  }

}




int main() {
  cout << "Advent of Code \n[Day 2]\n\n";

  std::ifstream fin("input.txt");
  string line, token, op;

  vector<int> intcode;

  if (fin.is_open()) {
    string delim = ",";
    // Primary file input loop
    while(getline(fin,line)) {

      int pos = line.find(delim);
      do {
        pos = line.find(delim);
        op = line.substr(0,pos);
        intcode.push_back(stoi(op));
        line = line.substr(pos+delim.size());

      } while (pos!=-1);
    }
    fin.close();
  }
  intcode[1] = 12;
  intcode[2] = 2;
  IntcodeLoop(intcode);

  cout << "Intcode: " << endl;
  Print(intcode);


  return 0;
}
