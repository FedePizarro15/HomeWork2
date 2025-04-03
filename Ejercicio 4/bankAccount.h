#pragma once

#include "string"

using namespace std;

class BankAccount {
protected:
    const string holder;
    const unsigned int id;
    double balance;

public:
    BankAccount(const string _holder, const unsigned int _id) : holder(_holder), id(_id), balance(0) {};
    BankAccount(const string _holder, const unsigned int _id, const double _balance) : holder(_holder), id(_id), balance(_balance) {};
    virtual ~BankAccount() = default;

    bool virtual withdraw(double amount) = 0;
    void virtual showInfo() = 0;
    void deposit(double amount);

    const unsigned int getId() const;
};