#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;


void Euler(double y, double x, double h, double finalX, int steps) {
  // y' = 4x - 2y
  // y(0) = 2
  // Goal: y(0.5)
  // Step: h = 0.1
  // y0 = 2
  // y1 = y0 + h(4 * x0 - 2 * y0)
  //
  // Solution: y = 2x - 1 + 3e^(-2x)
  double solution = 2 * x - 1 + 3 * exp(-2*x);
  double nextY = y + h * (4*x - 2*y);
  double error = fabs((nextY - solution) / solution) * 100;
  double nextX = x + h;
  //cout << "Step: " << setw(2) << steps  << setw(5) << " Y(" << x << ") = " << setw(3) << nextY << " % Error: " << error << endl;
  printf("Step: %2d Y(%1.2f) = %2.4f Error: %2.2f%% \n", steps, x, nextY, error);
  if (nextX <= finalX ) {
    Euler(nextY, nextX, h, finalX, ++steps);
  }
}

int main() {
  cout << "Step size 0.1\n\n";
  Euler(2, 0, 0.1, 0.5, 1);
  cout << "\nStep size 0.05\n\n";
  Euler(2, 0, 0.05, 0.5, 1);
  cout << "\nStep size 0.001\n\n";
  Euler(2, 0, 0.001, 0.5, 1);


  return 0;
}
