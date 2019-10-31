// Lab 14 -- binary search tree
//
// Programmer name: Vince Rothenberg
<<<<<<< HEAD
// Date completed:  October 25, 2019
=======
// Date completed:  Oct 29 2019
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b

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
<<<<<<< HEAD
    this->size = 0;
    this->root = nullptr;
=======
    this->root = nullptr;
    this->size = 0;
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b

  }

  // Destructor.
  // Clear the tree.
  ~BSTree() {
<<<<<<< HEAD
    this->clear();
=======
    this->clear(this->root);
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b

  }

  // Returns the size (number of nodes) of this tree.
  unsigned int getSize() {
    return this->size;

  }

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear() {
<<<<<<< HEAD
    return this->root->clear();
=======
    this->clear(this->root);
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b

  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T data) {
<<<<<<< HEAD
    return this->root->insert(T, this->root);
=======
    return this->insert(data, this->root);
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b

  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
<<<<<<< HEAD
    return this->root->printInOrder(this->root);
=======
    this->printInOrder(this->root);
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b

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
<<<<<<< HEAD

  }


  bool insert(T newData, Node *&troot) {
    if (troot == nullptr) {
      // Tree empty
      troot = new Node<T>(newData);
      return true;
    } else if (newData > troot->data) {
      // Larger, right subtree
      insert(newData, troot->right);
    } else if (newData < troot->data) {
      // Smaller, left subtree
      insert(newData, troot->left);
=======
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
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b
    } else {
      // Duplicate
      return false;
    }
<<<<<<< HEAD
  }

  void printInOrder(Node *troot) {

=======
    return false;
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
>>>>>>> cf5a840745204d10e2dc09e6dcd3194bb78b388b
  }
};
