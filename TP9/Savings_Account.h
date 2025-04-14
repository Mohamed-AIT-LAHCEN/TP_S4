#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

class Savings_Account : public Account {
protected:
    static constexpr double def_int_rate = 0.0;
    
public :
    double int_rate;
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
};

#endif // SAVINGS_ACCOUNT_H
