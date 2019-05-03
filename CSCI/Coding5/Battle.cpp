#include "Battle.h"

Battle::Battle() {
  cout << "Default battle\n";
}

Battle::Battle(Player p, Enemy e) {
  cout << "The battle has begun!\n";
  CinReader read;
  while (!battleOver && p.GetHealth() > 0 && e.GetHealth() > 0) {
    round_++;
    cout << "Round: " << round_ << endl;
    cout << p.GetName() << " the level " << p.GetLevel() << " " << p.GetRole() << endl;
    cout << "Health: " << p.GetHealth() << " Wealth: " << p.GetWealth() << endl << endl;
    cout << "======== VERSUS ===========\n"
    << "Level " << e.GetLevel() << " " << e.GetRole() << endl
    << "Health: " << e.GetHealth() << endl;
    cout << "Enter your action: \n"
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
        cout << "You attack!\n";
        if (enemyAction == 0) {
          //Enemy blocks
          //cout << e.GetRole() << " blocks!\n";
          //damageToEnemy = max(((p.GetAttack() + (rand() % 3)) - (e.GetArmor() + rand() % 3)) , 1);
          //e.SetHealth(e.GetHealth() - damageToEnemy);
          damageToEnemy = PlayerAttack(p, e, true);
        } else {
          //Enemy attacks

          //damageToEnemy = max((p.GetAttack() + (rand() % 3)) - e.GetArmor() , 1);
          //e.SetHealth(e.GetHealth() - damageToEnemy);
          damageToEnemy = PlayerAttack(p, e, false);
          if (e.GetHealth() > 0) {
            //Enemy survives player attack

            //cout << e.GetRole() << " attacks!\n";
            //damageToPlayer = max((e.GetAttack() + (rand() % 3)) - p.GetArmor() , 1);
            //p.SetHealth(p.GetHealth() - damageToPlayer);
            damageToPlayer = EnemyAttack(e, p, false);
          }
        }

        cout << "You inflicted " << damageToEnemy << " damage!\n";
        //cout << "Enemy health: " << e.GetHealth() << endl;

        break;
      case 'B':
        cout << "You block!\n";
        if (enemyAction == 0) {
          //Enemy blocks
          cout << e.GetRole() << " blocks!\n";
        } else {
          //Enemy attacks
          //cout << e.GetRole() << " attacks!\n";
          //damageToPlayer = max((e.GetAttack() + (rand() % 3)) - (p.GetArmor() + (rand() % 3)), 1);
          //p.SetHealth(p.GetHealth() - damageToPlayer);
          EnemyAttack(e, p, true);
          cout << "You suffered " << damageToPlayer << " damage!\n";
        }

        break;
      case 'R':
        cout << "You run!\n";
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
  cout << e.GetRole() << " attacks!\n";
  int armorModifier = 0;
  if (block) {
    armorModifier = rand() % 3;
    cout << p.GetName() << " blocks!\n";
  }
  int damageToPlayer = max( (e.GetAttack() + (rand() % 3)) - (p.GetArmor() + armorModifier), 1);
  p.SetHealth(p.GetHealth() - damageToPlayer);

  return damageToPlayer;

}

int Battle::PlayerAttack(Player& p, Enemy& e, bool block) {
  int armorModifier = 0;
  if (block) {
    armorModifier = rand() % 3;
    cout << e.GetRole() << " blocks!\n";
  }
  int damageToEnemy = max( ( p.GetAttack() + (rand() % 3) ) - (e.GetArmor() + armorModifier) , 1);
  e.SetHealth(e.GetHealth() - damageToEnemy);
  return damageToEnemy;

}
