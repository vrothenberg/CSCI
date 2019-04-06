// OPENING HEADER COMMENTS GO HERE
// HEADER GUARDS GO HERE
#ifndef ROTHENBERG_DOUBLELIST_H
#define ROTHENBERG_DOUBLELIST_H
// NEEDED INCLUDES GO HERE
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

// CLASS DESCRIPTION GOES HERE
class DoubleList {
 public:
   // PUBLIC MEMBER FUNCTIONS GO HERE
   DoubleList();
   int GetSize();
   double GetItem(int position);
   double Sum();
   double Average();
   double Max();
   void Output();
   void Insert(double value);
   void Clear();


 private:
  // This creates a constant to use for the size of the array, i.e. the maximum
  // capacity of the list
  static const int kListCapacity = 10;
  // Create an Array of size kListCapacity.
  // CODE TO CREATE THE ARRAY GOES HERE
  double dList_[kListCapacity];

  // Create a variable to hold the current size of the list. Note this means
  // how many elements are being used in the array, not how many values it can
  // hold
  // CODE TO CREATE THE CURRENT SIZE VARIABLE
  int dListSize_ = 0;


};

#endif
