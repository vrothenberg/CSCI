#include "Game.h"




//Constructor
Game::Game() {
  srand((unsigned)time(0));
  gameOver_ = false;
}

//Runs primary game loop
//Prints out high scores
void Game::Start() {
  ClearScreen();
  cout << "Welcome to A Spooky Domicile!\n\n";
  HighScores();
  newPlayer_.Initialize();
  while(!gameOver_) {
    LoadRoom(newPlayer_);
  }
  UpdateHighScores();
}

//Helper Functions

//Loads room from player class attributes
void Game::LoadRoom(Player& p) {
  ClearScreen();
  int num = p.GetRoomNumber();
  p.IncrementRoomVisits();
  cout << "LoadRoomNumber: " << num << endl;

  switch(p.GetRoomNumber()) {
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

//Increments number of cycles in game displays current information
void Game::Tick(Player& p) {
  gameTicks_++;
  HUD(newPlayer_);
}

//Displays current information
void Game::HUD(Player& p) {
  //stringf padding
  cout << "Tick: " << gameTicks_ << " Room visits: " << p.GetRoomVisits() << endl;
  cout << p.GetName() << " the Level " << p.GetLevel() << " " << p.GetRole() << endl;
  //cout << "Health: " << p.GetHealth() << " Wealth: " << p.GetWealth() << endl;
  printf("Health : %3d Wealth  : %3d \n", p.GetHealth(), p.GetWealth());
  //cout << "Attack: " << p.GetAttack() << " Defense: " << p.GetArmor() << endl;
  printf("Attack : %3d Defense : %3d \n", p.GetAttack(), p.GetArmor());
  cout << "Weapon: " << p.GetWeaponName() << " Armor: " << p.GetArmorName() << endl << endl;
  p.PrintMessages();
}

//Creates vector of scores from highscores.txt file
void Game::HighScores() {
  scores_ = CreateVector("highscores.txt");
  OutputScores(scores_);

}

//Inserts new ranked score
void Game::UpdateHighScores() {
  vector<string> newScore{newPlayer_.GetName(), to_string(newPlayer_.GetWealth())};
  scores_ = UpdateVector(scores_, newScore);
  SaveToFile(scores_, "highscores.txt");
}

//Room Functions

//Room 1
//Armor, Weapon
void Game::Foyer(Player& p) {

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
        p.SetRoomNumber(2);
        inRoom = false;
        break;
      case 'E':
        p.SetRoomNumber(3);
        inRoom = false;
        break;
      case 'S':
        p.SetRoomNumber(4);
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

//Room 2
//Armor
void Game::SunRoom(Player& p) {

  bool inRoom = true;
  CinReader read;
  string readCharString = "eEsSlL";
  while(inRoom) {
    Tick(p);
    cout << "You bask in the light of the Sun Room.\n"
    << "You feel your health regaining.\n\n"
    << "To the east is the Foyer.\n"
    << "To the south a door leads down a verdant, meandering path.\n\n"
    << "Enter your action: \n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(readCharString));
    ClearScreen();
    switch (c) {
      case 'E':
        p.SetRoomNumber(1);
        inRoom = false;
        break;
      case 'S':
        p.SetRoomNumber(5);
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

//Room 3
//Armor, Weapon
void Game::Office(Player& p) {
  CinReader read;
  bool inRoom = true;
  string readCharString = "eEsSlL";
  while (inRoom) {
    Tick(p);
    cout << "You enter a well furnished Office.\n\n"
    << "To the west is the Foyer.\n"
    << "To the south is the Library.\n\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(S)outh\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(readCharString));
    ClearScreen();
    switch (c) {
      case 'W':
        p.SetRoomNumber(1);
        inRoom = false;
        break;
      case 'S':
        p.SetRoomNumber(6);
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

//Room 4
void Game::Hall(Player& p) {

  int modifier = 2 + p.GetRoomVisits(4);
  CinReader read;
  string readCharString = "nNwWeEsSlL";
  bool inRoom = true;
  while (inRoom) {
    Tick(p);
    int roll = rand() % modifier;
    if (roll==0) {
      Battle b(p, 4);
      b.AddMessage("You walk down the hall and encounter an enemy!");

      p.IncrementRoomVisits();
      modifier = 2 + p.GetRoomVisits(4);
    }

    cout << "You stand in a dimly lit Hall.\n"
    << "Your least favorite art hangs on the walls.\n\n"
    << "To the north is the Foyer.\n"
    << "To the west is the Garden.\n"
    << "To the east is the Library.\n";
    if (basementKey_) cout << "To the south is the basement.\n";
    else cout << "To the south is a locked door.\n";
    cout << "\nEnter your action: \n"
    << "(N)orth\n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";

    char c  = toupper(read.readChar(readCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        p.SetRoomNumber(1);
        inRoom = false;
        break;
      case 'W':
        p.SetRoomNumber(5);
        inRoom = false;
        break;
      case 'E':
        p.SetRoomNumber(6);
        inRoom = false;
        break;
      case 'S':
        if (basementKey_) {
          p.SetRoomNumber(7);
          inRoom = false;
        } else {
          p.AddMessage("The door won't open.");
        }
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

//Room 5
//Weapon
void Game::Garden(Player& p) {

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
    cout << "\nEnter your action: \n"
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
        p.SetRoomNumber(2);
        inRoom = false;
      case 'E':
        p.SetRoomNumber(4);
        inRoom = false;
        break;
      case 'S':
        if (caveDiscovered_) {
          p.SetRoomNumber(8);
          inRoom = false;
        } else p.AddMessage("The thicket repels you.");
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

//Room 6
//Weapon
void Game::Library(Player& p) {

  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNwWlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand in a dusty library.  Books tower above.\n\n"
    << "To the north is the Office.\n"
    << "To the west is the Hall.\n\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(W)est\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        p.SetRoomNumber(3);
        inRoom = false;
      case 'W':
        p.SetRoomNumber(4);
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

//Room 7
//Armor, Weapon
void Game::Basement(Player& p) {

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
    << "To the south is a stone doorway.  It's engraved with glowing symbols.\n\n"
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
        p.SetRoomNumber(4);
        inRoom = false;
      case 'W':
        p.SetRoomNumber(8);
        inRoom = false;
        break;
      case 'E':
        p.SetRoomNumber(9);
        inRoom = false;
        break;
      case 'S':
        p.AddMessage("The tomb opens!  You fall into its depths.");
        p.SetRoomNumber(10);
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

//Room 8
void Game::Cave(Player& p) {


  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNeElL";
  while (inRoom) {
    Tick(p);
    cout << "You hunch down in a small, dark cave.\n\n"
    << "To the north sunlight breaches the crevices.\n"
    << "To the east a cavern opens.\n\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(E)ast\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        caveDiscovered_ = true;
        p.SetRoomNumber(5);
        inRoom = false;
      case 'E':
        p.SetRoomNumber(7);
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

//Room 9
//Armor, Weapon
void Game::Utility(Player& p) {


  bool inRoom = true;
  CinReader read;
  string roomCharString = "wWlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand in a well-stocked utility room.\n\n"
    << "To the west is the maintenance door.\n\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'W':
        p.SetRoomNumber(7);
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

//Room 10
//Boss
void Game::Tomb(Player& p) {


  bool inRoom = true;
  CinReader read;
  string roomCharString = "nNlL";
  while (inRoom) {
    Tick(p);
    cout << "You stand before an ominous tomb.\n\n"
    << "To the north is the basement.\n\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(L)ook around\n";
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();
    switch (c) {
      case 'N':
        p.SetRoomNumber(7);
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

void Game::LookAround(Player& p) {
  int divisor = 5;
  if (p.GetRoomNumber() >= 4) divisor = 6;
  int treasure = (10 * (rand()%p.GetRoomNumber() + 1))/(p.GetRoomVisits());

  int i = (rand()%divisor) + 1;
  p.AddMessage("You look around and find...");
  switch (i) {
    case 1:
      //Wealth
      //Decreases in proportion to room visits
      p.AddMessage("Treasure!");
      p.AddMessage(treasure + " wealth gained.");
      p.SetWealth(p.GetWealth() + treasure );
      break;
    case 2:
      //Hidden secret
      if (!basementKey_) {
        p.AddMessage("You found a key!");
        basementKey_ = true;
      } else if(p.GetRoomNumber() == 5 && !caveDiscovered_) {
        caveDiscovered_ = true;
        p.AddMessage("You discovered a cave!");
      } else {
        p.AddMessage("Treasure!");
        p.AddMessage(treasure + " wealth gained.");
        //int treasure = (10 * (rand()%p.GetRoomNumber() + 1))/(p.GetRoomVisits());
        p.SetWealth(p.GetWealth() + treasure );
      }
      break;
    case 3:
      //Weapon
      if (weapons_.find(p.GetRoomNumber()) != weapons_.end()) {
        Weapon weapon = weapons_[p.GetRoomNumber()];
        if (weapon.attackModifier_ > p.GetAttackModifier()) {
          p.SetAttackModifier(weapon.attackModifier_);
          p.SetWeaponName(weapon.name_);
          p.AddMessage("A weapon!");
          p.AddMessage("You now wield the " + weapon.name_);
        } else {
          p.AddMessage("Lousy junk.");
        }

      } else {
        p.AddMessage("Nothing.");
      }

      break;
    case 4:
      //Armor
      if (armors_.find(p.GetRoomNumber()) != armors_.end()) {
        Armor armor = armors_[p.GetRoomNumber()];
        if (armor.armorModifier_ > p.GetArmorModifier()) {
          p.SetArmorModifier(armor.armorModifier_);
          p.SetArmorName(armor.name_);
          p.AddMessage("A piece of armor!");
          p.AddMessage("You now wear the " + armor.name_);
        } else {
          p.AddMessage("Lousy junk");
        }

      } else {
        p.AddMessage("Nothing");
      }
      break;
    case 5:
      p.AddMessage("A mysterious force acts!\n");
      if (p.GetHealth() < p.GetMaxHealth()) {
        p.SetHealth(p.GetMaxHealth());
        p.AddMessage("Your health rejuvenates.\n");
      } else {
        p.AddMessage("Yet it remains a mystery.");
      }

      break;
    case 6:
      {
        Battle lookBattle(p, p.GetRoomNumber());
        lookBattle.AddMessage("An enemy approaches!\n");
      }
      break;
    default:
      cerr << "Invalid random number generation.\n";
      break;
  }
  p.IncrementRoomVisits();
}

Weapon w1 = {1, 1, "Umbrella"};
Weapon w2 = {3, 2, "Red Stapler"};
Weapon w3 = {5, 3, "Old Hoe"};
Weapon w4 = {6, 4, "Bible"};
Weapon w5 = {7, 5, "Pool Noodles"};
Weapon w6 = {9, 6, "Jumper Cables"};

Armor a1 = {1, 1, "Raincoat"}; //Foyer
Armor a2 = {2, 2, "Tanning Goggles"}; //Sunroom
Armor a3 = {3, 3, "Snazzy Polo"}; //Office
Armor a4 = {7, 4, "'Alternative' Leather Garb"}; //Basement
Armor a5 = {9, 5, "Welding Mask"}; //Utility

Game::WeaponMap Game::weapons_ = {
    { 1, w1 },
    { 3, w2 },
    { 5, w3 },
    { 6, w4 },
    { 7, w5 },
    { 9, w6 }
};

Game::ArmorMap Game::armors_ = {
    { 1, a1 },
    { 2, a2 },
    { 3, a3 },
    { 7, a4 },
    { 9, a5 }
};
