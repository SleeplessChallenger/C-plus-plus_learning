//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#include "iostream"
#include "string"

#include "AccountChallenge.h"


AccountChallenge::AccountChallenge(std::string name, double balance)
        : name{name}, balance{balance} {
}

bool AccountChallenge::deposit(double amount) {
    if (amount < 0) {
        return false;
    } else {
        balance += amount;
        return true;
    }
}

bool AccountChallenge::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

double AccountChallenge::get_balance() const {
    return balance;
}

std::ostream &operator<<(std::ostream &os, const AccountChallenge &account) {
    os << "[Account: " << account.name << "; " << account.balance << "]";
    return os;
}