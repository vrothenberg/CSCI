#include "DLList.h"

void Handler::ReadFile(string file) {

  ifstream fin(file);
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
  char op = opLine[0].c_str();
  switch(op) {
    case '#':
      // Comment
      break;
    case 'C':
      // Create dynamic list instance
      this->myList.Create();


      break;
    case 'X':
      // Clear current list instance of contents
      break;
    case 'D':
      // Delete dynamic list and set to nullptr
      break;
    case 'I':
      // Insert number into list (sorted)
      break;
    case 'F':
      // Add number to front of list
      break;
    case 'B':
      // Add number to back of list
      break;
    case 'E':
      // Eliminate all occurrences of number from list
      break;
    case 'R':
      // Remove first occurrence of number from the list
      break;
    case 'G':
      // Get number from the list
      break;
    case 'A':
      // Return contents of head node
      break;
    case 'Z':
      // Return contents of tail node
      break;
    case 'T':
      // Pop the head node
      break;
    case 'K':
      // Pop the tail node
      break;
    case 'N':
      // Return the size of the list
      break;
    case 'P':
      // Print all items in the list
      break;
    default:
      cout << "Invalid input.  Shouldn't be here.\n";
      break;
  }
};


// Constructor
DLList::DLList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
};

DLList::~SList() {
  this->Clear();
}

// Create dynamic list instance
void DLList::Create() {
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
  cout << "LIST CREATED\n";
};

// Clear the current list instance of contents
void DLList::Clear() {
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
  cout <<
};

// Delete the dynamic list instance and set to nullptr
void DLList::Delete() {
  this->Clear();

};

// Insert number into list (sorted)
void DLList::Insert(int num);

// Add number to front of list
void DLList::Front(int num);

// Add number to back of list
void DLList::Back(int num);

// Eliminate all occurrences of number from the list
void DLList::EliminateAll(int num);

// Remove the first occurrence of number from the list
void DLList::RemoveFirst(int num);

// Get number from the list
void DLList::GetNum(int num) {

};

// Return contents of head node
void DLList::HeadContents() {
  cout << "VALUE " << this->head->value << "AT TAIL\n";
};

// Return contents of tail node
void DLList::TailContents() {
  cout << "VALUE " << this->tail->value << "AT TAIL\n";
};

// Pop the head node
void DLList::PopHead();

// Pop the tail node
void DLList::PopTail();

// Return size of list
void DLList::ListSize() {
  cout << "LIST SIZE IS " << this->size << endl;
};

// Print all items in list
void DLList::PrintList() {
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
};
