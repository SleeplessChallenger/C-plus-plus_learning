//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#ifndef LEARNINGC___ACCOUNTUTILS_H
#define LEARNINGC___ACCOUNTUTILS_H

#include "vector"
#include "AccountChallenge.h"
#include "SavingsAccountChallenge.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"


// Account class
void display(const std::vector<AccountChallenge> &accounts);

void deposit(std::vector<AccountChallenge> &accounts, double amount);

void withdraw(std::vector<AccountChallenge> &accounts, double amount);

// Savings Account class
void display(const std::vector<SavingsAccountChallenge> &accounts);

void deposit(std::vector<SavingsAccountChallenge> &accounts, double amount);

void withdraw(std::vector<SavingsAccountChallenge> &accounts, double amount);

// Checking Account class

void display(const std::vector<CheckingAccount> &accounts);

void deposit(std::vector<CheckingAccount> &accounts, double amount);

void withdraw(std::vector<CheckingAccount> &accounts, double amount);

// Trust Account class
void display(const std::vector<TrustAccount> &accounts);

void deposit(std::vector<TrustAccount> &accounts, double amount);

void withdraw(std::vector<TrustAccount> &accounts, double amount);

// Trust Account class
bool checkWithdrawIsValid(const double &balance,
                          const double &amount,
                          int &times_attempted,
                          double &max_withdraw_percent,
                          const int &trust_number_limit);

void increaseAmountIfThresholdPassed(double &amount, const double &threshold, const int &bonus);

#endif //LEARNINGC___ACCOUNTUTILS_H
