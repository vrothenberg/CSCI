#pragma once
#pragma once
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double RmNum = 0; // increases difficulty, item quality, xp
double SklPt;
int XP;
double Score = 0; // scores player performance, used in xp calculation
int Lvl = 1;

class Character
{
public:
	string CharFName, CharLName, PlayerName, Soul;
	int Hlth = 100;
	double Atk = rand() % 10 + 1;
	double Def = rand() % 10 + 1;
	int Int = rand() % 10 + 1;
};

Character Enemy;
Character Player;
Character Boss;

class Item
{
public:
	string ItemName, ItemColor, ItemLegend;
};

Item Weapon;
Item Armor;

void HUD() // player stats no enemy
{
	cout << Player.PlayerName << "    ||||    No Enemy" << endl
		<< "Health: " << Player.Hlth << "    ||||" << endl
		<< "Attack: " << Player.Atk << "    ||||" << endl
		<< "Defense: " << Player.Def << "    ||||" << endl
		<< "Weapon: " << Weapon.ItemColor << " " << Weapon.ItemName << " " << Weapon.ItemLegend << endl
		<< "Armor: " << Armor.ItemColor << " " << Armor.ItemName << " " << Armor.ItemLegend << endl
		<< "Score: " << Score << " | Depth: " << RmNum << " | Level " << Lvl << " " << Player.Soul << endl << endl;
};

void EHUD() // player stats with enemy
{
	cout << Player.PlayerName << "    ||||    " << Enemy.CharFName << " " << Enemy.CharLName << endl
		<< "Health: " << Player.Hlth << "    ||||    " << "Health: " << Enemy.Hlth << endl
		<< "Attack: " << Player.Atk << "    ||||    " << "Attack: " << Enemy.Atk << endl
		<< "Defnese: " << Player.Def << "    ||||    " << "Defense: " << Enemy.Def << endl
		<< "Weapon: " << Weapon.ItemColor << " " << Weapon.ItemName << " " << Weapon.ItemLegend << endl
		<< "Armor: " << Armor.ItemColor << " " << Armor.ItemName << " " << Armor.ItemLegend << endl
		<< "Score: " << Score << " | Depth: " << RmNum << " | Level " << Lvl << " " << Player.Soul << endl << endl;
};

void Soul()
{
	if (Player.Soul == "Berserker")
	{
		Player.Atk = Player.Atk + RmNum * 0.8;
	}
	if (Player.Soul == "Tactician")
	{
		Player.Def = Player.Def + RmNum * 0.8;
	}
	if (Player.Soul == "Immortal")
	{
		Player.Hlth = Player.Hlth + RmNum * 0.8;
	}
	if (Player.Soul == "Forsaken")
	{
		Score = Score + RmNum * 0.8;
	}
}

void PlrLvl()
{
	XP = RmNum * 1.5 + 10;
	system("cls");
	HUD();
	cout << "You have increased in power!" << endl
		<< "You have " << XP << " points to add." << endl
		<< "Increase attack by... ";
	cin >> SklPt;
	if (XP >= SklPt)
	{
		Player.Atk = Player.Atk + SklPt;
		XP = XP - SklPt;
	}
	else
	{
		system("cls");
		HUD();
		cout << "You should have entered a number below " << XP << ". The God of Attack has forsaken you this round." << endl << endl;
		system("pause");
	}
	if (XP > 0)
	{
		system("cls");
		HUD();
		cout << endl << "You  still have " << XP << " points to add." << endl
			<< "Increase defense by... ";
		cin >> SklPt;
		if (XP >= SklPt)
		{
			Player.Def = Player.Def + SklPt;
			XP = XP - SklPt;
		}
		else
		{
			system("cls");
			HUD();
			cout << "You should have entered a number below " << XP << ". The God of Defense has forsaken you this round." << endl << endl;
			system("pause");
		}
	}
	if (XP > 0)
	{
		system("cls");
		HUD();
		cout << endl << "The remainder is offered the the Health God." << endl << endl;
		Player.Hlth = Player.Hlth + XP * 15;
		system("pause");
	}
	if (XP == 0)
	{
		system("cls");
		HUD();
		cout << "With your new abilites you find the courage to proceed..." << endl << endl;
		system("pause");
	}
};

void XpSys()
{
	double Exp = sin(RmNum + Score);
	double ExFunc = 0.002*(RmNum + Score);
	if (Exp >= ExFunc)
	{
		cout << "You reflect on your journey this far and..." << endl;
		PlrLvl();
		Soul();
		++Lvl;
	}
};

void EnAtk()
{
	double RDmg = (rand() % 10) * 5;
	if (RDmg >= 40)
	{
		cout << Enemy.CharFName << " landed a critical blow!" << endl;;
	}
	int Dmg = (Enemy.Atk / Player.Def) * RDmg;
	Player.Hlth = Player.Hlth - Dmg;
	cout << Enemy.CharFName << " " << Enemy.CharLName << " " << Enemy.CharFName << " dealt " << Dmg << " damage!" << endl << endl;
};

void PlrAtk()
{
	double RDmg = (rand() % 10) * 5;
	if (RDmg >= 40)
	{
		cout << Player.PlayerName << " landed a critical blow!" << endl;
	}
	int Dmg = (Player.Atk / Enemy.Def) * RDmg;
	Enemy.Hlth = Enemy.Hlth - Dmg;
	cout << Player.PlayerName << " dealt " << Dmg << " damage!" << endl << endl;
};


/*
item name generator
*/