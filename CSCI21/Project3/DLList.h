#pragma once

#include "CinReader.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

using std::logic_error;
using std::ostringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;



/*
OPERATION codes + descriptions

CODE [argument] : description

# any text      : ignore as comment
C               : create dynamic list instance
X               : clear the current list instance of contents
D               : delete the dynamic list instance and set to nullptr
I number        : insert number into list (sorted)
F number        : add number to front of list
B number        : add number to back of list
E number        : eliminate all occurrences of number from the list
R number        : remove the first occurrence of number from the list
G number        : get number from the list
A               : return contents of head node
Z               : return contents of tail node
T               : pop the head node
K               : pop the tail node
N               : return the size of the list
P               : print all items in the list
*/

class Handler {
public:
  void ReadFile(string file);

  void Operation(vector<string> opLine);

  // Create dynamic list instance
  void Create();

  // Clear the current list instance of contents
  void Clear();

  // Delete the dynamic list instance and set to nullptr
  void Delete();

  // Insert number into list (sorted)
  void Insert(int num);

  // Add number to front of list
  void Front(int num);

  // Add number to back of list
  void Back(int num);

  // Eliminate all occurrences of number from the list
  void EliminateAll(int num);

  // Remove the first occurrence of number from the list
  void RemoveFirst(int num);

  // Get number from the list
  void GetNum(int num);

  // Return contents of head node
  void HeadContents();

  // Return contents of tail node
  void TailContents();

  // Pop the head node
  void PopHead();

  // Pop the tail node
  void PopTail();

  // Return size of list
  void ListSize();

  // Print all items in list
  void PrintList();

private:
  DLList<int> myList;

};

template <typename T>
class DLList {
public:
  // Constructor
  DLList();

  // Destructor
  ~DLList();


private:
  // Number of nodes in list
  unsigned int size;

  // A singly-linked list node with a pointer to next and a data field.
  // Implements a constructor to initialize the data field to a param value
  // and the pointer to nullptr.
  struct Node {
    Node *next;
    Node *prev;
    T value;

    Node(T newValue) {
      next = nullptr;
      prev = nullptr;
      value = newValue;
    }

  }

  * head;
  * tail;

};
