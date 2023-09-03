//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(std::string name, double balance)
        : AccountChallenge{name, balance} {

}

bool CheckingAccount::withdraw(double amount) {
    amount = amount + checking_fee;
    return AccountChallenge::withdraw(amount);
}

CheckingAccount &CheckingAccount::operator-=(const CheckingAccount &rhs) {
    name = name + " " + rhs.name;
    balance = balance + rhs.balance;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account) {
    std::cout << "Checking Account: name " << account.name << "; " << "balance: " << account.balance << "; ";
    return os;
}
