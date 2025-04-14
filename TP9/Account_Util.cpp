#include "Account_Util.h"
#include <iostream>

// Display functions
void display(const std::vector<Account>& accounts) {
    std::cout << "=== Accounts===========================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
    std::cout << std::endl;
}

void display(const std::vector<Savings_Account>& accounts) {
    std::cout << "=== Savings Accounts=====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
    std::cout << std::endl;
}

void display(const std::vector<Checking_Account>& accounts) {
    std::cout << "=== Checking Accounts=====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
    std::cout << std::endl;
}

void display(const std::vector<Trust_Account>& accounts) {
    std::cout << "=== Trust Accounts=====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
    std::cout << std::endl;
}

// Deposit functions
void deposit(std::vector<Account>& accounts, double amount) {
    std::cout << "=== Depositing to Accounts ==================================" << std::endl;
    for (auto& acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed to deposit " << amount << " to " << acc << std::endl;
    std::cout << std::endl;
}

void deposit(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "=== Depositing to Savings Accounts===========================" << std::endl;
    for (auto& acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed to deposit " << amount << " to " << acc << std::endl;
    std::cout << std::endl;
}

void deposit(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "=== Depositing to Checking Accounts===========================" << std::endl;
    for (auto& acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed to deposit " << amount << " to " << acc << std::endl;
    std::cout << std::endl;
}

void deposit(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "=== Depositing to Trust Accounts===========================" << std::endl;
    for (auto& acc : accounts)
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed to deposit " << amount << " to " << acc << std::endl;
    std::cout << std::endl;
}

// Withdraw functions
void withdraw(std::vector<Account>& accounts, double amount) {
    std::cout << "=== Withdrawing from Accounts =============================" << std::endl;
    for (auto& acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    std::cout << std::endl;
}

void withdraw(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "=== Withdrawing from Savings Accounts=======================" << std::endl;
    for (auto& acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    std::cout << std::endl;
}

void withdraw(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "=== Withdrawing from Checking Accounts=======================" << std::endl;
    for (auto& acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    std::cout << std::endl;
}

void withdraw(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "=== Withdrawing from Trust Accounts=======================" << std::endl;
    for (auto& acc : accounts)
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    std::cout << std::endl;
}