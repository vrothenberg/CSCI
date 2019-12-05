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

bool Path(string wire) {
  char d = wire[0];
  int x = stoi(wire.substr(1, wire.size()));
  return true;

}

int main() {
  cout << "Advent of Code \n[Day 3]\n\n";

  std::ifstream fin("input.txt");
  string line, token, op;

  vector<string> wires;

  vector<vector<char>> wiremap;


  if (fin.is_open()) {
    string delim = ",";
    // Primary file input loop
    while(getline(fin,line)) {

      int pos = line.find(delim);
      do {
        pos = line.find(delim);
        op = line.substr(0,pos);
        wires.push_back(op);
        line = line.substr(pos+delim.size());

      } while (pos!=-1);
    }
    fin.close();
  }
  int maxRight = 0;
  int maxLeft = 0;
  int maxUp = 0;
  int maxDown = 0;
  int currX = 0;
  int currY = 0;

  char d;
  int x;
  cout << "X: " << 0 << " Y: " << 0 << endl;
  for (int i = 0; i < wires.size(); i++) {
    //Path(wires[i]);
    string wire = wires[i];
    char d = wire[0];
    int n = stoi(wire.substr(1, wire.size()));
    if (d == 'R') {
      // Right
      currX += n;
      if (currX > maxRight) maxRight = currX;
    } else if (d == 'L') {
      // Left
      currX -= n;
      if (currX < maxLeft) maxLeft = currX;
    } else if (d == 'U') {
      // Up
      currY += n;
      if (currX > maxUp) maxUp = currY;
    } else if (d == 'D') {
      // Down
      currY -= n;
      if (currX < maxDown) maxDown = currY;
    }
    cout << "X: " << currX << " Y: " << currY << endl;
  }
  cout << "Width: " << maxLeft + maxRight << endl;
  cout << "Max Left: " << maxLeft << " Max Right: " << maxRight << endl;
  cout << "Height: " << maxUp + maxDown << endl;
  cout << "Max Up: " << maxUp << " Max Down: " << maxDown << endl;


  return 0;
}
