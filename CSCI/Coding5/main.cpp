#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "Battle.h"

//Atom Gpp Compiler
//C++ compiler command line options:

// Game.cpp Player.cpp Enemy.cpp Battle.cpp CinReader.cpp System.cpp Character.cpp

int main() {

  Game newGame;
  newGame.Start();

  cout << "Game over!\n";

  return 0;
}
