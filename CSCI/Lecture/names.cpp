/*
 * Name          : Vince Rothenberg
 * Description   : Final Review
 */

#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::string;
using std::cin;

/*
 * This class represents a dynamic array to hold names.
 * The size of the array will be dynamic.
 */
class Names {
 public:
  /*
   *  Constructor
   *  Create a dynamic string array of the given capacity. If the the capacity
   *  is invalid (i.e. capacity < 1), set the capacity to be 10. Also sets the
   *  size_ member variable to be 0 and capacity_ to the given capacity.
   *  @param int capacity - The capacity of the dynamic string array. Should
   *                        also set the capacity_ member variable to this
   *                        value. If capacity is invalid, use a capacity of 10
   */
  Names(int capacity);

  /*
   * Destructor
   * Cleans-Up after any dynamically created variables (i.e. the dynamic array)
   */
  ~Names();

  /*
   * Member Function Capitalize()
   * Capitalizes the string parameter (by-reference).
   * The first character in the string and any character after a space should be
   * UPPERCASE. All other characters should be lowercase.
   */
  void Capitalize(string &to_capitalize);

  /*
   * Member Function AddName()
   * Adds the string parameter to the first avaiable spot in the array (i.e. size_)
   * Also capitalizes the string.  Use the Capitalize() member function.
   * If the string is empty DO NOT add the string to the array.
   * If the array is FULL DO NOT add the string to the array.
   * This function should also increase the size_ member variable by 1.
   * @param string name - The name to add to the array. If empty, DO NOT ADD
   * @uses Capitalize()
   */
  void AddName(string name);

  /*
   * Member Function ShuffleNames()
   * Shuffles ALL of the names in the array
   * @uses rand()
   */
  void ShuffleNames();

  /*
   * Member Function OutputNames()
   * Outputs all names in the array, comma separated, via cout.
   * You SHOULD output a newline at the end of output
   */
  void OutputNames();

  /*
   * Accessor for capacity_
   */
  int capacity();

  /*
   * Accessor for size_
   */
  int size();

 private:
  // A pointer for your dynamic array
  string *names_;
  // To hold the capacity of the array
  int capacity_;
  // The hold the current size of the array
  int size_;
};

// main() is for testing. DO NOT ALTER
int main() {
  // Setup the Random Number Generator
  srand(time(0));

  // Setup our Variables
  Names names(15);
  Names wrong(0);
  Names negative(-5);

  // Testing Constructor and Accessors
  cout << "Testing Constructor and Accessors\n"
       << "---------------------------------------------------------\n";
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test Names(15) && capacity()" << endl;
  cout << ((names.size() == 0) ? "Passed" : "Failed")
       << " Test Names(15) && size()" << endl;
  cout << ((wrong.capacity() == 10) ? "Passed" : "Failed")
       << " Test Names(0) && capacity()" << endl;
  cout << ((wrong.size() == 0) ? "Passed" : "Failed")
       << " Test Names(0) && size()" << endl;
  cout << ((negative.capacity() == 10) ? "Passed" : "Failed")
       << " Test Names(-5) && capacity()" << endl;
  cout << ((negative.size() == 0) ? "Passed" : "Failed")
       << " Test Names(-5) && size()" << endl;




  // Testing Capitalize()
  cout << "\n\nTesting Capitalize\n"
       << "---------------------------------------------------------\n";
  string to_capitalize = "hello world";
  string orig = to_capitalize;
  names.Capitalize(to_capitalize);
  string correct = "Hello World";
  if (to_capitalize == correct) {
    cout << "Passed Test Capitalize(\"" << orig << "\")" << endl;
  } else {
    cout << "Failed Test Capitalize(\"" << orig << "\")" << endl;
    cout << "Yours:   " << to_capitalize << endl;
    cout << "Correct: " << correct << endl;
  }

  orig = to_capitalize = "hELLO wORLD";
  names.Capitalize(to_capitalize);
  correct = "Hello World";
  if (to_capitalize == correct) {
    cout << "Passed Test Capitalize(\"" << orig << "\")" << endl;
  } else {
    cout << "Failed Test Capitalize(\"" << orig << "\")" << endl;
    cout << "Yours:   " << to_capitalize << endl;
    cout << "Correct: " << correct << endl;
  }

  orig = to_capitalize = "fOO";
  names.Capitalize(to_capitalize);
  correct = "Foo";
  if (to_capitalize == correct) {
    cout << "Passed Test Capitalize(\"" << orig << "\")" << endl;
  } else {
    cout << "Failed Test Capitalize(\"" << orig << "\")" << endl;
    cout << "Yours:   " << to_capitalize << endl;
    cout << "Correct: " << correct << endl;
  }

  orig = to_capitalize = "a bb ccc dddd eeee ffff&gggg";
  names.Capitalize(to_capitalize);
  correct = "A Bb Ccc Dddd Eeee Ffff&gggg";
  if (to_capitalize == correct) {
    cout << "Passed Test Capitalize(\"" << orig << "\")" << endl;
  } else {
    cout << "Failed Test Capitalize(\"" << orig << "\")" << endl;
    cout << "Yours:   " << to_capitalize << endl;
    cout << "Correct: " << correct << endl;
  }




  // Testing AddName()
  cout << "\n\nTesting AddName() && OutputNames()\n"
       << "---------------------------------------------------------\n";
  orig = "Foo";
  names.AddName(orig);


  cout << ((names.size() == 1) ? "Passed" : "Failed")
       << " Test AddName(\"" << orig << "\") && size()" << endl;
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test capacity()" << endl;
  cout << "Testing OutputNames()\nYour Names  : ";
  names.OutputNames();



  cout << "Should Match: Foo\n\n";



  orig = "Bar";
  names.AddName(orig);
  cout << ((names.size() == 2) ? "Passed" : "Failed")
       << " Test AddName(\"" << orig << "\") && size()" << endl;
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test capacity()" << endl;
  cout << "Testing OutputNames()\nYour Names  : ";
  names.OutputNames();
  cout << "Should Match: Foo, Bar\n\n";

  orig = "john doe";
  names.AddName(orig);
  cout << ((names.size() == 3) ? "Passed" : "Failed")
       << " Test AddName(\"" << orig << "\") && size()" << endl;
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test capacity()" << endl;
  cout << "Testing OutputNames()\nYour Names  : ";
  names.OutputNames();
  cout << "Should Match: Foo, Bar, John Doe\n\n";

  orig = "jANE dOE";
  names.AddName(orig);
  cout << ((names.size() == 4) ? "Passed" : "Failed")
       << " Test AddName(\"" << orig << "\") && size()" << endl;
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test capacity()" << endl;
  cout << "Testing OutputNames()\nYour Names  : ";
  names.OutputNames();
  cout << "Should Match: Foo, Bar, John Doe, Jane Doe\n\n";

  orig = "";
  names.AddName(orig);
  cout << ((names.size() == 4) ? "Passed" : "Failed")
       << " Test AddName(\"" << orig << "\") && size()" << endl;
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test capacity()" << endl;
  cout << "Testing OutputNames()\nYour Names  : ";
  names.OutputNames();
  cout << "Should Match: Foo, Bar, John Doe, Jane Doe\n\n";


  names.AddName("5");
  names.AddName("6");
  names.AddName("7");
  names.AddName("8");
  names.AddName("9");
  names.AddName("10");
  names.AddName("11");
  names.AddName("12");
  names.AddName("13");
  names.AddName("14");
  names.AddName("15");
  cout << ((names.size() == 15) ? "Passed" : "Failed")
       << " Test AddName(\"" << orig << "\") && size()" << endl;
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test capacity()" << endl;
  cout << "Testing OutputNames()\nYour Names  : ";
  names.OutputNames();
  cout << "Should Match: Foo, Bar, John Doe, Jane Doe, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15\n\n";

  orig = "Too Many";
  names.AddName(orig);
  cout << ((names.size() == 15) ? "Passed" : "Failed")
       << " Test AddName(\"" << orig << "\") && size()" << endl;
  cout << ((names.capacity() == 15) ? "Passed" : "Failed")
       << " Test capacity()" << endl;
  cout << "Testing OutputNames()\nYour Names  : ";
  names.OutputNames();
  cout << "Should Match: Foo, Bar, John Doe, Jane Doe, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15\n\n";


  // Testing Capitalize()
  cout << "\n\nTesting ShuffleNames()\n"
       << "---------------------------------------------------------\n";
  names.ShuffleNames();
  names.OutputNames();
  names.ShuffleNames();
  names.OutputNames();
  names.ShuffleNames();
  names.OutputNames();
  names.ShuffleNames();
  names.OutputNames();
  names.ShuffleNames();
  names.OutputNames();
  names.ShuffleNames();
  names.OutputNames();
  names.ShuffleNames();
  names.OutputNames();
}


/*
 * DEFINE MEMBER FUNCTIONS HERE
 */


  /*
   *  Constructor
   *  Create a dynamic string array of the given capacity. If the the capacity
   *  is invalid (i.e. capacity < 1), set the capacity to be 10. Also sets the
   *  size_ member variable to be 0 and capacity_ to the given capacity.
   *  @param int capacity - The capacity of the dynamic string array. Should
   *                        also set the capacity_ member variable to this
   *                        value. If capacity is invalid, use a capacity of 10
   */
  Names::Names(int capacity) {
    if (capacity < 1) capacity = 10;
    capacity_ = capacity;
    names_ = new string[capacity_];
    size_ = 0;
  }

  /*
   * Destructor
   * Cleans-Up after any dynamically created variables (i.e. the dynamic array)
   */
  Names::~Names() {
    delete[] names_;
  }

  /*
   * Member Function Capitalize()
   * Capitalizes the string parameter (by-reference).
   * The first character in the string and any character after a space should be
   * UPPERCASE. All other characters should be lowercase.
   */
  void Names::Capitalize(string &to_capitalize) {
    for (int i = 0; i < to_capitalize.length(); i++) {
      to_capitalize.at(i) = tolower(to_capitalize.at(i));
    }
    to_capitalize.at(0) = toupper(to_capitalize.at(0));
    for (int i = 1; i < to_capitalize.length(); i++) {
      if (to_capitalize.at(i) == ' ')
        to_capitalize.at(i+1) = toupper(to_capitalize.at(i+1));
    }
  }

  /*
   * Member Function AddName()
   * Adds the string parameter to the first avaiable spot in the array (i.e. size_)
   * Also capitalizes the string.  Use the Capitalize() member function.
   * If the string is empty DO NOT add the string to the array.
   * If the array is FULL DO NOT add the string to the array.
   * This function should also increase the size_ member variable by 1.
   * @param string name - The name to add to the array. If empty, DO NOT ADD
   * @uses Capitalize()
   */
  void Names::AddName(string name) {
    if (name.length() > 0 && size() < capacity()) {
      Capitalize(name);
      names_[size()] = name;
      size_++;
    }

  }

  /*
   * Member Function ShuffleNames()
   * Shuffles ALL of the names in the array
   * @uses rand()
   */
  void Names::ShuffleNames() {
    for (int i = 0; i < size(); i++) {
      int pos = rand() % size();
      string temp = names_[i];
      names_[i] = names_[pos];
      names_[pos] = temp;
    }
  }

  /*
   * Member Function OutputNames()
   * Outputs all names in the array, comma separated, via cout.
   * You SHOULD output a newline at the end of output
   */
  void Names::OutputNames() {
    if (size() > 0) {
      if (size() > 2) {
        for (int i = 0; i < size() - 1; i++) {
          cout << names_[i] << ", ";
        }
      cout << names_[size() - 1] << endl;
      }
    }
  }

  /*
   * Accessor for capacity_
   */
  int Names::capacity() {
    return capacity_;
  }

  /*
   * Accessor for size_
   */
  int Names::size() {
    return size_;
  }
