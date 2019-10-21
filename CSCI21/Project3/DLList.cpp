#include "DLList.h"

Handler::Handler(string file) {
  this->file = file;

}

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
        } while (pos!=-1 );

        Operation(opLine);

        /*
        for(string s : opLine){
          cout << s << " ";
        }
        cout << endl;
        */

      } catch (const std::exception &e) {
        // Shouldn't occur normally
        cout << "ERROR!\n";
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
      this->Create();
      break;
    case 'X':
      // Clear current list instance of contents
      this->HandleDLList->Clear();
      break;
    case 'D':
      // Delete dynamic list and set to nullptr
      this->HandleDLList->Delete();
      break;
    case 'I':
      // Insert number into list (sorted)
      this->HandleDLList->Insert(num);
      break;
    case 'F':
      // Add number to front of list
      this->HandleDLList->Front(num);
      break;
    case 'B':
      // Add number to back of list
      this->HandleDLList->Back(num);
      break;
    case 'E':
      // Eliminate all occurrences of number from list
      this->HandleDLList->EliminateAll(num);
      break;
    case 'R':
      // Remove first occurrence of number from the list
      this->HandleDLList->RemoveFirst(num);
      break;
    case 'G':
      // Get number from the list
      this->HandleDLList->GetNum(num);
      break;
    case 'A':
      // Return contents of head node
      this->HandleDLList->HeadContents();
      break;
    case 'Z':
      // Return contents of tail node
      this->HandleDLList->TailContents();
      break;
    case 'T':
      // Pop the head node
      this->HandleDLList->PopHead();
      break;
    case 'K':
      // Pop the tail node
      this->HandleDLList->PopTail();
      break;
    case 'N':
      // Return the size of the list
      this->HandleDLList->ListSize();
      break;
    case 'P':
      // Print all items in the list
      this->HandleDLList->PrintList();
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
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
};

template <typename T>
DLList<T>::~DLList() {
  this->Clear();
}

template <typename T>
void DLList<T>::Clear() {
  this->head = nullptr;
  this->tail = nullptr;
}


// Delete the dynamic list instance and set to nullptr
template <typename T>
void DLList<T>::Delete() {
  this->Clear();

};

// Insert number into list (sorted)
template <typename T>
void DLList<T>::Insert(T value) {
  cout << "INSERT\n";
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
  if(this->size == 0) throw std::logic_error("EMPTY LIST");
  Node<T>* temp = this->head;
  while(temp != nullptr) {
    cout << temp->value;
    temp = temp->next;
  }
  cout << "ELIMINATE ALL\n";
};

// Remove the first occurrence of number from the list
template <typename T>
void DLList<T>::RemoveFirst(T value) {
  if(this->size == 0) throw std::logic_error("EMPTY LIST");
  cout << "REMOVE FIRST\n";
};

// Get number from the list
template <typename T>
void DLList<T>::GetNum(T value) {
  if(this->size == 0) throw std::logic_error("EMPTY LIST");
  cout << "GET NUM\n";

};

// Return contents of head node
template <typename T>
void DLList<T>::HeadContents() {
  if(this->size == 0) throw std::logic_error("EMPTY LIST");
  cout << "VALUE " << this->head->value << " AT HEAD\n";
};

// Return contents of tail node
template <typename T>
void DLList<T>::TailContents() {
  if(this->size == 0) throw std::logic_error("EMPTY LIST");
  cout << "VALUE " << this->tail->value << " AT TAIL\n";
};

// Pop the head node
template <typename T>
void DLList<T>::PopHead() {
  if(this->size == 0) throw std::logic_error("EMPTY LIST");
  cout << "POP HEAD\n";
};

// Pop the tail node
template <typename T>
void DLList<T>::PopTail() {
  if(this->size == 0) throw std::logic_error("EMPTY LIST");
  cout << "POP TAIL\n";
};

// Return size of list
template <typename T>
void DLList<T>::ListSize() {
  cout << "LIST SIZE IS " << this->size << endl;
};

// Print all items in list
template <typename T>
void DLList<T>::PrintList() {
  Node<T>* temp = this->head;
  while(temp != nullptr) {
    cout << temp->value;
    if (temp->next != nullptr) cout << ",";
    temp = temp->next;
  }
};
