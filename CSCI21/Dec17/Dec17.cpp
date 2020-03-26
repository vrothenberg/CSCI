#include <array>
#include <iostream>
#include <vector>
using namespace std;

unsigned int Hash(string data, unsigned int max) {
  //return data.size();
  unsigned int sum(0);
  for (char c : data) {
    sum += c;
  }
  return sum % max;
}

int main() {
  array<vector<string>, 10> database; // Buckets

  string s1("abc");
  string s2("bac");  // Hash key collision
  string s3("cba");

  database[Hash(s1, database.size())].push_back(s1);
  database[Hash(s2, database.size())].push_back(s2);
  database[Hash(s3, database.size())].push_back(s3);

  cout << "cat hashes to: " << Hash("cat", )
  return 0;
}
