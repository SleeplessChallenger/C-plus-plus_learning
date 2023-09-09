//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#ifndef LEARNINGC___TRUSTPOLYACCOUNT_H
#define LEARNINGC___TRUSTPOLYACCOUNT_H

#include "string"

#include "AccountPoly.h"

class TrustPolyAccount : public AccountPoly {
private:
    static constexpr const double default_amount = 0.0;
    static constexpr const char *default_name = "Default Trust Account";
    static constexpr const double default_int_rate = 1.5;

protected:
    double int_rate;

    static double trust_threshold;
    static int trust_bonus;
    static int trust_number_limit;
    static int times_attempted;
    static double max_withdraw_percent;

public:
    virtual bool deposit(double amount) override;

    virtual bool withdraw(double amount) override;

    virtual void print_obj(std::ostream &os) const override;

    TrustPolyAccount(std::string name = default_name, double amount = default_amount,
                     double int_rate = default_int_rate);

    virtual ~TrustPolyAccount() = default;
};


#endif //LEARNINGC___TRUSTPOLYACCOUNT_H
