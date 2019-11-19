// Project 4 - Tree Implementation
//
// Programmer name: Vince Rothenberg
// Date completed:  Nov 19 2019

#pragma once

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Word {
public:
  // Constructor
  Word() {
    this->count = 0;

  };

  // Constructor overload
  //
  Word(string word) {
    this->word = word;
    this->count = 0;
  };

  // Destructor
  ~Word() {

  };

  // Accessor
  // Returns Word's string attribute
  string GetWord() {
    return this->word;
  };

  // Accessor
  // Returns Word's unsigned int count attribute
  unsigned int GetCount() {
    return this->count;
  };

  // Mutable
  void SetWord(string word) {
    this->word = word;
  };

  // Increments the Word object's unsigned int count attribute
  void Increment() {
    this->count++;
  };

  // Returns true if the Word object's string attribute is
  // equal to the target Word's string attribute.
  bool operator==(const Word &target) {
    return (this->getWord() == target.getWord());

  }

  // Returns true if this Word object's string attribute comes (lexicographically)
  // after the target Word's string attribute. Case-insensitive.
  bool operator>(const Word &target) {
    return (this->getWord() > target.getWord());
  };

  // Returns true if this Word object's string attribute comes (lexicographically)
  // before the target Word's string attribute. Case-insensitive.
  bool operator<(const Word &target) {
    return (this->getWord() < target.getWord());
  };

  // Example: APPLE 3
  // Places a string representation of the Word on an output stream.
  ostream &operator<<(ostream &outs, const Word &src) {
    outs << src.getWord() << " " << src.getCount();
    return outs;
  };

private:
  string word;
  unsigned int count;

};

class Handler {
public:
  // Constructor
  Handler(string file) {

  };

  // Destructor
  ~Handler() {

  };

  // File I/O, parses input file and calls Operation function
  void ReadFile(string file) {
    std::ifstream fin(file);
    string line, token, op;

    if (fin.is_open()) {
      string delim = " ";
      // Primary file input loop
      while(getline(fin,line)) {
        try {
          vector<string> opLine;
          int pos = line.find(delim);

          // Loop at least once to parse input line
          do {
            pos = line.find(delim);
            op = line.substr(0,pos);
            opLine.push_back(op);
            line = line.substr(pos+delim.size());
          } while (pos!=-1);
          // Pass vector of operation and operand to Operation function
          Operation(opLine);
        } catch (const std::exception &e) {
          // Shouldn't occur normally
          cout << e.what() << endl;
        }
      }
    } else cout << "FAILED TO OPEN FILE.\n";
  };

  // Executes operations from parsed operation string vector
  void Operation(vector<string> opLine) {
    string treeNull = "MUST CREATE TREE INSTANCE\n";
    char op = opLine[0][0];
    string word = 0;
    if (opLine.size() == 2) word = stoi(opLine[1]);

    switch(op) {
      case '#':
        // Comment
        break;
      case 'C':
        // Create dynamic tree instance
        if (this->HandleTree == nullptr) this->Create();
        else {
          this->HandleTree->Clear();
          cout << "TREE CREATED\n";
        };
        break;
      case 'X':
        // Clear current tree instance of contents
        if (this->HandleTree) {
          this->HandleTree->Clear();
          cout << "TREE CLEARED\n";
        } else cout << treeNull;
        break;
      case 'D':
        // Delete dynamic tree instance and set to nullptr
        if (this->HandleTree) {
          this->HandleTree->Clear();
          delete this->HandleTree;
          this->HandleTree = nullptr;
          cout << "TREE DELETED\n";
        } else cout << treeNull;
        break;
      case 'I':
        // Insert word into binary search tree (sorted)
        if (this->HandleTree) this->HandleTree->Insert(word);
        else cout << treeNull;
        break;
      case 'F':
        // Find word (string) from the tree
        if (this->HandleTree) this->HandleTree->Find(word);
        else cout << treeNull;
        break;
      case 'R':
        // Remove word (string) from the tree
        if (this->HandleTree) this->HandleTree->Remove(word);
        else cout << treeNull;
        break;
      case 'G':
        // Get word (string) from the tree
        if (this->HandleTree) this->HandleTree->GetWord(word);
        else cout << treeNull;
        break;
      case 'N':
        // Return the size of the tree
        if (this->HandleTree) this->HandleTree->ListSize();
        else cout << treeNull;
        break;
      case 'O':
        // In Order print
        if (this->HandleTree) this->HandleTree->InOrderPrint();
        else cout << treeNull;
        break;
      case 'E':
        // Reverse Order print
        if (this->HandleTree) this->HandleTree->ReverseOrderPrint();
        else cout << treeNull;
        break;
      default:
        cout << "Invalid input.\n";
        break;
    }
  };

  // Create dynamic list instance
  void Create() {
    this->HandleTree = new DLList<int>();
    cout << "LIST CREATED\n";
  };



private:
  HandleTree<T>

}

template <typename T>
class BSTree {
public:
  // Default constructor.
  // Initialize the tree with size 0 and null root.
  BSTree() {
    this->size = 0;
    this->root = nullptr;
  }

  // Destructor.
  // Clear the tree.
  ~BSTree() {
    this->clear(this->root);

  }

  // Returns the size (number of nodes) of this tree.
  unsigned int getSize() {
    return this->size;
  }

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear() {
    this->clear(this->root);
  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T data) {
    return this->insert(data, this->root);
  }

  // Find the target data in the tree. Returns true if target is found.
  // Returns false otherwise.
  bool find(T target) {
    return this->find(target, this->root);
  }

  // Remove the target data from the tree. Returns true if the target
  // is found and removed. Returns false otherwise.
  bool remove(T target) {
    return this->remove(target, this->root);
  }

  // Return a pointer to the target data. Returns nullptr if the target
  // data is not found.
  T *get(T target) {
    return this->get(target, this->root);
  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
    this->printInOrder(this->root);
  }

  // Print the data in the tree to STDOUT, reverse-order (descending).
  void printReverseOrder() {
    this->printReverseOrder(this->root);
  }

private:
  unsigned int size; // the number of nodes in the tree

  // A binary search tree node with constructor.
  struct Node {
    T data;
    Node *leftChild;
    Node *rightChild;

    Node(T newData) : data(newData), leftChild(nullptr), rightChild(nullptr) {}
  } * root; // the root of the tree

  // Helper functions to hide internal node pointers from the public API.

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear(Node *&troot) {
    if (troot != nullptr) {
      if (troot->leftChild != nullptr) {
        clear(troot->leftChild);
      }
      if (troot->rightChild != nullptr) {
        clear(troot->rightChild);
      }
      delete troot;
      troot = nullptr;
      this->size--;
    }
  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T newData, Node *&troot) {
    if (troot == nullptr) {
      // Tree empty
      troot = new Node(newData);
      this->size++;
      return true;
    } else if (newData < troot->data) {
      // Left subtree
      if (troot->leftChild != nullptr) insert(newData, troot->leftChild);
      else {
        troot->leftChild = new Node(newData);
        this->size++;
        return true;
      }
    } else if (newData > troot->data) {
      // Right subtree
      if (troot->rightChild != nullptr) insert(newData, troot->rightChild);
      else {
        troot->rightChild = new Node(newData);
        this->size++;
        return true;
      }
    } else {
      // Duplicate
      return false;
    }
    return false;
  }

  // Find the target data in the tree. Returns true if target is found.
  // Returns false otherwise.
  bool find(T target, Node *troot) {
    if (troot != nullptr) {
      if (target == troot->data) {
        return true;
      } else if (troot->leftChild != nullptr && target < troot->data) {
        return find(target, troot->leftChild);
      } else if (troot->rightChild != nullptr && target > troot->data) {
        return find(target, troot->rightChild);
      }
      return false;
    }
    return false;
  }

  // Remove the target data from the tree. Returns true if the target
  // is found and removed. Returns false otherwise.
  bool remove(T target, Node *&troot) {
    if (troot != nullptr) {
      if (target < troot->data) {
        return remove(target, troot->leftChild);
      } else if (target > troot->data) {
        return remove(target, troot->rightChild);
      } else if (target == troot->data) {
        //Delete
        if (troot->leftChild == nullptr && troot->rightChild == nullptr) {
          // No Children
          delete troot;
          troot = nullptr;
        } else if (troot->leftChild == nullptr && troot->rightChild != nullptr) {
          // Only right child
          Node* temp = troot;
          troot = troot->rightChild;
          delete temp;
        } else if (troot->leftChild != nullptr && troot->rightChild == nullptr) {
          // One Left Child
          Node* temp = troot;
          troot = temp->leftChild;
          delete temp;
        } else if (troot->rightChild != nullptr && troot->leftChild != nullptr) {
          // Two Children
          removeMax(troot->data, troot->leftChild);
        }
        this->size--;
        return true;
      }
      return false;
    }
    return false;
  }


  void removeMax(T &removed, Node *&troot) {
    if (troot != nullptr) {
      if(troot->rightChild != nullptr) {
        // Largers nodes in right subtree
        removeMax(removed, troot->rightChild);
      } else {
        // Max is root
        removed = troot->data;
        delete troot;
        troot = nullptr;
      }
    }
  }

  // Return a pointer to the target data. Returns nullptr if the target
  // data is not found.
  T *get(T target, Node *troot) {
    if (troot != nullptr) {
      if (target == troot->data) {
        int* p = &troot->data;
        return p;
      } else if (troot->leftChild != nullptr && target < troot->data) {
        return get(target, troot->leftChild);
      } else if (troot->rightChild != nullptr && target > troot->data) {
        return get(target, troot->rightChild);
      }
      return nullptr;
    }
    return nullptr;
  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder(Node *troot) {
    if (troot != nullptr){
      if (troot->leftChild != nullptr) {
        // Left subtree
        printInOrder(troot->leftChild);
      }
      cout << troot->data << endl;
      if (troot->rightChild != nullptr) {
        // Right subtree
        printInOrder(troot->rightChild);
      }
    }
  }

  // Print the data in the tree to STDOUT, reverse-order (descending).
  void printReverseOrder(Node *troot) {
    if (troot != nullptr){
      if (troot->rightChild != nullptr) {
        // Right subtree
        printReverseOrder(troot->rightChild);
      }
      cout << troot->data << endl;
      if (troot->leftChild != nullptr) {
        // Left subtree
        printReverseOrder(troot->leftChild);
      }
    }
  }
};
