//Header Guards
#ifndef ROTHENBERG_ENEMY_H
#define ROTHENBERG_ENEMY_H

#include <iostream>
#include "Character.h"

struct EnemyType {
  string name = "Salty Squatter";
  string taunts[3] = {"Get outta here!\n", "This is my house now!\n", "I want hamborger!\n"};
  int attr[8] = {1, 10, 10, 1, 1, 1, 1, 1};
};

const int ROOM_ENEMY_ARRAY[7][3] = {
  //roomEnemyArray_[roomNumber_ - 4] = roomEnemies[]
  {0,1,3}, //Hall
  {1,2,2}, //Garden
  {0,1,3}, //Library
  {3,4,6}, //Basement
  {2,3,5}, //Cave
  {4,6,6}, //Utility
  {6,6,7}, //Tomb
};

class Enemy : public Character {
public:
  //Constructors
  Enemy(int room, int difficulty);
  //Static variable
  static EnemyType Enemies[8];

private:
  //Default Enemy member variable values
  string role_;
  string taunts_[3];
  int level_;
  int experience_;
  int wealth_;
  int health_;
  int attack_;
  int armor_;
  int dexterity_;
  int intelligence_;
  int speed_;
};

#endif
