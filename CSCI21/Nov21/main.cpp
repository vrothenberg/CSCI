#include <iostream>
using namespace std;

// POLLUTION!
// Returns the result of x + y.
int(x,y) {
  int result = x + y;

  // Don't do this!
  cout << x << " " << y << " = " << endl;

  return result;
}

int main() {
  int result = add(1,2);
}
