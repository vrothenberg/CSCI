#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

vector<string> split_string(string);

// Complete the taumBday function below.
unsigned long taumBday(unsigned long b, unsigned long w, unsigned long bc, unsigned long wc, unsigned long z) {
  cout << b << ", " << w << ", " << bc << ", " << wc << ", " << z << endl;
  unsigned long result;
  if (bc > (wc + z)) {
    //Black too expensive, convert to white
    //cout << "Converting to white\n";
    result = b * (wc + z) + w * wc;
  } else if (wc > (bc + z)) {
    //White too expensive, convert to black
    //cout << "Converting to black\n";
    result = b * bc + w * (bc + z);
  } else {
    //Conversion not economical
    //cout << "Conversion not economical\n";
    unsigned long bxbc;
    bxbc = b * bc;
    //cout << bxbc << " + " << w * wc << endl;
    result = b * bc + w * wc;
  }
  cout << "Result : " << result << endl;
  return result;
}

int main()
{
    ofstream fout("output.txt");
    ifstream fin("input.txt");

    int t;
    fin >> t;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string bw_temp;
        getline(fin, bw_temp);

        vector<string> bw = split_string(bw_temp);

        unsigned long b = stoi(bw[0]);

        unsigned long w = stoi(bw[1]);

        string bcWcz_temp;
        getline(fin, bcWcz_temp);

        vector<string> bcWcz = split_string(bcWcz_temp);

        unsigned long bc = stoi(bcWcz[0]);

        unsigned long wc = stoi(bcWcz[1]);

        unsigned long z = stoi(bcWcz[2]);

        unsigned long result = taumBday(b, w, bc, wc, z);

        fout << result << "\n";
    }

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
