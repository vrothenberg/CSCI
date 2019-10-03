// Lab 5 -- C++ (re)fresher, pt 5
//
// Programmer name: Vince Rothenberg
// Date completed:  24 Sep 2019

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bankaccount.h"

TEST_CASE("BankAccount class") {

  BankAccount b1;
  CHECK(b1.getBalance() == 0.0);
  CHECK(b1.getAccountNumber() == 0);
  BankAccount b2(2);
  CHECK(b2.getBalance() == 0.0);
  CHECK(b2.getAccountNumber() == 2);
  BankAccount b3(1.00, 3);
  CHECK(b3.getBalance() == 1.00);
  CHECK(b3.getAccountNumber() == 3);
  b3.deposit(2.33);
  CHECK(b3.getBalance() == 3.33);
  CHECK(b3.withdraw(10.00) == false);
  CHECK(b3.getBalance() == 3.33);
  CHECK(b3.withdraw(3.33) == true);
  CHECK(b3.getBalance() == 0.0);
  BankAccount b4(99.35, 12345);
  CHECK(b4.toString() == "Account #12345, Current balance $99.35");



}
