//
// Created by Daniil Slobodeniuk on 2023/07/04.
//

#include "iostream"

using namespace std;

void eight_challenge() {
    int num_cents{0};

    int dollars{0};
    int quarters{0};
    int dimes{0};
    int nickels{0};
    int pennies{0};

    cout << "Enter amount of cents you want to be parsed: \n" << endl;
    cin >> num_cents;

    const int dollar_const = 100;
    dollars = num_cents / dollar_const;
    num_cents = num_cents - dollars * dollar_const; // remaining
    cout << "Dollars: " << dollars << endl;

    const int quarter_const = 25;
    quarters = num_cents / quarter_const;
    num_cents = num_cents - quarters * quarter_const;
    cout << "Quarters: " << quarters << endl;

    const int dime_const = 10;
    dimes = num_cents / dime_const;
    num_cents = num_cents - dimes * dime_const;
    cout << "Dimes:  " << dimes << endl;

    const int nickels_const = 5;
    nickels = num_cents / nickels_const;
    num_cents = num_cents - nickels * nickels_const;
    cout << "Nickels: " << nickels << endl;

    const int pennies_const = 1;
    pennies = num_cents / pennies_const;
    cout << "Pennies: " << pennies << endl;

    cout << "That's all!" << endl;

}