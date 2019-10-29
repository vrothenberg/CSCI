// Lab 14 -- binary search tree
//
// Programmer name: Vince Rothenberg
// Date completed:  Oct 29 2019

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
    this->root = nullptr;
    this->size = 0;

  }

  // Destructor.
  // Clear the tree.
  ~BSTree() {
    this->root->clear();

  }

  // Returns the size (number of nodes) of this tree.
  unsigned int getSize() {
    return this->size;

  }

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear() {
    this->root>clear();

  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T data) {
    return this->insert(data, this->root);

  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
    this->printInOrder(this->root);

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

  }

  bool insert(T newData, Node *&troot) {
    if (troot == nullptr) {
      // Tree empty
      troot = new Node<T>(newData);
      return true;
    } else if (newData < troot) {
      // Left subtree
      if (troot->leftChild != nullptr) insert(newData, troot->leftChild);
      else troot->leftChild = new Node<T>(newData);
    } else if (newData > troot) {
      // Right subtree
      if (troot->rightChild != nullptr) insert(newData, troot->rightChild);
      else troot->rightChild = new Node<T>(newData);
    } else {
      // Duplicate
      return false;
    }
  }

  void printInOrder(Node *troot) {
    if (troot == nullptr) {
      // Tree empty
    } else {
      if (troot->leftChild != nullptr) {
        // Left subtree

      } else if (troot->rightChild != nullptr) {
        // Right subtree

      }
      cout << troot->data << endl;
    }
  }
};
