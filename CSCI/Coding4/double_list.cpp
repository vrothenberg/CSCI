#include "double_list.h"

// The second part of creating a constant for our class
const int DoubleList::kListCapacity;

// YOUR MEMBER FUNCTION DEFINITIONS GO HERE

//Default Constructor
//Initializes the list to zeroes.
DoubleList::DoubleList() {
  for (int i = 0; i < kListCapacity; i++) {
    dList_[i] = 0;
  }
}

//Returns number of added items.
int DoubleList::GetSize() {
  return dListSize_;
}

//Returns the double value at the given location.
//Abstracts indexing allowing user to input 1 for first element
double DoubleList::GetItem(int position) {
  position--;
  if (position >= 0 && position < kListCapacity) {
    return dList_[position];
  } else {
    cerr << "No Item At Location";
    return 0;
  }
}

//Returns the sum of values in list
//Outputs error if list empty
double DoubleList::Sum() {
  double sum = 0;
  if (dListSize_ > 0) {
    for(int i = 0; i < dListSize_; i++) {
      sum += dList_[i];
    }
    return sum;
  } else {
    cerr << "List Empty";
  }
}

//Returns the average value of the list
//Outputs error if list empty
double DoubleList::Average() {
  if (dListSize_ > 0) {
    double sum = 0;
    for (int i = 0; i < dListSize_; i++) {
      sum += dList_[i];
    }
    return sum/dListSize_;
  } else {
    cerr << "List Empty";
  }
}

//Returns the maximum value in list
double DoubleList::Max() {
  if (dListSize_ > 0) {
    double max = dList_[0];
    for (int i = 0; i < dListSize_; i++) {
      if (dList_[i] > max) {
        max = dList_[i];
      }
    }
    return max;
  } else {
    cerr << "List Empty";
  }
}

//Outputs a comma separated list of current values
void DoubleList::Output() {
  if (dListSize_ > 0) {
    for (int i = 0; i < dListSize_; i++) {
      cout << dList_[i];
      if (i < dListSize_ - 1) {
        cout << ", ";
      }
    }
  } else {
    cerr << "List Empty";
  }
}

//Mutators
//Adds an item to the end of the list.
//Outputs error if list is full
void DoubleList::Insert(double value) {
  if (dListSize_ >= kListCapacity) {
    cerr << "List Full";
  } else {
    dList_[dListSize_] = value;
    dListSize_++;
  }
}

//Resets all values in list to 0
void DoubleList::Clear() {
  for (int i = 0; i < dListSize_; i++) {
    dList_[i] = 0;
  }
  dListSize_ = 0;
}
