//Header Guards
#ifndef ROTHENBERG_GAME_H
#define ROTHENBERG_GAME_H

#include <iostream>
#include <ctime>
#include "CinReader.h"
#include "Player.h"
using std::cout;
using std::endl;
using std::cerr;

class Game {
public:
  Game();
  void Start();
  Player newPlayer_;
  const array[][] roomEnemyArray_ = {
    //roomEnemyArray_[roomNumber_ - 4] = roomEnemies[]
    {0,1,3}, //Hall
    {1,2,2}, //Garden
    {0,1,3}, //Library
    {3,4,6}, //Basement
    {2,3,5}, //Cave
    {4,6,6}, //Utility
    {6,6,7}, //Tomb
}
  //Enemy types
  const array[] enemyArray_ = {
    {"Salty Squatter",       1, 10, 10, 1, 1, 1, 1, 1},
    {"Rude Realtor",         2, 20, 15, 2, 2, 1, 1, 2},
    {"Sneaky Snake",         3, 30, 10, 3, 1, 3, 1, 3},
    {"Avaricious Anarchist", 4, 40, 20, 4, 3, 3, 3, 4},
    {"Crazed Chemist",       5, 50, 25, 5, 3, 4, 5, 3},
    {"Guano Guy",            6, 60, 30, 5, 4, 3, 3, 4},
    {"Meth'd-out Mechanic",  8, 80, 40, 8, 8, 5, 4, 4},
    {"Big Guy ... For You", 10, 100, 100, 10, 10, 5, 5, 5}
  }

private:
  //Global variables

  bool gameOver_ = false;
  int roomNumber_ = 1;
  int gameTicks_ = 0;
  bool caveDiscovered_ = false;
  bool basementKey_ = false;

  //Helper Functions
  void LoadRoom(Player p);
  void Tick();
  void ClearScreen();
  void HUD(Player p);

  //Room Functions
  void Foyer();
  void SunRoom();
  void Office();
  void Hall();
  void Garden();
  void Library();
  void Basement();
  void Cave();
  void Utility();
  void Tomb();

  //Puzzle
  void LookAround();

};

#endif
