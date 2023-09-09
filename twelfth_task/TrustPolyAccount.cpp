//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#include "string"

#include "UtilsPoly.h"
#include "TrustPolyAccount.h"

double TrustPolyAccount::trust_threshold = 5000.0;
int TrustPolyAccount::trust_bonus = 50;
int TrustPolyAccount::trust_number_limit = 3;
int TrustPolyAccount::times_attempted = 0;
double TrustPolyAccount::max_withdraw_percent = 0.2;

TrustPolyAccount::TrustPolyAccount(std::string name, double amount, double int_rate)
        : AccountPoly{name, amount}, int_rate{int_rate} {

}

bool TrustPolyAccount::withdraw(double amount) {
    if (!checkTrustPolyWithdrawIsValid(
            balance, amount, times_attempted, max_withdraw_percent, trust_number_limit)) {
        return false;
    }
    return AccountPoly::withdraw(amount);
}

bool TrustPolyAccount::deposit(double amount) {
    increaseTrustPolyAmountIfThresholdPassed(amount, trust_threshold, trust_bonus);
    return AccountPoly::deposit(amount);
}

void TrustPolyAccount::print_obj(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "Trust Account with balance: " << balance << " and int_rate: " << int_rate;
}