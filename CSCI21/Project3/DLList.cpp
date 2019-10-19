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
      this->Delete();
      break;
    case 'I':
      // Insert number into list (sorted)
      this->Insert(num);
      break;
    case 'F':
      // Add number to front of list
      this->Front(num);
      break;
    case 'B':
      // Add number to back of list
      this->Back(num);
      break;
    case 'E':
      // Eliminate all occurrences of number from list
      this->EliminateAll(num);
      break;
    case 'R':
      // Remove first occurrence of number from the list
      this->RemoveFirst(num);
      break;
    case 'G':
      // Get number from the list
      this->GetNum(num);
      break;
    case 'A':
      // Return contents of head node
      this->HeadContents();
      break;
    case 'Z':
      // Return contents of tail node
      this->TailContents();
      break;
    case 'T':
      // Pop the head node
      this->PopHead();
      break;
    case 'K':
      // Pop the tail node
      this->PopTail();
      break;
    case 'N':
      // Return the size of the list
      this->ListSize();
      break;
    case 'P':
      // Print all items in the list
      this->PrintList();
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

// Clear the current list instance of contents
void Handler::Clear() {
  /*
  Node* temp = head;
  for (int i = 0; i < this->size; i++) {
    Node* temp1 = temp->next;
    delete temp;
    temp = temp1;
  }
  delete temp;
  temp = nullptr;
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
  */
  cout << "CLEAR\n";
};

// Delete the dynamic list instance and set to nullptr
void Handler::Delete() {
  this->HandleDLList->Clear();

};

// Insert number into list (sorted)
void Handler::Insert(int num) {
  cout << "INSERT\n";
};

// Add number to front of list
void Handler::Front(int num) {
  cout << "FRONT\n";
};

// Add number to back of list
void Handler::Back(int num) {
  cout << "BACK\n";
};

// Eliminate all occurrences of number from the list
void Handler::EliminateAll(int num) {
  cout << "ELIMINATE ALL\n";
};

// Remove the first occurrence of number from the list
void Handler::RemoveFirst(int num) {
  cout << "REMOVE FIRST\n";
};

// Get number from the list
void Handler::GetNum(int num) {
  cout << "GET NUM\n";

};

// Return contents of head node
void Handler::HeadContents() {
  cout << "VALUE \n";
  //<< this->head->value << "AT TAIL\n";
};

// Return contents of tail node
void Handler::TailContents() {
  cout << "VALUE \n";
  // << this->tail->value << "AT TAIL\n";
};

// Pop the head node
void Handler::PopHead() {
  cout << "POP HEAD\n";
};

// Pop the tail node
void Handler::PopTail() {
  cout << "POP TAIL\n";
};

// Return size of list
void Handler::ListSize() {
  cout << "LIST SIZE IS \n";
  //<< this->size << endl;
};

// Print all items in list
void Handler::PrintList() {
  /*
  Node* temp = head;
  ostringstream sout;
  for (int i = 0; i < this->size; i++) {
    sout << temp->value;
    if (temp->next != nullptr) {
      sout << ",";
      temp = temp->next;
    }
  }
  cout << sout.str();
  */
  cout << "PRINT\n";
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
  this->HandleDLList->Clear();

};

// Insert number into list (sorted)
template <typename T>
void DLList<T>::Insert(int num) {
  cout << "INSERT\n";
};

// Add number to front of list
template <typename T>
void DLList<T>::Front(int num) {
  cout << "FRONT\n";
};

// Add number to back of list
template <typename T>
void DLList<T>::Back(int num) {
  cout << "BACK\n";
};

// Eliminate all occurrences of number from the list
template <typename T>
void DLList<T>::EliminateAll(int num) {
  cout << "ELIMINATE ALL\n";
};

// Remove the first occurrence of number from the list
template <typename T>
void DLList<T>::RemoveFirst(int num) {
  cout << "REMOVE FIRST\n";
};

// Get number from the list
template <typename T>
void DLList<T>::GetNum(int num) {
  cout << "GET NUM\n";

};

// Return contents of head node
template <typename T>
void DLList<T>::HeadContents() {
  cout << "VALUE \n";
  //<< this->head->value << "AT TAIL\n";
};

// Return contents of tail node
template <typename T>
void DLList<T>::TailContents() {
  cout << "VALUE \n";
  // << this->tail->value << "AT TAIL\n";
};

// Pop the head node
template <typename T>
void DLList<T>::PopHead() {
  cout << "POP HEAD\n";
};

// Pop the tail node
template <typename T>
void DLList<T>::PopTail() {
  cout << "POP TAIL\n";
};

// Return size of list
template <typename T>
void DLList<T>::ListSize() {
  cout << "LIST SIZE IS \n" << this->size << endl;
};

// Print all items in list
template <typename T>
void DLList<T>::PrintList() {
  /*
  Node* temp = head;
  ostringstream sout;
  for (int i = 0; i < this->size; i++) {
    sout << temp->value;
    if (temp->next != nullptr) {
      sout << ",";
      temp = temp->next;
    }
  }
  cout << sout.str();
  */
  cout << "PRINT\n";
};
