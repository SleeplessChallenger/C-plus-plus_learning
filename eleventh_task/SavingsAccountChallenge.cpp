//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#include "SavingsAccountChallenge.h"

#include "iostream"


SavingsAccountChallenge::SavingsAccountChallenge(std::string name, double balance, double int_rate)
        : AccountChallenge{name, balance}, int_rate{int_rate} {

}

bool SavingsAccountChallenge::deposit(double amount) {
    amount = amount * (int_rate / 100);
    return AccountChallenge::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccountChallenge &account) {
    os << "[Savings Account: " << account.balance << "; " << account.name << "; " << account.int_rate << "%;";
    return os;
}