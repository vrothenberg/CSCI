#include <iostream>
#include <iomanip>
using namespace std;

class Multi {
public:
// This function will get input from the user to fill up the entire
// multidimensional array. The function should let the user know what
// row and what column position they are inputting into
void FillUp();
// This function will Output the array member variable. Each row
// should output on its own line and columns should be separated by a
// comma and space.
void Output();
private:
int a_[2][3];
int num_of_rows_ = 2;
int num_of_cols_ = 3;
};


int main() {
  /*
  std::streamsize original_precision = cout.precision();
  std::ios::fmtflags original_flags = cout.flags();

  double ten = 10, nine = 9;
  cout.setf(std::ios::showpoint|std::ios::showpos);
  cout.precision(0);

  cout.precision(original_precision);
  cout.flags(original_flags);

  cout << "T minus " << setw(10) << setfill('.') << ten << " seconds and counting...\n";
  cout << "T minus " << setw(10) << setfill('_') << nine << " seconds and counting...\n";

  */



  // Create a Multi Object
  Multi object;
  // Call the FillUp Function
  object.FillUp();
  // Output the Multidimensional Array
  object.Output();




  return 0;
}

void Multi::FillUp() {
  for (int i = 0; i < num_of_rows_; i++) {
    for (int j = 0; j < num_of_cols_; j++) {
      cout << "Row: " << i << " Column: " << j << " Enter value: \n";
      cin >> a_[i][j];
    }
  }

}

void Multi::Output() {
  for (int i = 0; i < num_of_rows_; i++) {
    cout << "Row " << i+1 << " : ";
    for (int j = 0; j < num_of_cols_; j++) {
      cout <<  a_[i][j];
      if (j < num_of_cols_ - 1) {
        cout << ", ";
      }
    }
    cout << endl;
  }
}
