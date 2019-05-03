/*
 * Name          : Vince Rothenberg
 * Description   : A class to perform string functions
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "CinReader.h"
using std::cout;
using std::endl;
using std::string;

// This class will perform string operations on strings
class StringHelper {
 public:
  // Capitalizes the first character in a string
  string Capitalize(string to_capitalize);
  // Converts a string to UPPERCASE
  string ToUppercase(string to_uppercase);
  // Converts a string to lowercase
  string ToLowercase(string to_lowercase);
  // Counts the number of numeric characters in a string
  int CountNumeric(string to_count);
  // Checks to make sure all characters in a string are alphabetic characters
  // i.e. (A-Z, a-z).
  bool CheckAlphabetic(string to_check);
};

// Program starts here
int main() {
  // Setup our Variables
  int choice;
  string my_string, cont;
  StringHelper helper;
  CinReader reader;
  // Loop and display our menu. Continue to loop until the user chooses '0'
  do {
    cout << "================================================\n";
    cout << "              String Functions Menu             \n";
    cout << "================================================\n";
    cout << " 1) Capitalize\n";
    cout << " 2) Make Uppercase\n";
    cout << " 3) Make Lowercase\n";
    cout << " 4) Count Numeric\n";
    cout << " 5) Check if all characters in a string are alphabetic\n";
    cout << " 0) Exit\n";
    cout << "\nPlease Enter a choice: ";
    // Get the user's choice
    choice = reader.readInt(0, 5);
    switch (choice) {
      case 1:
        cout << "Please enter a string to capitalize: ";
        my_string = reader.readString(false);
        cout << "Your string capitalized is: "
             << helper.Capitalize(my_string) << endl;
        break;
      case 2:
        cout << "Please enter a string to UPPERCASE: ";
        my_string = reader.readString(false);
        cout << "Your string UPPERCASED is: "
             << helper.ToUppercase(my_string) << endl;
        break;
      case 3:
        cout << "Please enter a string to lowercase: ";
        my_string = reader.readString(false);
        cout << "Your string lowercased is: "
             << helper.ToLowercase(my_string) << endl;
        break;
      case 4:
        cout << "Please enter a string to count numeric characters: ";
        my_string = reader.readString(false);
        cout << "There are "
             << helper.CountNumeric(my_string)
             << " numeric characters in the string "
             << my_string << endl;
        break;
      case 5:
        cout << "Please enter a string to check to make sure all characters are alphabetic: ";
        my_string = reader.readString(false);
        cout << "There string "
             << my_string
             << ((helper.CheckAlphabetic(my_string)) ? " contains " : " does not contain ")
             << "only alphabetic characters" << endl;
        break;
    }
    if (choice != 0) {
      cout << "Press Enter to Continue ";
      cont = reader.readString();
      cout << string(50, '\n');
    }
  } while (choice != 0);

  // This ends our program
  return 0;
}

string StringHelper::Capitalize(string to_capitalize) {
  to_capitalize.at(0) = toupper(to_capitalize.at(0));
  return to_capitalize;
}


string StringHelper::ToUppercase(string to_uppercase) {
  for (int i = 0; i < to_uppercase.size(); i++) {
    to_uppercase.at(i) = toupper(to_uppercase.at(i));
  }
  return to_uppercase;

}
// Converts a string to lowercase
string StringHelper::ToLowercase(string to_lowercase) {
  for (int i = 0; i < to_lowercase.size(); i++) {
    to_lowercase.at(i) = tolower(to_lowercase.at(i));
  }
  return to_lowercase;
}
// Counts the number of numeric characters in a string
int StringHelper::CountNumeric(string to_count) {
  int count = 0;
  for (int i = 0; i < to_count.size(); i++) {
    if ( isdigit(to_count.at(i)) ) count++;
  }
  return count;
}
// Checks to make sure all characters in a string are alphabetic characters
// i.e. (A-Z, a-z).
bool StringHelper::CheckAlphabetic(string to_check) {
  for (int i = 0; i < to_check.size(); i++) {
    if (!isalpha(to_check.at(i))) return false;
  }
  return true;
}
