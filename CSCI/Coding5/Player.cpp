#include "Player.h"

//Constructors
Player::Player() {
  roomNumber_ = 1;
}

//Player initialization function, sets name, role and stats
void Player::Initialize() {
  //Prompts user to configure their player name and role
  SetName();
  cout << "Choose your role: \n"
  << "(R) Repo man - Strong and determined. \n"
  << "(H) Hazmat - Armored and resilient. \n"
  << "(S) Scientist - Clever and intrepid. \n"
  << "(D) Detective - Incisive and dexterous. \n"
  << "(T) Teenager - Curious and fast. \n";
  CinReader read;
  char c = toupper(read.readChar("sShHdDrRtT"));
  switch (c) {
    case 'S':
      SetAttributes("Scientist", 1, 0, 15, 3, 2, 3, 4, 3);
      break;
    case 'H':
      SetAttributes("Hazmat",    1, 0, 25, 4, 5, 2, 3, 1);
      break;
    case 'D':
      SetAttributes("Detective", 1, 0, 15, 4, 3, 4, 4, 3);
      break;
    case 'R':
      SetAttributes("Repo Man",  1, 0, 30, 5, 5, 2, 1, 2);
      break;
    case 'T':
      SetAttributes("Teenager",  1, 0, 10, 2, 2, 5, 3, 3);
      break;
    default:
      cerr << "Invalid role.\n";
      break;
  }
  //Conditional statement for comparatively awesome players
  if(GetName() == "Luke") {
    SetName("Based Luke");
    SetRole("Overpowered " + GetRole());
    SetHealth(GetHealth() + 10);
    SetMaxHealth(GetHealth());
    SetAttack(GetAttack() + 3);
    SetArmor(GetArmor() + 3);
    SetIntelligence(GetIntelligence() + 3);
    SetDexterity(GetDexterity() + 3);
    SetSpeed(GetSpeed() + 3);
  }
}

//Accessor Functions

//Returns player name
string Player::GetName() {
  return name_;
}

//Returns number of visits of current room using visits_ array
int Player::GetRoomVisits() {
  return visits_[roomNumber_-1];
}

//Returns number of visits of specific room argument using visits_ array
int Player::GetRoomVisits(int roomNumber) {
  return visits_[roomNumber-1];
}

//Returns current room number
int Player::GetRoomNumber() {
  return roomNumber_;
}

//Outputs enqueued messages for HUD
void Player::PrintMessages() {
  string output = messages_;
  messages_ = "";
  cout << output << endl;
}

//Returns base character attack stat plus weapon attack value
int Player::GetAttack() {
  return Character::GetAttack() + GetAttackModifier();
}

//Returns weapon attack value
int Player::GetAttackModifier() {
  return attackModifier_;
}

//Returns base character armor value plus armor defense value
int Player::GetArmor() {
  return Character::GetArmor() + GetArmorModifier();
}

//Returns armor defense value
int Player::GetArmorModifier() {
  return armorModifier_;
}

//Returns weapon name string
string Player::GetWeaponName() {
  return weaponName_;
}

//Returns armor name string
string Player::GetArmorName() {
  return armorName_;
}

//Returns game over flag
bool Player::GetGameOver() {
  return gameOver_;
}


//Mutator Functions

//Prompts user to set a name between 1 and 15 characters long
void Player::SetName() {
  cout << "Enter your player name: ";
  CinReader read;
  string name = read.readString();
  while (name.length() < 1 || name.length() > 15) {
    ClearScreen();
    cout << "Name must be between 1 and 15 characters.\n";
    name = read.readString();
  }
  SetName(name);
}

//Function overload for provided name argument
void Player::SetName(string name) {
  if (name.length() > 0 && name.length() < 15) name_ = name;
  else name_ = "Nameless";
  ClearScreen();
}

//Increments current room visits by 1
void Player::IncrementRoomVisits() {
  visits_[roomNumber_-1]++;
}

//Sets current room number
void Player::SetRoomNumber(int roomNumber) {
  if(roomNumber > 0 && roomNumber <= 10) roomNumber_ = roomNumber;
}

//Enqueues message to be displayed under HUD
void Player::AddMessage(string s) {
  messages_ += s + "\n";
}

//Sets attack modifier member variable
void Player::SetAttackModifier(int attackModifier) {
  attackModifier_ = attackModifier;
}

//Sets armor modifier member variable
void Player::SetArmorModifier(int armorModifier) {
  armorModifier_ = armorModifier;
}

//Sets weapon name member variable
void Player::SetWeaponName(string weaponName) {
  weaponName_ = weaponName;
}

//Sets armor name member variable
void Player::SetArmorName(string armorName) {
  armorName_ = armorName;
}

//Adds experience to cumulative member variable
//Levels up based on exponential equation
void Player::AddExp(int exp) {
  if (exp >= 0) SetExp(GetExp() + exp);
  int threshhold = 10 * pow(2, GetLevel());
  if (GetExp() > threshhold) {
    SetLevel(GetLevel() + 1);
    SetMaxHealth(GetMaxHealth() + 5);
    SetAttack(GetAttack() + 1);
    SetArmor(GetArmor() + 1);
    SetIntelligence(GetIntelligence() + 1);
    SetDexterity(GetDexterity() + 1);
    SetSpeed(GetSpeed() + 1);
  }
}

//Set gameOver_ flag member variable
void Player::SetGameOver(bool status) {
  gameOver_ = status;
}
