#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char* argv[]) {

  if (argc != 2) {
    cout << "usage: " << argv[0] << " POSSIBLE_PALINDROME" << endl;
  } else {
    string pal(argv[1]);
    stack<char> cs;
    queue<char> cq;

    cout << "Testing " << pal << "..." << endl;

    for (char p : pal) {
      cs.push(p);
      cq.push(p);

    }

    while (!cs.empty()) {
      char a = cs.top();
      char b = cq.front();
      if (a == b){
        cs.pop();
        cq.pop();
      } else {
        break;
      }
    }
    if (cs.empty()) {
      cout << pal << " is a palindrome" << endl;
    } else {
      cout << pal << " is not a palindrome" << endl;
    }
  }

  return 0;
}
