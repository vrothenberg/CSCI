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
  return "Nice to meet you, " + name + ".";

}

// Return true if denominator is a factor of numerator.
// Return false otherwise.
bool isFactor(int numerator, int denominator) {
  if (denominator == 0) return false;
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
  dimes = initialValue / 10;
  initialValue -= dimes * 10;
  nickels = initialValue / 5;
  initialValue -= nickels * 5;
  pennies = initialValue;

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
  CHECK(greet("Vince") == "Nice to meet you, Vince.");
  CHECK(greet("") == "Nice to meet you.");
  CHECK(isFactor(2,4) == true);
  CHECK(isFactor(1,0) == false);
  CHECK(isFactor(2,7) == false);
  unsigned int quarters = 0, dimes= 0, nickels = 0, pennies = 0;
  makeChange(100, quarters, dimes, nickels, pennies);
  CHECK(quarters == 4);
  CHECK(dimes == 0);
  CHECK(nickels == 0);
  CHECK(pennies == 0);
  quarters = dimes = nickels = pennies = 0;
  makeChange(41, quarters, dimes, nickels, pennies);
  CHECK(quarters == 1);
  CHECK(dimes == 1);
  CHECK(nickels == 1);
  CHECK(pennies == 1);
  CHECK(celsiusToFahrenheit(0) == 32);
  CHECK(celsiusToFahrenheit(100) == 212);
  CHECK(celsiusToFahrenheit(-1000) == Approx(-459.67));
  CHECK(fahrenheitToCelsius(0) == Approx(-17.7777777778));
  CHECK(fahrenheitToCelsius(32) == Approx(0));
  CHECK(fahrenheitToCelsius(212) == Approx(100));
  CHECK(fahrenheitToCelsius(-1000) == Approx(-273.15));


}
