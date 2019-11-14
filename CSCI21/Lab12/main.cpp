#include "slist.hpp"

#include <iostream>
#include <string>
using namespace std;

// Stacks

/*
int main() {
  string expression = "(x+y)";
  SList<char> myList;
  int result = 0;

  for (char c : expression) {
    if (e == '(') {
      myList.pushFront(e);
    } else if (e == ')') {
      if (myList.empty()) {
        result = 1;
        break;
      } else {
        myList.popFront()
      }
    }
  }

  if (!myList.empty()) {
    result = -1;
  }

  if (result == -1) {
    cout << expression << " is LEFT HEAVY\n";
  } else if (result == 1) {
    cout << expression << " is RIGHT HEAVY\n";
  } else if (result == 0) {
    cout << expression << " is BALANCED\n";
  }


  return 0;
}
*/

// Reverse Polish Notation
// ((1+2)*3)/4
// 12+3*4/

int main () {
  string expression = "12+"; // RPN expression
  SList<int> list;

  int x, y, result;

  for (char e : expression) {
    if (isdigit(e)) {
      SList.pushFront(e - 48);
    } else { // + - * /
      y = list.front();
      list.popFront();
      x = list.front();
      list.popFront();

      if (e == '+') {
        result = x + y;
      } else if (e == '-') {
        result = x - y;
      } else if (e == '*') {
        result = x * y;
      } else if (e == '/') {
        result = x / y;
      }

      list.pushFront(result);
    }
  }

  cout << expression << " evaluated = " << list.front() << endl;

  return 0;
}
