// Lab 3 -- C++ (re)fresher, functions and testing
//
// Programmer name: Vince Rothenberg
// Date completed: September 5 2019

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
using std::string;

// COMPLETE EACH OF THE FOLLOWING FUNCTIONS

// Return a greeting: "Nice to meet you, NAME."
// If name param is empty string, return "Nice to meet you."
string greet(string name) {

  if (name.length() == 0) {
    return "Nice to meet you.";
  }
  return "Nice to meet you, " + name;

}

// Return true if denominator is a factor of numerator.
// Return false otherwise.
bool isFactor(int numerator, int denominator) {
    if (denominator % numerator == 0) return true;
    return false;
}

// Given an initial value, compute how many quarters, dimes, nickels, and
// pennies would be given as change.
void makeChange(unsigned int initialValue, unsigned int &quarters,
                unsigned int &dimes, unsigned int &nickels,
                unsigned int &pennies)
{
  quarters = initialValue / 25;
  initialValue -= quarters * 25;
  dimes = initalValue / 10;
  initialValue -= dimes * 10;
  nickels = initalValue / 5;
  initalValue = -= nickels * 5;
  pennies = initalValue;

}

// Convert a Celsius temperature to a Fahrenheit temperature.
double celsiusToFahrenheit(double celsiusTemp) {
  if (celsiusTemp < -273.15) celsiusTemp = -273.15;
  double fahrenheitTemp = celsiusTemp * (9.0/5.0) + 32;
  return fahrenheitTemp;
}

// Convert a Fahrenheit temperature to a Celsius temperature.
double fahrenheitToCelsius(double fahrenheitTemp) {
  if (fahrenheitTemp < -459.67) fahrenheitTemp = -459.67;
  double celsiusTemp = (fahrenheitTemp - 32) * (5.0/9.0);
  return celsiusTemp;
}

/*
 * Unit test.
 */

TEST_CASE("Function implementations") {

}
