// Lab 6 -- argc and argv, file input
//
// Programmer name: Vince Rothenberg
// Date completed: October 1, 2019

#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

struct Item {
  string name;
  unsigned int quantity;
};

void printItem(const Item &item) {
  cout << item.name << ", quantity: " << item.quantity << endl;
}

// Add functions as wanted/needed to help with file processing

int main(int argc, char *argv[]) {

  // If two arguments not provided, return error
  if (argc != 2) {
    cout << "Error.  Enter filename.\n";
  } else {
    // Open file
    ifstream fin(argv[1]);
    string line;
    if (fin.is_open()) {
      string delim = ":";
      // Loop through each line
      while (getline(fin, line)) {
        // Split line by delimiter ':'
        int mark = line.find(delim);
        string name = line.substr(0, mark);
        string quantity = line.substr(mark+1, line.length());

        // Create item struct
        Item it;
        it.name = name;
        it.quantity = stoi(quantity);

        // Print item
        printItem(it);
      }
      fin.close();
    } else {
      cout << "Error.  Fail to open.\n";
    }


  }



  // If a filename argument has been passed via argv,
  // attempt to open the file and read its contents.
  //
  // Absence of a filename via argv should produce an error message.
  // A non-existent file should produce an error message.
  //
  // If the file can be opened, assume that it has an unknown
  // number of lines, with each line containing a NAME:QUANTITY
  // pair. (ex., "apples:10")
  //
  // Parse each line and populate the data fields in item,
  // then pass item to the printItem function. The output
  // of the function serves as confirmation that file and data
  // processing are functioning properly.



  return 0;
}
