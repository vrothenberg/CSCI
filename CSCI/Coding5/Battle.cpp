#include "Battle.h"

Battle::Battle() {
  cout << "Default battle\n";
}

Battle::Battle(Player p, Enemy e) {
  CinReader read;
  string messages = "";
  AddMessage("The battle has begun!");
  while (!battleOver && p.GetHealth() > 0 && e.GetHealth() > 0) {
    round_++;
    cout << "Round: " << round_ << endl;
    cout << p.GetName() << " the level " << p.GetLevel() << " " << p.GetRole() << endl;
    cout << "Health: " << p.GetHealth() << " Wealth: " << p.GetWealth() << endl << endl;
    cout << "======== VERSUS ===========\n"
    << "Level " << e.GetLevel() << " " << e.GetRole() << endl
    << "Health: " << e.GetHealth() << endl << endl;
    PrintMessages();
    cout << "\nEnter your action: \n"
    << "(W) Weapon\n"
    << "(B) Block\n"
    << "(R) Run\n";
    char c = toupper(read.readChar("wWbBrR"));
    //Enemy action
    int enemyAction = rand() % 2;
    ClearScreen();
    int damageToEnemy = 0;
    int damageToPlayer = 0;
    switch(c) {
      case 'W':
        AddMessage("You attack!");
        if (enemyAction == 0) {
          //Enemy blocks
          damageToEnemy = PlayerAttack(p, e, true);
        } else {
          //Enemy attacks
          damageToEnemy = PlayerAttack(p, e, false);
          if (e.GetHealth() > 0) {
            //Enemy survives player attack
            damageToPlayer = EnemyAttack(e, p, false);
          }
        }
        break;
      case 'B':
        AddMessage("You block!");
        if (enemyAction == 0) {
          //Enemy blocks
          cout << e.GetRole() << " blocks!\n";
        } else {
          //Enemy attacks
          damageToPlayer = EnemyAttack(e, p, true);
        }
        break;
      case 'R':
        AddMessage("You run!");
        battleOver = true;
        break;
      default:
        cerr << "Invalid action.\n";
        break;
    }
  }

  if (p.GetHealth() > 0 && e.GetHealth() <= 0) {
    cout << "Victory!\n";
    p.SetWealth(p.GetWealth() + e.GetWealth());
    p.SetExp(p.GetExp() + e.GetExp());
  } else if (p.GetHealth() <= 0) {
    cout << "Game over!\n";
    //gameOver_ = true;
  }

}

int Battle::EnemyAttack(Enemy& e, Player& p, bool block) {
  AddMessage(e.GetRole() + " attacks!");
  int armorModifier = 0;
  if (block) {
    armorModifier = rand() % 3;
    AddMessage(p.GetName() + " blocks!");
  }
  int damageToPlayer = max( (e.GetAttack() + (rand() % 3)) - (p.GetArmor() + armorModifier), 1);
  p.SetHealth(p.GetHealth() - damageToPlayer);
  string message = "You suffered " + to_string(damageToPlayer) + " damage!";
  AddMessage(message);
  return damageToPlayer;
}

int Battle::PlayerAttack(Player& p, Enemy& e, bool block) {
  int armorModifier = 0;
  if (block) {
    armorModifier = rand() % 3;
    AddMessage(e.GetRole() + " blocks!");
  }
  int damageToEnemy = max( ( p.GetAttack() + (rand() % 3) ) - (e.GetArmor() + armorModifier) , 1);
  e.SetHealth(e.GetHealth() - damageToEnemy);
  string message = "You inflicted " + to_string(damageToEnemy) + " damage upon the " + e.GetRole();
  AddMessage(message);
  return damageToEnemy;
}

void Battle::AddMessage(string s) {
  messages_ += s + "\n";
}

string Battle::GetMessages() {
  string temp = messages_;
  messages_ = "";
  return temp;
}

void Battle::PrintMessages() {
  cout << GetMessages();
}
