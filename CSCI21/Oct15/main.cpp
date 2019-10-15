#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;



int main () {
  vector<int> v1 = {10,20,30,40,50};

  //vector<int>::iterator i;
  //i = v1.begin();
  //cout << *i;

  for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
    cout << *i << endl;
  }

  for (auto i : v1) {
    cout << i << endl;
  }

  return 0;
}
