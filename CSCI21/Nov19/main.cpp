#include <iostream>
#include <vector>
using namespace std;

void countdown(int n) {
  if (n == 0) return;
  cout << n << "...";
  countdown(n-1);
}

bool isPrime(int n) {
  for (int i=2; i<=n/2;i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool allPrimes(vector<int> possiblePrimes) {
  if (possiblePrimes.size() == 0) {
    return true;
  }

  cout << "testing -> ";
  for (int i : possiblePrimes) {
    cout << i << " ";
  }
  cout << endl;

  if (!isPrime(possiblePrimes.at(0))) {
    return false;
  }

  return allPrimes(vector<int>(possiblePrimes.begin()+1, possiblePrimes.end()));
}

int main() {
  countdown(10);
  cout << endl << endl;

  vector<int> vPrimes = {1,2,3,5,7,11,13,17,19,23};
  vector<int> vOneIsNotPrimes = {1,2,3,4,5,7,11,13,17,19,23};

  cout << "all primes (should be)? " << boolalpha << allPrimes(vPrimes) << endl;
  cout << "all primes (should NOT be)? " << boolalpha << allPrimes(vOneIsNotPrimes) << endl;
  return 0;
}
