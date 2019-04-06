/*
 * Name        : test_distance.cpp
 * Author      : Luke Sathrum
 * Description : This program will test all the interface functions
 *               to make sure your lab will compile. Your output should
 *               match my output. Note due to significant digits on
 *               conversion your numbers may be slightly different.
 *               If your class does not compile with this program then
 *               it will not compile when you turn it in.
 */

#include <iostream>
#include "distance.h"
using std::cout;
using std::endl;

// Program starts here
int main() {
  // Test the Constructor
  Distance one, two(10), three(5, 'A'), four(-10), five(-5, 'C');
  cout << "**** TESTING CONSTRUCTORS ****\n";
  cout << "------------- Distance object ---------------\n";
  cout << "yours   : " << one.meters() << endl;
  cout << "actual  : " << 0 << endl;
  cout << "------------- Distance object(10) ---------------\n";
  cout << "yours   : " << two.meters() << endl;
  cout << "actual  : " << 10 << endl;
  cout << "------------- Distance object(-10) ---------------\n";
  cout << "yours   : " << four.meters() << endl;
  cout << "actual  : " << 0 << endl;
  cout << "------------- Distance object(5, 'A') ---------------\n";
  cout << "yours   : " << three.meters() << endl;
  cout << "actual  : " << 9.144 << endl;
  cout << "------------- Distance object(-5, 'C') ---------------\n";
  cout << "yours   : " << five.meters() << endl;
  cout << "actual  : " << 0 << endl;
  cout << "** END TESTING CONSTRUCTORS **\n\n";

  // Test the Mutator
  one.set_meters(13);
  cout << "**** TESTING Mutator ****\n";
  cout << "your meters(13)  : " << one.meters() << endl;
  cout << "actual           : " << 13 << endl;
  one.set_meters(-13);
  cout << "your meters(-13) : " << one.meters() << endl;
  cout << "actual           : " << 0 << endl;
  cout << "** END TESTING Mutator **\n\n";

  // Test GetDistance
  one.set_meters(10);
  cout << "**** TESTING GetDistance() ****\n";
  cout << "------  10 in Kilometers ------\n";
  cout << "yours   : " << one.GetDistance('K') << endl;
  cout << "actual  : " << 0.01 << endl;
  cout << "------  10 in Centimeters ------\n";
  cout << "yours   : " << one.GetDistance('C') << endl;
  cout << "actual  : " << 1000 << endl;
  cout << "------  10 in Miles ------\n";
  cout << "yours   : " << one.GetDistance('M') << endl;
  cout << "actual  : " << 0.00621371 << endl;
  cout << "------  10 in Feet ------\n";
  cout << "yours   : " << one.GetDistance('F') << endl;
  cout << "actual  : " << 32.8084 << endl;
  cout << "------  10 in Inches ------\n";
  cout << "yours   : " << one.GetDistance('I') << endl;
  cout << "actual  : " << 393.701 << endl;
  cout << "------  10 in Fathom ------\n";
  cout << "yours   : " << one.GetDistance('A') << endl;
  cout << "actual  : " << 5.46807 << endl;
  cout << "** END TESTING GetDistance() **\n\n";

  // Test SetDistance
  cout << "**** TESTING SetDistance() ****\n";
  cout << "---- Kilometers -> Meters ----\n";
  one.SetDistance(10, 'K');
  cout << "yours   : " << one.meters() << endl;
  cout << "actual  : " << 10000 << endl;
  cout << "---- Centimeters -> Meters ----\n";
  one.SetDistance(10, 'C');
  cout << "yours   : " << one.meters() << endl;
  cout << "actual  : " << 0.1 << endl;
  cout << "---- Miles -> Meters ----\n";
  one.SetDistance(10, 'M');
  cout << "yours   : " << one.meters() << endl;
  cout << "actual  : " << 16093.4 << endl;
  cout << "---- Feet -> Meters ----\n";
  one.SetDistance(10, 'F');
  cout << "yours   : " << one.meters() << endl;
  cout << "actual  : " << 3.048 << endl;
  cout << "---- Inches -> Meters ----\n";
  one.SetDistance(10, 'I');
  cout << "yours   : " << one.meters() << endl;
  cout << "actual  : " << 0.254 << endl;
  cout << "---- Fathom -> Meters ----\n";
  one.SetDistance(10, 'A');
  cout << "yours   : " << one.meters() << endl;
  cout << "actual  : " << 18.288 << endl;
  cout << "** END TESTING SetDistance() **\n\n";

  // Test Output
  one.set_meters(100);
  cout << "**** TESTING Output() ****\n";
  cout << "------  100 in Meters ------\n";
  cout << "yours   : ";
  one.Output();
  cout << endl;
  cout << "actual  : " << "100.00 Meters" << endl;
  cout << "------  100 in Kilometers ------\n";
  cout << "yours   : ";
  one.Output('K');
  cout << endl;
  cout << "actual  : " << "0.10 Kilometers" << endl;
  cout << "------  100 in Centimeters ------\n";
  cout << "yours   : ";
  one.Output('C');
  cout << endl;
  cout << "actual  : " << "10000.00 Centimeters" << endl;
  cout << "------  100 in Miles ------\n";
  cout << "yours   : ";
  one.Output('M');
  cout << endl;
  cout << "actual  : " << "0.06 Miles" << endl;
  cout << "------  100 in Feet ------\n";
  cout << "yours   : ";
  one.Output('F');
  cout << endl;
  cout << "actual  : " << "328.08 Feet" << endl;
  cout << "------  100 in Inches ------\n";
  cout << "yours   : ";
  one.Output('I');
  cout << endl;
  cout << "actual  : " << "3937.01 Inches" << endl;
  cout << "------  100 in Fathom ------\n";
  cout << "yours   : ";
  one.Output('A');
  cout << endl;
  cout << "actual  : " << "54.68 Fathoms" << endl;
  cout << "------  100 in ????? ------\n";
  cout << "yours   : ";
  one.Output('?');
  cout << endl;
  cout << "actual  : " << "Invalid Unit" << endl;
  cout << "** END TESTING Output() **\n";

  // This ends our program
  return 0;
}
