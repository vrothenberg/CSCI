//Header Guards
#ifndef ROTHENBERG_ENEMY_H
#define ROTHENBERG_ENEMY_H

#include <iostream>
#include "Character.h"

//EnemyType struct
//Stores name, taunts, and stats
struct EnemyType {
  string name = "Salty Squatter";
  string taunts[3] = {"Get outta here!\n", "This is my house now!\n", "I want hamborger!\n"};
  int attr[9] = {1, 10, 10, 1, 1, 1, 1, 1, 0};
};

//Multidimensional array of EnemyType Enemies based on room number
const int ROOM_ENEMY_ARRAY[7][3] = {
  {0,1,3}, //Hall
  {1,2,2}, //Garden
  {0,1,3}, //Library
  {3,4,6}, //Basement
  {2,3,5}, //Cave
  {4,6,6}, //Utility
  {7,7,7}, //Tomb
};

class Enemy : public Character {
public:
  //Constructors
  Enemy(int room, int difficulty);

  //Accessor
  string GetTaunt();

  //Static variable of possible enemies and stat values
  static EnemyType Enemies[8];

private:
  //Default Enemy member variable values
  string taunts_[3];
};

#endif
