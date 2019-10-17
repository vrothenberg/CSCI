#include "DLList.h"


int main(int argc, char* argv[]) {
  string file;
  CinReader read;

  // Check arguments for
  if(argc == 1) {
    // No file provided
    file = "sample_input.txt";
    cout << "ERROR! No file provided.\n";
  } else if (argc == 2) {
    // File name provided
    file = argv[1];
  } else {
    file = argv[1];
    cout << "Invalid number of arguments\n";
  }
  //string readCharString = "#CXDIFBERGAZTKNP";
  Handler myHandle;
  myHandle.ReadFile(string file);

  return 0;
}
