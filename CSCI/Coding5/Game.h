//Header Guards
#ifndef ROTHENBERG_GAME_H
#define ROTHENBERG_GAME_H

#include <iostream>
#include <ctime>
#include "CinReader.h"
#include "Player.h"
#include "Enemy.h"

using std::cout;
using std::endl;
using std::cerr;

class Game {
public:
  Game();
  void Start();
  Player newPlayer_;

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
  void Foyer(Player p);
  void SunRoom(Player p);
  void Office(Player p);
  void Hall(Player p);
  void Garden(Player p);
  void Library(Player p);
  void Basement(Player p);
  void Cave(Player p);
  void Utility(Player p);
  void Tomb(Player p);

  //Puzzle
  void LookAround(Player p);

};

#endif
