// Lab 12 -- templated singly-linked list class
//
// Programmer name: Vince Rothenberg
// Date completed:  __________

#include <sstream>
#include <stdexcept>
#include <string>
using std::logic_error;
using std::ostringstream;
using std::string;

template <typename T>
class SList {
public:
  // Default constructor.
  // Initializes head to nullptr, size to 0.
  SList() {
    this->head = nullptr;
    this->size = 0;

  }

  // Destructor.
  // Invokes clear to free the memory associated with all nodes in the list.
  ~SList() {
    this->clear();
  }

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void pushFront(T value) {
    Node* temp = new Node(value);
    temp->next = this->head;
    this->head = temp;
    this->size++;
  }

  // Remove the head node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  void popFront() noexcept(false) {
    if (this->empty()) throw std::logic_error("EMPTY LIST");
    Node* temp = this->head->next;
    delete this->head;
    this->head = temp;
    this->size--;
  }

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  T front() noexcept(false) {
    if (this->empty()) throw std::logic_error("EMPTY LIST");
    return this->head->value;
  }

  // Return the number of nodes in this list.
  unsigned int getSize() const {
    return this->size;
  }

  // Check to see if this list is empty.
  bool empty() const {
    return (this->size == 0 && this->head == nullptr);
  }

  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void clear() {
    Node* temp = head;
    for (int i = 0; i < this->size; i++) {
      Node* temp1 = temp->next;
      delete temp;
      temp = temp1;
    }
    delete temp;
    temp = nullptr;
    this->head = nullptr;
    this->size = 0;
  }

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string toString() const {
    Node* temp = head;
    ostringstream sout;
    for (int i = 0; i < this->size; i++) {
      sout << temp->value;
      if (temp->next != nullptr) {
        sout << ",";
        temp = temp->next;
      }
    }
    return sout.str();
  }

private:
  unsigned int size; // the number of nodes in this list

  // A singly-linked list node with a pointer to next and a data field.
  // Implements a constructor to initialize the data field to a param value
  // and the pointer to nullptr.
  struct Node {
    Node *next;
    T value;

    Node(T newValue) {
      next = nullptr;
      value = newValue;
    }

  } * head; // a pointer to the first node in the list
};
