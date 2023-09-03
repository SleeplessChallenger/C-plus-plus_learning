//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#ifndef LEARNINGC___CHECKINGACCOUNT_H
#define LEARNINGC___CHECKINGACCOUNT_H

#include "iostream"
#include "string"

#include "AccountChallenge.h"

class CheckingAccount : public AccountChallenge {
    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);

private:
    static constexpr const char *def_name = "Default Checking Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double checking_fee = 1.5;

public:
    CheckingAccount(std::string name = def_name, double balance = def_balance);

    bool withdraw(double amount);

    CheckingAccount &operator-=(const CheckingAccount &rhs);
};


#endif //LEARNINGC___CHECKINGACCOUNT_H
