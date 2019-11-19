// Project 4 - Binary Search Tree
//
// Programmer Name: Vince Rothenberg
// Date Completed: November 19 2019
//
// Implements Handler class to operate on dynamic templated doubly linked lists
// DLList class object composed of Node structs, which point to previous and next
// Default Node type: int


#include "Tree.hpp"

int main(int argc, char* argv[]) {
  string file;

  // Check arguments
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

  Handler Tree(file);

  return 0;
}
