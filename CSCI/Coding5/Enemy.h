//Header Guards
#ifndef ROTHENBERG_ENEMY_H
#define ROTHENBERG_ENEMY_H

#include <iostream>
#include "Player.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;

/*
struct EnemyTypes {
  struct Squatter {
    string name = "Salty Squatter";
    string taunts[3] = {"Get outta here!\n", "This is my house now!\n", "I want hamborger!\n"};
    int attributes[8] = {1, 10, 10, 1, 1, 1, 1, 1};
   };
};
*/

class Enemy : public Player {
public:
  //Constructors
  Enemy();
  Enemy(int room, int difficulty);

private:
  //Default Enemy member variable values
  string role_ = "Squatter";
  string taunts_[3] = {"Words!\n", "Taunt!\n", "Yelling!\n"};
  int level_ = 1;
  int experience_ = 10;
  int wealth_ = 10;
  int health_ = 10;
  int attack_ = 1;
  int armor_ = 1;
  int dexterity_ = 1;
  int intelligence_ = 1;
  int speed_ = 1;
};

#endif
