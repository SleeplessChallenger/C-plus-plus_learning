//
// Created by Daniil Slobodeniuk on 2023/08/25.
//

#include "AccountChallenge.h"
#include "TrustAccount.h"
#include "AccountUtils.h"

#include "string"

double TrustAccount::trust_threshold = 5000.0;
int TrustAccount::trust_bonus = 50;
int TrustAccount::trust_number_limit = 3;
int TrustAccount::times_attempted = 0;
double TrustAccount::max_withdraw_percent = 0.2;

TrustAccount::TrustAccount(std::string name, double balance, double int_rate)
        : AccountChallenge{name, balance}, int_rate{int_rate} {

}

/**
 *
 * @param amount just amount which user puts
 * @return successful/unsuccessful attempt
 *
 * Rules for the account:
 * <ul>
 *  <li>if amount > 5000: 50 bonus</li>
 *  <li>if times_attempted > 3: error</li>
 *  <li>each deposit < 20% from total account balance</li>
 * </ul>
 */
bool TrustAccount::deposit(double amount) {
    increaseAmountIfThresholdPassed(amount, trust_threshold, trust_bonus);
    return AccountChallenge::deposit(amount);
}

bool TrustAccount::withdraw(double amount) {
    if (!checkWithdrawIsValid(balance, amount, times_attempted, max_withdraw_percent, trust_number_limit)) {
        return false;
    }
    return AccountChallenge::withdraw(amount);
}

TrustAccount &TrustAccount::operator+=(const TrustAccount &rhs) {
    name = name + " " + rhs.name;
    double overall_balance{balance + rhs.balance};
    balance = overall_balance;

    int_rate = (int_rate > rhs.int_rate) ? int_rate : rhs.int_rate;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &account) {
    std::cout << "Trust Account: name " << account.name << "; " << "balance: " << account.balance << "; " << "int rate"
              << account.int_rate;
    return os;
}
