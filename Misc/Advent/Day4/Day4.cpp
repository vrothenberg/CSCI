#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::vector;
using std::ostringstream;

const int pwLen = 6;

int Max(int a, int b) {
  if (a >= b) return a;
  return b;
}

vector<int> ToArray(int n) {
  vector<int> result(pwLen);
  for(int i = 0; i < pwLen; i++) {
    result[pwLen-i-1] = (n % 10);
    n /= 10;
  }
  return result;
}

// Increasing digits
bool Increasing(vector<int> digits) {
  bool valid = true;
  for (int i = 0; i < pwLen - 1; i++) {
    if (digits[i+1] < digits[i]) {
      // Invalid
      valid = false;
      break;
    }
  }
  return valid;
}

bool Adjacent(vector<int> digits) {
  for (int i = 0; i < pwLen -1; i++) {
    int j = i+1;
    if (digits[i] == digits[j]) {
      int numAdjacent = 2;
      j++;
      while(digits[i] == digits[j]) {
        numAdjacent++;
        j++;
      }
      if (numAdjacent == 2) return true;
      else i = j-1;
    }
  }
  return false;
}


int main() {
  cout << "Advent of Code \n[Day 4]\n\n";

  int start = 138307;
  int end =   654504;

  //int start = 577888;
  //int end = 577888;

  int validPasswords = 0;
  for (int pw = start; pw <= end; pw++) {
    // Iterate through possible passwords
    vector<int> digits = ToArray(pw);
    if (Increasing(digits) && Adjacent(digits)) {
      validPasswords++;
      cout << pw << " " << validPasswords << endl;

    }
  }
  cout << "Valid Passwords: " << validPasswords << endl;
  return 0;
}
