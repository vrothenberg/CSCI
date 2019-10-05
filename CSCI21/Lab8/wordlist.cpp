#include "wordlist.h"

// Add a word to the words vector.
void WordList::addWord(string word) {
  this->words.push_back(word);
}

// Remove a word from the words vector.
// Return true on success.
bool WordList::removeWord(string word) {
  bool status = false;
  for (int i = this->words.size() - 1; i >= 0; i--) {
    if (this->words[i] == word) {
      status = true;
      this->words[i] = this->words.back();
      this->words.pop_back();
    }
  }
  return status;
}

// Return true if the words vector contains the word.
bool WordList::hasWord(string word) {
  for (int i = 0; i < this->words.size(); i++) {
    if (this->words[i] == word) {
      return true;
    }
  }
  return false;
}

// Return the number of words, i.e., size of the vector.
unsigned int WordList::getWordCount() {
  return this->words.size();
}

// Clear all of the contents of the list.
void WordList::clear() {
  this->words.clear();
}

// Return a string representation of the word list.
// String will contain a numbered list, one word per line.
/*
 * EXAMPLE:
 *
 * [1] apple
 * [2] grapefruit
 * [3] orange
 *
 */
string WordList::toString() {
  ostringstream strout;
  for (int i = 0; i < this->words.size(); i++) {
    strout << "[" << i+1 << "] " << this->words[i] << "\n";
  }
  return strout.str();
}
