#pragma once

#include "bankAccount.h"

class SavingsAccount final : public BankAccount {
    private:
        int payToShow = 0;
        
    public:
        SavingsAccount(const string _holder, const unsigned int _id) : BankAccount(_holder, _id) {};
        SavingsAccount(const string _holder, const unsigned int _id, const double _balance) : BankAccount(_holder, _id, _balance) {};

        bool withdraw(double amount) override;
        void showInfo() override;

        friend class CheckingAccount;
};