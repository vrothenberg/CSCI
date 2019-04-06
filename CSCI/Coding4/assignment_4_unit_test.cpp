/*
 * Name        : assignment_4_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class DoubleList.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <sstream>
#include <streambuf>
#include "double_list.h"
// To Check for Header Guards
#include "double_list.h"
using std::cout;
using std::endl;
using std::string;


// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
template <typename T>
void Test(bool test, string more_info = "", T yours = T(),
          T expected = T());
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 22;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // START DEBUGGING CODE

  // END DEBUGGING CODE

  // To test your code
  // Comment out UnitTest() if doing your own debugging above
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;

  // Tests
  DoubleList my_list;
  std::stringstream sserr, ssout;
  std::streambuf* old_cerr = std::cerr.rdbuf(sserr.rdbuf());
  string empty = "List Empty";
  string full = "List Full";
  string no_value = "No Item At Location";
  string empty_str;
  int value;

  int int_yours, int_actual;
  double dbl_yours;
  string str_yours, str_actual;

  int_yours = my_list.GetSize();
  int_actual = 0;
  Test(int_yours == int_actual, "Default Constructor & GetSize()", int_yours, int_actual);

  value = my_list.GetItem(0);
  str_yours = sserr.str();
  Test(str_yours == no_value, "GetItem(0) - Error Message", str_yours, no_value);

  int_actual = 0;
  Test(value == int_actual, "GetItem(0)", value, int_actual);
  sserr.str("");

  value = my_list.GetItem(-1);
  str_yours = sserr.str();
  Test(str_yours == no_value, "GetItem(-1) - Error Message", str_yours, no_value);

  int_actual = 0;
  Test(value == int_actual, "GetItem(-1)", value, int_actual);
  sserr.str("");


  my_list.Sum();
  str_yours = sserr.str();
  Test(str_yours == empty, "Sum() - Error Message", str_yours, empty);
  sserr.str("");

  my_list.Average();
  str_yours = sserr.str();
  Test(str_yours == empty, "Average() - Error Message", str_yours, empty);
  sserr.str("");

  my_list.Max();
  str_yours = sserr.str();
  Test(str_yours == empty, "Max() - Error Message", str_yours, empty);
  sserr.str("");

  std::streambuf* old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);
  str_yours = sserr.str();
  Test(str_yours == empty, "Output() - Error Message", str_yours, empty);

  str_yours = ssout.str();
  Test(str_yours == "", "Output()", str_yours, empty_str);
  sserr.str("");
  ssout.str("");

  cout << "\nAdding the values 2.5, 8.8, 5.5, 7.3, 1.1 to the list\n\n";
  my_list.Insert(2.5);
  my_list.Insert(8.8);
  my_list.Insert(5.5);
  my_list.Insert(7.3);
  my_list.Insert(1.1);
  int_yours = my_list.GetSize();
  int_actual = 5;
  Test(int_yours == int_actual, "Insert() & GetSize()", int_yours, int_actual);

  old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);
  str_yours = ssout.str();
  str_actual = "2.5, 8.8, 5.5, 7.3, 1.1";
  Test(str_yours == str_actual, "Output()", str_yours, str_actual);
  ssout.str("");

  dbl_yours = my_list.GetItem(3);
  int_actual = 5.5;
  Test(dbl_yours == 5.5, "GetItem(3)", dbl_yours, 5.5);

  dbl_yours = my_list.Sum();
  Test(dbl_yours >= 25.19 && dbl_yours <= 25.21, "Sum()", dbl_yours, 25.20);

  dbl_yours = my_list.Average();
  Test(dbl_yours >= 5.039 && dbl_yours <= 5.041, "Average()", dbl_yours, 5.040);

  dbl_yours = my_list.Max();
  Test(dbl_yours >= 8.79 && dbl_yours <= 8.81, "Max()", dbl_yours, 8.80);

  cout << "\nClearing the list\n\n";
  my_list.Clear();
  int_yours = my_list.GetSize();
  Test(int_yours == 0, "Clear() & GetSize()", int_yours, 0);

  old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);

  str_yours = sserr.str();
  Test(str_yours == empty, "Output() - Error Message", str_yours, empty);
  str_yours = ssout.str();
  Test(str_yours == "", "Output()", str_yours, empty_str);
  sserr.str("");
  ssout.str("");

  cout << "\nAdding the values 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 to the list"
       << endl << endl;
  my_list.Insert(1);
  my_list.Insert(2);
  my_list.Insert(3);
  my_list.Insert(4);
  my_list.Insert(5);
  my_list.Insert(6);
  my_list.Insert(7);
  my_list.Insert(8);
  my_list.Insert(9);
  my_list.Insert(10);
  my_list.Insert(11);

  str_yours = sserr.str();
  Test(str_yours == full, "Insert() \"One too many\"", str_yours, full);
  int_yours = my_list.GetSize();
  int_actual = 10;
  Test(int_yours == int_actual, "GetSize()", int_yours, int_actual);

  old_cout = std::cout.rdbuf(ssout.rdbuf());
  my_list.Output();
  cout.rdbuf(old_cout);
  str_yours = ssout.str();
  str_actual = "1, 2, 3, 4, 5, 6, 7, 8, 9, 10";
  Test(str_yours == str_actual, "Output()", str_yours, str_actual);
  ssout.str("");

  // Restore cerr
  std::cerr.rdbuf(old_cerr);

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
}

// For testing (DO NOT ALTER)
template <typename T>
void Test(bool test, string more_info, T yours, T expected) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test && yours != T()) {
      cout << "Correct Answer: " << std::boolalpha << '"' << expected << '"'
           << endl;
      cout << "   Your Answer: " << std::boolalpha << '"' << yours << '"'
           << endl << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}
