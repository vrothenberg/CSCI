//Name: Vince Rothenberg
//September 3 2019
//CSCI 21 Lab 2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "CinReader.h"

void clearScreen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

using namespace std;

int main() {
  clearScreen();
  srand(time(0));

  CinReader read;

  /*
  for (size_t i = 0; i < 10; i++) {
    cout << "Random number " << i+1 << ": " << (rand()%10) + 1 << endl;
  }


  int bed = (rand() % 4) + 1;

  switch(bed) {
    case 1:
      cout << "Too soft\n";
      break;
    case 2:
      cout << "Too hard.\n";
      break;
    case 3:
      cout << "Just right.\n";
      break;
    default:
      cout << "WTF\n";
      break;
  }

  */

  cout << "Rock Paper Scissors\n\n";

  bool play = true;
  string moves[3] = {"Rock", "Paper", "Scissors"};
  enum playerMoves { ROCK = 'R', PAPER = 'P', SCISSORS = 'S'};
  string readCharString = "rRpPsS";

  int round = 1;
  int score = 0;

  char move = 'R';

  while(play) {
    cout << "Round : " << round << endl;
    cout << "Score : " << score << endl << endl;

    cout << "Enter your move... \n"
         << "(R)ock\n"
         << "(P)aper\n"
         << "(S)cissors\n";

    char move = toupper(read.readChar(readCharString));
    int compMove = rand()%3;

    cout << "Computer chooses " << moves[compMove] << endl;

    switch (move) {
      case ROCK:
        if (compMove == 0) {
          cout << "DRAW\n";
        } else if (compMove == 1) {
          cout << "LOSE\n";
        } else {
          cout << "WIN\n";
          score++;
        }
      break;

      case PAPER:
        if (compMove == 0) {
          cout << "WIN\n";
          score++;
        } else if (compMove == 1) {
          cout << "DRAW\n";
        } else {
          cout << "LOSE\n";
        }
      break;

      case SCISSORS:
        if (compMove == 0) {
          cout << "LOSE\n";
        } else if (compMove == 1) {
          cout << "WIN\n";
          score++;
        } else {
          cout << "DRAW\n";
        }
      break;

      default:
        cout << "Invalid\n";
      break;

    }

    cout << "Play Again?  Y / N \n";
    char playBool = toupper(read.readChar("yYnN"));
    if (playBool == 'N') {
      play = false;
    } else {
      round++;
    }
    clearScreen();



  }

  return 0;
}
