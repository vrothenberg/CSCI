#define CATCH_CONFIG_MAIN

#include "catch.hpp"


// Write a function that:
// (1) takes a numerator and a denominator
// (2) computes and returns the quotient and remainder
// (3) returns true if denominator is a factor of numerator

bool foo(int numerator, int denominator, int& quotient, int& remainder) {
  if (denominator == 0) {
    quotient = remainder = 0;
    return false;
  }
  quotient = numerator / denominator;
  remainder = numerator % denominator;
  if (remainder == 0) return true;
  return false;
}

TEST_CASE("function implementations") {
  int quotient, remainder;
  bool result = foo(1, 0, quotient, remainder);
  CHECK(result == false);
  CHECK(quotient == 0);
  CHECK(remainder == 0);

  result = foo(9,3,quotient, remainder);
  CHECK(result == true);
  CHECK(quotient == 3);
  CHECK(remainder == 0);
}
