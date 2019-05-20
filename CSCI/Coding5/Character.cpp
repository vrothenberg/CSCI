#include "Character.h"

//Constructor
Character::Character() {
  time_ = time(0);

}

//Accessor Functions
//Return private member variables
string Character::GetRole() {
  return role_;
}
int Character::GetLevel() {
  return level_;
}
int Character::GetExp() {
  return experience_;
}
int Character::GetWealth() {
  return wealth_;
}
//Current health, i.e. after damage inflicted
int Character::GetHealth() {
  return health_;
}
//Total possible health based on level and role
int Character::GetMaxHealth() {
  return maxHealth_;
}
int Character::GetAttack() {
  return attack_;
}
int Character::GetArmor() {
  return armor_;
}
int Character::GetDexterity() {
  return dexterity_;
}
int Character::GetIntelligence() {
  return intelligence_;
}
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
void Character::SetRole(string role) {
  if (role.length() > 0 && role.length() < 30) role_ = role;
  else cerr << "Invalid role!\n";

}
void Character::SetLevel(int level) {
  if (level > 0) level_ = level;
  else cerr << "Invalid level!\n";
}
void Character::SetExp(int exp) {
  if (exp >= 0) experience_ = exp;
  else cerr << "Invalid experience!\n";
}
void Character::SetWealth(int wealth) {
  if (wealth >= 0) wealth_ = wealth;
  else cerr << "Invalid wealth!\n";
}
void Character::SetHealth(int health) {
  health_ = health;
}
void Character::SetMaxHealth(int maxHealth) {
  if (maxHealth < 0) maxHealth = 10;
  maxHealth_ = maxHealth;
}
void Character::SetAttack(int attack) {
  if (attack > 0) attack_ = attack;
  else cerr << "Invalid attack!\n";
}
void Character::SetArmor(int armor) {
  if (armor > 0) armor_ = armor;
  else cerr << "Invalid armor!\n";
}
void Character::SetDexterity(int dexterity) {
  if (dexterity > 0) dexterity_ = dexterity;
  else cerr << "Invalid dexterity!\n";
}
void Character::SetIntelligence(int intelligence) {
  if (intelligence > 0) intelligence_ = intelligence;
  else cerr << "Invalid intelligence!\n";
}
void Character::SetSpeed(int speed) {
  if (speed > 0) speed_ = speed;
  else cerr << "Invalid speed!\n";
}
