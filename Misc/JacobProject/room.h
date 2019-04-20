#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "player.h"

using namespace std;


/*

**** CREATES ENEMIES, CHANGES PLAYER PARAMETERS, STEP BY STEP COMBAT, HEAVY LIFTING OF GAME ****

enemy room (4/10)
trap room (1/10)
health refill room(1/10)
special item room (1/10)
boss room (1/10)
auto level room (1/10)
empty room (1/10)

*/

inline void RmGen()
{
	srand((unsigned)time(NULL));
	int x = rand() % 10 + 1; // room spawn chance
	int a = rand() % 9 + 5; // enemy taunts
	int b = rand() % 5 + 1; // room probabilities
	int RmCbt = 0;

	if (x <= 4)
	{
		srand((unsigned)time(0));
		int num1 = rand() % 5 + 1;
		int num2 = rand() % 5 + 1;

		// FIRST NAME MODIFIERS ~~~~~~~
		if (num1 == 1)
		{
			Enemy.CharFName = "Logan";
			Enemy.Atk = Enemy.Atk + 1;
			Enemy.Def = Enemy.Def + 2;
		}
		if (num1 == 2)
		{
			Enemy.CharFName = "Nathan";
			Enemy.Atk = Enemy.Atk + 2;
			Enemy.Def = Enemy.Def + 1;
		}
		if (num1 == 3)
		{
			Enemy.CharFName = "Jacob";
			Enemy.Atk = Enemy.Atk + 2;
			Enemy.Def = Enemy.Def + 2;
		}
		if (num1 == 4)
		{
			Enemy.CharFName = "Amy";
			Enemy.Atk = Enemy.Atk + 2;
			Enemy.Def = Enemy.Def + 2;
		}
		if (num1 == 5)
		{
			Enemy.CharFName = "Saoirse";
			Enemy.Atk = Enemy.Atk + 1;
			Enemy.Def = Enemy.Def + 1;
		}

		//******* LAST NAME MODIFIERS ~~~~~~~~
		if (num2 == 1)
		{
			Enemy.CharLName = "Aurelius";
			Enemy.Atk = Enemy.Atk + 0;
			Enemy.Def = Enemy.Def + 3;
		}
		if (num2 == 2)
		{
			Enemy.CharLName = "Purcell";
			Enemy.Atk = Enemy.Atk + 2;
			Enemy.Def = Enemy.Def + 2;
		}
		if (num2 == 3)
		{
			Enemy.CharLName = "Pixler";
			Enemy.Atk = Enemy.Atk + 1;
			Enemy.Def = Enemy.Def + 2;
		}
		if (num2 == 4)
		{
			Enemy.CharLName = "Rawlins";
			Enemy.Atk = Enemy.Atk + 2;
			Enemy.Def = Enemy.Def + 1;
		}
		if (num2 == 5)
		{
			Enemy.CharLName = "Guiness";
			Enemy.Atk = Enemy.Atk + 1;
			Enemy.Def = Enemy.Def + 1;
		}

		system("cls");
		Enemy.Hlth = 100 + RmNum * 10;
		Enemy.Atk = Enemy.Atk + RmNum * 1.2;
		Enemy.Def = Enemy.Def + RmNum * 1.2;
		EHUD();
		cout << "You are confronted by " << Enemy.CharFName << " " << Enemy.CharLName << "!" << endl;

		//******** ENEMY TAUNTS ~~~~~~~
		if (a == 5)
		{
			cout << Enemy.CharFName << ": Prepare to die!" << endl << endl;
		}
		if (a == 6)
		{
			cout << Enemy.CharFName << ": I will wear you like a cloak!" << endl << endl;
		}
		if (a == 7)
		{
			cout << Enemy.CharFName << ": Fancy meeting you here." << endl << endl;
		}
		if (a == 8)
		{
			cout << Enemy.CharFName << ": You look lost, let me show you the exit..." << endl << endl;
		}
		if (a == 9)
		{
			cout << Enemy.CharFName << ": You have some nice thing, mind if I tske them?" << endl << endl;
		}

		system("pause");

		while (RmCbt == 0)
		{

			system("cls");
			EHUD();

			EnAtk();
			PlrAtk();

			system("pause");

			if (Enemy.Hlth <= 0)
			{
				cout << "you win!";
				++RmCbt;
			}
			if (Player.Hlth <= 0)
			{
				cout << "you scored " << Score;
				++RmCbt;
			}
		}
		++Score;
		++RmNum;
		XpSys();
		system("pause");
	}
	if (x == 5) // trap room
	{
		Player.Hlth = Player.Hlth * 0.45;
		system("cls");
		HUD();
		if (a == 1)// bunch of if statemnts for different story parts
		{

		}
		++RmNum;
		system("pause");
	}
	if (x == 6) // health room
	{
		if (a >= 0 && a <= 9)
		{
			system("cls");
			HUD();
			cout << "In the dark dungeon, a wellspring glows." << endl
				<< "While bathing, you are visited by a mermaid who restores your body and mind." << endl
				<< "Refreshed, you continue your advance." << endl << endl;
		}
		Player.Hlth = Player.Hlth + 100;
		++RmNum;
		system("pause");
		//refills health
	}
	if (x == 7) //boss room
	{
		system("cls");
		HUD();
		cout << "boss room" << x << endl;
		Score = Score + 3;
		++RmNum;
		XpSys();
		system("pause");
		//boss room
		// Score = Score + 5
	}
	if (x == 8)
	{
		system("cls");
		HUD();

		cout << "The three dungeon Gods bestow you with a gift of light that dissapears when you touch it..." << endl << endl;
		PlrLvl();
		++RmNum;
	}// level up room
	if (x == 9)		// empty room
	{
		system("cls");
		HUD();

		cout << "empty room" << endl;
		++RmNum;
		system("pause");
	}
	if (x == 10) // special item room
	{
		system("cls");
		HUD();
		cout << "special item room" << x << endl;
		++RmNum;
		system("pause");
		//special item room
	}
}