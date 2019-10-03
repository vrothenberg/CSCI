// Cereal class with driver to test basic functionality
//
// Programmer: Vince Rothenberg <vrothenberg@gmail.com>
// Date completed: 24 Sep 2019
//
// References: Stack Overflow

#include <iostream>
#include <string>

using namespace std;

// Cereal represents a box of cereal.
class Cereal {
public:
  //Cereal constructor
  Cereal(string name = "Nameless", string brand = "NoBrand", double servingSize = 0,
         unsigned int calsPerServing = 0, bool hasToy = false) {

    this->name = name;
    this->brand = brand;
    this->servingSize = servingSize;
    this->calsPerServing = calsPerServing;
    this->hasToy = hasToy;


  }

  // setName overwrites Cereal name with new value.
  // If name == "Cheerios", nothing is done.
  setName(string name) {
    if (name != "Cheerios") {
      this->name = name;
    }
  }
  setBrand(string brand);
  setServingSize(double serving);
  setCalsPerServing(unsigned int cals);
private:
  string name;
  string brand;
  double servingSize;
  unsigned int calsPerServing;
  bool hasToy;
};

int main() {
  Cereal c1;
  //Should fail
  c1.setName("Cheerios");
  //Should work
  Cereal c2;
  c2.setName("Not Cheerios");

  Cereal c3("Cheerios", "General Mills", 3.14, 200, false);

  Cereal c4;


  return 0;
}
