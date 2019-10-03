#include "bankaccount.h"
#include <sstream>
#include <string>
#include <iostream>

using std::cout;


// function implementations for class BankAccount

  BankAccount::BankAccount() {
    this->balance = 0.0;
    this->accountNumber = 0;
  };

  // Initialize a BankAccount with balance=0.0 and accountNumber=accountNumber
  BankAccount::BankAccount(unsigned int accountNumber) {
    this->balance = 0.0;
    if (accountNumber < 0) {
      accountNumber = 0;
      cout << "Invalid account number, defaulting to 0.\n";
    }
    this->accountNumber = accountNumber;

  };

  // Initialize a BankAccount with balance=balance and accountNumber=accountNumber
  BankAccount::BankAccount(double balance, unsigned int accountNumber) {
    if (balance < 0) {
      balance = 0;
      cout << "Invalid balance, defaulting to 0.\n";
    }
    this->balance = balance;
    this->accountNumber = accountNumber;
  };

  // Deposit funds. Balance will increase by amount.
  void BankAccount::deposit(double amount) {
    this->balance += amount;
  };

  // If amount <= balance, reduce balance by amount and return true.
  // Otherwise return false.
  bool BankAccount::withdraw(double amount) {
    if ((this->balance - amount) >= 0) {
      this->balance -= amount;
      return true;
    }
    return false;
  };

  // Return the balance.
  double BankAccount::getBalance() {
    return this->balance;
  };

  // Return the accountNumber.
  unsigned int BankAccount::getAccountNumber() {
    return this->accountNumber;
  };

  // Example: "Account #12345, Current balance $99.35"
  // Use the "magic formula" to format the balance.
  string BankAccount::toString() {
    stringstream strout;
    strout.setf(ios::fixed);
    strout.setf(ios::showpoint);
    strout.precision(2);
    strout << "Account #" << this->accountNumber << ", Current balance $" << this->balance;
    return strout.str();
  };
