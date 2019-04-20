//Header Guards
#ifndef ROTHENBERG_GAME_H
#define ROTHENBERG_GAME_H

#include <iostream>
#include "CinReader.h"
using std::cout;
using std::endl;
using std::cerr;

class Game {
public:
  Game();
  void Start();

private:
  //Global variables

  bool gameOver_ = false;
  int roomNumber_ = 1;
  int gameTicks_ = 0;
  bool caveDiscovered_ = false;

  //Helper Functions
  void LoadRoom();
  void Tick();
  void ClearScreen();

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
