#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countingSort function below.
vector<int> countingSort(vector<int> arr) {
  int max = 0;

  for (int i = 0; i < arr.size(); i++)
    if (arr[i] > max)
      max = arr[i];

  vector<int> counts(max);

  for (int i = 0; i < arr.size(); i++) {
    counts[arr[i]]++;
  }

  vector<int> result;

  for (int i = 0; i < max; i++) {
    for (int j = 0; j < counts[i]; j++) {
      result.push_back(i);
    }
  }

  return result;

}

int main()
{
    ofstream fout("output.txt");
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

    vector<int> result = countingSort(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

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
