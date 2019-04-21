#include "Player.h"

//Constructors
Player::Player() {
  cout << "Player initialized.  Call Creation() to set up character.\n";
}

//Accessor Functions
string Player::GetName() {
  return name_;
}
string Player::GetRole() {
  return role_;
}
int Player::GetLevel() {
  return level_;
}
int Player::GetExp() {
  return experience_;
}
int Player::GetWealth() {
  return wealth_;
}
int Player::GetHealth() {
  return health_;
}
int Player::GetAttack() {
  return attack_;
}
int Player::GetArmor() {
  return armor_;
}

//Mutator Functions

void Player::Creation() {
  SetName();
  cout << "Choose your role: \n"
  << "(S) Scientist - Clever and intrepid. \n"
  << "(H) Hazmat - Equipped for the worst. \n"
  << "(D) Detective - Incisive and dexterous. \n"
  << "(R) Repo man - Strong and determined. \n"
  << "(T) Teenager - Curious and fast. \n";
  CinReader read;
  char c = toupper(read.readChar("sShHdDrRtT"));
  switch (c) {
    case 'S':
      SetAttributes("Scientist", 1, 0, 10, 3, 2, 3, 10, 3);
      break;
    case 'H':
      SetAttributes("Hazmat",    1, 0, 20, 4, 5, 2, 3, 1);
      break;
    case 'D':
      SetAttributes("Detective", 1, 0, 15, 5, 3, 4, 7, 3);
      break;
    case 'R':
      SetAttributes("Repo Man",  1, 0, 30, 7, 7, 5, 2, 2);
      break;
    case 'T':
      SetAttributes("Teenager",  1, 0, 5 , 2, 2, 7, 5, 7);
      break;
    default:
      cerr << "Invalid role!\n";
      break;
  }
}

void Player::SetName() {
  cout << "Enter your player name: ";
  CinReader read;
  string name = read.readString();
  SetName(name);
}

void Player::SetName(string name) {
  if (name.length() > 0 && name.length() < 30) name_ = name;
  else cerr << "Invalid name!\n";
}

void Player::SetAttributes(string role, int level = 0, int experience = 0,
  int health = 0, int attack = 0, int armor = 0, int dexterity = 0,
  int intelligence = 0, int speed = 0) {

  SetRole(role);
  SetLevel(level);
  SetExp(experience);
  SetHealth(health);
  SetAttack(attack);
  SetArmor(armor);
  SetDexterity(dexterity);
  SetIntelligence(intelligence);
  SetSpeed(speed);
}
void Player::SetRole(string role) {
  if (role.length() > 0 && role.length() < 30) role_ = role;
  else cerr << "Invalid role!\n";

}
void Player::SetLevel(int level) {
  if (level > 0) level_ = level;
  else cerr << "Invalid level!\n";
}
void Player::SetExp(int exp) {
  if (exp >= 0) experience_ = exp;
  else cerr << "Invalid experience!\n";
}
void Player::SetHealth(int health) {
  if (health >= 0) health_ = health;
  else cerr << "Invalid health!\n";
}
void Player::SetAttack(int attack) {
  if (attack > 0) attack_ = attack;
  else cerr << "Invalid attack!\n";
}
void Player::SetArmor(int armor) {
  if (armor > 0) armor_ = armor;
  else cerr << "Invalid armor!\n";
}
void Player::SetDexterity(int dexterity) {
  if (dexterity > 0) dexterity_ = dexterity;
  else cerr << "Invalid dexterity!\n";
}
void Player::SetIntelligence(int intelligence) {
  if (intelligence > 0) intelligence_ = intelligence;
  else cerr << "Invalid intelligence!\n";
}
void Player::SetSpeed(int speed) {
  if (speed > 0) speed_ = speed;
  else cerr << "Invalid speed!\n";
}
