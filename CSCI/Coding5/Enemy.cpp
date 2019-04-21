#include "Enemy.h"

Enemy::Enemy();
Enemy::Enemy(int room, int difficulty) {
  Game.roomEnemyArray_[room][difficulty];
}

//Accessor Functions
string Enemy::GetRole() {
  return role_;
}
int Enemy::GetLevel() {
  return level_;
}
int Enemy::GetExp() {
  return experience_;
}
int Enemy::GetWealth() {
  return wealth_;
}
int Enemy::GetHealth() {
  return health_;
}
int Enemy::GetAttack() {
  return attack_;
}
int Enemy::GetArmor() {
  return armor_;
}
int Enemy::GetDexterity() {
  return dexterity_;
}
int Enemy::GetIntelligence() {
  return intelligence_;
}
int Enemy::GetSpeed() {
  return speed_;
}

//Mutator Functions
void Enemy::Creation() {

}
void Enemy::SetAttributes(string role, int level, int experience, int health,
  int attack, int armor, int dexterity, int intelligence, int speed);
void Enemy::SetRole(string role);
void Enemy::SetLevel(int level);
void Enemy::SetExp(int exp);
void Enemy::SetHealth(int health);
void Enemy::SetAttack(int attack);
void Enemy::SetArmor(int armor);
void Enemy::SetDexterity(int dexterity);
void Enemy::SetIntelligence(int intelligence);
void Enemy::SetSpeed(int speed);
