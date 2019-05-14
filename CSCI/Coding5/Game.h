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
  Player newPlayer_;
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
  void LoadRoom(Player& p);
  void Tick(Player& p);
  void HUD(Player& p);
  void HighScores();
  void UpdateHighScores();

  //Room Functions
  void Foyer(Player& p);
  void SunRoom(Player& p);
  void Office(Player& p);
  void Hall(Player& p);
  void Garden(Player& p);
  void Library(Player& p);
  void Basement(Player& p);
  void Cave(Player& p);
  void Utility(Player& p);
  void Tomb(Player& p);

  //Puzzle
  void LookAround(Player& p);


};

#endif
