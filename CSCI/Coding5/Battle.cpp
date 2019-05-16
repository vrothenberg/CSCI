#include "Battle.h"

Battle::Battle(Player& p, int room) {
  Enemy newEnemy(room, rand()%3);
  AddMessage("The battle has begun!");
  BattleLoop(p, newEnemy);

}

Battle::Battle(Player& p, Enemy& e) {
  AddMessage("The battle has begun!");
  BattleLoop(p, e);
}


//Battle loop, halts if either player or enemy health drops to 0 or lower

void Battle::BattleLoop(Player& p, Enemy& e) {
  ClearScreen();
  CinReader read;
  while (!battleOver && p.GetHealth() > 0 && e.GetHealth() > 0) {
    round_++;
    cout << "Round: " << round_ << endl;
    cout << p.GetName() << " the level " << p.GetLevel() << " " << p.GetRole() << endl;
    cout << "Health: " << p.GetHealth() << " Wealth: " << p.GetWealth() << endl << endl;
    cout << "======== VERSUS ===========\n"
    << "Level " << e.GetLevel() << " " << e.GetRole() << endl
    << "Health: " << e.GetHealth() << endl << endl;
    PrintMessages();
    string readCharString = "wWbBrR";
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

    char c = toupper(read.readChar(readCharString));
    //Enemy action
    int enemyAction = rand() % 2;
    int playerAction = 0;
    int playerDeflect = 0;
    ClearScreen();
    int damageToEnemy = 0;
    int damageToPlayer = 0;
    switch(c) {
      case 'W':
        //Weapon
        AddMessage("You attack!");
        PlayerAttack(p, e, enemyAction);
        break;
      case 'S':
        //Sophistry
        AddMessage("You use sophistry!");
        Sophistry(p, e);
        break;
      case 'D':
        //Deflect
        AddMessage("You try to deflect.");
        playerDeflect = 1;
        break;
      case 'B':
        //Block
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
    if (enemyAction == 0 && e.GetHealth() > 0)
      EnemyAttack(e, p, playerAction, playerDeflect);
  }

  if (p.GetHealth() > 0 && e.GetHealth() <= 0) {
    p.AddMessage("The " + e.GetRole() + " has been defeated!\nYou are victorious!");
    p.SetWealth(p.GetWealth() + e.GetWealth());
    p.AddExp(e.GetExp());
    battleOver = true;
  } else if (p.GetHealth() <= 0) {
    p.AddMessage("Game over!");
    battleOver = true;
    p.SetGameOver(true);
  }
}

void Battle::EnemyAttack(Enemy& e, Player& p, bool block, bool deflect) {
  string message;
  AddMessage(e.GetRole() + " attacks!");
  int armorModifier = 0;
  if (block) {
    armorModifier = rand() % 3;
    AddMessage(p.GetName() + " blocks!");
  }

  int damageToPlayer = max( (e.GetAttack() + (rand() % 3)) - (p.GetArmor() + armorModifier), 1);
  int dexDiff = p.GetDexterity() - e.GetDexterity();
  if (deflect) {
    if (p.GetDexterity() > e.GetDexterity() && (rand() % dexDiff) > 0) {
      AddMessage("You successfully deflect!");
      int damageToEnemy = max(( ( (e.GetAttack() + (rand() % 3)) * (dexDiff / p.GetDexterity()) ) - e.GetArmor() ), 1);
      message = "You deflect " + to_string(damageToEnemy) + " damage!";
      e.SetHealth(e.GetHealth() - damageToEnemy);
    } else {
      AddMessage("You fail to deflect!");
      message = "You suffer " + to_string(damageToPlayer) + " damage!";
      p.SetHealth(p.GetHealth() - damageToPlayer);
    }
    AddMessage(message);


  //return damageToPlayer;
  } else {
    message = "You suffer " + to_string(damageToPlayer) + " damage!";
    p.SetHealth(p.GetHealth() - damageToPlayer);
    AddMessage(message);

  }
}

void Battle::PlayerAttack(Player& p, Enemy& e, bool block) {
  int armorModifier = 0;
  if (block) {
    armorModifier = rand() % 3;
    AddMessage(e.GetRole() + " blocks!");
  }
  int damageToEnemy = max( ( p.GetAttack() + (rand() % 3) ) - (e.GetArmor() + armorModifier) , 1);
  e.SetHealth(e.GetHealth() - damageToEnemy);
  string message = "You inflicted " + to_string(damageToEnemy) + " damage upon the " + e.GetRole();
  AddMessage(message);
  //return damageToEnemy;
}

void Battle::Sophistry(Player& p, Enemy& e) {
  if (p.GetIntelligence() > e.GetIntelligence()) {
    p.AddMessage("Your intellect deterritorializes the totality of the enemy's interiority!");
    p.AddMessage(e.GetRole() + " hurt itself in its confusion!");
    e.SetHealth(e.GetHealth() - (p.GetIntelligence() - e.GetIntelligence()));
  } else {
    p.AddMessage("The post-modern dialectic deconstructs your paradigm!");
    p.AddMessage("You hurt yourself out of confusion!");
    p.SetHealth(p.GetHealth() - (e.GetIntelligence() - p.GetIntelligence()));
  }

}

//Queues messages for output below HUD
void Battle::AddMessage(string s) {
  messages_ += s + "\n";
}

void Battle::PrintMessages() {
  string output = messages_;
  messages_ = "";
  cout << output;
}
