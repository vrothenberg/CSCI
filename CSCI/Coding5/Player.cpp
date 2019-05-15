#include "Player.h"

//Constructors
Player::Player() {
  roomNumber_ = 1;
}


void Player::Initialize() {
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
  if(GetName() == "Luke") {
    SetName("Based Luke");
    SetRole("Overpowered " + GetRole());
    SetHealth(GetHealth() + 10);
    SetMaxHealth(GetHealth());
    SetAttack(GetAttack() + 3);
    SetArmor(GetArmor() + 3);
  }
}

//Accessor Functions
string Player::GetName() {
  return name_;
}

string Player::GetRoomMessage() {
  return roomMessage_;
}

int Player::GetRoomVisits() {
  return visits_[roomNumber_-1];
}

int Player::GetRoomVisits(int roomNumber) {
  return visits_[roomNumber-1];
}

int Player::GetRoomNumber() {
  return roomNumber_;
};

void Player::PrintMessages() {
  string output = messages_;
  messages_ = "";
  cout << output << endl;
}

int Player::GetAttack() {
  return Character::GetAttack() + GetAttackModifier();
}

int Player::GetAttackModifier() {
  return attackModifier_;
}

int Player::GetArmor() {
  return Character::GetArmor() + GetArmorModifier();
}

int Player::GetArmorModifier() {
  return armorModifier_;
}

int Player::GetHealthModifier() {
  return healthModifier_;
}

string Player::GetWeaponName() {
  return weaponName_;
}
string Player::GetArmorName() {
  return armorName_;
}


//Mutator Functions

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

void Player::SetName(string name) {
  if (name.length() > 0 && name.length() < 15) name_ = name;
  else name_ = "Nameless";
  ClearScreen();
}

void Player::IncrementRoomVisits() {
  visits_[roomNumber_-1]++;
}

void Player::SetRoomMessage(string message) {
  cout << "SET!\n";
  roomMessage_ = message;
}

void Player::SetRoomNumber(int roomNumber) {
  if(roomNumber > 0 && roomNumber <= 10) roomNumber_ = roomNumber;
}

void Player::AddMessage(string s) {
  messages_ += s + "\n";
}

void Player::SetAttackModifier(int attackModifier) {
  attackModifier_ = attackModifier;
}

void Player::SetArmorModifier(int armorModifier) {
  armorModifier_ = armorModifier;
}

void Player::SetHealthModifier(int healthModifier) {
  healthModifier_ = healthModifier;
}

void Player::SetWeaponName(string weaponName) {
  weaponName_ = weaponName;
}

void Player::SetArmorName(string armorName) {
  armorName_ = armorName;
}

void Player::AddExp(int exp) {
  if (exp >= 0) SetExp(GetExp() + exp);
  int threshhold = 10 * pow(2, GetLevel());
  if (GetExp() > threshhold) {
    SetLevel(GetLevel() + 1);
    SetMaxHealth(GetMaxHealth() + 5);
    SetAttack(GetAttack() + 1);
    SetArmor(GetArmor() + 1);
  }
}
