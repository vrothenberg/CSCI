//Header Guards
#ifndef ROTHENBERG_CHARACTER_H
#define ROTHENBERG_CHARACTER_H

#include "System.h"
#include <ctime>

using std::cout;
using std::endl;
using std::cerr;
using std::string;

//Character base class, Player and Enemy classes inherit from Character
class Character {

  public:
  //Constructor
  Character();

  //Accessor Functions
  //Return private member variables
  string GetRole();
  int GetLevel();
  int GetExp();
  int GetWealth();
  int GetHealth();
  int GetMaxHealth();
  int GetAttack();
  int GetArmor();
  int GetDexterity();
  int GetIntelligence();
  int GetSpeed();

  //Mutator Functions
  //Sets multiple member variables on character initialization
  void SetAttributes(string role, int level, int experience, int health,
    int attack, int armor, int dexterity, int intelligence, int speed);

  //Set private member variables
  void SetRole(string role);
  void SetLevel(int level);
  void SetExp(int exp);
  void SetWealth(int wealth);
  void SetHealth(int health);
  void SetMaxHealth(int maxHealth);
  void SetAttack(int attack);
  void SetArmor(int armor);
  void SetDexterity(int dexterity);
  void SetIntelligence(int intelligence);
  void SetSpeed(int speed);

private:
  //Default Player member variable values
  string role_ = "Aimless";
  int level_ = 0;
  int experience_ = 0;
  int wealth_ = 0;
  int health_ = 0;
  int maxHealth_ = 0;
  int attack_ = 0;
  int armor_ = 0;
  int dexterity_ = 0;
  int intelligence_ = 0;
  int speed_ = 0;
  time_t time_;

};



#endif
