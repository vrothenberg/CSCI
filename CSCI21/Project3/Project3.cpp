#include "DLList.h"


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

  Handler DoubleLinkedList(file);
  vector<string> opLine = {"C"};
  DoubleLinkedList.Operation({"C"});
  DoubleLinkedList.Operation({"F", "10"});
  DoubleLinkedList.Operation({"A"});
  DoubleLinkedList.Operation({"B", "20"});
  DoubleLinkedList.Operation({"Z"});
  DoubleLinkedList.Operation({"F", "5"});
  DoubleLinkedList.Operation({"B", "35"});
  DoubleLinkedList.Operation({"N"});
  DoubleLinkedList.Operation({"P"});

  return 0;
}
