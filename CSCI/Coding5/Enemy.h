//Header Guards
#ifndef ROTHENBERG_ENEMY_H
#define ROTHENBERG_ENEMY_H

#include <iostream>
#include "CinReader.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;

class Enemy : public Player {
public:
  Enemy();
private:
  string name_;
  string role_;
  int level_;
  int experience_;
  int health_;
  int attack_;
  int armor_;
};

#endif
