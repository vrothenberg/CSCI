#include "Player.h"

//Constructors
Player::Player() {
  SetName();
  cout << "Choose your role: \n"
  << "(S) Scientist - Clever and intrepid. \n"
  << "(H) Hazmat - Equipped for the worst. \n"
  << "(D) Detective - Incisive and dexterous. \n"
  << "(R) Repo man - Strong and determined. \n"
  << "(T) Teenager - Curious and fast. \n";
  CinReader read;
  char c = toupper(read.readChar("sShHdDrRtT"));
  switch (c) {
    case 'S':
      SetAttributes("Scientist", 1, 0, 15, 3, 2, 3, 7, 3);
      break;
    case 'H':
      SetAttributes("Hazmat",    1, 0, 25, 4, 5, 2, 3, 1);
      break;
    case 'D':
      SetAttributes("Detective", 1, 0, 15, 4, 3, 4, 5, 3);
      break;
    case 'R':
      SetAttributes("Repo Man",  1, 0, 30, 7, 7, 5, 2, 2);
      break;
    case 'T':
      SetAttributes("Teenager",  1, 0, 10, 2, 2, 7, 5, 7);
      break;
    default:
      cerr << "Invalid role!\n";
      break;
  }
}

//Accessor Functions
string Player::GetName() {
  return name_;
}

int Player::GetRoomVisits(int roomNumber) {
  return visits_[roomNumber-1];
}

string Player::GetRoomMessage() {
  return roomMessage_;
}

//Mutator Functions

void Player::SetName() {
  cout << "Enter your player name: ";
  CinReader read;
  string name = read.readString();
  while (name.length() < 1 || name.length() > 20) {
    ClearScreen();
    name = read.readString();
  }
  SetName(name);
}

void Player::SetName(string name) {
  if (name.length() > 0 && name.length() < 20) name_ = name;
  else cerr << "Invalid name!\n";
}

void Player::IncrementRoomVisits(int roomNumber) {
  visits_[roomNumber]++;
}

void Player::SetRoomMessage(string message) {
  cout << "SET!\n";
  roomMessage_ = message;
}
