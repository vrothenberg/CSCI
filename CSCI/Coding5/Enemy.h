//Header Guards
#ifndef ROTHENBERG_ENEMY_H
#define ROTHENBERG_ENEMY_H

#include <iostream>
#include "CinReader.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;

class Enemy {
public:
  //Constructors
  Enemy();
  Enemy(int room, int difficulty);

  //Accessor Functions
  string GetName();
  string GetRole();
  int GetLevel();
  int GetExp();
  int GetWealth();
  int GetHealth();
  int GetAttack();
  int GetArmor();
  int GetDexterity();
  int GetIntelligence();
  int GetSpeed();

  //Mutator Functions
  void Creation();
  void SetAttributes(string role, int level, int experience, int health,
    int attack, int armor, int dexterity, int intelligence, int speed);
  void SetRole(string role);
  void SetLevel(int level);
  void SetExp(int exp);
  void SetHealth(int health);
  void SetAttack(int attack);
  void SetArmor(int armor);
  void SetDexterity(int dexterity);
  void SetIntelligence(int intelligence);
  void SetSpeed(int speed);

private:
  string role_ = "Squatter";
  int level_ = 1;
  int experience_ = 10;
  int wealth_ = 10;
  int health_ = 10;
  int attack_ = 1;
  int armor_ = 1;
  int dexterity_ = 1;
  int intelligence_ = 1;
  int speed_ = 1;
};

#endif
