#include "Game.h"

Game::Game() {
  srand((unsigned)time(0));
  gameOver_ = false;
  roomNumber_ = 1;
  ClearScreen();
  cout << "Welcome to the game!" << endl;
}

void Game::Start() {
  ClearScreen();
  while(!gameOver_) {
    LoadRoom(newPlayer_);
  }
}

void Game::LoadRoom(Player p) {

  switch(roomNumber_) {
    case 1:
      Foyer(p);
      break;
    case 2:
      SunRoom(p);
      break;
    case 3:
      Office(p);
      break;
    case 4:
      Hall(p);
      break;
    case 5:
      Garden(p);
      break;
    case 6:
      Library(p);
      break;
    case 7:
      Basement(p);
      break;
    case 8:
      Cave(p);
      break;
    case 9:
      Utility(p);
      break;
    case 10:
      Tomb(p);
      break;
    default:
      cerr << "Invalid room number.\n";
      break;
  }
}

void Game::Tick(Player p) {
  p.IncrementRoomVisits(roomNumber_);
  HUD(newPlayer_);
  gameTicks_++;
}


void Game::HUD(Player p) {
  //stringf padding
  cout << p.GetRoomMessage();
  cout << "Tick: " << gameTicks_ << " Room visits: " << p.GetRoomVisits(roomNumber_) << endl;
  cout << p.GetName() << " the level " << p.GetLevel() << " " << p.GetRole() << endl;
  cout << "Health: " << p.GetHealth() << " Wealth: " << p.GetWealth() << endl << endl;
}

void Game::Foyer(Player p) {
  //Room 1
  //Loot, Armor, Weapon

  bool inRoom = true;
  CinReader read;
  string readCharString = "wWeEsSlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand in the Foyer.\n\n"
    << "To the west the sun flows through a large glass door.\n"
    << "To the east is an old mahogany door.\n"
    << "To the south is a dimly lit hallway.\n\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(readCharString));
    ClearScreen();
    switch (c) {
      case 'W':
        roomNumber_ = 2;
        inRoom = false;
        break;
      case 'E':
        roomNumber_ = 3;
        inRoom = false;
        break;
      case 'S':
        roomNumber_ = 4;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::SunRoom(Player p) {
  //Room 2
  //Loot, Armor

  bool inRoom = true;
  CinReader read;
  string readCharString = "eEsSlL";
  while(inRoom) {
    Tick(p);
    cout << "You bask in the light of the Sun Room.\n"
    << "You feel your health regaining.\n\n"
    << "To the east is the Foyer.\n"
    << "To the south a door leads down a verdant, meandering path.\n"
    << "Enter your action: \n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(readCharString));
    ClearScreen();
    switch (c) {
      case 'E':
        roomNumber_ = 1;
        inRoom = false;
        break;
      case 'S':
        roomNumber_ = 5;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Office(Player p) {
  //Room 3
  //Loot, Armor, Weapon
  CinReader read;
  bool inRoom = true;
  string readCharString = "eEsSlL";
  while (inRoom) {
    Tick(p);
    cout << "You enter a well furnished Office.\n\n"
    << "To the west is the Foyer.\n"
    << "To the south is the Library.\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(readCharString));
    ClearScreen();
    switch (c) {
      case 'W':
        roomNumber_ = 1;
        inRoom = false;
        break;
      case 'S':
        roomNumber_ = 6;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Hall(Player p) {
  //Room 4
  int modifier = 6;
  int roll = rand() % modifier;
  //Enemy, Loot
  //Enemy newEnemy;
  CinReader read;
  string readCharString = "nNwWeEsS";
  bool inRoom = true;
  while (inRoom) {
    Tick(p);
    cout << "You walk down the dimly lit Hall.\n\n"
    << "To the north is the Foyer.\n"
    << "To the west is the Garden.\n"
    << "To the east is the Library.\n";
    if (basementKey_) cout << "To the south is the basement.\n";
    else cout << "To the south is a locked door.\n";
    cout << "Enter your action: \n"
    << "(N)orth\n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";

    char c  = toupper(read.readChar(readCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        roomNumber_ = 1;
        inRoom = false;
        break;
      case 'W':
        roomNumber_ = 5;
        inRoom = false;
        break;
      case 'E':
        roomNumber_ = 6;
        inRoom = false;
        break;
      case 'S':
        if (basementKey_) {
          roomNumber_ = 7;
          inRoom = false;
        } else {
          p.SetRoomMessage("The door won't open.");
        }
        break;
      case 'L':
        cout << "You look around.\n";
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Garden(Player p) {
  //Room 5
  //Enemy, Loot, Weapon

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNeEsSlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand in an overgrown garden.\n\n"
    << "To the north is the Sun Room.\n"
    << "To the east is the Hall.\n";
    if(caveDiscovered_) {
      cout << "To the south is a Cave.\n";
    }
    cout << "Enter your action: \n"
    << "(N)orth\n"
    << "(E)ast\n";
    if(caveDiscovered_) {
      cout << "(S)outh\n";
    }
    cout << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        roomNumber_ = 2;
        inRoom = false;
      case 'E':
        roomNumber_ = 4;
        inRoom = false;
        break;
      case 'S':
        if (caveDiscovered_) {
          roomNumber_ = 8;
          inRoom = false;
        } else p.SetRoomMessage("The thicket repels you.\n");
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Library(Player p) {
  //Room 6
  //Enemy, Loot, Weapon
  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNwWlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand in a dusty library.  Books tower above.\n\n"
    << "To the north is the Office.\n"
    << "To the west is the Hall.\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(W)est\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        roomNumber_ = 3;
        inRoom = false;
      case 'W':
        roomNumber_ = 4;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Basement(Player p) {
  //Room 7
  //Enemy, Loot, Weapon

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNwWeEsSlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand in a cold basement. To your side is a cavern.\n"
    << "A single bare lightbulb hangs above.\n\n"
    << "To the north is a stairway to the Hall.\n"
    << "To the west a faint light glimmers from the rocks.\n"
    << "To the east is a maintenace door marked 'Utility'.\n"
    << "To the south is a stone doorway.  It's engraved with glowing symbols.\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        roomNumber_ = 4;
        inRoom = false;
      case 'W':
        roomNumber_ = 8;
        inRoom = false;
        break;
      case 'E':
        roomNumber_ = 9;
        inRoom = false;
        break;
      case 'S':
        p.SetRoomMessage("The tomb opens!  You fall into its depths.\n");
        roomNumber_ = 10;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Cave(Player p) {
  //Room 8
  //Enemy, Loot

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNeElL";
  while (inRoom) {
    Tick(p);
    cout << "You hunch down in a small, dark cave.\n\n"
    << "To the north sunlight breaches the crevices.\n"
    << "To the east a cavern opens.\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(E)ast\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        caveDiscovered_ = true;
        roomNumber_ = 5;
        inRoom = false;
      case 'E':
        roomNumber_ = 7;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Utility(Player p) {
  //Room 9
  //Enemy, Loot, Armor, Weapon

  bool inRoom = true;
  CinReader read;
  string roomCharString = "wWlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand in a well-stocked utility room.\n\n"
    << "To the west is the maintenance door.\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'W':
        roomNumber_ = 7;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::Tomb(Player p) {
  //Room 10
  //Boss

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand before an ominous tomb.\n\n"
    << "To the north is the basement.\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        roomNumber_ = 7;
        inRoom = false;
        break;
      case 'L':
        LookAround(p);
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

void Game::LookAround(Player p) {
  int i = (rand()%6) + 1;
  cout << "You look around and find... \n";
  switch (i) {
    case 1:
      cout << "A thing!\n";
      break;
    case 2:
      cout << "A hidden secret!\n";
      break;
    case 3:
      cout << "A weapon!";
      break;
    case 4:
      cout << "A piece of armor!";
      break;
    case 5:
      cout << "A mysterious force acts!\n";
      break;
    case 6:
      cout << "An enemy approaches!\n";
      break;
    default:
      cerr << "Invalid random number generation.\n";
      break;
  }
  cout << "You roll a " << i << endl;
}
