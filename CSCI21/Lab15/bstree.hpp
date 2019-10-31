// Lab 15 -- binary search tree
//
// Programmer name: Vince Rothenberg
// Date completed:  Oct 30 2019

#pragma once

#include <iostream>
using std::cout;
using std::endl;

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

  bool remove(T target, Node *&troot) {
    if (troot != nullptr) {
      if (target == troot->data) {

        return true;
      } else if (troot->leftChild != nullptr && target < troot->data) {
        return remove(target, troot->leftChild);
      } else if (troot->rightChild != nullptr && target > troot->data) {
        return remove(target, troot->rightChild);
      }
      return false;
    }
    return false;

  }

  void removeMax(T &removed, Node *&troot) {


  }

  T *get(T target, Node *troot) {
    if (troot != nullptr) {
      if (target == troot->data) {
        return troot;
      } else if (troot->leftChild != nullptr && target < troot->data) {
        return get(target, troot->leftChild);
      } else if (troot->rightChild != nullptr && target > troot->data) {
        return get(target, troot->rightChild);
      }
      return nullptr;
    }
    return nullptr;

  }

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

  void printReverseOrder(Node *troot) {
    if (troot != nullptr){
      if (troot->rightChild != nullptr) {
        // Right subtree
        printInOrder(troot->rightChild);
      }
      cout << troot->data << endl;
      if (troot->leftChild != nullptr) {
        // Left subtree
        printInOrder(troot->leftChild);
      }
    }
  }
};
