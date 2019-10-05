#include "functions.h"

// FILE PROCESSING

// Read each line of a file into a vector.
vector<string> readFile(string filename) {
  vector<string> result;
  ifstream fin(filename);
  string line;
  if (fin.is_open()) {
    while(getline(fin, line)) {
      // add to vector
      result.push_back(line);
    }
    fin.close();
  }
  return result;
}

stringStreamMethod(string c) {
  stringstream ss(c);
  string token, color;
  int r, g, b;
  getline(ss, token, '^');
  color = token;
  getline(ss, token, '^');
  r = stoi(token);
  getline(ss, token, '^');
  g = stoi(token);
  getline(ss, token, '^');
  b = stoi(token);
}

stringSubStringMethod(string c) {
  string color, token;
  int r,g,b;
  int pos;
  string delim = "->";
  pos = c.find(delim);
  color = c.substr(0,pos);
  c = c.substr(pos+delim.size());
}


// STRING PROCESSING -- ALL CASE-INSENSITIVE

// Return input with all characters in uppercase.
string toupper(string input) {
  for (int i = 0; i < input.length(); i++) {
    int a = (int)input[i];
    if (a >= 95 && a <= 122) {
      // is lower
      a -= 32;
      char c = a;
      input[i] = c;
    }
  }
  return input;
}

// Return input with all characters in lowercase.
string tolower(string input) {
  for (int i = 0; i < input.length(); i++) {
    int a = (int)input[i];
    if (a >= 65 && a <= 90) {
      // is upper
      a += 32;
      char c = a;
      input[i] = c;
    }
  }
  return input;
}

// Return a count of all digits in the input.
unsigned int digits(string input) {
  int count = 0;
  for (int i = 0; i < input.length(); i++) {
    int a = (int)input[i];
    if (a >= 48 && a <= 57) {
      // is digit
      count++;
    }
  }
  return count;
}

// Return a count of all punctuation characters in the input.
unsigned int punctuation(string input) {
  int count = 0;
  for (int i = 0; i < input.length(); i++) {
    int a = (int)input[i];
    if ((a >= 33 && a <= 46)  || (a >= 58 && a <= 64)) {
      // is punctuation
      // may need more precise conditions for punctuation
      count++;
    }
  }
  return count;
}

// Return a count of all vowels (AEIOU) in the input.
unsigned int vowels(string input) {
  input = toupper(input);
  int count = 0;
  for (int i = 0; i < input.length(); i++) {
    int a = (int)input[i];
    if (a ==  65 || a == 69 || a == 73 || a == 79 || a == 85) {
      // is punctuation
      // may need more precise conditions for punctuation
      count++;
    }
  }
  return count;
}

// VECTOR PROCESSING FUNCTIONS

// Compute total number of characters of all strings in a vector.
unsigned int allCharacters(const vector<string>& v) {
  int totalCount = 0;
  for (int i = 0; i < v.size(); i++) {
    totalCount += v[i].length();
  }
  return totalCount;
}

// Compute total number of digits in all strings in a vector.
unsigned int allDigits(const vector<string>& v) {
  int totalCount = 0;
  for (int i = 0; i < v.size(); i++) {
    totalCount += digits(v[i]);
  }
  return totalCount;
}

// Compute total number of punctuation characters in all strings
// in a vector.
unsigned int allPunctuation(const vector<string>& v) {
  int totalCount = 0;
  for (int i = 0; i < v.size(); i++) {
    totalCount += punctuation(v[i]);
  }
  return totalCount;
}

// Compute total number of vowels in all strings in a vector.
unsigned int allVowels(const vector<string>& v) {
  int totalCount = 0;
  for (int i = 0; i < v.size(); i++) {
    totalCount += vowels(v[i]);
  }
  return totalCount;
}
