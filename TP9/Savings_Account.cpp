#include "Savings_Account.h"

// Constructor
Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account(name, balance), int_rate(int_rate) {}

// Deposit method
bool Savings_Account::deposit(double amount) {
    if (amount <= 0) {
        return false;
    }
    amount += amount * (int_rate / 100); // Add interest to the deposit
    return Account::deposit(amount);
}

// Overloaded << operator
std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "]";
    return os;
}