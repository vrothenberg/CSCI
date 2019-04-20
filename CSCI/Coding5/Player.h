//Header Guards
#ifndef ROTHENBERG_PLAYER_H
#define ROTHENBERG_PLAYER_H

#include <iostream>
#include "CinReader.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;

class Player {
public:
  //Constructors
  Player();
  Player(string name);

  //Accessor Functions
  string GetName();
  string GetRole();
  int GetLevel();
  int GetExp();
  int GetHealth();
  int GetAttack();
  int GetArmor();
  int GetDexterity();
  int GetIntelligence();
  int GetSpeed();

  //Mutator Functions
  void SetName();
  void SetName(string name);
  void SetRole();
  void SetAttributes(string role, int experience, int health,
    int attack, int armor, int dexterity, int intelligence, int speed);
  void SetLevel(int level);
  void SetExp(int exp);
  void SetHealth(int health);
  void SetAttack(int attack);
  void SetArmor(int armor);
  void SetDexterity(int dexterity);
  void SetIntelligence(int intelligence);
  void SetSpeed(int speed);

private:
  //Default member variable values
  string name_ = "Nameless";
  string role_ = "Aimless";
  int level_ = 1;
  int experience_ = 0;
  int health_ = 0;
  int attack_ = 0;
  int armor_ = 0;
  int dexterity_ = 0;
  int intelligence_ = 0;
  int speed_ = 0;
};

#endif
