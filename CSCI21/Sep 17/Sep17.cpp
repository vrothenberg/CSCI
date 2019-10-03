#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

struct Color {
  unsigned int red;
  unsigned int green;
  unsigned int blue;
};

struct Rectangle {
  unsigned int width;
  unsigned int height;
  Color color;

};

string toString(const Color &c) {
  stringstream strout;
  strout << "(" << c.red <<"," << c.green << "," << c.blue << ")";
  return strout.str();
}


string toString(const Rectangle &r) {
  stringstream strout;

  strout << "rect: width=" << r.width << ", height=" << r.height << ", color=";
  strout << toString(r.color);

  return strout.str();
}

void setWidth(Rectangle &r, unsigned int width) {
  if (width > 0) {
    r.width = width;
  }
}

void setHeight(Rectangle &r, unsigned int height) {
  if (height > 0) {
    r.height = height;
  }
}

unsigned int area(const Rectangle &r) {
  return r.width * r.height;
}



int main () {
  Color c1 = {255, 0, 0};
  Rectangle r1 = {5, 5, c1};
  Rectangle r2 = {5, 10, {0, 255, 0}};
  cout << toString(r2) << endl;

  return 0;
}
