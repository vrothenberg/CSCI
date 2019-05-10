/*
 * Name          : Vince Rothenberg
 * Description   : Lab 24
 */

#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::endl;
using std::string;

// This class will perform string operations on strings
class StringHelper {
 public:
  // Checks to see if a word (string) is in another string
  bool CheckWordExists(string original_string, string to_check) {
    if(original_string.find(to_check)==string::npos) return false;
    return true;
  }
  // Checks to see if any of the characters in a string are in another string
  bool CheckCharacterExists(string original_string, string to_check) {
    if(original_string.find_first_of(to_check)==string::npos) return false;
    return true;
  }
  // Checks to see if a character is a vowel (a, e, i, o, u). Returns true if it
  // is a vowel, otherwise it returns false. If includeY is set to true then 'y'
  // is also a vowel and should be treated as such
  bool IsVowel(char c, bool includeY = false) {
    string sc = string(1,c);
    string vowels = "aeiouAEIOU";
    if (includeY) vowels += "yY";
    if(sc.find_first_of(vowels)==string::npos) return false;
    return true;
  }
  // The purpose of this function is to convert a single word to its Pig Latin
  // equivalent. The rules:
  // 1) If a word starts with a vowel, the Pig Latin version is the original
  //    word with "way" added to the end
  // 2) If a word starts with a consonant, or a series of consecutive
  //    consonants, the Pig Latin version transfers all consonants up to the
  //    first vowel to the end of the word, and adds "ay" to the end.
  // 3)  The letter 'y' should be treated as a consonant if it is the first
  //     letter of a word, but treated as a vowel otherwise.
  string ToPigLatin(string to_change) {

    if (IsVowel(to_change[0])) {
      //Starts with vowel
      to_change.insert(to_change.size(), "way");
    } else {
      string vowels = "aeiouyAEIOUY";
      int location;
      if (IsVowel(to_change[0], true)) {
        location = to_change.substr(1, to_change.size()).find_first_of(vowels) + 1;
      } else {
        location = to_change.find_first_of(vowels);
      }

      to_change.insert(to_change.size(), to_change.substr(0, location) + "ay");
      to_change.erase(0,location);
    }
    return to_change;
  }
};

// Program starts here (DO NOT ALTER)
int main() {
  // Setup our Variables
  string string_one;
  StringHelper helper;
  string_one = "Hello World!";

  // Testing CheckWordExists()
  cout << "Testing CheckWordExists()\n"
       << "---------------------------------------------------------\n";
  cout << ((helper.CheckWordExists(string_one, "ello")) ? "Passed" : "Failed")
       << " Test CheckWordExists(\"Hello World!\", \"ello\")" << endl;
  cout << ((helper.CheckWordExists(string_one, "!")) ? "Passed" : "Failed")
       << " Test CheckWordExists(\"Hello World!\", \"!\")" << endl;
  cout << ((helper.CheckWordExists(string_one, " ")) ? "Passed" : "Failed")
       << " Test CheckWordExists(\"Hello World!\", \" \")" << endl;
  cout << ((helper.CheckWordExists(string_one, "foo")) ? "Failed" : "Passed")
       << " Test CheckWordExists(\"Hello World!\", \"foo\")" << endl;
  cout << ((helper.CheckWordExists(string_one, "olleH")) ? "Failed" : "Passed")
       << " Test CheckWordExists(\"Hello World!\", \"olleH\")" << endl;
  cout << ((helper.CheckWordExists(string_one, "H!")) ? "Failed" : "Passed")
       << " Test CheckWordExists(\"Hello World!\", \"H!\")" << endl;

  // Testing CheckCharacterExists()
  cout << "\nTesting CheckCharacterExists()\n"
       << "---------------------------------------------------------\n";
  cout << ((helper.CheckCharacterExists(string_one, "aeiou")) ? "Passed" : "Failed")
       << " Test CheckCharacterExists(\"Hello World!\", \"aeiou\")" << endl;
  cout << ((helper.CheckCharacterExists(string_one, "WH")) ? "Passed" : "Failed")
       << " Test CheckCharacterExists(\"Hello World!\", \"WH\")" << endl;
  cout << ((helper.CheckCharacterExists(string_one, "!@#")) ? "Passed" : "Failed")
       << " Test CheckCharacterExists(\"Hello World!\", \"!@#\")" << endl;
  cout << ((!helper.CheckCharacterExists(string_one, "AEIOU")) ? "Passed" : "Failed")
       << " Test CheckCharacterExists(\"Hello World!\", \"AEIOU\")" << endl;
  cout << ((!helper.CheckCharacterExists(string_one, "abc")) ? "Passed" : "Failed")
       << " Test CheckCharacterExists(\"Hello World!\", \"abc\")" << endl;
  cout << ((!helper.CheckCharacterExists(string_one, "@#$")) ? "Passed" : "Failed")
       << " Test CheckCharacterExists(\"Hello World!\", \"@#$\")" << endl;

  // Testing IsVowel
  cout << "\nTesting IsVowel()\n"
       << "---------------------------------------------------------\n";
  cout << ((helper.IsVowel('A') ? "Passed" : "Failed"))
       << " Test IsVowel('A')" << endl;
  cout << ((helper.IsVowel('a') ? "Passed" : "Failed"))
       << " Test IsVowel('a')" << endl;
  cout << ((helper.IsVowel('O') ? "Passed" : "Failed"))
       << " Test IsVowel('O')" << endl;
  cout << ((helper.IsVowel('o') ? "Passed" : "Failed"))
       << " Test IsVowel('o')" << endl;
  cout << ((!helper.IsVowel('Y') ? "Passed" : "Failed"))
       << " Test IsVowel('Y')" << endl;
  cout << ((!helper.IsVowel('y') ? "Passed" : "Failed"))
       << " Test IsVowel('y')" << endl;
  cout << ((!helper.IsVowel('B') ? "Passed" : "Failed"))
       << " Test IsVowel('B')" << endl;
  cout << ((!helper.IsVowel(' ') ? "Passed" : "Failed"))
       << " Test IsVowel(' ')" << endl;
  cout << ((helper.IsVowel('Y', true) ? "Passed" : "Failed"))
       << " Test IsVowel('Y', true)" << endl;
  cout << ((helper.IsVowel('y', true) ? "Passed" : "Failed"))
       << " Test IsVowel('y', true)" << endl;

  // Testing ToPigLatin
  cout << "\nTesting ToPigLatin()\n"
       << "---------------------------------------------------------\n";
  string yours = helper.ToPigLatin("flower");
  string correct = "owerflay";
  if (yours == correct) {
    cout << "Passed Test ToPigLatin(\"flower\")" << endl;
  } else {
    cout << "Failed Test ToPigLatin(\"flower\")" << endl;
    cout << "Yours:   " << yours << endl;
    cout << "Correct: " << correct << endl;
  }

  yours = helper.ToPigLatin("yellow");
  correct = "ellowyay";
  if (yours == correct) {
    cout << "Passed Test ToPigLatin(\"yellow\")" << endl;
  } else {
    cout << "Failed Test ToPigLatin(\"yellow\")" << endl;
    cout << "Yours:   " << yours << endl;
    cout << "Correct: " << correct << endl;
  }

  yours = helper.ToPigLatin("bypass");
  correct = "ypassbay";
  if (yours == correct) {
    cout << "Passed Test ToPigLatin(\"bypass\")" << endl;
  } else {
    cout << "Failed Test ToPigLatin(\"bypass\")" << endl;
    cout << "Yours:   " << yours << endl;
    cout << "Correct: " << correct << endl;
  }

  yours = helper.ToPigLatin("apple");
  correct = "appleway";
  if (yours == correct) {
    cout << "Passed Test ToPigLatin(\"apple\")" << endl;
  } else {
    cout << "Failed Test ToPigLatin(\"apple\")" << endl;
    cout << "Yours:   " << yours << endl;
    cout << "Correct: " << correct << endl;
  }

  yours = helper.ToPigLatin("igloo");
  correct = "iglooway";
  if (yours == correct) {
    cout << "Passed Test ToPigLatin(\"igloo\")" << endl;
  } else {
    cout << "Failed Test ToPigLatin(\"igloo\")" << endl;
    cout << "Yours:   " << yours << endl;
    cout << "Correct: " << correct << endl;
  }

  yours = helper.ToPigLatin("hamburger");
  correct = "amburgerhay";
  if (yours == correct) {
    cout << "Passed Test ToPigLatin(\"hamburger\")" << endl;
  } else {
    cout << "Failed Test ToPigLatin(\"hamburger\")" << endl;
    cout << "Yours:   " << yours << endl;
    cout << "Correct: " << correct << endl;
  }

  yours = helper.ToPigLatin("rhythm");
  correct = "ythmrhay";
  if (yours == correct) {
    cout << "Passed Test ToPigLatin(\"rhythm\")" << endl;
  } else {
    cout << "Failed Test ToPigLatin(\"rhythm\")" << endl;
    cout << "Yours:   " << yours << endl;
    cout << "Correct: " << correct << endl;
  }

  // This ends our program
  return 0;
}

// FILL IN THE DEFINITIONS
