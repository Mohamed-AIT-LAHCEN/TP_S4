#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include <iostream>
#include <string>
#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
private:
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
public :
    double num_withdrawals;
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
};

#endif // TRUST_ACCOUNT_H
