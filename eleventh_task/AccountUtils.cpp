//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#include "iostream"
#include "vector"

#include "AccountUtils.h"

#include "AccountChallenge.h"
#include "SavingsAccountChallenge.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

// Displays account objects in a vector of Account objects
void display(const std::vector<AccountChallenge> &accounts) {
    std::cout << "Displaying accounts" << std::endl;
    for (const AccountChallenge &account: accounts)
        std::cout << account << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<AccountChallenge> &accounts, double amount) {
    std::cout << "Depositing to Accounts" << std::endl;
    for (AccountChallenge &account: accounts) {
        if (account.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << account << std::endl;
        } else {
            std::cout << "Failed Deposit of " << account << " to " << account << std::endl;
        }
    }
}

// Withdraw amount from each Account object
void withdraw(std::vector<AccountChallenge> &accounts, double amount) {
    std::cout << "Withdrawing from Accounts" << std::endl;
    for (AccountChallenge &account: accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << account << std::endl;
        } else {
            std::cout << "Failed Withdrawal of " << amount << " from " << account << std::endl;
        }
    }
}

// Displays account objects in a vector of Account objects
void display(const std::vector<SavingsAccountChallenge> &accounts) {
    std::cout << "Displaying SavingsAccount" << std::endl;
    for (const SavingsAccountChallenge &account: accounts) {
        std::cout << account << std::endl;
    }
}

// Deposits supplied amount to each SavingAccount in the vector
void deposit(std::vector<SavingsAccountChallenge> &accounts, double amount) {
    std::cout << "Depositing to SavingsAccount" << std::endl;
    for (SavingsAccountChallenge account: accounts) {
        if (account.deposit(amount)) {
            std::cout << "Deposited " << amount << " to " << account << std::endl;
        } else {
            std::cout << "Failed Deposit of " << amount << " to " << account << std::endl;
        }
    }
}

// Withdrew amount from each SavingsAccount in the vector
void withdraw(std::vector<SavingsAccountChallenge> &accounts, double amount) {
    std::cout << "SavingsAccount" << std::endl;
    for (SavingsAccountChallenge &account: accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << account << std::endl;
        } else {
            std::cout << "Failed Withdrawal of" << amount << " from " << account << std::endl;
        }
    }
}

// Displays Checking Account
void display(const std::vector<CheckingAccount> &accounts) {
    std::cout << "Displaying Checking Account" << std::endl;
    for (const CheckingAccount &account: accounts) {
        std::cout << account << std::endl;
    }
}

// Deposit to Checking Account
void deposit(std::vector<CheckingAccount> &accounts, double amount) {
    std::cout << "Depositing to Checking Account" << std::endl;
    for (CheckingAccount &account: accounts) {
        if (account.deposit(amount)) {
            std::cout << "Successfully deposited to " << account << " sum: " << amount << std::endl;
        } else {
            std::cout << "Error while depositing to " << account << " sum: " << amount << std::endl;
        }
    }
}

// Withdrew from Checking Account
void withdraw(std::vector<CheckingAccount> &accounts, double amount) {
    std::cout << "Withdrawing from Checking Account" << std::endl;
    for (CheckingAccount &account: accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew " << amount << " from " << account << std::endl;
        } else {
            std::cout << "Failed Withdrawal of" << amount << " from " << account << std::endl;
        }
    }
}

// Displays Trust Account
void display(const std::vector<TrustAccount> &accounts) {
    std::cout << "Displaying Trust Account" << std::endl;
    for (const TrustAccount &account: accounts) {
        std::cout << account << std::endl;
    }
}

// Deposit to Trust Account
void deposit(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "Depositing to Trust Account" << std::endl;
    for (TrustAccount &account: accounts) {
        if (account.deposit(amount)) {
            std::cout << "Successfully deposited to " << account << " sum: " << amount << std::endl;
        } else {
            std::cout << "Error while depositing to " << account << " sum: " << amount << std::endl;
        }
    }
}

// Withdraw from Trust account
void withdraw(std::vector<TrustAccount> &accounts, double amount) {
    std::cout << "Withdraw from Trust Account" << std::endl;
    for (TrustAccount &account: accounts) {
        if (account.withdraw(amount)) {
            std::cout << "Withdrew from " << account << " amount " << amount << std::endl;
        } else {
            std::cout << "Error withdrawing from " << account << " amount " << amount << std::endl;
        }
    }
}


// TrustAccount checker
bool checkWithdrawIsValid(const double &balance,
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

void increaseAmountIfThresholdPassed(double &amount, const double &threshold, const int &bonus) {
    if (amount > threshold) {
        amount = amount + bonus;
    }
}