//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#ifndef LEARNINGC___TRUSTACCOUNT_H
#define LEARNINGC___TRUSTACCOUNT_H

#include "string"

#include "AccountChallenge.h"

class TrustAccount : public AccountChallenge {
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &account);

private:
    static constexpr const char *def_name = "Default Trust Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double def_int_rate = 5;
protected:
    double int_rate;

    static double trust_threshold;
    static int trust_bonus;
    static int trust_number_limit;
    static int times_attempted;
    static double max_withdraw_percent;

public:

    TrustAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    bool deposit(double amount);

    bool withdraw(double amount);

    TrustAccount &operator+=(const TrustAccount &rhs);
};


#endif //LEARNINGC___TRUSTACCOUNT_H
