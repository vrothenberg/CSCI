#include "Player.h"

//Constructors
Player::Player() {
  roomNumber_ = 1;
}

//Prompts user to configure their player name and role
//If user is especially awesome it will add bonus stats
void Player::Initialize() {
  //Calls set name function to prompt user
  SetName();
  //Outputs roles to choose from
  cout << "Choose your role: \n"
  << "(R) Repo man - Strong and determined. \n"
  << "(H) Hazmat - Armored and resilient. \n"
  << "(S) Scientist - Clever and intrepid. \n"
  << "(D) Detective - Incisive and dexterous. \n"
  << "(T) Teenager - Curious and fast. \n";
  CinReader read;
  char c = toupper(read.readChar("sShHdDrRtT"));
  //Switch statement to initialize player role and attributes
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
  //Conditional statement for comparatively awesome users
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
};

//Outputs enqueued messages for HUD
void Player::PrintMessages() {
  string output = messages_;
  messages_ = "";
  cout << output << endl;
}

//Returns player base attack and attack modifier value
int Player::GetAttack() {
  return Character::GetAttack() + GetAttackModifier();
}

//Returns player attack modifier from weapon
int Player::GetAttackModifier() {
  return attackModifier_;
}

//Returns player base defense and defense modifier from armor
int Player::GetArmor() {
  return Character::GetArmor() + GetArmorModifier();
}

//Returns player defense modifier from armor
int Player::GetArmorModifier() {
  return armorModifier_;
}

//Returns player health modifier
int Player::GetHealthModifier() {
  return healthModifier_;
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
//Prompts user for name, must be between 1 and 14 characters long
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

//Overloaded setname function for supplied string
//Defaults to "Nameless" for invalid name lengths
void Player::SetName(string name) {
  if (name.length() > 0 && name.length() < 15) name_ = name;
  else name_ = "Nameless";
  ClearScreen();
}

//Increments visits for current room number
//Used for determining likelihood of finding wealth or an enemy
void Player::IncrementRoomVisits() {
  visits_[roomNumber_-1]++;
}

//Sets current room number
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
    SetIntelligence(GetIntelligence() + 1);
    SetDexterity(GetDexterity() + 1);
    SetSpeed(GetSpeed() + 1);
  }
}

void Player::SetGameOver(bool status) {
  gameOver_ = status;
}
