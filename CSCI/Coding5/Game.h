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
  Game();
  void Start();
  Player player_;
  typedef map<int, Weapon> WeaponMap;
  static WeaponMap weapons_;
  typedef map<int, Armor> ArmorMap;
  static ArmorMap armors_;

private:
  //Global variables
  time_t time_ = time(0);
  bool gameOver_ = false;
  int gameTicks_ = 0;
  vector<vector<string>> scores_;

  //Location flags
  bool caveDiscovered_ = false;
  bool basementKey_ = false;

  //Item flags
  int roomWeapons[6] = {0,0,0,0,0,0};
  int roomArmors[5] = {0,0,0,0,0};

  //Helper Functions
  void LoadRoom();
  void Tick();
  void HUD();
  void HighScores();
  void UpdateHighScores();
  void GameOver();
  void BattleRoll();

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

  //Puzzle
  void LookAround();


};

#endif
