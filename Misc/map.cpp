#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


int main() {

  int a = 24;
  int b = 49;

  vector<int> zero;
  cout << "Before";
  for (int i = 0; i < zero.size(); i++)
    cout << zero[i];
  cout << "After";






    /*
    vector<int> v;
    map<int, int>m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        if(m.find(temp)==m.end()) {
            m.insert(make_pair(temp, i));
        }

    }
    set<int> s(v.begin(), v.end());
    set<int>::iterator pos;/*
    for (pos = s.begin(); pos != s.end(); ++pos) {
        cout << *pos << " First occurence: " << m[*pos] + 1 << endl;
    }


    //map<int, int> m;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int query, position;
        cin >> query;
        string present = "No ";
        set<int>::iterator pos;

        for (pos = s.begin(); pos != s.end(); ++pos) {
            if (*pos == query) {
                present = "Yes ";
                position = m[*pos] + 1;
                break;
            } else if(*pos > query) {
                position = m[*pos] + 1;
                break;
            }
        }
        cout << present << position << endl;
    }
    */

    return 0;
}
