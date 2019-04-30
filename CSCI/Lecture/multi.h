/*
 * Name          : multi.h
 * Author        :
 * Description   : Creating a class to hold multidimensional array.
 */

// Opening Header Guard
#ifndef MULTI_H
#define MULTI_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*
 * The multi class will create a dynamic multidimensional array
 */
class Multi {
 public:
  /*
   * Constructor
   * Creates a dynamic multidimensional array of size rows x columns.
   * @param int rows    - The number of rows, defaults to 5.
   * @param int columns - The number of columns, defaults to be 5.
   */
  Multi(int rows = 5, int columns = 5);

  /*
   * FillUp()
   * Fills up (via user input) the dynamic multidimensional array.
   * Each input should be preceded by an output statement letting the use know
   * where they are filling up.
   */
  void FillUp();

  /*
   * Output()
   * Outputs (via console) the contents of the dynamic multidimensional array.
   * Each row should be on its own line and columns should be comma separated.
   * Example:
   * 1, 2, 3, 4, 5
   * 2, 3, 4, 5, 6
   * 3, 4, 5, 6, 7
   */
  void Output();

 private:
  int **multi_array_;
  int rows_;
  int columns_;
};

// Closing Header Guard
#endif
