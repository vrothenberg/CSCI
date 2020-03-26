#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Object Oriented Programming

Classes + Objects -> Encapsulation
Overloadding / Overriding -> Polymorphism
Inheritance (Flawed)
*/

// Incomplete
// class Being {
// public:
//   Being(): alive(true) {}
//
//   // In Java called an interface
//   virtual void beBorn() = 0;
//   virtual void die() = 0;
//   virtual bool isAlive() = 0;
//
// protected:
//   bool alive;
// };

class Animal /* : public Being */ {
public:
  Animal() {
    cout << "Animal::Animal()" << endl;
  }
  Animal(string name): name(name) {
    cout << "Animal::Animal(" << name << ")" << endl;
  }

  // IMPORTANT!  virtual prevents memory leaks
  // Descends down inheritance tree, calling destructors
  virtual ~Animal() {
    cout << "Animal::~Animal(" << name << ")" << endl;
  }

  virtual void print() {
    cout << "Animal -> " << name << endl;
  }

protected:
  string name;
};

// Never do this!
// class Pet {
//
// };

class Mammal : public Animal /*, public Pet */ {
public:
  Mammal() {
    cout << "Animal::Mammal" << endl;
  }

  Mammal(string name) : Animal(name) {
    cout << "Mammal::Mammal(" << name << ")" << endl;
  }

  ~Mammal() {
    cout << "Mammal::~Mammal(" << this->name << ")" << endl;
  }
  void print() {
    cout << "MAMMAL! -> " << this->name << endl;
  }
};

int main() {

  // Animal a1("snail");
  // a1.print();
  //
  // Mammal m1("tiger");
  // m1.print();

  vector<Animal*> zoo;

  zoo.push_back(new Mammal("gorilla"));
  zoo.push_back(new Animal("fish"));

  for (auto *a : zoo) {
    a->print();
  }

  for (size_t i=0; i < zoo.size(); i++) {
    delete zoo[i];
  }
  zoo.clear();




  return 0;
}
