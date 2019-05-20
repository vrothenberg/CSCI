#include "System.h"

void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}

//Splits a string by a delimiter character and returns a vector
vector<string> Split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok); //Loops and adds each element to vector
  }
  return internal;
}

//Returns new sorted vector of vectors (2 dimensional array)
//Input old score vector of vectors, and new score vector
vector<vector<string>> UpdateVector(vector< vector<string> > oldVector, vector<string> row) {
  vector<vector<string>> newVector;
  bool pushed = false; //Check if row has been inserted
  for (int i = 0; i<oldVector.size(); i++) {
    //Iterate through high scores vector
    if (stoi(row[1]) > stoi(oldVector[i][1]) && pushed == false) {
      //Check if row's score element is larger than the current high score element
      //Must convert string to int using stoi to perform check
      newVector.push_back(row);
      pushed = true;
    }
    newVector.push_back(oldVector[i]);
  }
  //Only keeps track of top 10, erases lowest score if full
  if (newVector.size()>10) newVector.erase(newVector.end() - 1);
  return newVector;
}


//Reads data from high scores file and returns 2 dimesional vector
vector<vector<string>> CreateVector(std::string file) {
  vector<vector<string>> fileVector;
  ifstream fin(file);
  if (fin.fail()) {
    cerr << "Failed to open file";
    return fileVector;
  }
  std::string line;
  while (std::getline(fin, line)) {
    vector<string> sline = Split(line, ' ');
    if (line.size()>1) {
      fileVector.push_back(sline);
    }
  }
  fin.close();
  return fileVector;
}

//Writes multidimensional vector to file
void SaveToFile(vector<vector<string>> inputVector, std::string file) {
  ofstream fout(file);
  for (int i = 0; i < inputVector.size(); i++) {
    fout << inputVector[i][0] << " " << inputVector[i][1] << endl;
  }
  fout.close();
}

//Prints top 10 player and score values from multidimensional vector
void OutputScores(vector<vector<string>> scores){
  cout << "=============== HIGH SCORES ===============\n\n";
  for (int i = 0; i<scores.size(); i++) {
    string name = scores[i][0];
    int score = stoi(scores[i][1]);
    //cout << "Player: " << name << " Score: " << score << endl;
    printf(" Player: %15s    Score: %7d \n", name.c_str(), score);
  }
  cout << "\n===========================================\n\n";
}
