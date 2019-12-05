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


int Fuel(int mass) {
  int f = (mass / 3) - 2;
  if (f <= 0) return 0;
  return f + Fuel(f);
}

int main() {
  cout << "Advent of Code \n[Day 1]\n\n";
  int totalFuel = 0;



  std::ifstream fin("input.txt");
  string line, token, op;

  if (fin.is_open()) {
    string delim = " ";
    // Primary file input loop
    while(getline(fin,line)) {
      totalFuel += Fuel(stoi(line));
    }
    fin.close();
  }
  cout << "Fuel: " << totalFuel << endl;







  return 0;
}
