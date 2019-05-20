//Header Guards
#ifndef ROTHENBERG_BATTLE_H
#define ROTHENBERG_BATTLE_H

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "Enemy.h"
#include "Player.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;

class Battle {
public:
  Battle(Player& p, int room);
  Battle(Player& p, Enemy& e);
  void BattleLoop(Player& p, Enemy& e);
  void EnemyAttack(Enemy& e, Player& p, bool block, bool deflect);
  void PlayerAttack(Player& p, Enemy& e, bool block);
  void Sophistry(Player& p, Enemy& e);
  void AddMessage(string s);
  void PrintMessages();


private:
  int round_ = 0;
  bool battleOver = false;
  string messages_ = "";

};

#endif
