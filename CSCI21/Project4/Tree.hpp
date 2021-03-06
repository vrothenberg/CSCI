// Project 4 - Tree Implementation
//
// Programmer name: Vince Rothenberg
// Date completed:  December 3 2019

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::vector;
using std::ostringstream;

string Capitalize(string word) {
  string result = "";
  for (char c : word) {
    result += toupper(c);
  }
  return result;
}

class Word {
public:
  // Constructor
  Word() {
    this->count = 1;
  };

  // Constructor overload
  // Takes string argument to initialize word attribute
  Word(string word) {
    this->word = word;
    this->count = 1;
  };

  // Destructor
  ~Word() {

  };

  // Accessor
  // Returns Word's string attribute
  string GetWord() const {
    return this->word;
  };

  // Accessor
  // Returns Word's unsigned int count attribute
  unsigned int GetCount() const {
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
    return (this->GetWord() == target.GetWord());

  };

  // Returns true if this Word object's string attribute comes (lexicographically)
  // after the target Word's string attribute. Case-insensitive.
  bool operator>(const Word &target) {
    return (this->GetWord() > target.GetWord());
  };

  // Returns true if this Word object's string attribute comes (lexicographically)
  // before the target Word's string attribute. Case-insensitive.
  bool operator<(const Word &target) {
    return (this->GetWord() < target.GetWord());
  };

  // Example: APPLE 3
  // Places a string representation of the Word on an output stream.
  friend ostream &operator<<(ostream &outs, const Word &src) {
    outs << Capitalize(src.GetWord()) << " " << src.GetCount();
    return outs;
  };

private:
  string word;
  unsigned int count;
};



template <typename T>
class BSTree {
public:
  // Default constructor.
  // Initialize the tree with size 0 and null root.
  BSTree() {
    this->size = 0;
    this->root = nullptr;
  };

  // Destructor.
  // Clear the tree.
  ~BSTree() {
    this->Clear(this->root);

  };

  // Returns the size (number of nodes) of this tree.
  unsigned int GetSize() {
    return this->size;
  };

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void Clear() {
    this->Clear(this->root);
  };

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool Insert(T data) {
    return this->Insert(data, this->root);
  };

  // Find the target data in the tree. Returns true if target is found.
  // Returns false otherwise.
  bool Find(T target) {
    return this->Find(target, this->root);
  };

  // Remove the target data from the tree. Returns true if the target
  // is found and removed. Returns false otherwise.
  bool Remove(T target) {
    return this->Remove(target, this->root);
  };

  // Return a pointer to the target data. Returns nullptr if the target
  // data is not found.
  T *Get(T target) {
    return this->Get(target, this->root);
  };

  // Print the data in the tree to STDOUT, in-order (ascending).
  string PrintInOrder() {
    return this->PrintInOrder(this->root);
  };

  // Print the data in the tree to STDOUT, reverse-order (descending).
  string PrintReverseOrder() {
    return this->PrintReverseOrder(this->root);
  };

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
  void Clear(Node *&troot) {
    if (troot != nullptr) {
      if (troot->leftChild != nullptr) {
        Clear(troot->leftChild);
      }
      if (troot->rightChild != nullptr) {
        Clear(troot->rightChild);
      }
      delete troot;
      troot = nullptr;
      this->size--;
    }
  };

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool Insert(T newData, Node *&troot) {
    if (troot == nullptr) {
      // Tree empty
      troot = new Node(newData);
      this->size++;
      return true;
    }
    else if (newData < troot->data) {
      // Left subtree
      if (troot->leftChild != nullptr) return Insert(newData, troot->leftChild);
      else {
        troot->leftChild = new Node(newData);
        this->size++;
        return true;
      }
    }
    else if (newData > troot->data) {
      // Right subtree
      if (troot->rightChild != nullptr) return Insert(newData, troot->rightChild);
      else {
        troot->rightChild = new Node(newData);
        this->size++;
        return true;
      }
    }
    else {
      // Duplicate, increment Word
      troot->data.Increment();
      return false;
    }
    // Should not be here
    cout << "INSERTION FAILED!" << endl;
    return false;
  };

  // Find the target data in the tree. Returns true if target is found.
  // Returns false otherwise.
  bool Find(T target, Node *troot) {
    if (troot != nullptr) {
      if (target == troot->data) {
        return true;
      } else if (troot->leftChild != nullptr && target < troot->data) {
        return Find(target, troot->leftChild);
      } else if (troot->rightChild != nullptr && target > troot->data) {
        return Find(target, troot->rightChild);
      }
      return false;
    }
    return false;
  };

  // Remove the target data from the tree. Returns true if the target
  // is found and removed. Returns false otherwise.
  bool Remove(T target, Node *&troot) {
    if (troot != nullptr) {
      if (target < troot->data) {
        return Remove(target, troot->leftChild);
      } else if (target > troot->data) {
        return Remove(target, troot->rightChild);
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
          RemoveMax(troot->data, troot->leftChild);
        }
        this->size--;
        return true;
      }
      return false;
    }
    return false;
  };


  void RemoveMax(T &removed, Node *&troot) {
    if (troot != nullptr) {
      if(troot->rightChild != nullptr) {
        // Largers nodes in right subtree
        RemoveMax(removed, troot->rightChild);
      } else {
        // Max is root
        removed = troot->data;
        delete troot;
        troot = nullptr;
      }
    }
  };

  // Return a pointer to the target data. Returns nullptr if the target
  // data is not found.
  T *Get(T target, Node *troot) {
    if (troot != nullptr) {
      if (target == troot->data) {
        // Return current node
        T* p = &troot->data;
        return p;
      } else if (troot->leftChild != nullptr && target < troot->data) {
        // Traverse left subtree
        return Get(target, troot->leftChild);
      } else if (troot->rightChild != nullptr && target > troot->data) {
        // Traverse right subtree
        return Get(target, troot->rightChild);
      }
      return nullptr;
    }
    // Failed to find target value
    return nullptr;
  };

  // Print the data in the tree to STDOUT, in-order (ascending).
  string PrintInOrder(Node *troot) {
    ostringstream sout;
    if (troot != nullptr) {
      if (troot->leftChild != nullptr) {
        // Left subtree
        sout << PrintInOrder(troot->leftChild);
      }
      // Current value
      sout << troot->data << endl;
      if (troot->rightChild != nullptr) {
        // Right subtree
        sout << PrintInOrder(troot->rightChild);
      }
    }
    return sout.str();
  };

  // Print the data in the tree to STDOUT, reverse-order (descending).
  string PrintReverseOrder(Node *troot) {
    ostringstream sout;
    if (troot != nullptr) {
      if (troot->rightChild != nullptr) {
        // Right subtree
        sout << PrintReverseOrder(troot->rightChild);
      }
      // Current value
      sout << troot->data << endl;
      if (troot->leftChild != nullptr) {
        // Left subtree
        sout << PrintReverseOrder(troot->leftChild);
      }
    }
    return sout.str();
  };
};

template <typename T>
class Handler {
public:
  // Default constructor
  Handler() {
    cout << "NO FILE PROVIDED\n";
  };

  // Overloaded Constructor
  // Takes string argument for filename, calls ReadFile function
  // File must be in local folder
  Handler(string file) {
    this->file = file;
    this->HandleTree = nullptr;
    this->ReadFile(file);
  };

  // Destructor
  ~Handler() {
    delete this->HandleTree;
  };

  // File I/O, parses input file and calls Operation function
  // Automatically capitalizes input strings 
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
            line = Capitalize(line.substr(pos+delim.size()));
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
    string word = "";
    if (opLine.size() == 2 && op != '#') word = opLine[1];

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
        if (this->HandleTree) {
          if (this->HandleTree->Insert(word))
            cout << "WORD " << word << " INSERTED" << endl;
          else cout << "WORD " << word << " INCREMENTED" << endl;
        }
        else cout << treeNull;
        break;
      case 'F':
        // Find word (string) from the tree
        if (this->HandleTree) {
          if (this->HandleTree->GetSize() == 0)
            cout << "TREE EMPTY" << endl;
          else if (this->HandleTree->Find(word))
            cout << "FOUND " << word << endl;
          else
            cout << word << " NOT FOUND" << endl;
        }
        else cout << treeNull;
        break;
      case 'R':
        // Remove word (string) from the tree
        if (this->HandleTree) {
          if (this->HandleTree->GetSize() == 0)
            cout << "TREE EMPTY" << endl;
          else if (this->HandleTree->Remove(word))
            cout << "REMOVED " << word << endl;
          else
            cout << word << " NOT FOUND" << endl;
        }
        else cout << treeNull;
        break;
      case 'G':
        // Get word (string) from the tree
        if (this->HandleTree) {
          if (this->HandleTree->GetSize() == 0) {
            cout << "TREE EMPTY" << endl;
          }
          else if (this->HandleTree->Get(word) == nullptr) {
            cout << word << " NOT FOUND" << endl;
          }
          else if (this->HandleTree->Get(word)->GetWord().size() > 0) {
            //cout << "GOT " << word << " " << this->HandleTree->Get(word)->GetCount() << endl;
            cout << "GOT " << *this->HandleTree->Get(word) << endl;
          }
          else
            cout << word << " NOT FOUND" << endl;
        }
        else cout << treeNull;
        break;
      case 'N':
        // Return the size of the tree
        if (this->HandleTree)
          cout << "TREE SIZE IS " << this->HandleTree->GetSize() << endl;
        else cout << treeNull;
        break;
      case 'O':
        // In Order print
        if (this->HandleTree) {
          if (this->HandleTree->GetSize() == 0)
            cout << "TREE EMPTY" << endl;
          else
            cout << this->HandleTree->PrintInOrder() << endl;
        }
        else cout << treeNull;
        break;
      case 'E':
        // Reverse Order print
        if (this->HandleTree) {
          if (this->HandleTree->GetSize() == 0)
            cout << "TREE EMPTY" << endl;
          else
            cout << this->HandleTree->PrintReverseOrder() << endl;
        }
        else cout << treeNull;
        break;
      case 'P':
        cout << "DEBUG" << endl;
        break;
      default:
        cout << "Invalid input.\n";
        break;
    }
  };

  // Create dynamic tree instance
  void Create() {
    this->HandleTree = new BSTree<T>();
    cout << "TREE CREATED\n";
  };

private:
  string file;
  BSTree<T>* HandleTree;

};
