#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::stoul;
using std::stod;
using std::cout;
using std::endl;
using std::sort;
using std::cin;

// Utility functions
void ClearScreen();
void ContinuePrompt();

// Country struct, populates _countriesv
struct Country {
  string _name = "Nameless"; //0
  unsigned int _population = 0;
  unsigned int _area = 0; //sq mi.
  double _popdensity = 0.0; //per sq mi.
  double _netmigration = 0.0;
  unsigned int _gdpcapita = 0;
  double _literacy = 0.0; // 6
  double _birthrate = 0.0;

  void Display();

};



class Countries {
public:
  // Constructor, takes csv file of countries as input
  Countries(string file);

  // Reads csv file and populates local private _countriesv vector
  bool ReadFile(string file);

  // Creates country object from vector of tokens and adds to _countriesv
  void AddCountry(vector<string> cline);

  // Returns size of _countriesv
  int GetSize();

  // Data viewing functions
  // Displays sorted list of num length based on column attribute
  // Displays top or bottom based on bool lohi, false = top

  // Population
  void Populous(bool lohi, int num);

  // Area
  void Area(bool lohi, int num);

  // Population Density
  void PopDensity(bool lohi, int num);

  // Net Migration
  void NetMigration(bool lohi, int num);

  // GDP Per Capita
  void GDPCapita(bool lohi, int num);

  // Literacy
  void Literacy(bool lohi, int num);

  // Birthrate 
  void Birthrate(bool lohi, int num);

private:
  vector<Country> _countriesv;
};
