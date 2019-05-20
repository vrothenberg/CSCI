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
  //Constructors

  //Creates 1 of 3 possible enemies based on room number
  Battle(Player& p, int room);

  //Starts a battle using provided player and enemy objects
  Battle(Player& p, Enemy& e);

  //Primary loop, halts if player or enemy health drops below 1
  void BattleLoop(Player& p, Enemy& e);

  //Enemy attack function, enemy and player objects passed by reference
  //Player block and deflect actions must be provided
  void EnemyAttack(Enemy& e, Player& p, bool block, bool deflect);

  //Player attack function, player and enemy objects passed by reference
  //Bool block argument takes int enemyAction, type coerced to bool
  void PlayerAttack(Player& p, Enemy& e, bool block);

  //Sophistry attack based on intelligence stats
  void Sophistry(Player& p, Enemy& e);

  //Queues messages for output in BattleLoop
  void AddMessage(string s);

  //Outputs enqueued messages below battle details and stats in BattleLoop
  void PrintMessages();


private:
  int round_ = 0;
  bool battleOver = false;
  string messages_ = "";

};

#endif
