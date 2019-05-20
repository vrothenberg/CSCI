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
using std::to_string;

//Resets console window
void ClearScreen();

//HighScore Helper Functions

//Returns vector of strings, splits using delimiter char
vector<string> Split(string str, char delimiter);

//Returns sorted multidimensional vector using oldVector and new entry
vector<vector<string>> UpdateVector(vector<vector<string>> oldVector, vector<string> row);

//Reads data from file, i.e. HighScores.txt, and returns multidimensional vector
vector<vector<string>> CreateVector(string file);

//Writes multidimensional vector to file
void SaveToFile(vector<vector<string>> scores, string file);

//Prints player and score values from multidimensional vector
void OutputScores(vector<vector<string>> scores);




#endif
