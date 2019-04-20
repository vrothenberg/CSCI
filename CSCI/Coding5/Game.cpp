#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"
#include "CinReader.h"



Game::Game() {
  gameOver_ = false;
  roomNumber_ = 1;
}

void Game::Start() {
  cout << "Welcome to the game!" << endl;

  while(!gameOver_){
    LoadRoom();
    Tick();
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

void Game::Tick() {
  gameTicks_++;
}

void Game::ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}

void Game::Foyer() {
  //Room 1
  bool inRoom = true;
  CinReader read;
  while (inRoom) {
    cout << "You stand in the Foyer.\n\n"
    << "To the west the sun flows through a large glass door.\n"
    << "To the east is an old mahogany door.\n"
    << "To the south is a dimly lit hallway.\n\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = read.readChar("wWeEsSlL");
    ClearScreen();
    switch (c) {
      case 'W':
        cout << "You open the door to the Sun Room.\n";
        roomNumber_ = 2;
        inRoom = false;
        break;
      case 'E':
        cout << "You open the door to the Office.\n";
        roomNumber_ = 3;
        inRoom = false;
        break;
      case 'S':
        cout << "You head down the dimly lit hallway.\n";
        roomNumber_ = 4;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::SunRoom() {
  //Room 2
  bool inRoom = true;
  CinReader read;
  while(inRoom) {
    cout << "You bask in the light of the Sun Room.\n"
    << "You feel your health regaining.\n\n"
    << "To the east is the Foyer.\n"
    << "To the south a door leads down a verdant, meandering path.\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = read.readChar("eEsSlL");
    ClearScreen();
    switch (c) {
      case 'E':
        cout << "You open the door to the Foyer.\n";
        roomNumber_ = 1;
        inRoom = false;
        break;
      case 'S':
        cout << "You walk towards an overgrown garden.\n";
        roomNumber_ = 5;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}


void Game::Office() {
  //Room 3
  CinReader read;
  char c = read.readChar("eEsSlL");
  bool inRoom = true;
  while (inRoom) {
    cout << "You enter a well furnished Office.\n\n"
    << "To the west is the Foyer.\n"
    << "To the south is the Library.\n";
    char c = read.readChar("eEsSlL");
    ClearScreen();
    switch (c) {
      case 'W':
        cout << "You open the door to the Hall.\n";
        roomNumber_ = 4;
        inRoom = false;
        break;
      case 'S':
        cout << "You open the door to the Library.\n";
        roomNumber_ = 6;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Hall() {
  //Room 4
  CinReader read;
  cout << "Enter your direction: \n";
  string readCharString = "nNwWeEsS";
  char c  = read.readChar(readCharString);
  bool inRoom = true;
  while(inRoom) {
    cout << "You walk down the dimly lit Hall.\n\n"
    << "To the north is the Foyer.\n"
    << "To the west is the Garden.\n"
    << "To the east is the Library.\n"
    << "To the south is a locked door.\n";
    ClearScreen();
    switch (c) {
      ClearScreen();
      case 'W':
        cout << "You open the door to the Garden.\n";
        roomNumber_ = 5;
        inRoom = false;
        break;
      case 'E':
        cout << "You open the door to the Library.\n";
        roomNumber_ = 6;
        inRoom = false;
        break;
      case 'S':
        cout << "You go down into the basement.\n";
        roomNumber_ = 7;
        inRoom = false;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }

}

void Game::Garden() {
  //Room 5
  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNeElL";
  if (caveDiscovered_ && roomCharString != "nNeElLsS") roomCharString += "sS";
  while (inRoom) {
    cout << "You stand in an overgrown garden.\n\n"
    << "To the north is the Sun Room.\n"
    << "To the east is the Hall\n";
    if(caveDiscovered_) {
      cout << "To the south is a Cave.\n";
    }
    char c = read.readChar(roomCharString);
    switch (c) {
      case 'N':
        cout << "You walk up a meandering path to the Sun Room.\n";
        roomNumber_ = 2;
        inRoom = false;
      case 'E':
        cout << "You open the door to the Foyer.\n";
        roomNumber_ = 1;
        inRoom = false;
        break;
      case 'S':
        cout << "You walk towards an overgrown garden.\n";
        roomNumber_ = 5;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
    Tick();
  }
}
void Game::Library() {
  //Room 6
  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNwWlL";
  while (inRoom) {
    cout << "You stand in a dusty library.  Books tower above.\n\n"
    << "To the north is the Office.\n"
    << "To the west is the Hall\n";
    char c = read.readChar(roomCharString);
    switch (c) {
      case 'N':
        cout << "You walk up a meandering path to the Sun Room.\n";
        roomNumber_ = 3;
        inRoom = false;
      case 'W':
        cout << "You open the door to the Hall.\n";
        roomNumber_ = 4;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }

    Tick();
  }

}
void Game::Basement() {
  //Room 7

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNwWlL";
  while (inRoom) {
    cout << "You stand in a cold basement. To your side is a cavern.\n"
    << "A single bare lightbulb hangs above.\n\n"
    << "To the north is the Hall.\n"
    << "To the west a faint light glimmers from the rocks.\n"
    << "To the east is a maintenace door marked 'Utility'.\n";
    char c = read.readChar(roomCharString);
    switch (c) {
      case 'N':
        cout << "You open the door to the Hall.\n";
        roomNumber_ = 4;
        inRoom = false;
      case 'W':
        cout << "You walk into the cavern.\n";
        roomNumber_ = 5;
        inRoom = false;
        break;
      case 'E':
        cout << "You open the maintenance door.\n";
        roomNumber_ = 9;
        inRoom = false;
        break;
      case 'S':
        cout << "The tomb opens!  You fall into its depths!\n";
        roomNumber_ = 10;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }

    Tick();
  }

}
void Game::Cave() {
  //Room 8

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNeElL";
  while (inRoom) {
    cout << "You hunch down in a small, dark cave.\n\n"
    << "To the north sunlight breaches the crevices.\n"
    << "To the east a cavern opens.\n";
    char c = read.readChar(roomCharString);
    switch (c) {
      case 'N':
        cout << "You climb into the light.\n";
        roomNumber_ = 5;
        inRoom = false;
      case 'E':
        cout << "You walk into the cave.\n";
        roomNumber_ = 7;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }

    Tick();
  }
}
void Game::Utility() {
  //Room 9

  bool inRoom = true;
  CinReader read;
  string roomCharString = "wWlL";
  while (inRoom) {
    cout << "You stand in a well-stocked utility room.\n\n"
    << "To the west is the maintenance door.\n";
    char c = read.readChar(roomCharString);
    switch (c) {
      case 'W':
        cout << "You open the maintenance door to the basement.\n";
        roomNumber_ = 7;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
    Tick();
  }
}

void Game::Tomb() {
  //Room 10

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNlL";
  while (inRoom) {
    cout << "You stand before an ominous tomb.\n\n"
    << "To the north is the basement.\n";
    char c = read.readChar(roomCharString);
    switch (c) {
      case 'N':
        cout << "You seek respite in the basement.\n";
        roomNumber_ = 7;
        inRoom = false;
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
    Tick();
  }
}

void Game::LookAround() {
  cout << "You looked around.\n";
}
