#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account : public Account {
private:
    static constexpr double per_check_fee = 1.50;
    
public :
    Checking_Account(std::string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
};

#endif // CHECKING_ACCOUNT_H
