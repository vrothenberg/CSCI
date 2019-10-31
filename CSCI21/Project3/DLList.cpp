#include "DLList.h"

Handler::Handler() {
  cout << "NO FILE PROVIDED\n";
};

Handler::Handler(string file) {
  this->file = file;
  this->HandleDLList = nullptr;
  this->ReadFile(file);
};

Handler::~Handler() {
  delete this->HandleDLList;
};

void Handler::ReadFile(string file) {
  std::ifstream fin(file);
  string line, token, op;

  if (fin.is_open()) {
    string delim = " ";
    // Primary file input loop
    while(getline(fin,line)) {
      try {
        vector<string> opLine;
        int pos = line.find(delim);
        do {
          pos = line.find(delim);
          op = line.substr(0,pos);
          opLine.push_back(op);
          line = line.substr(pos+delim.size());
        } while (pos!=-1);

        Operation(opLine);

      } catch (const std::exception &e) {
        // Shouldn't occur normally
        cout << e.what() << endl;
      }

    }
  }
};

void Handler::Operation(vector<string> opLine) {
  char op = opLine[0][0];
  int num = 0;
  if (opLine.size() == 2) num = stoi(opLine[1]);

  switch(op) {
    case '#':
      // Comment
      break;
    case 'C':
      // Create dynamic list instance
      if (this->HandleDLList == nullptr) this->Create();
      else cout << "LIST ALREADY EXISTS\n";
      break;
    case 'X':
      // Clear current list instance of contents
      if (this->HandleDLList) {
        this->HandleDLList->Clear();
        cout << "LIST CLEARED\n";
      } else {
        cout << "MUST CREATE LIST INSTANCE\n";
      }
      break;
    case 'D':
      // Delete dynamic list and set to nullptr
      if (this->HandleDLList) {
        this->HandleDLList->Clear();
        delete this->HandleDLList;
        this->HandleDLList = nullptr;
        cout << "LIST DELETED\n";
      } else cout << "MUST CREATE LIST INSTANCE\n";

      break;
    case 'I':
      // Insert number into list (sorted)
      if (this->HandleDLList) this->HandleDLList->Insert(num);
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'F':
      // Add number to front of list
      if (this->HandleDLList) this->HandleDLList->Front(num);
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'B':
      // Add number to back of list
      if (this->HandleDLList) this->HandleDLList->Back(num);
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'E':
      // Eliminate all occurrences of number from list
      if (this->HandleDLList) this->HandleDLList->EliminateAll(num);
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'R':
      // Remove first occurrence of number from the list
      if (this->HandleDLList) this->HandleDLList->RemoveFirst(num);
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'G':
      // Get number from the list
      if (this->HandleDLList) this->HandleDLList->GetNum(num);
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'A':
      // Return contents of head node
      if (this->HandleDLList) this->HandleDLList->HeadContents();
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'Z':
      // Return contents of tail node
      if (this->HandleDLList) this->HandleDLList->TailContents();
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'T':
      // Pop the head node
      if (this->HandleDLList) this->HandleDLList->PopHead();
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'K':
      // Pop the tail node
      if (this->HandleDLList) this->HandleDLList->PopTail();
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'N':
      // Return the size of the list
      if (this->HandleDLList) this->HandleDLList->ListSize();
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    case 'P':
      // Print all items in the list
      if (this->HandleDLList) this->HandleDLList->PrintList();
      else cout << "MUST CREATE LIST INSTANCE\n";
      break;
    default:
      cout << "Invalid input.  Shouldn't be here.\n";
      break;
  }
};



// Create dynamic list instance
void Handler::Create() {
  this->HandleDLList = new DLList<int>();
  cout << "LIST CREATED\n";
};

// Constructor
template <typename T>
DLList<T>::DLList() {
  //Node<T>::created = 0;
  //Node<T>::destroyed = 0;

  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
};


// Destructor
template <typename T>
DLList<T>::~DLList() {
  this->Clear();
};

// Clear the current list instance of contents
template <typename T>
void DLList<T>::Clear() {
  Node<T>* temp = this->head;
  while(temp != nullptr) {
    Node<T>* temp1 = temp->next;
    delete temp;
    temp = temp1;
  }
  delete temp;
  temp = nullptr;
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
};


// Delete the dynamic list instance and set to nullptr
template <typename T>
void DLList<T>::Delete() {
  this->Clear();
};

// P 0  N   P  1  N   P 2  N
// n 10 1   0 20  2   1 30 n

// Insert number into list (sorted)
template <typename T>
void DLList<T>::Insert(T value) {
  Node<T>* temp = new Node<T>(value);
  if(this->size == 0) {
    cout << "FIRST VALUE\n";
    this->head = temp;
    this->tail = temp;
  } else {
    Node<T>* current = this->head;
    bool inserted = false;
    while(current != nullptr && inserted == false) {
      if (current->value >= temp->value) {
        // Insert before current
        temp->next = current;
        temp->prev = current->prev;
        current->prev = temp;
        if (current == this->head) {
          // New node becomes head
          this->head = temp;
        } else if (current->next == nullptr) {
          // New node
          this->tail = current;
        }
        inserted = true;
        break;
      } else if (current->next == nullptr && inserted == false) {
        // cout << "TEMP: " << temp->value << " LARGER THAN " << current->value << endl;
        // New node larger than all elements
        current->next = temp;
        temp->prev = current;
        temp->next = nullptr;
        this->tail = temp;
        inserted = true;
      }
      current = current->next;
    }
    //delete current;
    //current = nullptr;
  }
  this->size++;
  cout << "VALUE " << value << " INSERTED\n";
};

// Add number to front of list
template <typename T>
void DLList<T>::Front(T value) {
  Node<T>* temp = new Node<T>(value);
  if (this->size == 0) {
    this->tail = temp;
  } else {
    temp->next = this->head;
    this->head->prev = temp;
  }
  this->head = temp;
  this->size++;
  cout << "VALUE " << value << " ADDED TO HEAD\n";
};

// Add number to back of list
template <typename T>
void DLList<T>::Back(T value) {
  Node<T>* temp = new Node<T>(value);
  if (this->size == 0) {
    this->head = temp;
  } else {
    temp->prev = this->tail;
    this->tail->next = temp;
  }
  this->tail = temp;
  this->size++;
  cout << "VALUE " << value << " ADDED TO TAIL\n";
};

// Eliminate all occurrences of number from the list
template <typename T>
void DLList<T>::EliminateAll(T value) {
  if(this->size == 0) throw std::logic_error("LIST EMPTY");
  Node<T>* current = this->head;
  while(current != nullptr) {
    //cout << "CURRENT VALUE: " << current->value << endl;
    if (current->value == value) {
      // Delete Node
      //cout << "DELETING NODE\n";
      Node<T>* temp = current;
      current = current->next;
      if (temp->prev != nullptr) temp->prev->next = current;
      else this->head = current;
      if (temp->next != nullptr) temp->next->prev = temp->prev;
      else this->tail = current;
      delete temp;
      temp = nullptr;
      this->size--;
    } else {
      current = current->next;
    }
  }
  cout << "VALUE " << value << " ELIMINATED\n";
};

// Remove the first occurrence of number from the list
template <typename T>
void DLList<T>::RemoveFirst(T value) {
  if(this->size == 0) throw std::logic_error("LIST EMPTY");
  Node<T>* current = this->head;
  while(current != nullptr) {
    if (current->value == value) {
      // First occurrence detected
      current->next->prev = current->prev;
      current->prev->next = current->next;
      break;
    }
    current = current->next;
  }
  delete current;
  current = nullptr;
  this->size--;
  cout << "VALUE " << value << " REMOVED\n";
};

// Get number from the list
template <typename T>
void DLList<T>::GetNum(T value) {
  if(this->size == 0) throw std::logic_error("LIST EMPTY");
  Node<T>* current = this->head;
  bool found = false;
  while(current != nullptr && found == false) {
    if(current->value == value) {
      cout << "VALUE " << value << " FOUND\n";
      found = true;
    };
    current = current->next;
  }
  if (found == false) cout << "VALUE " << value << " NOT FOUND\n";
};

// Return contents of head node
template <typename T>
void DLList<T>::HeadContents() {
  if(this->size == 0) throw std::logic_error("LIST EMPTY");
  cout << "VALUE " << this->head->value << " AT HEAD\n";
};

// Return contents of tail node
template <typename T>
void DLList<T>::TailContents() {
  if(this->size == 0) throw std::logic_error("LIST EMPTY");
  cout << "VALUE " << this->tail->value << " AT TAIL\n";
};

// Pop the head node
template <typename T>
void DLList<T>::PopHead() {
  if(this->size == 0) throw std::logic_error("LIST EMPTY");
  Node<T>* temp = this->head;
  this->head = temp->next;
  this->head->prev = nullptr;
  delete temp;
  temp = nullptr;
  this->size--;
  cout << "REMOVED HEAD\n";
};

// Pop the tail node
template <typename T>
void DLList<T>::PopTail() {
  if(this->size == 0) throw std::logic_error("LIST EMPTY");
  Node<T>* temp = this->tail;
  this->tail = temp->prev;
  this->tail->next = nullptr;
  delete temp;
  temp = nullptr;
  this->size--;
  cout << "REMOVED TAIL\n";
};

// Return size of list
template <typename T>
void DLList<T>::ListSize() {
  cout << "LIST SIZE IS " << this->size << endl;
};

// Print all items in list
template <typename T>
void DLList<T>::PrintList() {
  Node<T>* current = this->head;
  if (this->size==0) cout << "LIST EMPTY";
  while(current != nullptr) {
    cout << current->value;
    if (current->next != nullptr) cout << ",";
    current = current->next;
  }
  cout << endl;
};
