#include "Battle.h"

//Battle Constructor
//Creates 1 of 3 possible enemies based on room number
//Calls BattleLoop for primary combat logic
Battle::Battle(Player& p, int room) {
  Enemy newEnemy(room, rand()%3);
  BattleLoop(p, newEnemy);
}

//Starts a battle using given player and enemy objects
Battle::Battle(Player& p, Enemy& e) {
  BattleLoop(p, e);
}


//Battle loop, halts if either player or enemy health drops to 0 or lower
void Battle::BattleLoop(Player& p, Enemy& e) {
  CinReader read;
  ClearScreen();

  //Battle introduction and enemy taunt messages
  AddMessage("An enemy approaches!\n");
  AddMessage(e.GetRole() + " : " + e.GetTaunt());

  //Main loop
  while (!battleOver) {
    //Increment round
    round_++;

    //Prints battle details and stats
    cout << "Round: " << round_ << endl << endl
    << "================================\n\n"
    << p.GetName() << " the level " << p.GetLevel() << " " << p.GetRole() << endl;
    printf("Health : %12d Wealth  : %d \n", p.GetHealth(), p.GetWealth());
    printf("Attack : %12d Defense : %d \n", p.GetAttack(), p.GetArmor());
    printf("Weapon : %12s Armor   : %s\n\n", p.GetWeaponName().c_str(), p.GetArmorName().c_str());
    cout << "============ VERSUS ============\n\n"
    << "Level " << e.GetLevel() << " " << e.GetRole() << endl;
    printf("Health : %12d Wealth  : %d \n", e.GetHealth(), e.GetWealth());
    printf("Attack : %12d Defense : %d \n\n", e.GetAttack(), e.GetArmor());
    PrintMessages();

    //Set of valid actions
    string readCharString = "wWbBrR";

    //
    cout << "\nEnter your action: \n"
    << "(W) Weapon\n";
    if (p.GetIntelligence() > 3) {
      cout << "(S) Sophistry\n";
      readCharString += "sS";
    }
    if (p.GetDexterity() > 3) {
      cout << "(D) Deflect\n";
      readCharString += "dD";
    }
    cout << "(B) Block\n"
    << "(R) Run\n";

    //Read player input and convert to uppercase for switch statement
    char c = toupper(read.readChar(readCharString));

    //Enemy action, if greater than 0
    int enemyAction = rand() % 3;
    //Battle variables
    int playerAction = 0;
    int playerDeflect = 0;
    int damageToEnemy = 0;
    int damageToPlayer = 0;

    ClearScreen();

    //Action branch
    switch(c) {
      case 'W':
        //Weapon attack
        AddMessage("You attack!");
        PlayerAttack(p, e, enemyAction);
        break;
      case 'S':
        //Sophistry attack, uses intelligence stat
        AddMessage("You use sophistry!");
        Sophistry(p, e);
        break;
      case 'D':
        //Deflect move, uses dexterity stat
        AddMessage("You try to deflect.");
        playerDeflect = 1;
        break;
      case 'B':
        //Block, raises defense
        AddMessage("You try to block.");
        playerAction = 1;
        break;
      case 'R':
        if (p.GetSpeed() > e.GetSpeed()) {
          AddMessage("You run!");
          battleOver = true;
        } else {
          AddMessage("You can't outrun the "  + e.GetRole());
        }
        break;
      default:
        cerr << "Invalid action.\n";
        break;
    }
    //Enemy attacks 2/3 of time and if their health is greater than 0
    if (enemyAction > 0 && e.GetHealth() > 0) {
      EnemyAttack(e, p, playerAction, playerDeflect);
    }

    //Battle finished
    //Enemy defeated
    if (p.GetHealth() > 0 && e.GetHealth() <= 0) {
      p.AddMessage("The " + e.GetRole() + " has been defeated!");
      p.SetWealth(p.GetWealth() + e.GetWealth());
      p.AddMessage("You gain " + to_string(e.GetWealth()) + " wealth.");
      p.AddExp(e.GetExp());
      //Check if boss defeated
      if (e.GetRole() == "Big Guy 4U") {
        p.AddMessage("You win A Spooky Domicile!");
        p.SetGameOver(true);
      }
      battleOver = true;
    //Player defeated
    } else if (p.GetHealth() <= 0) {
      p.AddMessage("You were defeated!");
      p.SetGameOver(true);
      battleOver = true;
    }
  }
}


//Enemy attack function, enemy and player objects passed by reference
//Player block and deflect actions must be provided
void Battle::EnemyAttack(Enemy& e, Player& p, bool block, bool deflect) {
  AddMessage(e.GetRole() + " attacks!");
  int armorModifier = 0;

  //Player blocks
  if (block) {
    armorModifier = rand() % 3;
    AddMessage(p.GetName() + " blocks!");
  }
  string message;
  int damageToPlayer = max( (e.GetAttack() + (rand() % 3)) - (p.GetArmor() + armorModifier), 1);
  int dexDiff = p.GetDexterity() - e.GetDexterity();
  bool deflectSucceeds = false;

  //Player deflects
  if (deflect) {
    //Deflect successful if player dexterity greater than enemy dexterity
    //Higher chance the greater the disparity
    if (p.GetDexterity() > e.GetDexterity() && (rand() % dexDiff) > 0) {
      AddMessage("You successfully deflect!");
      int damageToEnemy = max(( ( (e.GetAttack() + (rand() % 3)) * (dexDiff / p.GetDexterity()) ) - e.GetArmor() ), 1);
      message = "You deflect " + to_string(damageToEnemy) + " damage!";
      e.SetHealth(e.GetHealth() - damageToEnemy);
    } else {
      //Deflect fails
      AddMessage("You fail to deflect!");
      message = "You suffer " + to_string(damageToPlayer) + " damage!";
      p.SetHealth(p.GetHealth() - damageToPlayer);
    }
    AddMessage(message);
  } else {
    //Player does not deflect or block
    message = "You suffer " + to_string(damageToPlayer) + " damage!";
    p.SetHealth(p.GetHealth() - damageToPlayer);
    AddMessage(message);
  }
}

//Player attack function, player and enemy objects passed by reference
//Enemy block action must be provided
void Battle::PlayerAttack(Player& p, Enemy& e, bool block) {
  int armorModifier = 0;

  //Enemy blocks
  //enemyAction is an int and provided for bool block argument, 0 is block and greater is attack
  if (!block) {
    armorModifier = rand() % 3;
    AddMessage(e.GetRole() + " blocks!");
  }
  //Calculates damage
  int damageToEnemy = max( ( p.GetAttack() + (rand() % 3) ) - (e.GetArmor() + armorModifier) , 1);
  e.SetHealth(e.GetHealth() - damageToEnemy);
  string message = "You inflicted " + to_string(damageToEnemy) + " damage upon the " + e.GetRole();
  AddMessage(message);
}


//Sophistry attack based on intelligence stat
void Battle::Sophistry(Player& p, Enemy& e) {
  if (p.GetIntelligence() > e.GetIntelligence()) {
    AddMessage("Your intellect deterritorializes the totality of the enemy's interiority!");
    int damage = p.GetIntelligence() - e.GetIntelligence();
    AddMessage(e.GetRole() + " inflicted " + to_string(damage) + " damage to itself in its confusion!");
    e.SetHealth(e.GetHealth() - damage);
  } else {
    AddMessage("The post-modern dialectic deconstructs your paradigm!");
    AddMessage("You hurt yourself out of confusion!");
    p.SetHealth(p.GetHealth() - (e.GetIntelligence() - p.GetIntelligence()));
  }
}

//Queues messages for output below HUD
void Battle::AddMessage(string s) {
  messages_ += s + "\n";
}

//Outputs messages and resets queue
void Battle::PrintMessages() {
  string output = messages_;
  messages_ = "";
  cout << output;
}
