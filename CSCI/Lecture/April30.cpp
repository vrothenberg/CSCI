#include <iostream>

using namespace std;

class Scores {
public:
  Scores(int size);
  ~Scores();

  void FillUp();

  void Output();

private:
  int size_;
  int *scores_;
};

int deletion() {
  //Create a dynamic variable
  int *p1 = new int;

  //Create another dynamic variable
  int *p2;
  p2 = new int;

  *p1 = 42;
  *p2 = *p1;

  cout << *p1 << " " << *p2 << endl;

  delete p1;
  delete p2;
  p1 = NULL;
  p2 = NULL;

  //Create a dynamic array
  int size;
  cout << "Enter a size: ";
  cin >> size;

  int *a = new int[size];

  for (int i = 0; i < size; i++) {
    a[i] = i * i;
  }

  for (int i = 0; i < size; i++) {
    cout << a[i] << endl;
  }

  //Deallocate array memory
  delete[] a;

  //Create a dynamic multidimensional array
  int **ma;
  ma = new int*[3];
  for (int i = 0; i < 3; i++) {
    ma[i] = new int[2];
  }

  //Do stuff

  //Cleanup
  for (int i = 0; i < 3; i++) {
    delete[] ma[i];
  }
  delete[] ma;

  return 0;
}

int destructor() {

  {
    Scores *obj = new Scores(5)
    ;
    obj->FillUp();
    obj->Output();
    delete obj;
    cout << "Leaving scope.\n";
  }
  cout << "We have left scope.\n";

  return 0;
}

int main() {

  typedef int* IntPtr;
  IntPtr p;

  double *d = new double[10];
  d[0] = 42;
  *(d+1) = 80;


  return 0;
}




Scores::Scores(int size) {
  if (size < 1 ) {
    size = 10;
  }
  size_ = size;
  scores_ = new int[size_];
}

Scores::~Scores() {
  cout << "In the destructor\n";
  delete[] scores_;
}

void Scores::FillUp() {
  for (int i = 0; i < size_; i++) {
    cout << "Enter score #" << i+1  << ": ";
    cin >> scores_[i];
  }

}

void Scores::Output() {

  for (int i = 0; i < size_-1; i++) {
    cout << scores_[i] << ", ";
  }
  cout  << scores_[size_ -1] << endl;

}
