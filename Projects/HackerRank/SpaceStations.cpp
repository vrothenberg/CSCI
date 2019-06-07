#include <bits/stdc++.h>
#include <map>
#include <time.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
  //n, number of cities 0 to n
  //cout << "n : " << n << endl;

  //
  //Implement binary search tree
  //

  //map<int, int> stations;
  vector<int> keys;
  //cities with space stations
  keys.push_back(c[0]);
  for (int i = 1; i < c.size(); i++) {
    //cout << c[i] << " ";
    //stations.insert(make_pair(c[i], 1));
    bool inserted = false;
    for (int k = 0; k < keys.size(); k++) {
      if (keys[k] > c[i]) {
        keys.insert(keys.begin() + k, c[i]);
        inserted = true;
        break;
      }
    }
    if (inserted == false) keys.push_back(c[i]);
  }

  for (int i = 0; i < keys.size(); i++) {
    cout << keys[i] << " ";
  }


  int maxDistance = 0;

  //loop through cities
  for (int i = 0; i < n; i++) {
    //cout << "City: " << i << endl;
    int fDistance = 0;
    bool stationAhead = false;
    for (int j = i; j < n; j++) {
      //foreward
      if (stations.find(j) != stations.end()) {
        stationAhead = true;
        break;
      }
      else fDistance++;
    }
    int bDistance = 0;
    bool stationBehind = false;
    for (int k = i; k >= 0; k--) {
      //backward
      if (stations.find(k) != stations.end()) {
        stationBehind = true;
        break;
      }
      else bDistance++;
    }
    int localDist = 0;
    if (stationBehind && stationAhead) {
      if (fDistance > bDistance) localDist = bDistance;
      else localDist = fDistance;
    } else if (stationBehind) localDist = bDistance;
    else if (stationAhead) localDist = fDistance;
    else localDist = -1;
    //cout << "bDist: " << bDistance << " fDist: " << fDistance << " localMax: " << localDist << endl;

    if (localDist > maxDistance) maxDistance = localDist;

  }

  cout << "Max Distance: " << maxDistance;

  return maxDistance;
}

int main()
{
  time_t begin;
  time(&begin);
    ofstream fout("output.txt");
    ifstream fin("input.txt");

    string nm_temp;
    getline(fin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(fin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    time_t after;
    time(&after);

    cout << "Seconds: " << difftime(after , begin);

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
