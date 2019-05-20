//Header Guards
#ifndef ROTHENBERG_GAME_H
#define ROTHENBERG_GAME_H

#include <ctime>
#include <map>
#include "CinReader.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"
#include "System.h"

using std::cout;
using std::endl;
using std::cerr;
using std::map;

struct Weapon {
  int room_;
  int attackModifier_;
  string name_;
};

struct Armor {
  int room_;
  int armorModifier_;
  string name_;
};

class Game {
public:
  //Constructor
  Game();

  //Primary game loop
  void Start();

  //Player object, member variables specified by calling Initialize()
  Player player_;

  //Custom type map of int and Weapon struct
  typedef map<int, Weapon> WeaponMap;

  //Map of weapons for efficient lookup
  static WeaponMap weapons_;

  //Custom type map of int and Armor struct
  typedef map<int, Armor> ArmorMap;

  //Map of armors for efficient lookup
  static ArmorMap armors_;

private:
  //Seed for rand()
  time_t time_ = time(0);

  //Game over flag
  bool gameOver_ = false;

  //Cumulative game iterations
  int gameTicks_ = 0;

  //High scores multidimensional vector
  vector<vector<string>> scores_;

  //Location flags
  bool caveDiscovered_ = false;
  bool basementKey_ = false;

  //Item flags
  int roomWeapons[6] = {0,0,0,0,0,0};
  int roomArmors[5] = {0,0,0,0,0};

  //Helper Functions

  //Loads room from player class roomNumber_
  void LoadRoom();

  //Increments gameTicks_ and calls HUD
  void Tick();

  //Outputs game state
  void HUD();

  //Outputs scores from HighScores.txt file
  void HighScores();

  //Inserts and sorts player score into HighScores.txt file
  void UpdateHighScores();

  //Farewell message, calls HighScores functions
  void GameOver();

  //Random chance of battle
  void BattleRoll(int danger);

  //Room Functions
  void Foyer();
  void SunRoom();
  void Office();
  void Hall();
  void Garden();
  void Library();
  void Basement();
  void Cave();
  void Utility();
  void Tomb();

  //Explore current room, random chance of items, enemies, health, wealth
  void LookAround();

};

#endif
