// transaction.cpp

#include <iostream>
#include "transaction.h"

void Transaction::display() const {
    std::cout << "Name: " << name << ", Action: " << action << ", Amount: " << amount << std::endl;
}
