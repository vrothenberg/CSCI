#include <iostream>

using namespace std;

int main() {
  /*

  string *students;
  int size;

  cout << "How many students?";
  cin >> size;

  students = new string[size];

  for (int i = 0; i < size; i++) {
    cout << "Enter the name of student # " << i + 1 << " : ";
    cin >> students[i];
  }

  for (int i = 0; i < size-1; i++) {
    cout << students[i] << ", ";
  }
  cout << students[size-1];


  const int kArraySize = 10;
  int a[kArraySize];
  int *p = a;
  int i;
  for (i = 0; i < kArraySize; i++) {
  a[i] = i;
  }
  for (i = 0; i < kArraySize; i++) {
  cout << p[i] << " ";
  }
  */

  int *dynArray;
  int size;

  cout << "Enter size of dynamic array:";
  cin >> size;

  dynArray = new int[size];


  return 0;
}
