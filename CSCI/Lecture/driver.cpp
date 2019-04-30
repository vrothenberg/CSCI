/*
 * Name        : driver.cpp
 * Author      : Luke Sathrum
 * Description : Testing Multi Class
 */
#include <iostream>
#include "multi.h"
using std::cout;
using std::endl;


// Program Execution Starts Here
int main() {
  // Creating a Multi object of default size (5 x 5)
  Multi five_by_five;

  // Filling it with values
  five_by_five.FillUp();

  // Outputting those values
  five_by_five.Output();

  // Creating a Multi object of a user defined size
  int rows, columns;
  cout << "How many rows? ";
  cin >> rows;
  cout << "How many columns? ";
  cin >> columns;
  Multi dynamic(rows, columns);

  // Filling it with values
  dynamic.FillUp();

  // Outputting those values
  dynamic.Output();

  // This ends program execution
  return 0;
}
