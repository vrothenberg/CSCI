#include "Enemy.h"
#include "Player.h"

//Constructors
Enemy::Enemy() {
  cout << "Default enemy object constructed.\n";
}

Enemy::Enemy(int room, int difficulty) {
  cout << "Enemy Difficulty: " << difficulty << " Room: " << room << endl;

  cout << Enemies[0].name << ": " << Enemies[0].taunts[0] << endl;

}

EnemyType Enemy::Enemies[8] = {
  {
    "Salty Squatter",
    {"Get outta here!\n", "This is my house now!\n", "I want hamborger!\n"},
    {1, 10, 10, 1, 1, 1, 1, 1}
  },
  {
    "Rude Realtor",
    {"Buy this house!\n", "I've got tiki torches in the back.\n", "This fixer-upper has great potential.\n"},
    {2, 20, 15, 2, 2, 1, 1, 2}
  },
  {
    "Sneaky Snake",
    {"Hiss!\n", "Sss...\n", "I'm a snake!\n"},
    {3, 30, 10, 3, 1, 3, 1, 3}
  },
  {
    "Avaricious Anarchist",
    {"This is my private property!\n", "A.C.A.B. also guns should be illegal.\n", "Read this pamphlet!\n"},
    {4, 40, 20, 4, 3, 3, 3, 4}
  },
  {
    "Crazed Chemist",
    {"Try out this molecule!\n", "I'm high on the universe!\n", "Did you take my flask?!\n"},
    {5, 50, 25, 5, 3, 4, 5, 3}
  },
  {
    "Guano Guy",
    {"This cave is exquisite, so get out!\n", "Bats are beautiful.\n", "One man's treasure..\n"},
    {6, 60, 30, 5, 4, 3, 3, 4}
  },
  {
    "Methy Mechanic",
    {"This Place Is Brimming With ENERGY!\n", "Frick Off!\n", "I'm gonna wrench you!\n"},
    {8, 80, 40, 8, 8, 5, 4, 4}
  },
  {
    "Big Guy ... For You",
    {"The Fire Rises.\n", "It doesn't matter who we are.\n", "I'm crashing this house - with no survivors!\n"},
    {9, 99, 99, 9, 9, 5, 5, 5}
  }
};
