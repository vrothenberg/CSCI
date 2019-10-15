#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int swaps = 0;


// Complete the insertionSort2 function below.
void insertionSort(vector<int> arr, int n) {
  int i = 1;

  while (i < n) {
    int j = i;
    while (j > 0 && arr[j-1] > arr[j]) {
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = arr[j];
      swaps++;
      j--;
    }
    i++;
  }



}

int main()
{
  ifstream fin("input.txt");
    int n;
    fin >> n;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(fin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort(arr, n);

    cout << swaps;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}