// bank.h

#ifndef BANK_H
#define BANK_H

#include <vector>
#include <unordered_map>
#include "transaction.h"

class Bank {
private:
    std::unordered_map<std::string, double> balances; // Track balances using a map

public:
    void processTransactions(const std::vector<Transaction>& transactions);
    void printBalances() const; // Function to print customer balances
};

#endif // BANK_H
