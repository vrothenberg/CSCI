#include "Character.h"

//Constructor
Character::Character() {
  //Seed time
  time_ = time(0);
}

//Accessor Functions

//Returns role
string Character::GetRole() {
  return role_;
}

//Returns level
int Character::GetLevel() {
  return level_;
}

//Returns experience
int Character::GetExp() {
  return experience_;
}

//Returns cumulative wealth
int Character::GetWealth() {
  return wealth_;
}

//Returns current health, i.e. after damage inflicted
int Character::GetHealth() {
  return health_;
}

//Returns total possible health based on level and role
int Character::GetMaxHealth() {
  return maxHealth_;
}

//Returns attack stat value
int Character::GetAttack() {
  return attack_;
}

//Returns defense stat value
int Character::GetArmor() {
  return armor_;
}

//Returns dexterity stat value
int Character::GetDexterity() {
  return dexterity_;
}

//Returns intelligence stat value
int Character::GetIntelligence() {
  return intelligence_;
}

//Returns speed stat value
int Character::GetSpeed() {
  return speed_;
}

//Mutator Functions
//Sets multiple member variables on character initialization
void Character::SetAttributes(string role, int level = 0, int experience = 0,
  int health = 0, int attack = 0, int armor = 0, int dexterity = 0,
  int intelligence = 0, int speed = 0) {

  SetRole(role);
  SetLevel(level);
  SetExp(experience);
  SetHealth(health);
  SetMaxHealth(health);
  SetAttack(attack);
  SetArmor(armor);
  SetDexterity(dexterity);
  SetIntelligence(intelligence);
  SetSpeed(speed);
}

//Sets role name, must be between 0 and 30 characters
void Character::SetRole(string role) {
  if (role.length() > 0 && role.length() < 30) role_ = role;
  else cerr << "Invalid role!\n";

}

//Sets level, must be greater than 0
void Character::SetLevel(int level) {
  if (level > 0) level_ = level;
  else cerr << "Invalid level!\n";
}

//Sets experience value, must be positive
void Character::SetExp(int exp) {
  if (exp >= 0) experience_ = exp;
  else cerr << "Invalid experience!\n";
}

//Sets wealth, must be positive
void Character::SetWealth(int wealth) {
  if (wealth >= 0) wealth_ = wealth;
  else cerr << "Invalid wealth!\n";
}

//Sets health value
void Character::SetHealth(int health) {
  health_ = health;
}

//Sets maximum health value, if not greater than 0 defaults to 10
void Character::SetMaxHealth(int maxHealth) {
  if (maxHealth < 0) maxHealth = 10;
  maxHealth_ = maxHealth;
}

//Sets attack value, must be greater than 0
void Character::SetAttack(int attack) {
  if (attack > 0) attack_ = attack;
  else cerr << "Invalid attack!\n";
}

//Sets defense value, must be greater than 0
void Character::SetArmor(int armor) {
  if (armor > 0) armor_ = armor;
  else cerr << "Invalid armor!\n";
}

//Sets dexterity stat value, must be greater than 0
void Character::SetDexterity(int dexterity) {
  if (dexterity > 0) dexterity_ = dexterity;
  else cerr << "Invalid dexterity!\n";
}

//Sets intelligence stat value, must be greater than 0
void Character::SetIntelligence(int intelligence) {
  if (intelligence > 0) intelligence_ = intelligence;
  else cerr << "Invalid intelligence!\n";
}

//Sets speed stat value, must be greater than 0
void Character::SetSpeed(int speed) {
  if (speed > 0) speed_ = speed;
  else cerr << "Invalid speed!\n";
}
