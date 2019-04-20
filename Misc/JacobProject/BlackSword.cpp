#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "pch.h"

using namespace std;


//Splits a string using a delimiter character e.g. whitespace ' '
//Returns a vector, like an array, a list of values as strings
vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok); //Loops and adds each element to vector
  }
  return internal;
}

vector< vector<string> > createVector(std::string file) {
  vector<vector<string>> fileVector;
  ifstream fin(file);
  if (fin.fail()){
    cerr << "Failed to open file";
    return fileVector;
  }
  std::string line;
  while (std::getline(fin, line)) {
    vector<string> sline = split(line, ' ');
    if (line.size()>1) {
      fileVector.push_back(sline);
    }
  }
  fin.close();
  return fileVector;
}


void saveToFile(vector< vector<string>> inputVector, std::string file) {
  ofstream fout(file);
  for (int i = 0; inputVector.size(); i++) {
    fout << inputVector[i][0] << " " << inputVector[i][1] << endl;
  }
  fout.close();
}

void outputScores(vector<vector<string>> scores){
  cout << "===== HIGH SCORES =====" << endl;
  for (int i = 0; i<scores.size(); i++) {
    string name = scores[i][0];
    int score = stoi(scores[i][1]);
    cout << "Player: " << name << " Score: " << score << endl;
  }
  cout << "=======================" << endl;
}


int main()
{
	string line;
	int exit = 0; // terminates program when =/= 0
	int x; // player command
	//string filename = "highscores.txt";

	cout << "~~~BLACK || SWORD~~~" << endl
		   << "____________________" << endl << endl;


	/*fstream MyFile;
	MyFile.open("highscores.txt");

	getline(MyFile, line);
	cout << line << endl;
	MyFile.close();
*/
	cout << endl << "====================" << endl
		<< "Enter 1 to begin." << endl
		<< "Enter 0 to exit." << endl;
	cin >> x;
	switch (x)
	{
	case 0:
	{
		system("cls");
		cout << endl << "Your Journey ended before it began and your name fades from memory." << endl;
		++exit;
		break;
	}
	case 1:
	{
		system("cls");
		HUD();
		cout << endl << "Old Guard: I am the gate keeper, I see you are wanting to get into the dungeon." << endl
			<< "Old Guard: Well, it's a blessing from the gods that I only have to keep things from getting out." << endl
			<< "Old Guard: Not much comes the other way, you see. Things only go in, but even I, an old man" << endl
			<< "Old Guard: can handle the miscreants that wander the top levels, the bottom ones, not so much, hehe." << endl
			<< "Old Guard: So adventurer, what is your name?" << endl << endl
			<< "My name is... ";
		cin >> Player.PlayerName;

		system("cls");
		HUD();
		cout << "Old Guard: Hello, " << Player.PlayerName << ". You have travelled a long way." << endl
			<< "Old Guard: Before I open the dungeon for you, there is something we must discuss." << endl
			<< "Old Guard: Firstly, what soul has the Gods given you?" << endl << endl
			<< "Enter 1 for the Berserker, exceptional skill with weapons. Quick offensive learning ability." << endl
			<< "Enter 2 for the Tactician, a mastermind that forms impenetrable defenses." << endl
			<< "Enter 3 for the Immortal, an undying warrior who can to regenerate his wounds" << endl
			<< "Enter 4 for the Forsaken, whom which the three Dungeon Gods ignore... for the most part." << endl << endl
			<< "The follow the path of the... ";
		cin >> x;
		if (x == 1)
		{
			Player.Soul = "Berserker";
			system("cls");
			HUD();

			cout << "Old Guard: So Khorne, the Dungeon God of Attack has given you his blessing, use it well, berserker." << endl
				<< "Old Guard: Take my old sword and tunic. I won't be needing them..." << endl << endl;

			Weapon.ItemColor = "Tarnished Grey";
			Weapon.ItemName = "Dirk";
			Player.Atk = Player.Atk + 15;
			Armor.ItemColor = "Tattered Brown";
			Armor.ItemName = "Tunic";
			Player.Def = Player.Def + 10;
			system("pause");

			system("cls");
			HUD();

			cout << "That's everything. ";
			system("pause");
		}
		if (x == 2)
		{
			Player.Soul = "Tactician";
			system("cls");
			HUD;

			Weapon.ItemColor = "Tarnished Grey";
			Weapon.ItemName = "Sling";
			Player.Atk = Player.Atk + 10;
			Armor.ItemColor = "Tattered Brown";
			Armor.ItemName = "Tunic";
			Player.Def = Player.Def + 15;
			system("pause");
		}
		if (x == 3)
		{
			Player.Soul = "Immortal";
			system("cls");
			HUD;

			Weapon.ItemColor = "Tarnished Grey";
			Weapon.ItemName = "Spear";
			Player.Atk = Player.Atk + 13;
			Armor.ItemColor = "Tattered Brown";
			Armor.ItemName = "Tunic";
			Player.Def = Player.Def + 12;
			system("pause");
		}
		if (x == 4)
		{
			Player.Soul = "Forsaken";
			system("cls");
			HUD;

			Weapon.ItemColor = "Tarnished Grey";
			Weapon.ItemName = "Club";
			Player.Atk = Player.Atk + 10;
			Armor.ItemColor = "Tattered Brown";
			Armor.ItemName = "Tunic";
			Player.Def = Player.Def + 10;
			system("pause");
		}

		break;
	}
	};
	while (exit == 0)
	{
		cin >> x;
		system("cls");
		HUD();
		if (x == 0)
		{
			cout << "Goodbye." << endl;
			exit = 1;
		}
		if (x == 1)
		{
			cout << "You entered the front room" << endl; // room and enemy logic
			system("pause");
			RmGen();
		}
		if (x == 2)
		{
			cout << "You entered the left room" << endl; // room and enemy logic
			system("pause");
			RmGen();
		}
		if (x == 3)
		{
			cout << "You entered the right room" << endl; // room and enemy logic
			system("pause");
			RmGen();
		}
		if (x == 5)
		{
			cout << "enter 1 to move forward; 2 to move left; 3 to move right; 5 for available commands; 0 to exit" << endl;
		}
		if (Player.Hlth <= 0)
		{
			++exit;
		}

	}

		/*MyFile.open("highscores.txt");
		getline(MyFile, line);
		MyFile << line << endl <<"Last Game: " << Player.PlayerName << " Score: " << Score << endl;
		MyFile.close(); */
		// ineffective high score method
}
