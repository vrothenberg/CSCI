//Header Guards
#ifndef ROTHENBERG_PLAYER_H
#define ROTHENBERG_PLAYER_H

#include "Character.h"
#include "CinReader.h"
#include "System.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;



class Player : public Character {
public:
  //Constructors
  Player();
  void Initialize();

  //Accessor Functions
  string GetName();
  string GetRoomMessage();
  int GetRoomVisits();
  int GetRoomVisits(int roomNumber);
  int GetRoomNumber();
  void PrintMessages();
  


  //Mutator Functions
  void SetName();
  void SetName(string name);
  void SetRoomMessage(string message);
  void IncrementRoomVisits();
  void SetRoomNumber(int roomNumber);
  void AddMessage(string s);

private:
  //Default Player member variable values
  string name_;
  int visits_[10] = {0,0,0,0,0,0,0,0,0,0};
  string roomMessage_;
  int roomNumber_ = 1;
  string messages_;

};



#endif
