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

  //Returns current room visits
  int GetRoomVisits();

  //Returns specific room visits
  int GetRoomVisits(int roomNumber);

  //Returns current room number
  int GetRoomNumber();

  //Outputs enqueued messages
  void PrintMessages();

  //Returns base character attack stat plus weapon attack value
  int GetAttack();

  //Returns weapon attack value
  int GetAttackModifier();

  //Returns base character defense value plus armor defense value
  int GetArmor();

  //Returns armor defense value
  int GetArmorModifier();

  //Returns weapon name string
  string GetWeaponName();

  //Returns armor name string
  string GetArmorName();

  //Returns game over flag
  bool GetGameOver();


  //Mutator Functions

  //Prompts user to set a name between 0 and 16 characters long
  void SetName();

  //Function overload for provided name argument
  void SetName(string name);

  //Increments current room visits by 1
  void IncrementRoomVisits();

  //Sets current room number
  void SetRoomNumber(int roomNumber);

  //Enqueues message to be displayed under HUD
  void AddMessage(string s);

  //Sets weapon attack modifier member variable
  void SetAttackModifier(int attackModifier);

  //Sets armor defense modifier member variable
  void SetArmorModifier(int armorModifier);

  //Sets weapon name member variable
  void SetWeaponName(string weaponName);

  //Sets armor name member variable
  void SetArmorName(string armorName);

  //Adds experience to cumulative experience_ member variable
  //Levels up based on exponential equation
  void AddExp(int exp);

  //Sets gameOver_ flag member variable
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
