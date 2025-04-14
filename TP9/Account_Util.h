#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

// Display functions
void display(const std::vector<Account>& accounts);
void display(const std::vector<Savings_Account>& accounts);
void display(const std::vector<Checking_Account>& accounts);
void display(const std::vector<Trust_Account>& accounts);

// Deposit functions
void deposit(std::vector<Account>& accounts, double amount);
void deposit(std::vector<Savings_Account>& accounts, double amount);
void deposit(std::vector<Checking_Account>& accounts, double amount);
void deposit(std::vector<Trust_Account>& accounts, double amount);

// Withdraw functions
void withdraw(std::vector<Account>& accounts, double amount);
void withdraw(std::vector<Savings_Account>& accounts, double amount);
void withdraw(std::vector<Checking_Account>& accounts, double amount);
void withdraw(std::vector<Trust_Account>& accounts, double amount);

#endif // _ACCOUNT_UTIL_H_