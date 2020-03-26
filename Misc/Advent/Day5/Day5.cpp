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

bool ParsePosition(vector<int>& v, int i) {
  if (v[i] == 1) {
    // Add
    v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
    return true;
  }
  else if (v[i] == 2) {
    // Multiply
    v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
    return true;
  }
  else if (v[i] == 3) {
    // Saves input to position

  }

  else if (v[i] == 99) {
    // Halt
    return false;

  }
  return false;
}

bool ParseImmediate(vector<int>& v, int i) {
  if (v[i] == 1) {
    // Add
    v[i+3] = v[i+1] + v[i+2];
    return true;
  }
  else if (v[i] == 2) {
    // Multiply
    v[i+3] = v[i+1] * v[i+2];
    return true;
  } else if (v[i] == 99) {
    // Halt
    return false;

  }
  return false;
}

void ParseInstruction(int i) {
  // ABCDE
  // 01002
  // DE = 2 digit Opcode
  // C = Mode of 1st parameter
  // B = Mode of 2nd parameter
  // A = Mode of 3rd parameter

  int opCode = i % 100;
  i /= 100;
  int p1Mode = i % 10;
  i /= 10;
  int p2Mode = i % 10;
  i /= 10;
  int p3Mode = i;

  cout << "opcode: " << opCode << " p1mode: " << p1Mode << " p2mode: " << p2Mode << " p3mode: " << p3Mode << endl;

  switch(opCode) {
    case 1:
      // Addition
      break;
    case 2:
      // Multiplication
      break;
    case 3:
      // Save to position of only parameter value
      break;
    case 4:
      //
  }
}

bool Multiply(vector<int>& v, int i) {
  v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
  return true;
}

void IntcodeLoop(vector<int>& v) {
  int i = 0;
  //while(Parse(v, i)) i += 4;
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

  ParseInstruction(intcode[0]);



  cout << "\nEND" << endl;


  return 0;
}
