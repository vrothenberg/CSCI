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

  //Accessor Functions
  string GetName();
  string GetRoomMessage();
  int GetRoomVisits(int roomNumber);


  //Mutator Functions
  void SetName();
  void SetName(string name);
  void SetRoomMessage(string message);
  void IncrementRoomVisits(int roomNumber);

private:
  //Default Player member variable values
  string name_ = "Nameless";
  int visits_[10] = {0,0,0,0,0,0,0,0,0,0};
  string roomMessage_;

};



#endif
