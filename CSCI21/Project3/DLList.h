// Project 3 - Doubly Linked List
//
// Programmer Name: Vince Rothenberg
// Date Completed: October 25 2019
//
// Implements Handler class to operate on dynamic templated doubly linked lists
// DLList class object composed of Node structs, which point to previous and next
// Default Node type: int 


#pragma once

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

// A templated doubly-linked list node with pointers to next and previous nodes.
// Implements a constructor to initialize the data field to a param value
// and the pointer to nullptr.
template <typename T>
struct Node {
  // Class static variables, keeps track of total dynamic objects
  static int created;
  static int destroyed;
  // Next and previous Node pointers
  struct Node* next;
  struct Node* prev;
  T value;
  // Constructor
  Node(T newValue) {
    next = nullptr;
    prev = nullptr;
    value = newValue;
    created++;
    //cout << "Nodes created: " << created << endl;
  }
  ~Node() {
    destroyed++;
    //cout << "Nodes destroyed: " << destroyed << endl;
  }
};

// Initializes Node struct static variables to 0
template <typename T>
int Node<T>::created = 0;
template <typename T>
int Node<T>::destroyed = 0;


// Templated doubly linked list
// Class functions implement insertion, push, pop, clear, delete, get, print
template <typename T>
class DLList {
public:
  // Constructor
  DLList();

  // Destructor
  ~DLList();

  // Clear current list instance of contents
  void Clear();

  // Delete the dynamic list instance and set to nullptr
  void Delete();

  // Insert number into list (sorted)
  void Insert(T num);

  // Add number to front of list
  void Front(T num);

  // Add number to back of list
  void Back(T num);

  // Eliminate all occurrences of number from the list
  void EliminateAll(T num);

  // Remove the first occurrence of number from the list
  void RemoveFirst(T num);

  // Get number from the list
  void GetNum(T num);

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
  // Number of nodes in list
  unsigned int size;

  // Beginning (head) and end (tail) node pointers
  Node<int>* head;
  Node<int>* tail;

};

class Handler {
public:
  // Constructor
  Handler();

  // Constructor, takes filename as input
  Handler(string file);

  // Destructor
  ~Handler();

  // Read file and execute operations
  void ReadFile(string file);

  // Perform operations on linked list
  void Operation(vector<string> opLine);

  // Create dynamic list instance
  void Create();


  // Filename variable
  string file;

  // Doubly Linked List class object
  DLList<int>* HandleDLList;

};
