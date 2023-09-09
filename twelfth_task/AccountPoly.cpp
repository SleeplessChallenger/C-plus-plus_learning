//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#include "string"

#include "AccountPoly.h"

AccountPoly::AccountPoly(std::string name, double amount)
        : name{name}, balance{amount} {

}

bool AccountPoly::withdraw(double amount) {
    if (amount > balance) {
        return false;
    } else {
        balance -= amount;
        return true;
    }
}

bool AccountPoly::deposit(double amount) {
    if (amount < 0) {
        return false;
    }
    balance += amount;
    return true;
}

void AccountPoly::print_obj(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Account name: " << name << " and balance: " << balance;
}