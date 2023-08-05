// bank.cpp

#include <iostream>
#include <unordered_map>
#include "bank.h"

void Bank::processTransactions(const std::vector<Transaction>& transactions) {
    for (const auto& transaction : transactions) {
        const std::string& name = transaction.name;
        const std::string& action = transaction.action;
        double amount = transaction.amount;

        if (action == "Deposit") {
            balances[name] += amount;
        } else if (action == "Withdraw") {
            balances[name] -= amount;
        } else if (action == "Check") {
            std::cout << "Balance for " << name << ": " << balances[name] << std::endl;
        } else {
            std::cerr << "Error: Invalid action for " << name << std::endl;
        }
    }
}

void Bank::printBalances() const {
    std::cout << "Customer Balances:" << std::endl;
    for (const auto& entry : balances) {
        const std::string& name = entry.first;
        double balance = entry.second;
        std::cout << "Name: " << name << ", Balance: " << balance << std::endl;
    }
}
