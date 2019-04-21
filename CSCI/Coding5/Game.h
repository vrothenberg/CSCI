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
  const array[][] roomEnemyArray_ = {{1,2,3},
  {1,2,3},
  {1,2,3}}
  //Finish
  const array[] enemyArray_ = {
    {"Desperate Realtor", },
    {"Angry Snake"},
    {"Hypocritical Anarchist"},
    {""}
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
