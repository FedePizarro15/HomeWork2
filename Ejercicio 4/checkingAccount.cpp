#include "checkingAccount.h"

#include <iostream>

bool CheckingAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << endl << "No hay suficientes fondos en la Cuenta Corriente." << endl;
        cout << "Consultando balance de Caja de Ahorro..." << endl << endl;

        if (!savingsAccount) {
            cout << "No hay una Caja de Ahorro vinculada." << endl << endl;
            return false;
        }

        if (amount > balance + savingsAccount->balance) {
            cout << "No hay suficientes fondos en la Caja de Ahorro" << endl << endl;
            return false;
        }

        double diference = amount - balance;

        if (balance == 0) {
            cout << "No se retiró dinero de la cuenta (Cuenta Corriente)." << endl << endl;
        } else {
            cout << "Se retiraron $" << balance << " de la cuenta (Cuenta Corriente)." << endl << endl;
        }
    
        balance = 0;
    
        savingsAccount->withdraw(diference);
        return true;
    }

    balance -= amount;

    cout << endl << "Se retiraron $" << amount << " de la cuenta (Caja de Ahorro)." << endl << endl;
    return true;
};

void CheckingAccount::showInfo() {
    cout << endl << "== Informe de la Cuenta ==" << endl << endl;
    cout << "Titular: " << holder << "." << endl;
    cout << "ID: " << id << "." << endl;
    cout << "Tipo de Cuenta: Cuenta Corriente." << endl;
    cout << "Balance: $" << balance << "." << endl << endl;
};