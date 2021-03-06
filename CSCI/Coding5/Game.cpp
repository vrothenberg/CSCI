#include "Game.h"

//Constructor
Game::Game() {
  srand((unsigned)time(0));
  gameOver_ = false;
}

//Prints title screen and high score table.
//Runs player initialization and primary game loop
void Game::Start() {
  ClearScreen();
  cout << "\n             A Spooky Domicile\n\n";
  HighScores();
  player_.Initialize();
  while(!player_.GetGameOver()) {
    LoadRoom();
  }
  GameOver();
}

//Helper Functions

//Loads room function from player class roomNumber_
void Game::LoadRoom() {
  ClearScreen();
  int num = player_.GetRoomNumber();
  player_.IncrementRoomVisits();

  switch(player_.GetRoomNumber()) {
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
      cerr << "Invalid room number.\n";
      break;
  }
}

//Increments number of cycles in game
//Calls HUD to display current information
void Game::Tick() {
  gameTicks_++;
  HUD();
}

//Displays current information
void Game::HUD() {
  cout << "Tick: " << gameTicks_ << " Room visits: " << player_.GetRoomVisits() << endl;
  cout << player_.GetName() << " the Level " << player_.GetLevel() << " " << player_.GetRole() << endl;
  printf("Health : %12d Wealth  : %d \n", player_.GetHealth(), player_.GetWealth());
  printf("Attack : %12d Defense : %d \n", player_.GetAttack(), player_.GetArmor());
  printf("Weapon : %12s Armor   : %s\n\n", player_.GetWeaponName().c_str(), player_.GetArmorName().c_str());
  //Displays enqueued messages
  player_.PrintMessages();
}

//Creates vector of scores from highscores.txt file
void Game::HighScores() {
  scores_ = CreateVector("HighScores.txt");
  OutputScores(scores_);
}

//Inserts new ranked score into high score vector and writes to file
void Game::UpdateHighScores() {
  vector<string> newScore{player_.GetName(), to_string(player_.GetWealth())};
  scores_ = UpdateVector(scores_, newScore);
  SaveToFile(scores_, "HighScores.txt");
}

//Game over function, stores score in high scores.
void Game::GameOver() {
  string x;
  player_.PrintMessages();
  UpdateHighScores();
  HighScores();
  cout << "Your score : " << to_string(player_.GetWealth()) << endl;
  //Pause console to prevent abrupt shutdown
  cout << "Thanks for playing!\n";
  cin >> x;
}

//Chance of a battle when entering room
//Chance inversely proportion to room visits
void Game::BattleRoll(int danger) {
  int modifier = 2 + player_.GetRoomVisits();
  int roll = rand() % modifier;
  if (roll < danger) {
    player_.AddMessage("An enemy emerges from the shadows!\n");
    Battle b(player_, player_.GetRoomNumber());
    player_.IncrementRoomVisits();
  }
}

//Room Functions

//Room 1
//Armor, Weapon
void Game::Foyer() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid action inputs
  string readCharString = "wWeEsSlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Increment gameTicks_, room visits, display HUD
    Tick();

    //Room description and actions
    cout << "You stand in the Foyer.\n\n"
    << "To the west the sun flows through a large glass door.\n"
    << "To the east is an old mahogany door.\n"
    << "To the south is a dimly lit hallway.\n\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";

    //Read player input
    char c = toupper(read.readChar(readCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'W':
        player_.SetRoomNumber(2);
        inRoom = false;
        break;
      case 'E':
        player_.SetRoomNumber(3);
        inRoom = false;
        break;
      case 'S':
        player_.SetRoomNumber(4);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 2
//Armor
//Regenerating health
void Game::SunRoom() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid action inputs
  string readCharString = "eEsSlL";
  CinReader read;

  //Regenerates health on room entry
  player_.SetHealth(player_.GetMaxHealth());

  //Room loop, continues until player leaves room, dies, or defeats boss
  while(inRoom && !player_.GetGameOver()) {
    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You bask in the light of the Sun Room.\n"
    << "You feel your health regaining.\n\n"
    << "To the east is the Foyer.\n"
    << "To the south a door leads down a verdant, meandering path.\n\n"
    << "Enter your action: \n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";

    //Read player input
    char c = toupper(read.readChar(readCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'E':
        player_.SetRoomNumber(1);
        inRoom = false;
        break;
      case 'S':
        player_.SetRoomNumber(5);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 3
//Armor, Weapon
void Game::Office() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid actions
  string readCharString = "wWsSlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You stand in a well furnished Office.\n\n"
    << "To the west is the Foyer.\n"
    << "To the south is the Library.\n\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(S)outh\n"
    << "(L)ook around\n";

    //Read player input
    char c = toupper(read.readChar(readCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'W':
        player_.SetRoomNumber(1);
        inRoom = false;
        break;
      case 'S':
        player_.SetRoomNumber(6);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 4
void Game::Hall() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid actions
  string readCharString = "nNwWeEsSlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Chance of battle while in room
    BattleRoll(4);
    if (player_.GetGameOver()) break;

    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You stand in a dimly lit Hall.\n"
    << "Your least favorite art hangs on the walls.\n\n"
    << "To the north is the Foyer.\n"
    << "To the west is the Garden.\n"
    << "To the east is the Library.\n";
    //Checks if player has found basement key to enable progress into basement
    if (basementKey_) cout << "To the south is the basement.\n";
    else cout << "To the south is a locked door.\n";
    cout << "\nEnter your action: \n"
    << "(N)orth\n"
    << "(W)est\n"
    << "(E)ast\n"
    << "(S)outh\n"
    << "(L)ook around\n";

    //Read player input
    char c  = toupper(read.readChar(readCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'N':
        player_.SetRoomNumber(1);
        inRoom = false;
        break;
      case 'W':
        player_.SetRoomNumber(5);
        inRoom = false;
        break;
      case 'E':
        player_.SetRoomNumber(6);
        inRoom = false;
        break;
      case 'S':
        if (basementKey_) {
          player_.SetRoomNumber(7);
          inRoom = false;
        } else {
          player_.AddMessage("The door won't open.");
        }
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 5
//Weapon
void Game::Garden() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid actions
  string roomCharString = "nNeEsSlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Chance of battle while in room
    BattleRoll(4);
    if (player_.GetGameOver()) break;

    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You stand in an overgrown garden.\n\n"
    << "To the north is the Sun Room.\n"
    << "To the east is the Hall.\n";

    //Checks if player has discovered cave to enable progress into cave
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

    //Read player input
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'N':
        player_.SetRoomNumber(2);
        inRoom = false;
        break;
      case 'E':
        player_.SetRoomNumber(4);
        inRoom = false;
        break;
      case 'S':
        if (caveDiscovered_) {
          player_.SetRoomNumber(8);
          inRoom = false;
        } else player_.AddMessage("The thicket repels you.");
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 6
//Weapon
void Game::Library() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid actions
  string roomCharString = "nNwWlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Chance of battle while in room
    BattleRoll(4);
    if (player_.GetGameOver()) break;

    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You stand in a dusty library.  Books tower above.\n\n"
    << "To the north is the Office.\n"
    << "To the west is the Hall.\n\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(W)est\n"
    << "(L)ook around\n";

    //Read player input
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'N':
        player_.SetRoomNumber(3);
        inRoom = false;
        break;
      case 'W':
        player_.SetRoomNumber(4);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 7
//Armor, Weapon
void Game::Basement() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid inputs
  string roomCharString = "nNwWeEsSlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Chance of battle while in room
    BattleRoll(7);
    if (player_.GetGameOver()) break;

    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
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

    //Read player input
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'N':
        player_.SetRoomNumber(4);
        inRoom = false;
        break;
      case 'W':
        player_.SetRoomNumber(8);
        inRoom = false;
        break;
      case 'E':
        player_.SetRoomNumber(9);
        inRoom = false;
        break;
      case 'S':
        player_.AddMessage("The tomb opens!  You fall into its depths.");
        player_.SetRoomNumber(10);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 8
void Game::Cave() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid inputs
  string roomCharString = "nNeElL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Chance of battle while in room
    BattleRoll(6);
    if (player_.GetGameOver()) break;

    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You hunch down in a small, dark cave.\n\n"
    << "To the north sunlight breaches the crevices.\n"
    << "To the east a cavern opens.\n\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(E)ast\n"
    << "(L)ook around\n";

    //Read player input
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'N':
        caveDiscovered_ = true;
        player_.SetRoomNumber(5);
        inRoom = false;
        break;
      case 'E':
        player_.SetRoomNumber(7);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 9
//Armor, Weapon
void Game::Utility() {
  //Flag for while loop
  bool inRoom = true;

  //Set of valid actions
  string roomCharString = "wWlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Chance of battle while in room
    BattleRoll(8);
    if (player_.GetGameOver()) break;

    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You stand in a well-stocked utility room.\n\n"
    << "To the west is the maintenance door.\n\n"
    << "Enter your action: \n"
    << "(W)est\n"
    << "(L)ook around\n";

    //Read player input
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'W':
        player_.SetRoomNumber(7);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Room 10
//Boss
void Game::Tomb() {
  //Flag for game loop
  bool inRoom = true;

  //Set of valid actions
  string roomCharString = "nNlL";
  CinReader read;

  //Room loop, continues until player leaves room, dies, or defeats boss
  while (inRoom && !player_.GetGameOver()) {
    //Chance of battle while in room
    BattleRoll(9);
    if (player_.GetGameOver()) break;

    //Increments gameTicks_, room visits, and displays HUD
    Tick();

    //Room description and actions
    cout << "You stand before an ominous tomb.\n\n"
    << "To the north is the basement.\n\n"
    << "Enter your action: \n"
    << "(N)orth\n"
    << "(L)ook around\n";

    //Read player input
    char c = toupper(read.readChar(roomCharString));
    ClearScreen();

    //Action branch
    switch (c) {
      case 'N':
        player_.SetRoomNumber(7);
        inRoom = false;
        break;
      case 'L':
        LookAround();
        break;
      default:
        cerr << "Invalid action taken.\n";
        break;
    }
  }
}

//Provides player a chance of finding wealth, items, or an enemy
void Game::LookAround() {
  int divisor = 5;
  //Room numbers 4 or more have enemies, last modulo case triggers battle
  if (player_.GetRoomNumber() >= 4) divisor = 6;
  //Wealth based on room number divided by number of times player has visited room
  int treasure = (10 * (rand()%player_.GetRoomNumber() + 1))/(player_.GetRoomVisits());

  int i = (rand()%divisor) + 1;
  string message;
  player_.AddMessage("You look around...");
  switch (i) {
    case 1:
      //Wealth
      //Decreases in proportion to room visits
      if (treasure > 1) {
        player_.AddMessage("Treasure!");
        message = to_string(treasure) + " wealth gained.";
        player_.AddMessage(message);
        player_.SetWealth(player_.GetWealth() + treasure );
      } else {
        player_.AddMessage("Nothing interesting.");
      }

      break;
    case 2:
      //Hidden secret
      if (!basementKey_) {
        player_.AddMessage("You found a key!");
        basementKey_ = true;
      } else if(player_.GetRoomNumber() == 5 && !caveDiscovered_) {
        caveDiscovered_ = true;
        player_.AddMessage("You discovered a cave!");
      } else if(treasure > 1) {
        player_.AddMessage("Treasure!");
        message = to_string(treasure) + " wealth gained.";
        player_.AddMessage(message);
        player_.SetWealth(player_.GetWealth() + treasure );
      } else {
        player_.AddMessage("Nothing interesting.");
      }
      break;
    case 3:
      //Weapon
      if (weapons_.find(player_.GetRoomNumber()) != weapons_.end()) {
        Weapon weapon = weapons_[player_.GetRoomNumber()];
        if (weapon.attackModifier_ > player_.GetAttackModifier()) {
          player_.SetAttackModifier(weapon.attackModifier_);
          player_.SetWeaponName(weapon.name_);
          player_.AddMessage("A weapon!");
          message = "You now wield the " + weapon.name_;
          player_.AddMessage(message);
        } else {
          player_.AddMessage("Lousy junk.");
        }
      } else {
        player_.AddMessage("Nothing interesting.");
      }
      break;
    case 4:
      //Armor
      if (armors_.find(player_.GetRoomNumber()) != armors_.end()) {
        Armor armor = armors_[player_.GetRoomNumber()];
        if (armor.armorModifier_ > player_.GetArmorModifier()) {
          player_.SetArmorModifier(armor.armorModifier_);
          player_.SetArmorName(armor.name_);
          player_.AddMessage("A piece of armor!");
          message = "You now wear the " + armor.name_;
          player_.AddMessage(message);
        } else {
          player_.AddMessage("Lousy junk.");
        }
      } else {
        player_.AddMessage("Nothing interesting.");
      }
      break;
    case 5:
      //Health regain
      player_.AddMessage("A mysterious force acts!");
      if (player_.GetHealth() < player_.GetMaxHealth()) {
        player_.SetHealth(player_.GetMaxHealth());
        player_.AddMessage("Your health rejuvenates.");
      } else {
        player_.AddMessage("Yet it remains a mystery.");
      }
      break;
    case 6:
      //Random battle
      {
        player_.AddMessage("You find an enemy!\n");
        Battle lookBattle(player_, player_.GetRoomNumber());
      }
      break;
    default:
      cerr << "Invalid random number generation.\n";
      break;
  }
  player_.IncrementRoomVisits();
}

//Weapon structs

Weapon w1 = {1, 1, "Umbrella"};
Weapon w2 = {3, 2, "Abacus"};
Weapon w3 = {5, 3, "Old Hoe"};
Weapon w4 = {6, 4, "Thesaurus"};
Weapon w5 = {7, 5, "Thwacker"};
Weapon w6 = {9, 6, "Rusty Spoon"};

//Armor structs

Armor a1 = {1, 1, "Raincoat"}; //Foyer
Armor a2 = {2, 2, "Sombrero"}; //Sunroom
Armor a3 = {3, 3, "Birkenstocks"}; //Office
Armor a4 = {7, 4, "McAfee AV"}; //Basement
Armor a5 = {9, 5, "Hopes and Prayers"}; //Utility

//Map of weapons for efficient lookup by room number

Game::WeaponMap Game::weapons_ = {
    { 1, w1 },
    { 3, w2 },
    { 5, w3 },
    { 6, w4 },
    { 7, w5 },
    { 9, w6 }
};

//Map of armors for efficient lookup by room number

Game::ArmorMap Game::armors_ = {
    { 1, a1 },
    { 2, a2 },
    { 3, a3 },
    { 7, a4 },
    { 9, a5 }
};
