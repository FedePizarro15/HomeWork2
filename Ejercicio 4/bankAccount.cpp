#include "bankAccount.h"

#include <iostream>

void BankAccount::deposit(double amount) {
    balance += amount;
    cout << "Se depositaron $" << amount << " en la cuenta exitosamente." << endl;
}

const unsigned int BankAccount::getId() const {return id;}