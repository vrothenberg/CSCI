// Lab 13 -- recursion
//
// Programmer name: Vince Rothenberg
// Date completed:  Oct 15 2019

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

// Compute and return the factorial of value. 0 and 1 return 1.
// Recursive.
unsigned int factorial (unsigned int value) {
	if (value <= 1) return 1;
	return value * factorial(value-1);

}

// Return the nth value of the Fibonacci sequence.
// Recursive.
unsigned int fibonacci (unsigned int nth) {
	if (nth < 3) return 1;
	return fibonacci(nth-1) + fibonacci(nth-2);

}

// Returns true if word is a palindrome. Returns false otherwise.
// Recursive.
bool wordIsPalindrome (string word) {
	if (word.size() <= 1) return true;
	if (word[0] != word[word.size()-1]) return false;
	return wordIsPalindrome(word.substr(1,word.size()-2));

}

// Produces a string containing the contents of a vector, separated by single spaces,
// starting at a given index and going forward to the end of the vector.
// Recursive.
string vectorForwardsAsString (const vector<int>& v, unsigned int index) {

	if (index >= v.size()) return "";
	return std::to_string(v.at(index)) + " " + vectorForwardsAsString(v, index+1);

}

// Produces a string containing the contents of a vector, separated by single spaces,
// starting at a given index and going backward to the end of the vector.
// Recursive.
string vectorBackwardsAsString (const vector<int>& v, int startIndex) {
	if (startIndex < 0) return "";
	return std::to_string(v.at(startIndex)) + " " + vectorBackwardsAsString(v, startIndex-1);
}

TEST_CASE("recursive functions") {

	SECTION("recursive factorial function") {
		CHECK(factorial(0) == 1);
		CHECK(factorial(1) == 1);
		CHECK(factorial(2) == 2);
		CHECK(factorial(5) == 120);
	}

	SECTION("recursive fibonacci function") {
		CHECK(fibonacci(1) == 1);
		CHECK(fibonacci(2) == 1);
		CHECK(fibonacci(3) == 2);
		CHECK(fibonacci(15) == 610);
	}

	SECTION("recursive wordIsPalindrome function") {
		CHECK(wordIsPalindrome("") == true);
		CHECK(wordIsPalindrome("a") == true);
		CHECK(wordIsPalindrome("sitonapotatopanotis") == true);
		CHECK(wordIsPalindrome("baseball") == false);
	}
}

TEST_CASE("recursive vector to string functions") {
	vector<int> numbers = {5, 10, 15, 20, 25};

	SECTION("recursive vector forwards as string function") {
		CHECK(vectorForwardsAsString(numbers, 0) == string("5 10 15 20 25 "));
		CHECK(vectorForwardsAsString(numbers, 3) == string("20 25 "));
		CHECK(vectorForwardsAsString(numbers, 5) == string(""));
	}

	SECTION("recursive vector backwards as string function") {
		CHECK(vectorBackwardsAsString(numbers, 4) == string("25 20 15 10 5 "));
		CHECK(vectorBackwardsAsString(numbers, 1) == string("10 5 "));
		CHECK(vectorBackwardsAsString(numbers, -1) == string(""));
	}
}
