// namespace std have been included for this problem.

#include <vector>
#include <iostream>

using namespace std;

vector< vector<int> > combinationUtil(int arr[], vector<int> data, int start, int end, int index, int r, vector< vector<int> > combinations, int must_have) {


    if (index == r) {
        vector<int> currCombo;
        bool has_must_have = false;
        for (int j = 0; j < r; j++) {
            if (data[j] == must_have) has_must_have = true;
            currCombo.push_back(data[j]);
        }
        if (has_must_have) {
          int sum = 0;
          for (int x = 0; x < currCombo.size(); x++) {
            sum += currCombo[x];
          }
          combinations.push_back(currCombo);
        }

    }

    for (int i = start; i <= end and end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r, combinations, must_have);
    }
    return combinations;
}

// Add any helper functions(if needed) above.
bool group_sum_with_num(int arr[], int sz, int must_have, int target_sum)
{
    if (sz == 0 and target_sum != 0) return false;

    bool found = false;
    for (int i = 0; i < sz; i++) {
        if (arr[i] == must_have) found = true;
    }
    if (not found) return false;


    vector< vector<int> > combinations;
    for (int r = 1; r < sz; r++) {
        vector<int> data(r,0);
        combinations = combinationUtil(arr, data, 0, sz-1, 0, r, combinations, must_have);
        for (int i = 0; i < combinations.size(); i++) {
            vector<int> combo = combinations[i];
            for (auto c: combo) cout << c << " ";
            cout << endl;
            int sum = 0;
            for (int j = 0; j < combo.size(); j++) {
                sum += combo[j];
            }
            if (sum == target_sum) return true;
        }
    }

    return false;

}

int main() {

  int arr[6] = {4,6,7,9,10,-11};

  cout << group_sum_with_num(arr, 6, 6, 12);


  return 0;
}
