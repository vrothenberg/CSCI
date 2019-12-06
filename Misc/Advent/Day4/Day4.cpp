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
  bool adjacent = false;
  for (int i = 0; i < pwLen -1; i++) {
    if (digits[i] == digits[i+1]) {
      adjacent = true;
      if (digits[i+1] == digits[i+2]) return false;
    }

  }
  return adjacent;
}


int main() {
  cout << "Advent of Code \n[Day 4]\n\n";

  int start = 138307;
  int end =   654504;

  int validPasswords = 0;
  for (int pw = start; pw <= end; pw++) {
    // Iterate through possible passwords
    vector<int> digits = ToArray(pw);
    if (Increasing(digits) && Adjacent(digits)) {
      cout << pw << endl;
      validPasswords++;
    }
  }
  cout << "Valid Passwords: " << validPasswords << endl;
  return 0;
}
