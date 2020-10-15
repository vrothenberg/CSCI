#include <iostream>
#include <vector>
using namespace std;

int count_paths(int rows, int cols) {
  int marr[rows][cols];

  cout << "Initialization" << endl;
  for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
          marr[j][i] = 0;
          cout << "(x,y): (" << i << "," << j << ") = " << marr[j][i] << endl;
      }
  }
  marr[rows-1][cols-1] = 1;

  cout << "Propagating" << endl;

  for (int y = rows - 1; y >= 0; y--) {
      for (int x = cols - 1; x >= 0; x--) {
          cout << "(x,y): (" << x << "," << y << ")" << endl;

          // Down
          int down = 0;
          if (y + 1 < rows) {
              down = marr[y+1][x];
              cout << "y+1 < rows : " << down << endl;
          }

          // Right
          int right = 0;
          if (x + 1 < cols) {
              cout << "x+1 < cols : " << marr[y][x+1] << endl;
              right = marr[y][x+1];
          }

          marr[y][x] += down + right;
      }
  }


  return marr[0][0];
}

int make_change(int coins[], int n, int amount)
{

    cout << "n: " << n << " amount: " << amount << endl;
    if (amount < 0) return 0;

    vector<int> coinRows(n+1);
    coinRows[0] = 0;
    for (int i = 0; i < n; i++) {
      coinRows[i+1] = coins[n-1-i];
    }

    vector<vector<int>> table( n+1 , vector<int> (amount+1, 0));

    // Initialize 0 column subAmount to 1, only 1 way to make change for 0
    for (int i = 0; i <= n; i++) {
        table[i][0] = 1;
    }

    for (int row = 1; row <= n; row++) {
        int coin = coinRows[row];

        for (int subAmount = 1; subAmount <= amount; subAmount++) {
            int prevCombo = table[row-1][subAmount];

            int currCombo = 0;
            if (subAmount - coin >= 0) {
                currCombo = table[row][subAmount - coin];
            }
            table[row][subAmount] = prevCombo + currCombo;

        }
    }


    for (int i = 0; i <= n; i++) {
        cout << coinRows[i] << " : ";

        for (int j = 0; j <= amount; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return table[n][amount];

}


string swap(string s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return s;
}

// Add any helper functions(if needed) above.
vector<string>  get_permutations(string s)
{
    //cout << "get_permutations(" << s << ")" << endl;
    vector<string> result;
    if (s.size() == 0) {
      //cout << "Empty string" << endl;
      return result;
    }


    //cout << "String: " << s << endl;
    for (int i = 0; i < s.size(); i++) {
        string permute = swap(s, 0, i);
        //cout << "Permute[" << i << "]: " << permute << endl;
        string permuteSubstring = permute.substr(1, string::npos);
        vector<string> combos = get_permutations(permuteSubstring);
        if (combos.size() == 0) result.push_back(permute);
        else {
          //cout << "Else: ";
          for (int j = 0; j < combos.size(); j++) {
              string ns = permute[0] + combos[j];
              //cout << ns << " ";
              result.push_back(ns);
          }
          //cout << endl;
        }


    }

    //cout << "Returning: ";
    for (int i = 0; i < result.size(); i++) {
      //cout << result[i] << " ";
    }
    //cout << endl;

    return result;

}


int main() {
  //cout << "Begin" << endl;

  /*


  vector<string> result = get_permutations("abc");

  //cout << "Main" << endl;

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << endl;
  }

  */

  int arr[] = {1,2,3,4,5};
  cout << sizeof(arr)/sizeof(arr[0]);



  return 0;
}
