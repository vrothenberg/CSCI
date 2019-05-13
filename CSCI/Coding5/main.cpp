#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "Battle.h"

//Atom Gpp Compiler
//C++ compiler command line options:

// ********************************************************************
// CinReader.cpp Character.cpp Player.cpp Enemy.cpp Game.cpp System.cpp
// ********************************************************************

// Game.cpp Player.cpp Enemy.cpp Battle.cpp CinReader.cpp System.cpp Character.cpp

int main() {
  /*

  Player p;
  Enemy e(2,2);
  ClearScreen();

  Battle b(p,e);
  */

  Game newGame;
  newGame.Start();

  cout << "Game over!\n";
  
  return 0;
}
