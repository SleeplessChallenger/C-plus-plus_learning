//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#include "iostream"
#include "vector"

#include "UtilsPoly.h"

/**
 * This method will trigger << operator which in Interface will use method
 * of the object to print required information
 * @param objects all account
 */
void display(const std::vector<AccountPoly *> &objects) {
    std::cout << "Displaying Account objects" << std::endl;

    for (const AccountPoly *acc: objects) {
        std::cout << *acc << std::endl;
    }
}

void deposit(std::vector<AccountPoly *> &objects, double amount) {
    std::cout << "Depositing from Account objects" << std::endl;

    for (AccountPoly *acc: objects) {
        if (acc->deposit(amount)) {
            std::cout << "Deposit from " << *acc << " was successful" << std::endl;
        } else {
            std::cout << "Deposit from " << *acc << " was unsuccessful" << std::endl;
        }
    }
}

void withdraw(std::vector<AccountPoly *> &objects, double amount) {
    std::cout << "Withdrawing from Account objects" << std::endl;

    for (AccountPoly *acc: objects) {
        if (acc->withdraw(amount)) {
            std::cout << "Withdrawing from " << *acc << " was successful" << std::endl;
        } else {
            std::cout << "Withdrawing from " << *acc << " was unsuccessful" << std::endl;
        }
    }
}

// Trust account helper function
bool checkTrustPolyWithdrawIsValid(const double &balance,
                                   const double &amount,
                                   int &times_attempted,
                                   double &max_withdraw_percent,
                                   const int &trust_number_limit) {
    if (times_attempted >= trust_number_limit) {
        return false;
    }

    if (balance * max_withdraw_percent <= amount) {
        return false;
    }

    times_attempted++;
    return true;
}

void increaseTrustPolyAmountIfThresholdPassed(double &amount, const double &threshold, const int &bonus) {
    if (amount > threshold) {
        amount = amount + bonus;
    }
}