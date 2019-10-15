#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;


struct Fruit {
  string name;
  int quantity;
};

int main () {
  vector<int> v1 = {10,20,30,40,50};

  //vector<int>::iterator i;
  //i = v1.begin();
  //cout << *i;

  /*
  for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
    cout << *i << endl;
  }

  for (auto i : v1) {
    cout << i << endl;
  }
  */


  vector<Fruit> basket = {
    Fruit{"apple", 1},
    Fruit{"apple", 2},
    Fruit{"banana", 2},
    Fruit{"oranges", 3},
    Fruit{"durian", 1},
    Fruit{"apple", 1},
  };

  vector<Fruit>::iterator i = basket.begin();
  cout << "The first fruit is: " << i->name << endl;

  for (Fruit f : basket) {
    cout << f.name << ' ';
  }
  cout << endl;

  for (int i = 0; i < basket.size(); i++) {
    if (basket[i].name == "durian") {
      basket.erase(basket.begin() + i);
      break;
    }
  }

  for (Fruit f : basket) {
    cout << f.name << ' ';
  }
  cout << endl;

  for (vector<Fruit>::iterator i = basket.begin(); i != basket.end(); i++) {
    if (i->name == "apple") {
      basket.erase(i);
      i--;
    }
  }

  for (Fruit f : basket) {
    cout << f.name << ' ';
  }
  cout << endl;



  return 0;
}
