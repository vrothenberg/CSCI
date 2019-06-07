#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
// n : number of prisoners
// m : number of sweets
// s : starting chair number
int saveThePrisoner(int n, int m, int s) {

  int prisoner = (s + (m % n) - 1) % n;
  return prisoner;


}



int main()
{
  string s = "ABCXYZ";

  for (int i = 0; i < s.size(); i++) {

    cout << s[i] << " " << (int)s[i] << endl;
  }


/*
  cout << "Output   : " << saveThePrisoner(208526924, 756265725, 150817879) << endl;
  cout << "Expected : " << 72975907;



  /*
  string line;
    ofstream fout("output.txt");
    cout << "Begin.\n";
    ifstream fin ("input.txt");
    int t;
    if (fin.is_open())
    {
      //cout << t << endl;
      string nms_temp;
      while ( getline (fin, nms_temp) )
      {
        //cout << nms_temp << endl;

        vector<string> nms = split_string(nms_temp);
        for (int i = 0; i < nms.size(); i++) {
          cout << nms[i] << " ";
        }
        cout << endl;
        if (nms.size()>1)
        {
          int n = std::stoi(nms[0]);

          int m = std::stoi(nms[1]);

          int s = std::stoi(nms[2]);

          int result = saveThePrisoner(n, m, s);
          cout << "Result : " << result << endl;

          fout << result << "\n";
        }

      }
      fin.close();
    }
    fout.close();
*/
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
