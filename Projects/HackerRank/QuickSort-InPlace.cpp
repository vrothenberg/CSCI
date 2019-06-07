#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

vector<string> split_string(string input_string);

void swap(vector<int> &arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int part(vector<int> &arr, int start, int end) {
  //Array by reference, start index, end index

  //Pivot last element in subarray
  int p = arr[end];

  int i = start;
  if (start < end) {
    for(int j = start; j < end; j++) {
      //If element less than pivot, swap it with first greater element (i) position
      if (arr[j] < p) {
        // Swap to i
        swap(arr, i, j);
        i++;
      }
    }
    //Final swap for pivot
    swap(arr, i, end);

    //Print array
    for (int a = 0; a < arr.size(); a++) {
      cout << arr[a] << " ";
    }
    cout << endl;
  }

  return i;
}


void quickSort(vector<int> &arr, int start, int end) {
  //Array by reference, start index, end index

  if (start < end) {
    //Partition and set pivot index
    int pIndex = part(arr, start, end);

    //Left subarray recursive call
    quickSort(arr, start, pIndex-1);

    //Right subarray recursive call
    quickSort(arr, pIndex+1, end);
  }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
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

    quickSort(arr, 0, n-1);

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
