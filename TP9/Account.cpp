#include "Account.h"
#include <iostream>

// Constructor
Account::Account(std::string name, double balance)
    : name{name}, balance{balance} {
}

// Deposit method
bool Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

// Withdraw method
bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

// Overloaded << operator
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}