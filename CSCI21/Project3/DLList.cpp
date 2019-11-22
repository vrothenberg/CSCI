#include "DLList.h"

// Default constructor
Handler::Handler() {
  cout << "NO FILE PROVIDED\n";
};

// Constructor with file provided, calls ReadFile
Handler::Handler(string file) {
  this->file = file;
  this->HandleDLList = nullptr;
  this->ReadFile(file);
};

// Destructor
Handler::~Handler() {
  delete this->HandleDLList;
};

// File I/O, parses input file and calls Operation function
void Handler::ReadFile(string file) {
  std::ifstream fin(file);
  string line, token, op;

  if (fin.is_open()) {
    string delim = " ";
    // Primary file input loop
    while (getline(fin,line)) {
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
        cout << "ReadFile ERROR!\n";
        cout << e.what() << endl;
      }
    }
  } else cout << "FAILED TO OPEN FILE.\n";
};

// Executes operations from parsed operation string vector
void Handler::Operation(vector<string> opLine) {
  string listNull = "MUST CREATE LIST INSTANCE";
  char op = opLine[0][0];
  int num = 0;
  if (opLine.size() == 2 && op != '#') num = stoi(opLine[1]);

  switch (op) {
    case '#':
      // Comment
      break;
    case 'C':
      // Create dynamic list instance
      if (this->HandleDLList == nullptr) {
        if (this->Create()) cout << "LIST CREATED" << endl;
        else cout << "FAILED TO CREATE LIST" << endl;
      }
      else {
        this->HandleDLList->Clear();
        cout << "LIST CREATED" << endl;
      };
      break;
    case 'X':
      // Clear current list instance of contents
      if (this->HandleDLList) {
        if (this->HandleDLList->Clear()) cout << "LIST CLEARED" << endl;
        else cout << "FAILED TO CLEAR LIST" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'D':
      // Delete dynamic list and set to nullptr
      if (this->HandleDLList) {
        this->HandleDLList->Clear();
        delete this->HandleDLList;
        this->HandleDLList = nullptr;
        cout << "LIST DELETED" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'I':
      // Insert number into list (sorted)
      if (this->HandleDLList) {
        if (this->HandleDLList->Insert(num))
          cout << "VALUE " << num << " INSERTED" << endl;
        else cout << "FAILED TO INSERT" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'F':
      // Add number to front of list
      if (this->HandleDLList) {
        if (this->HandleDLList->Front(num))
          cout << "VALUE " << num << " ADDED TO HEAD" << endl;
        else cout << "FAILED TO ADD TO HEAD" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'B':
      // Add number to back of list
      if (this->HandleDLList) {
        if (this->HandleDLList->Back(num))
          cout << "VALUE " << num << " ADDED TO TAIL" << endl;
        else cout << "FAILED TO ADD TO TAIL" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'E':
      // Eliminate all occurrences of number from list
      if (this->HandleDLList) {
        if (this->HandleDLList->EliminateAll(num))
          cout << "VALUE " << num << " ELIMINATED" << endl;
        else cout << "VALUE " << num << " NOT FOUND" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'R':
      // Remove first occurrence of number from the list
      if (this->HandleDLList) {
        if (this->HandleDLList->RemoveFirst(num))
          cout << "VALUE " << num << " REMOVED" << endl;
        else cout << "VALUE " << num << " NOT FOUND" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'G':
      // Get number from the list
      if (this->HandleDLList) {
        if (this->HandleDLList->GetNum(num))
          cout << "VALUE " << num << " FOUND\n";
        else cout << "VALUE " << num << " NOT FOUND\n";
      }
      else cout << listNull << endl;
      break;
    case 'A':
      // Return contents of head node
      if (this->HandleDLList) {
        if (this->HandleDLList->ListSize() > 0)
          cout << "VALUE " << this->HandleDLList->HeadContents() << " AT HEAD" << endl;
        else cout << "LIST EMPTY" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'Z':
      // Return contents of tail node
      if (this->HandleDLList) {
        if (this->HandleDLList->ListSize() > 0)
          cout << "VALUE " << this->HandleDLList->TailContents() << " AT TAIL" << endl;
        else cout << "LIST EMPTY" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'T':
      // Pop the head node
      if (this->HandleDLList) {
        if (this->HandleDLList->ListSize() > 0) {
          this->HandleDLList->PopHead();
          cout << "REMOVED HEAD" << endl;
        }
        else cout << "LIST EMPTY" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'K':
      // Pop the tail node
      if (this->HandleDLList) {
        if (this->HandleDLList->ListSize() > 0) {
          this->HandleDLList->PopTail();
          cout << "REMOVED TAIL" << endl;
        }
        else cout << "LIST EMPTY" << endl;
      }
      else cout << listNull << endl;
      break;
    case 'N':
      // Return the size of the list
      if (this->HandleDLList)
        cout << "LIST SIZE IS " << this->HandleDLList->ListSize() << endl;
      else cout << listNull << endl;
      break;
    case 'P':
      // Print all items in the list
      if (this->HandleDLList) {
        if (this->HandleDLList->ListSize() > 0)
          cout << this->HandleDLList->PrintList() << endl;
        else cout << "LIST EMPTY" << endl;
      }
      else cout << listNull << endl;
      break;
    default:
      cout << "Invalid input." << endl;
      break;
  }
};

// Create dynamic list instance
bool Handler::Create() {
  this->HandleDLList = new DLList<int>();
  return true;
};

// DLList Constructor
template <typename T>
DLList<T>::DLList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
};

// DLList Destructor
template <typename T>
DLList<T>::~DLList() {
  // Clear list contents, deletes pointers and sets to nullptr
  this->Clear();
};

// Clear the current list instance of contents
template <typename T>
bool DLList<T>::Clear() {
  if (this->size == 0) return true;
  Node<T>* temp = this->head;
  while (temp != nullptr) {
    Node<T>* temp1 = temp->next;
    delete temp;
    temp = temp1;
  }
  delete temp;
  temp = nullptr;
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
  return true;
};

// Insert number into list (sorted)
template <typename T>
bool DLList<T>::Insert(T value) {
  if (this->size == 0) return Front(value);
  Node<T>* current = this->head;
  bool inserted = false;
  while (current != nullptr) {
    if (current->value >= value) {
      // Insert before current
      if (current == this->head) {
        // New node becomes head
        return Front(value);
      } else {
        // Current has valid previous node to assign newNode as its next
        Node<T>* newNode = new Node<T>(value);
        current->prev->next = newNode;
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev = newNode;
        this->size++;
        return true;
      }
    } else if (current->next == nullptr) {
      // New node larger than all elements
      return Back(value);
    } else current = current->next;
  }
  return false;
};

// Add number to front of list
template <typename T>
bool DLList<T>::Front(T value) {
  Node<T>* temp = new Node<T>(value);
  if (this->size == 0) {
    this->tail = temp;
  } else {
    temp->next = this->head;
    this->head->prev = temp;
  }
  this->head = temp;
  this->size++;
  return true;
};

// Add number to back of list
template <typename T>
bool DLList<T>::Back(T value) {
  Node<T>* temp = new Node<T>(value);
  if (this->size == 0) {
    this->head = temp;
  } else {
    temp->prev = this->tail;
    this->tail->next = temp;
  }
  this->tail = temp;
  this->size++;
  return true;
};

// Eliminate all occurrences of number from the list
template <typename T>
bool DLList<T>::EliminateAll(T value) {
  if (this->size == 0) return false;
  bool elim = false;
  while(RemoveFirst(value)) {
    elim = true;
  }
  return elim;
};

// Remove the first occurrence of number from the list
template <typename T>
bool DLList<T>::RemoveFirst(T value) {
  if (this->size == 0) return false;
  bool removed = false;
  Node<T>* current = this->head;
  while (current != nullptr) {
    if (current->value == value) {
      // First occurrence detected
      if (current->next != nullptr) {
        // Current next node exists
        if (current->prev != nullptr) {
          // Current previous node exists
          removed = true;
          current->prev->next = current->next;
          current->next->prev = current->prev;
          delete current;
          current = nullptr;
          this->size--;
          return true;
        } else {
          // Current is head
          return PopHead();
        }
      } else {
        // Current next node does not exist
        return PopTail();
      }
    }
    current = current->next;
  }
  return removed;
};

// Get number from the list
template <typename T>
bool DLList<T>::GetNum(T value) {

  if (this->size == 0) return false;
  Node<T>* current = this->head;
  bool found = false;
  while (current != nullptr && found == false) {
    if (current->value == value) {
      found = true;
      return true;
    };
    current = current->next;
  }
  return found;
};

// Return contents of head node
template <typename T>
T DLList<T>::HeadContents() {
  if (this->size == 0) throw std::logic_error("LIST EMPTY");
  return this->head->value;
};

// Return contents of tail node
template <typename T>
T DLList<T>::TailContents() {
  if (this->size == 0) throw std::logic_error("LIST EMPTY");
  return this->tail->value;
};

// Pop the head node
template <typename T>
bool DLList<T>::PopHead() {
  if (this->size == 0) return false;
  Node<T>* temp = this->head;
  if (this->size == 1) {
    this->head->next = nullptr;
    this->head = nullptr;
  } else {
    this->head = temp->next;
    this->head->prev = nullptr;
  }
  delete temp;
  temp = nullptr;
  this->size--;
  return true;
};

// Pop the tail node
template <typename T>
bool DLList<T>::PopTail() {

  if (this->size == 0) return false;
  Node<T>* temp = this->tail;
  if (this->size == 1) {
    this->tail->next = nullptr;
    this->tail->prev = nullptr;
    this->tail = nullptr;
  } else {
    this->tail = temp->prev;
    this->tail->next = nullptr;
  }
  delete temp;
  temp = nullptr;
  this->size--;
  return true;
};

// Return size of list
template <typename T>
unsigned int DLList<T>::ListSize() {
  return this->size;
};

// Print all items in list
template <typename T>
string DLList<T>::PrintList() {
  ostringstream sout;
  Node<T>* current = this->head;
  if (this->size == 0) throw std::logic_error("LIST EMPTY");
  while (current != nullptr) {
    sout << current->value;
    if (current->next != nullptr) sout << ",";
    current = current->next;
  }
  return sout.str();
};
