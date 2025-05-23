#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account
{
protected:
    static constexpr const char *def_name = "Unnamed Account"; 
    static constexpr double def_balance = 0.0;          
    std::string name;
    double balance;

public:
    Account(std::string name = def_name, double balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
};

#endif // ACCOUNT_H