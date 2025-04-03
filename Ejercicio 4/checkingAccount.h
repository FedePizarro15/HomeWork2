#pragma once

#include "bankAccount.h"
#include "savingsAccount.h"

class CheckingAccount final : public BankAccount {
    private:
        SavingsAccount* savingsAccount;

    public:
        CheckingAccount(const string _holder, const unsigned int _id) : BankAccount(_holder, _id), savingsAccount(nullptr) {};
        CheckingAccount(const string _holder, const unsigned int _id, const double _balance) : BankAccount(_holder, _id, _balance), savingsAccount(nullptr) {};
        CheckingAccount(const string _holder, const unsigned int _id, const double _balance, SavingsAccount* _savingsAccount) : BankAccount(_holder, _id, _balance), savingsAccount(_savingsAccount) {};

        bool withdraw(double amount) override;
        void showInfo() override;

        void setSavingsAccount(SavingsAccount* sa) {
            savingsAccount = sa;
        }
};