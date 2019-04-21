#include <iostream>
#include "Game.h"
#include "Enemy.h"
#include "Player.h"


const int array[][] ROOM_ENEMY_ARRAY = {
  //roomEnemyArray_[roomNumber_ - 4] = roomEnemies[]
  {0,1,3}, //Hall
  {1,2,2}, //Garden
  {0,1,3}, //Library
  {3,4,6}, //Basement
  {2,3,5}, //Cave
  {4,6,6}, //Utility
  {6,6,7}, //Tomb
}

const array[] ENEMY_ARRAY = {
  //Enemy types
  {"Salty Squatter",       1, 10, 10, 1, 1, 1, 1, 1},
  {"Rude Realtor",         2, 20, 15, 2, 2, 1, 1, 2},
  {"Sneaky Snake",         3, 30, 10, 3, 1, 3, 1, 3},
  {"Avaricious Anarchist", 4, 40, 20, 4, 3, 3, 3, 4},
  {"Crazed Chemist",       5, 50, 25, 5, 3, 4, 5, 3},
  {"Guano Guy",            6, 60, 30, 5, 4, 3, 3, 4},
  {"Methy Mechanic",       8, 80, 40, 8, 8, 5, 4, 4},
  {"Big Guy ... For You",  9, 99, 99, 9, 9, 5, 5, 5}
}
/

int main() {

  //Player newPlayer;
  Enemy newEnemy();
  /*

  Game newGame;
  newGame.Start();
  cout << "Game over!" << endl;
  */

  return 0;
}
