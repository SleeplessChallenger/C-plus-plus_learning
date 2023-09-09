//
// Created by Daniil Slobodeniuk on 2023/09/03.
//

#ifndef LEARNINGC___ACCOUNTPOLY_H
#define LEARNINGC___ACCOUNTPOLY_H

#include "string"

#include "I_PrintablePoly.h"

class AccountPoly : public I_PrintablePoly {
private:
    static constexpr const char *default_name = "Default";
    static constexpr const double default_balance = 0.0;

protected:
    std::string name;
    double balance;

public:

    virtual bool deposit(double amount) = 0;

    virtual bool withdraw(double amount) = 0;

    virtual void print_obj(std::ostream &os) const override;

    AccountPoly(std::string name = default_name, double amount = default_balance);

    virtual ~AccountPoly() = default;
};


#endif //LEARNINGC___ACCOUNTPOLY_H
