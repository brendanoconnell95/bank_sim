#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "transaction.h"
#include "bank.h"

std::vector<Transaction> readEventsFromCSV(const std::string& filename) {
    std::vector<Transaction> transactions;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return transactions;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string name, action;
        double amount;

        if (std::getline(stream, name, ',') &&
            std::getline(stream, action, ',') &&
            (stream >> amount)) {
            transactions.emplace_back(name, action, amount);
        }
    }

    file.close();
    return transactions;
}

int main() {
    std::vector<Transaction> transactions;

    // Read events from CSV file and create Transaction objects
    transactions = readEventsFromCSV("events.csv");

    Bank bank;
    bank.processTransactions(transactions);
    bank.printBalances(); // Print customer balances

    return 0;
}
