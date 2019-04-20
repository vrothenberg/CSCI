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
  int number_;
  bool gameOver_;
  int roomNumber_;
  //Helper Functions
  void LoadRoom();

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




};

#endif
