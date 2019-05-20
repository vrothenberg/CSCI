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

  //Returns role
  string GetRole();

  //Returns level
  int GetLevel();

  //Returns experience
  //If enemy, player acquires experience based on this value after battle
  int GetExp();

  //Returns wealth
  //If enemy, player acquires this wealth after battle
  int GetWealth();

  //Returns current health
  int GetHealth();

  //Returns maximum health
  int GetMaxHealth();

  //Returns attack stat value
  int GetAttack();

  //Returns defense stat value
  int GetArmor();

  //Returns dexterity stat value
  int GetDexterity();

  //Returns intelligence stat value
  int GetIntelligence();

  //Returns speed stat value
  int GetSpeed();

  //Mutator Functions
  //Sets multiple member variables on character initialization
  void SetAttributes(string role, int level, int experience, int health,
    int attack, int armor, int dexterity, int intelligence, int speed);

  //Sets role name, must be between 0 and 30 characters
  void SetRole(string role);

  //Sets level, must be greater than 0
  void SetLevel(int level);

  //Sets experience, must be positive
  void SetExp(int exp);

  //Sets wealth, must be positive
  void SetWealth(int wealth);

  //Sets health value
  void SetHealth(int health);

  //Sets maximum health value, defaults to 10
  void SetMaxHealth(int maxHealth);

  //Sets attack value, must be greater than 0
  void SetAttack(int attack);

  //Sets defense value, must be greater than 0
  void SetArmor(int armor);

  //Sets dexterity stat value, must be greater than 0
  void SetDexterity(int dexterity);

  //Sets intelligence stat value, must be greater than 0
  void SetIntelligence(int intelligence);

  //Sets speed stat value, must be greater than 0
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
