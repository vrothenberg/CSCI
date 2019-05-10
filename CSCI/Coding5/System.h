//Header Guards
#ifndef ROTHENBERG_SYSTEM_H
#define ROTHENBERG_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;

void ClearScreen();

//HighScore Helper Functions
vector<string> Split(string str, char delimiter);
vector<vector<string>> UpdateVector(vector<vector<string>> oldVector, vector<string> row);
vector<vector<string>> CreateVector(string file);
void SaveToFile(vector<vector<string>> scores, string file);
void OutputScores(vector<vector<string>> scores);




#endif
