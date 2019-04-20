#include <iostream>
using namespace std;

void DoStuff(int par_by_value, int &par_by_ref);

void ZeroBoth(int &input1, int &input2);

void SwapValues(int &var1, int &var2);

int main() {
  int var1, var2;
  var1 = 1, var2 = 2;

  cout << "var1 = " << var1 << endl;
  cout << "var2 = " << var2 << endl;
  SwapValues(var1, var2);
  cout << "var1 = " << var1 << endl;
  cout << "var2 = " << var2 << endl;



  return 0;
}

void DoStuff(int par_by_value, int &par_by_ref) {
  par_by_value = 111;
  cout << "par_by_value = "<< par_by_value << endl;
  par_by_ref = 222;
  cout << "par_by_ref = " << par_by_ref << endl;

}

void SwapValues(int &var1, int &var2) {
  int temp = var1;
  var1 = var2;
  var2 = temp;
}
