#pragma once

#include "string"

using namespace std;

class BankAccount {
private:
    double balance;
    string holder;
public:
    BankAccount();
    ~BankAccount();

    void deposit(double amount);
    void withdraw(double amount);
    void showInfo();
};