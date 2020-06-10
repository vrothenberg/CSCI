#include <iostream>

using namespace std;

int count_paths(int rows, int cols) {
  int marr[rows][cols];

  cout << "Initialization" << endl;
  for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
          marr[j][i] = 0;
          cout << "(x,y): (" << i << "," << j << ") = " << marr[j][i] << endl;
      }
  }
  marr[rows-1][cols-1] = 1;

  cout << "Propagating" << endl;

  for (int y = rows - 1; y >= 0; y--) {
      for (int x = cols - 1; x >= 0; x--) {
          cout << "(x,y): (" << x << "," << y << ")" << endl;

          // Down
          int down = 0;
          if (y + 1 < rows) {
              down = marr[y+1][x];
              cout << "y+1 < rows : " << down << endl;
          }

          // Right
          int right = 0;
          if (x + 1 < cols) {
              cout << "x+1 < cols : " << marr[y][x+1] << endl;
              right = marr[y][x+1];
          }

          marr[y][x] += down + right;
      }
  }


  return marr[0][0];
}

int main() {

  cout << count_paths(3,3);


  return 0;
}
