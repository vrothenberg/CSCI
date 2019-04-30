#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

//Atom Gpp Compiler
//C++ compiler command line options:

// ********************************************************************
// CinReader.cpp Character.cpp Player.cpp Enemy.cpp Game.cpp System.cpp
// ********************************************************************

/*
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
*/

int main() {
  cout << "Launched.\n";
  Game newGame;
  newGame.Start();
  cout << "Game over!\n";

  return 0;
}
