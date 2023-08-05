// transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    std::string name;
    std::string action;
    double amount;

    Transaction(const std::string& name, const std::string& action, double amount)
        : name(name), action(action), amount(amount) {}

    void display() const;
};

#endif // TRANSACTION_H
