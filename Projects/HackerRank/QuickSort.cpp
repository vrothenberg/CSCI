#include <bits/stdc++.h>
using namespace std;

void part(vector <int> &arr) {

  int n = arr.size();

  if (n > 1) {
    int p = arr[0];
    vector<int> left;
    vector<int> right;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] <= p)
        left.push_back(arr[i]);
      else if (arr[i] > p)
        right.push_back(arr[i]);
    }


    if (left.size() > 1) {
      part(left);
    }
    for (int i = 0; i < left.size(); i++) {
      cout << left[i] << " ";
    }
    cout << p;

    if (right.size() > 1) {
      part(right);
    }
    for (int i = 0; i < right.size(); i++) {
      cout << right[i] << " ";
    }
    cout << endl;

    // Complete.
  }
}


void quickSort(vector <int> &arr) {
	// Complete this function
  //cout << "Entering quickSort\n";
  int n = arr.size();

  if (n > 1) {
    /*
    cout << "arr: ";
    for (int i = 0; i < arr.size(); i++)
      cout << arr[i] << " ";
    cout << endl;
    */


    int p = arr[0];
    vector<int> left;
    vector<int> right;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] <= p)
        left.push_back(arr[i]);
      else if (arr[i] > p)
        right.push_back(arr[i]);
    }


    if (left.size() > 1) {
      //cout << "left > 1\n";
      quickSort(left);
    }


    if (right.size() > 1) {
      //cout << "right > 1\n";
      quickSort(right);
    }

    //cout << "Sorting " << n << endl;
    int index = 0;

    for (int i = 0; i < left.size(); i++) {
      cout << left[i] << " ";
      arr[index] = left[i];
      index++;
    }
    cout << p << " ";
    arr[index] = p;
    index++;
    for (int i = 0; i < right.size(); i++) {
      cout << right[i] << " ";
      arr[index] = right[i];
      index++;
    }
    cout << endl;

    // Complete.
  }


}


int main()
{
  ifstream fin("input.txt");
    int n;
    fin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        fin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
