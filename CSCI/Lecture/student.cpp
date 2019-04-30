#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/*
 * This class holds information about a student, namely their name and a list
 * of their classes.
 */
class Student {
 public:
  /*
   * Constructor
   * 1) Sets name_ to its parameter
   * 2) Sets num_classes_ to its parameter
   * 3) Creates a dynamic string array and stores in class_list_
   */
  Student(string name, int num_classes);

  /*
   * Destructor
   * Frees the memory associated with the dynamic string array
   */
  ~Student();

  /*
   * Accessor for name_
   */
  string name();

  /*
   * Accessor for num_classes_
   */
  int num_classes();

  /*
   * Mutator for name_
   */
  void set_name(string name);

  /*
   * Loops through the dynamic array and asks the student for the name of their
   * classes. Stores each class in its own element of the array
   */
  void SetupClasses();

  /*
   * Outputs the student's name and their classes, comma separated.
   */
  void OutputClassList();
 private:
  string name_;
  int num_classes_;
  string *class_list_;
};

// To Test
int main() {

  Student me("John Doe", 4);
  cout << me.name() << " has " << me.num_classes() << " classes." << endl;
  cout << "Changing John -> Jane" << endl;
  me.set_name("Jane Doe");
  me.SetupClasses();
  me.OutputClassList();


  return 0;
}


// Member Function Definitions
// CODE HERE
Student::Student(string name, int num_classes) {
  name_ = name;
  num_classes_ = num_classes;
  class_list_ = new string[num_classes_];
}

/*
 * Destructor
 * Frees the memory associated with the dynamic string array
 */
Student::~Student() {
  delete[] class_list_;
  class_list_ = NULL;
}

/*
 * Accessor for name_
 */
string Student::name() {
  return name_;
}

/*
 * Accessor for num_classes_
 */
int Student::num_classes() {
  return num_classes_;
}

/*
 * Mutator for name_
 */
void Student::set_name(string name) {
  name_ = name;
}

/*
 * Loops through the dynamic array and asks the student for the name of their
 * classes. Stores each class in its own element of the array
 */
void Student::SetupClasses() {
  for (int i = 0; i < num_classes_; i++) {
    cout << "Enter class #" << i+1 << endl;
    cin >> class_list_[i];
  }
}

/*
 * Outputs the student's name and their classes, comma separated.
 */
void Student::OutputClassList() {
  for (int i = 0; i < num_classes_ - 1; i++) {
    cout << class_list_[i] << ", ";
  }
  cout << class_list_[num_classes_ - 1] << endl;
}
