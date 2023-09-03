//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#ifndef LEARNINGC___SAVINGSACCOUNTCHALLENGE_H
#define LEARNINGC___SAVINGSACCOUNTCHALLENGE_H

#include "iostream"

#include "AccountChallenge.h"

class SavingsAccountChallenge : public AccountChallenge {
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccountChallenge &src);

private:
    static constexpr const char *def_name = "Unnamed SavingsAccount Name";
    static constexpr const double def_balance = 0.0;
    static constexpr const double def_int_rate = 0.0;

protected:
    double int_rate;

public:
    SavingsAccountChallenge(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    bool deposit(double amount);
};


#endif //LEARNINGC___SAVINGSACCOUNTCHALLENGE_H
