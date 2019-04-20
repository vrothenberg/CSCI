#include "Game.h"
#include "CinReader.h"



Game::Game() {
  number_ = 0;
  gameOver_ = false;
  roomNumber_ = 1;
}

void Game::Start() {
  cout << "Welcome to the game!" << endl;
  while(!gameOver_){
    LoadRoom();

  }
}

void Game::LoadRoom() {
  switch(roomNumber_) {
    case 1:
      Foyer();
      break;
    case 2:
      SunRoom();
      break;
    case 3:
      Office();
      break;
    case 4:
      Hall();
      break;
    case 5:
      Garden();
      break;
    case 6:
      Library();
      break;
    case 7:
      Basement();
      break;
    case 8:
      Cave();
      break;
    case 9:
      Utility();
      break;
    case 10:
      Tomb();
      break;
    default:
      cerr << "Invalid room number\n";
      break;
  }
}

void Game::Foyer() {
  //Room 1
  cout << "You stand in the Foyer.\n\n"
  << "To the west the sun flows through a large glass door.\n"
  << "To the east is an old mahogany door.\n"
  << "To the south is a dimly lit hallway.\n\n"
  << "Enter your action: \n"
  << "(W)est\n"
  << "(E)ast\n"
  << "(S)outh\n"
  << "(L)ook around\n";
  CinReader read;
  char c = toupper(read.readChar("wWeEsSlL"));
  switch (c) {
    case 'W':
      cout << "You open the door to the Sun Room.\n";
      roomNumber_ = 2;
      break;
    case 'E':
      cout << "You open the door to the Office.\n";
      roomNumber_ = 3;
      break;
    case 'S':
      cout << "You head down the dimly lit hallway.\n";
      roomNumber_ = 4;
      break;
    case 'L':
      cout << "You look around.\n";
      break;
    default:
      cerr << "Invalid action taken.\n";
      break;
  }

}

void Game::SunRoom() {
  //Room 2
  cout << "You bask in the light of the Sun Room.\n"
  << "You feel your health regaining.\n\n"
  << "To the east is the Foyer.\n"
  << "To the south is the Garden.\n";
  CinReader read;
  char c = toupper(read.readChar("eEsSlL"));
  switch (c) {
    case 'E':
      cout << "You open the door to the Foyer.\n";
      roomNumber_ = 1;
      break;
    case 'S':
      cout << "You walk towards an overgrown garden.\n";
      roomNumber_ = 5;
      break;
    case 'L':
      cout << "You look around.\n";
      break;
    default:
      cerr << "Invalid action taken.\n";
      break;
  }

}


void Game::Office() {
  //Room 3
  cout << "You enter a well furnished Office.\n\n"
  << "To the west is the Foyer.\n"
  << "To the south is the Library.\n";

}

void Game::Hall() {
  //Room 4
  cout << "You walk down the dimly lit Hall.\n\n"
  << "To the north is the Foyer.\n"
  << "To the west is the Garden.\n"
  << "To the east is the Library.\n"
  << "To the south is a locked door.\n";
  CinReader read;
  cout << "Enter your direction: \n";
  read.readChar("nNwWeEsS");


}

void Game::Garden() {
  //Room 5
  cout << "You stand in an overgrown garden.\n\n";
}
void Game::Library() {
  //Room 6
  cout << "You stand in a dusty library.  Books tower above.\n\n";
}
void Game::Basement() {
  //Room 7
  cout << "You stand in a cold basement.\n"
  << "A single bare lightbulb hangs above.\n\n";
}
void Game::Cave() {
  //Room 8
  cout << "You hunch down in a small, dark cave.\n\n";
}
void Game::Utility() {
  //Room 9
  cout << "You stand in a utility room.\n\n";
}
void Game::Tomb() {
  //Room 10
  cout << "You stand before an ominous tomb.\n\n";
}
