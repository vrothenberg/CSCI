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
    int enemyArmorBoost = 0;
    switch(c) {
      case 'W':
        cout << "You attack!\n";
        if (enemyAction == 0) {
          //Enemy blocks
          cout << e.role_ << " blocks!\n";
          enemyArmorBoost = (rand() % 3) + 1;
          damageToEnemy = max((p.GetAttack() + (rand() % 3)) - (e.GetArmor() + rand() % 3)) , 1);
          e.SetHealth(e.GetHealth() - damageToEnemy);
        } else {
          //Enemy attacks
          damageToEnemy = max((p.GetAttack() + (rand() % 3)) - e.GetArmor() , 1);
          e.SetHealth(e.GetHealth() - damageToEnemy);
          cout << e.role_ << " attacks!\n";
          damageToPlayer = max((e.GetAttack() + (rand() % 3)) - p.GetArmor() , 1);
          p.SetHealth(p.GetHealth() - damageToPlayer);
        }

        cout << damage << " damage!\n\n";


        cout << "You inflicted " << damageToEnemy << " damage!\n";
        cout << "Enemy health: " << e.GetHealth() << endl;
        if


        break;
      case 'B':
        cout << "You block!\n";

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
