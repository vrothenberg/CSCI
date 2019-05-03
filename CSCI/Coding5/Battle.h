//Header Guards
#ifndef ROTHENBERG_BATTLE_H
#define ROTHENBERG_BATTLE_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include "Enemy.h"
#include "Player.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;

class Battle {
public:
  Battle();
  Battle(Player p, Enemy e);
  int EnemyAttack(Enemy& e, Player& p, bool block);
  int PlayerAttack(Player& p, Enemy& e, bool block);

private:
  int round_ = 0;
  bool battleOver = false;

};

#endif
