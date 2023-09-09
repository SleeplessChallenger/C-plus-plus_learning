//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#ifndef LEARNINGC___UTILSPOLY_H
#define LEARNINGC___UTILSPOLY_H

#include "vector"

#include "AccountPoly.h"


void display(const std::vector<AccountPoly *> &objects);

void deposit(std::vector<AccountPoly *> &objects, double amount);

void withdraw(std::vector<AccountPoly *> &objects, double amount);

// Trust account helper functions
bool checkTrustPolyWithdrawIsValid(const double &balance,
                          const double &amount,
                          int &times_attempted,
                          double &max_withdraw_percent,
                          const int &trust_number_limit);

void increaseTrustPolyAmountIfThresholdPassed(double &amount, const double &threshold, const int &bonus);

#endif //LEARNINGC___UTILSPOLY_H
