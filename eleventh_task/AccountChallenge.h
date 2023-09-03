//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#ifndef LEARNINGC___ACCOUNTCHALLENGE_H
#define LEARNINGC___ACCOUNTCHALLENGE_H

#include "iostream"
#include "string"

class AccountChallenge {
    friend std::ostream &operator<<(std::ostream &os, const AccountChallenge &src);

private:
    /*
     * Allows to make actions with variables in the compile time.
     * In this case it allows these variables to be assigned to the params in the constructor
     */
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

protected:
    std::string name;
    double balance;

public:
    AccountChallenge(std::string name = def_name, double balance = def_balance);

    bool deposit(double amount);

    bool withdraw(double amount);

    double get_balance() const;
};


#endif //LEARNINGC___ACCOUNTCHALLENGE_H
