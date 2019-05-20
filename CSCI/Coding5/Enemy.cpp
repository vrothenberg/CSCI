#include "Enemy.h"
#include "Player.h"

//Constructors
//Creates enemy object using enemy template array, room number and difficulty level
Enemy::Enemy(int room, int difficulty) {
  int enemyIndex = ROOM_ENEMY_ARRAY[room-4][difficulty];
  EnemyType eTemplate = Enemies[enemyIndex];
  SetAttributes(eTemplate.name, eTemplate.attr[0], eTemplate.attr[1], eTemplate.attr[2],
    eTemplate.attr[3], eTemplate.attr[4], eTemplate.attr[5], eTemplate.attr[6], eTemplate.attr[7]);
  SetWealth(eTemplate.attr[8]);
  for (int i = 0; i < 3; i++) {
    taunts_[i] = eTemplate.taunts[i];
  }
}

string Enemy::GetTaunt() {
  return taunts_[rand()%3];
}

//Array of enemy templates
EnemyType Enemy::Enemies[8] = {
  {
    "Salty Squatter",
    {"Get outta here!\n", "This is my house now!\n", "I want hamborger!\n"},
    {1, 10, 10, 1, 1, 1, 1, 1, 5}
  },
  {
    "Rude Realtor",
    {"Buy this house!\n", "I've got tiki torches in the garage.\n", "This fixer-upper has great potential.\n"},
    {2, 20, 15, 2, 2, 1, 1, 2, 20}
  },
  {
    "Sneaky Snake",
    {"Hiss!\n", "Sss...\n", "I'm a snake!\n"},
    {3, 30, 10, 3, 1, 3, 1, 3, 0}
  },
  {
    "Avaricious Anarchist",
    {"This is my private property!\n", "A.C.A.B. also guns should be illegal.\n", "Read this pamphlet!\n"},
    {4, 40, 20, 4, 3, 3, 3, 4, 10}
  },
  {
    "Crazed Chemist",
    {"Try out this molecule!\n", "I'm high on the universe!\n", "Did you take my flask?!\n"},
    {5, 50, 25, 5, 3, 4, 5, 3, 30}
  },
  {
    "Guano Guy",
    {"This cave is exquisite, so get out!\n", "Bats are beautiful.\n", "One man's treasure..\n"},
    {6, 60, 30, 5, 4, 3, 3, 4, 20}
  },
  {
    "Meth'd Out Mechanic",
    {"This Place Is Brimming With ENERGY!\n", "Frick Off!\n", "I'm gonna wrench you!\n"},
    {8, 80, 40, 8, 8, 5, 4, 4, 50}
  },
  {
    "Big Guy 4U",
    {"The Fire Rises.\n", "It doesn't matter who we are. What matters is our plan.\n", "I'm crashing this house - with no survivors!\n"},
    {9, 99, 99, 9, 9, 5, 5, 5, 99}
  }
};
