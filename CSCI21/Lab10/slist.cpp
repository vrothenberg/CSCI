#include "slist.h"


  // Default constructor.
  // Initializes head to nullptr, size to 0.
  SList::SList() {
    this->head = nullptr;
    this->size = 0;
  };

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void SList::pushFront(int value) {
    Node *temp = new Node(value);
    temp->next = this->head;
    this->head = temp;
    this->size++;
  };

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  int SList::front() noexcept(false) {
    if (this->size == 0) throw std::logic_error("EMPTY LIST");
    return this->head->value;

  };

  // Return the number of nodes in this list.
  unsigned int SList::getSize() const {
    return this->size;
  };

  // Check to see if this list is empty.
  bool SList::empty() const {
    return !this->size;
  };

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string SList::toString() const {
    Node* temp = head;
    string result = "";
    /*
    while (temp->next != nullptr) {
      result += std::to_string(temp->value) + ",";
      temp = temp->next;
    }*/
    for (int i = 0; i < this->size; i++) {

      result += std::to_string(temp->value);
      if (temp->next != nullptr) {
        result += ",";
        temp = temp->next;
      }

    }

    return result;
  };
