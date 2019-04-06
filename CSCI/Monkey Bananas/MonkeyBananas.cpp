/*
 * Name        : MonkeyBananas.cpp
 * Author      : Vince Rothenberg
 * Description : A game where the user either throws or blocks a banana
 against a computer opponent.
 * Sources Used: Previous knowledge, StackOverflow
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "CinReader.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

// If you want to clear the screen just type: ClearScreen();
void ClearScreen();
//void GameLoop();

int wins = 0;
int losses = 0;
int draws = 0;

void AdvancedMode() {
    // Set up the CinReader instance
    CinReader reader;

    //Initialize hasBanana variables
    int user_banana_count = 0;
    int comp_banana_count = 0;
    //Initialize continue_game variable for quit function
    bool continue_game = true;

    //Clear simple or advanced mode prompt
    ClearScreen();
    //Game introduction and rules
    cout << "To play the game you have three moves:\n"
    << "(G) Grab a banana\n"
    << "(T) Throw a banana you have already grabbed\n"
    << "(B) Block a banana from the opponent\n\n"
    << "You may grab as many bananas as you can for more powerful bananas\n"
    << "If both players throw the more powerful banana wins\n\n"
    << "Press [Enter] to continue ...\n";
    reader.readString();
    ClearScreen();

    int round = 1;

    //Main game loop,
    while(continue_game) {
      //Current game state
      if (user_banana_count == 1) {
        cout << "You hold your banana steadfast!\n";
      } else if (user_banana_count > 1) {
        cout << "You hold " << user_banana_count
        << " bananas with martial intent!\n";
      } else {
        cout << "You are bananaless\n";
      }
      if (comp_banana_count == 1) {
        cout << "Computer holds their banana menancingly!\n";
      } else if (comp_banana_count > 1) {
        cout << "Computer holds " << comp_banana_count
        << " bananas and threatens to use them!\n";
      } else {
        cout << "Computer is bananaless\n";
      }
      cout << "\nRound: " << round << endl;

      //Re-initalize player actions every loop
      char user_action;
      int comp_action;
      char user_ammo_choice;
      //Set default input actions to Grab and Block
      string input_string ="gGbB";
      cout << "\nChoose your action: \n"
      << "(G) Grab a banana\n";
      //Allow Throw input action if user has banana
      if(user_banana_count>0){
        cout << "(T) Throw a banana\n";
        input_string += "tT";
      }
      cout << "(B) Block a banana\n\n";

      //Assign user_action to user input from valid set of characters
      user_action = toupper(reader.readChar(input_string));
      ClearScreen();
      //Action branch for inputs
      if (user_action == 'G') {
        //User grabs
        cout << "You grab a banana\n";
        user_banana_count++;
      } else if (user_action == 'T') {
        //User ammo selection
        //Decrements ammo count
        string input_string = "Bb";
        cout << "Total ammo: " << user_banana_count << endl
        << "Select ammo type \n"
        << "(B)anana: cost 1\n";
        if (user_banana_count>=3) {
          cout << "(P) Plantain: cost 3\n";
          input_string = input_string + "Pp";
        }
        if (user_banana_count >=5) {
          cout << "(S) Super banana: cost 5\n";
          input_string = input_string + "Ss";
        }
        if (user_banana_count >= 10) {
          cout << "(N) Nuclear nanner: cost 10\n";
          input_string = input_string + "Nn";
        }

        user_ammo_choice = toupper(reader.readChar(input_string));
        ClearScreen();
        //
        if (user_ammo_choice == 'B') {
          cout << "You throw a banana!\n";
          user_banana_count -= 1;
        } else if(user_ammo_choice == 'P') {
          cout << "You throw a plantain!\n";
          user_banana_count -= 3;
        } else if(user_ammo_choice == 'S') {
          cout << "You throw a super banana!\n";
          user_banana_count -= 5;
        } else if(user_ammo_choice == 'N') {
          cout << "You throw a nuclear nanner!\n";
          user_banana_count -= 10;
        }
      }
      else if (user_action == 'B') {
        //Block a banana
        cout << "You pose to block a banana!\n";
      }

      //Computer actions
      if (comp_banana_count==0) {
        //Grab a banana if computer does not have one
        comp_banana_count++;
        cout << "Computer grabs a banana!\n";
        if (user_action == 'T') {
          cout << "Computer gets banana'd in the face!\n"
          << "User wins!\n";
          ::wins++;
          continue_game = false;
          break;
        }
      } else {
        //Generate random computer action
        comp_action = rand() % 3;
        if (comp_action == 0) {
          //Computer blocks
          if (user_action == 'T') {
            cout << "Computer blocks successfully!\n" << endl;
          } else {
            cout << "Computer blocks!\n" << endl;
          }
        } else if (comp_action == 1) {
          //Computer throws
          //Generates a computer ammo choices only if it has enough ammo
          int comp_ammo_divisor = (comp_banana_count / 3) + 1;
          int comp_ammo_choice = rand() % comp_ammo_divisor;

          enum AmmoTypes {
            banana = 0,
            plantain = 1,
            super = 2,
            nuke = 3};

          switch (comp_ammo_choice) {
            case banana:
              comp_banana_count -= 1;
              cout << "Computer throws a banana!\n";
              if (user_action == 'T') {
                if (user_ammo_choice == 'B') {
                  cout << "Draw!\n";
                  ::draws++;
                  continue_game = false;
                } else {
                  cout << "User wins!\n";
                  ::wins++;
                  continue_game = false;
                }
              } else if (user_action == 'B') {
                cout << "User successfully blocks!\n";
              } else {
                cout << "User gets banana'd in the face!\n"
                << "User loses!\n";
                ::losses++;
                continue_game = false;
              }
              break;

            case plantain:
              comp_banana_count -= 3;
              cout << "Computer throws a plantain!\n";
              if (user_action == 'T') {
                if (user_ammo_choice == 'B') {
                  cout << "User gets plantain'd in the face!\n"
                  << "User loses!\n";
                  ::losses++;
                  continue_game = false;
                } else if (user_ammo_choice == 'P') {
                  cout << "Draw!\n";
                  ::draws++;
                } else {
                  cout << "User wins!\n";
                  ::wins++;
                  continue_game = false;
                }
              } else if (user_action == 'B') {
                cout << "User successfully blocks!\n";
              } else {
                cout << "User gets banana'd in the face!\n"
                << "User loses!\n";
                ::losses++;
                continue_game = false;
              }
              break;

            case super:
              comp_banana_count -= 5;
              cout << "Computer throws a super banana!\n";
              if (user_action == 'T') {
                if (user_ammo_choice == 'B' || user_ammo_choice == 'P') {
                  cout << "User gets super banana'd in the face!\n"
                  << "User loses!\n";
                  ::losses++;
                  continue_game = false;
                } else if (user_ammo_choice == 'S') {
                  cout << "Draw!\n";
                  ::draws++;
                  continue_game = false;
                } else {
                  cout << "User wins!\n";
                  ::wins++;
                  continue_game = false;
                }
              } else if (user_action == 'B') {
                cout << "User successfully blocks!\n";
              } else {
                cout << "User gets super banana'd in the face!\n"
                << "User loses!\n";
                ::losses++;
                continue_game = false;
              }
              break;

            case nuke:
              comp_banana_count -= 10;
              cout << "Computer throws a nuclear nanner!\n";
              if (user_action == 'T') {
                if (user_ammo_choice == 'N') {
                  cout << "Draw!\n";
                  ::draws++;
                  continue_game = false;
                } else {
                  cout << "User gets nuclear nanner'd in the face!\n"
                  << "User loses!\n";
                  ::losses++;
                  continue_game = false;
                }
              }
              else if(user_action == 'B') {
                cout << "User successfully blocks!";
              } else {
                cout << "User gets nuclear nanner'd in the face!\n"
                << "User loses!\n";
                ::losses++;
                continue_game = false;
              }
              break;
          }
        } else {
          //Computer grabs
          comp_banana_count++;
          cout << "Computer grabs a banana!" << endl;
          if (user_action == 'T') {
            cout << "Computer gets banana'd in the face!\n";
            cout << "User wins!\n";
            ::wins++;
            break;
          }
        }
      }
      //Iterate round number
      round++;
    }
}

// Write your Game Code inside of GameLoop()
void SimpleMode() {
  // Set up the CinReader instance
  CinReader reader;

  // PUT CODE HERE TO HANDLE THE GAME AND INDIVIDUAL ROUNDS

  //Initialize hasBanana variables
  bool user_has_banana = false;
  bool comp_has_banana = false;
  //Initialize continue_game variable for quit function
  bool continue_game = true;
  ClearScreen();
  cout << "To play the game you have three moves:\n\n"
  << "(G) Grab a banana\n"
  << "(T) Throw a banana you have already grabbed\n"
  << "(B) Block a banana from the opponent\n\n"
  << "If both players throw a banana the game is a draw.\n\n"
  << "Press Enter to continue\n";
  reader.readString();
  ClearScreen();

  //Main game loop,
  while(continue_game) {
    //Current game state
    cout << endl;
    if (user_has_banana){
      cout << "You hold your banana steadfast!\n";
    } else {
      cout << "You are bananaless\n";
    }
    if (comp_has_banana){
      cout << "The computer holds their banana menancingly!\n";
    } else {
      cout << "The computer is bananaless\n";
    }


    //Re-initalize player actions every loop
    char user_action;
    int comp_action;
    string input_string = "bB";

    cout << "\nChoose your action: \n";
    if (user_has_banana == false) {
      cout << "(G) Grab a banana\n";
      input_string += "gG";
    } else {
      cout << "(T) Throw a banana\n";
      input_string += "tT";
    }
    cout << "(B) Block a banana\n";
    //Assign user_action to user input from valid set of characters
    user_action = toupper(reader.readChar(input_string));
    //Clear screen after choice every loop
    ClearScreen();
    //User action branch for inputs
    if (user_action == 'G'){
      //Check if user already has banana to prevent multiple grabs
      if(user_has_banana) {
        cout << "You already have a banana!  Either throw it or block." << endl;
      } else {
        cout << "You grab a banana" << endl;
        user_has_banana = true;
      }
    }
    else if(user_action == 'T'){
      //Check if User has already grabbed a banana before throwing
      if (user_has_banana){
        cout << "You throw your banana!" << endl;
        //Assign user_has_banana variable to false after throwing
        user_has_banana = false;
      }
      //Prompt user to grab a banana before throwing
      else {
        cout << "You must first grab a banana!" << endl;
      }
    }
    else if(user_action == 'B'){
      //Block a banana
      cout << "You pose to block a banana" << endl;
    }

    //Computer actions

    if(!comp_has_banana){
      //Grab a banana if computer does not have one
      comp_has_banana = true;
      cout << "Computer grabs a banana!" << endl;
      if (user_action == 'T') {
        cout << "Computer gets banana'd in the face!" << endl;
        cout << "User wins!" << endl;
        continue_game = false;
        ::wins++;
        break;
      }
    } else {
      comp_action = rand() % 2;
      if (comp_action == 0){
        if (user_action == 'T') {
          cout << "Computer blocks successfully!" << endl;
        } else {
          cout << "Computer blocks!" << endl;
        }
      } else {
        cout << "Computer throws a banana!" << endl;
        comp_has_banana = false;
        if (user_action == 'T') {
          cout << "The game is a draw!" << endl;
          ::draws++;
          continue_game = false;
          break;
        } else if (user_action == 'B'){
          cout << "User blocks successfully!" << endl;
        } else {
          cout << "User gets banana'd in the face!" << endl;
          cout << "Computer wins!" << endl;
          ::losses++;
          continue_game = false;
          break;
        }
      }
    }
  }
}

// DO NOT ALTER
// Write your code in GameLoop() below
int main() {

  // Set up CinReader instance
  CinReader reader;
  // Create Needed Variables
  char again;
  char mode;
  // Seed the Random Number Generator
  srand(time(0));

  // Loop until the user no longer wants to play
  // This is the GAME LOOP
  do {
    // Send us to the GameLoop()
    //Introduction of how to play the game
    cout
    << "====================================\n"
    << "========== Monkey Bananas ==========\n"
    << "====================================\n\n"
    << "Choose mode: \n"
    << "(S) Simple\n"
    << "  Players can grab one banana to throw\n"
    << "(A) Advanced\n"
    << "  Players can grab multiple bananas for more powerful throws\n";
    mode = toupper(reader.readChar("SsAa"));
    ClearScreen();


    //Game mode selection
    if (mode == 'S') {
      SimpleMode();
    } else if (mode == 'A') {
      AdvancedMode();
    }


    // Prompt user to see if the want to continue to play
    if(wins>0 || losses>0 || draws > 0) {
      cout << "===== Score =====" << endl
      << "Wins: " << wins << endl
      << "Losses: " << losses << endl
      << "Draws: "  << draws << endl;
    }
    cout << "Would you like to play again? (Y / N)\n";
    again = toupper(reader.readChar("YNyn"));
    cout << endl;
    ClearScreen();
  } while (again == 'Y');

  // This ends our program
  return 0;
}


// DO NOT ALTER
void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}
