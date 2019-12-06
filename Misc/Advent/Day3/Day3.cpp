#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::vector;
using std::ostringstream;

int Max(int a, int b) {
  if (a >= b) return a;
  return b;
}

bool Path(string wire, vector<vector<char>>& wiremap, int& currX, int& currY) {
  char d = wire[0];
  int n = stoi(wire.substr(1, wire.size()));
  int limit;
  string skip = "+O";

  switch(d) {
    case 'D':
      // Down
      cout << "[Down] ";
      limit = currY + n;
      wiremap.at(currY)[currX] = '+';
      for (currY++; currY < limit; currY++) {
        cout << "X: " << currX << " Y: " << currY << endl;
        if (skip.find(wiremap.at(currY)[currX]) == string::npos) {
          // Don't skip
        } wiremap.at(currY)[currX] = '#';
        else wiremap.at(currY)[currX] = '|';
      }
      break;
    case 'U':
      // Up
      cout << "[Up] ";
      limit = currY - n;
      for (currY; currY > limit; currY--) {
        cout << "X: " << currX << " Y: " << currY << endl;
        if (wiremap.at(currY)[currX] == '+') wiremap.at(currY)[currX] = '#';
        else if(wiremap.at(currY)[currX] == 'O') continue;
        else wiremap.at(currY)[currX] = '|';
      }
      break;
    case 'L':
      // Left
      cout << "[Left] ";
      limit = currX - n;
      for (currX; currX > limit; currX--) {
        cout << "X: " << currX << " Y: " << currY << endl;
        if (wiremap.at(currY)[currX] == '+') wiremap.at(currY)[currX] = '#';
        else if(wiremap.at(currY)[currX] == 'O') continue;
        else wiremap.at(currY)[currX] = '_';
      }
      break;
    case 'R':
      // Right
      cout << "[Right] ";
      limit = currX + n;
      for (currX; currX < limit; currX++) {
        cout << "X: " << currX << " Y: " << currY << endl;
        if (wiremap.at(currY)[currX] == '+') wiremap.at(currY)[currX] = '#';
        else if(wiremap.at(currY)[currX] == 'O') continue;
        else wiremap.at(currY)[currX] = '_';
      }
      break;
    default:
      // Invalid direction
      return false;
  }
  if (wiremap.at(currY).at(currX) != 'X') {
    cout << "END";
    wiremap.at(currY)[currX] = '+';
  }


  return true;
}

int main() {
  cout << "Advent of Code \n[Day 3]\n\n";

  std::ifstream fin("input.txt");
  string line, token, op;

  vector<vector<string>> wires;

  //
  // File input
  //
  if (fin.is_open()) {
    string delim = ",";
    // Primary file input loop
    int i = 0;
    while(getline(fin,line)) {
      wires.push_back(vector<string>);

      int pos = line.find(delim);
      do {
        pos = line.find(delim);
        op = line.substr(0,pos);
        wires[i].push_back(op);
        line = line.substr(pos+delim.size());

      } while (pos!=-1);
      i++;
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

  //
  // Determine map size
  //

  for (int i = 0; i < wires.size(); i++)
  {
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
    //cout << "X: " << currX << " Y: " << currY << endl;

  }

  int width = maxRight + abs(maxLeft) + 3;
  int height = maxUp + abs(maxDown) + 3;
  cout << "Width: " << width << endl;
  cout << "Max Left: " << maxLeft << " Max Right: " << maxRight << endl;
  cout << "Height: " << height << endl;
  cout << "Max Up: " << maxUp << " Max Down: " << maxDown << endl;



  //
  // Build map
  //

  vector<char> v(width, '.');
  vector<vector<char>> wiremap(height, v);
  for (int i = 0; i < height; i++) {
    wiremap.at(i).resize(width);
  }
  int originX = abs(maxLeft) + 1;
  int originY = maxUp + 1;

  cout << "Origin X: " << originX << " Y: " << originY << endl;


  //
  // Path
  //
  currX = originX;
  currY = originY;
  for (int i = 0; i < wires.size(); i++) {
    Path(wires[i], wiremap, currX, currY);
  }
  wiremap.at(originY).at(originX) = 'O';


  //
  // Print to output.txt
  //
  std::ofstream fout("output.txt");
  if (fout.is_open()) {
    for (int i = 0; i < wiremap.size(); i++) {
      for (int j = 0; j < wiremap.at(i).size(); j++) {
        fout << wiremap.at(i).at(j);
      }
      fout << endl;
      //Path(wires[i], wiremap, currX, currY);
    }
  }
  fout.close();

  return 0;
}
