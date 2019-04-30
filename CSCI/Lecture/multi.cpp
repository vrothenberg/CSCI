/*
 * Name          : multi.cpp
 * Author        : Vince Rothenberg
 * Description   : Creating a class to hold multidimensional array.
 */

#include "multi.h"

// Member Function Definitions
/*

 * Constructor
 * Creates a dynamic multidimensional array of size rows x columns.
 * @param int rows    - The number of rows, defaults to 5.
 * @param int columns - The number of columns, defaults to be 5.
 */
Multi::Multi(int rows, int columns) {
  if (rows < 1) {
    rows = 5;
  }
  rows_ = rows;
  if (columns < 1) {
    columns = 5;
  }
  columns_ = columns;
  multi_array_ = new int*[rows_];
  for(int i = 0; i < rows_; i++) {
    multi_array_[i] = new int[columns_];
  }

}

/*
 * FillUp()
 * Fills up (via user input) the dynamic multidimensional array.
 * Each input should be preceded by an output statement letting the use know
 * where they are filling up.
 */
void Multi::FillUp() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      cout << "Multidimensional Array Row: " << i + 1 << " Column: " << j + 1 << ": ";
      cin >> multi_array_[i][j];
    }
  }
}

/*
 * Output()
 * Outputs (via console) the contents of the dynamic multidimensional array.
 * Each row should be on its own line and columns should be comma separated.
 * Example:
 * 1, 2, 3, 4, 5
 * 2, 3, 4, 5, 6
 * 3, 4, 5, 6, 7
 */
void Multi::Output() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_ - 1; j++) {
      cout << multi_array_[i][j] << ", ";
    }
    cout << multi_array_[i][columns_ - 1] << endl;
  }
}
