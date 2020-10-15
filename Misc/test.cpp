#include <iostream>
#include <vector>
using namespace std;

static bool result = false;


void subsetSum(vector<int> s, int sum, int ite, int const target_sum ) {
  if (target_sum == sum) {
    result = true;
    return;
  } else {
    for (int i = ite; i < s.size(); i++) {
      subsetSum(s, sum + s[i], i + 1, target_sum);
    }
  }
}


bool group_sum_with_num(int arr[], int sz, int must_have, int target_sum)
{
  if (sz == 0) return false;
  vector<int> myvec;
  bool found = false;
  for (int i = 0; i < sz; i++) {
    if (arr[i] == must_have) found = true;
    else myvec.push_back(arr[i]);
  }
  if (found == false) return false;

  subsetSum(myvec, must_have, 0, target_sum);

  return result;
}

int main () {
  //int array[] = {4,6,7,9,10,-11};
  //cout << group_sum_with_num(array, 6, 6, 12);
  int array[] = {1,2,3,6,5};
  cout << group_sum_with_num(array, 5, 3, 7) << endl;
  return 0;
}
