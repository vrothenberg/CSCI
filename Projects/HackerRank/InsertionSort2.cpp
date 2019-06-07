#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> insertionSort1(int index, vector<int> arr) {
  int n = arr.size();
  int x = arr[index];
  int i = index - 1;
  bool inserted = false;

  while (i >= 0 && !inserted) {
    //cout << "i:" << i << " ";
    if (arr[i] > x)
      arr[i + 1] = arr[i];
    else if (arr[i] < x) {
      arr[i + 1] = x;
      inserted = true;
    }
    /*
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
    */
    i--;
  }
  if (!inserted) {
    arr[0] = x;
    /*
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
      */
  }
  return arr;
}

// Complete the insertionSort2 function below.
void insertionSort2(int n, vector<int> arr) {

  for (int i = 1; i < n; i++) {

    //Insert in sorted order
    bool inserted = false;
    int j = i - 1;
    int x = arr[i];
    while(!inserted && j >= 0) {
      if (arr[j] > x) {
        arr[j+1] = arr[j];

      } else if (arr[j] < x) {
        arr[j+1] = x;
        inserted = true;

      }

      j--;
    }

    if (!inserted) {
      arr[0] = x;
    }

    //Display
    for (int i = 0; i < arr.size(); i++)
      cout << arr[i] << " ";
    cout << endl;


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

    insertionSort2(n, arr);

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
