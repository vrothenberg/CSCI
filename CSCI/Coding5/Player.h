//Header Guards
#ifndef ROTHENBERG_PLAYER_H
#define ROTHENBERG_PLAYER_H

#include "Character.h"
#include "CinReader.h"
#include "System.h"
#include <cmath>
using std::cout;
using std::endl;
using std::cerr;
using std::string;



class Player : public Character {
public:
  //Constructors
  Player();

  //Initialize function prompts user to set name
  void Initialize();

  //Accessor Functions
  //Returns player name
  string GetName();
  int GetRoomVisits();
  int GetRoomVisits(int roomNumber);
  int GetRoomNumber();
  void PrintMessages();
  int GetAttack();
  int GetAttackModifier();
  int GetArmor();
  int GetArmorModifier();
  int GetHealthModifier();
  string GetWeaponName();
  string GetArmorName();
  bool GetGameOver();

  //Mutator Functions
  void SetName();
  void SetName(string name);
  void IncrementRoomVisits();
  void SetRoomNumber(int roomNumber);
  void AddMessage(string s);
  void SetAttackModifier(int attackModifier);
  void SetArmorModifier(int armorModifier);
  void SetHealthModifier(int healthModifier);
  void SetWeaponName(string weaponName);
  void SetArmorName(string armorName);
  void AddExp(int exp);
  void SetGameOver(bool status);



private:
  //Default Player member variable values
  string name_;
  int visits_[10] = {0,0,0,0,0,0,0,0,0,0};
  string roomMessage_;
  int roomNumber_ = 1;
  string messages_;
  int attackModifier_ = 0;
  int armorModifier_ = 0;
  int healthModifier_ = 0;
  string weaponName_ = "Unarmed";
  string armorName_ = "Clothes";
  int maxHealth_;
  bool gameOver_ = false;

};



#endif
