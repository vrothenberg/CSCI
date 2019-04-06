#include <iostream>
#include "CinReader.h"
#include <fstream>

#include <cmath>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int oldMain() {
  /*
  //Create the stream
  /*
  ofstream fout("multiples_of_three.txt");

  //Open the file
  //fin.open("infile.txt");
  //fout.open("outfile.txt", std::ios::app);

  for (int i = 1; i <= 15; i++) {
    fout << 3 * i << endl;
  }
  */
  ifstream fin("multiples_of_three.txt");
  /*
  int sum = 0;
  for (int i = 0; i < 15; i++) {
    int n;
    fin >> n;
    sum += n;
  }
  cout << "The sum is: " << sum;
  */




  ofstream fout("multiples_of_three.txt", std::ios::app);
  for (int i = 1; i <= 15; i++) {
    fout << 45 + 3 * i << endl;
  }





  /*

  //Read / Write
  int first, second, third;
  fin >> first >> second >> third;
  fout << (first + second + third) << endl;

  cout << "File I/O has been completed" << endl;

  //Close the file
  fin.close();
  fout.close();

  int one_number, another_number;
  fin >> one_number >> another_number;

  */
  return 0;
}

int April_2_IO() {

  string filename;
  cout << "Please enter a filename (story.txt): ";
  cin >> filename;
  ifstream fin(filename.c_str());

  if (fin.fail()) {
    cerr << "Error opening " << filename << endl;
    return 1;
  }

  char next;
  int n = 1;
  fin.get(next);

  cout << n << " ";
  while(!fin.eof()) {
    cout << next;
    if(next == '\n'){
      n++;
      cout << n << " ";
    }

    fin.get(next);
  }

  fin.close();

  return 0;
}

void DogHouse() {
  const double kCostPerSqFt = 10.50;
  double budget, area, length_side;

  cout << "How much is your budget? $";
  cin >> budget;

  area = budget / kCostPerSqFt;

  length_side = sqrt(area);

  cout.setf(std::ios::showpoint|std::ios::fixed);
  cout.precision(2);

  cout << "Your dog house will cost $" << budget << endl
       << "and will be " << length_side << " x " << length_side << endl;
}

int Round(double number) {
   int iNumber = number;
   if (number - iNumber > 0.5) {
     return iNumber + 1;
   }
   return iNumber;
}

int SumThree(int x, int y, int z) {
  return x + y + z;
}

char IsPositive(double n) {
  if (n >= 0 ) {
    return 'P';
  }
  return 'N';
}

int RoundElegant(double number) {
  return floor(number + 0.5);
}



int April_4() {




  return 0;
}

void Output();

int main() {
  int i;
for (int i = 0; i < 3; i++) {
cout << i << endl;
}
cout << i << endl;


  return 0;
}
