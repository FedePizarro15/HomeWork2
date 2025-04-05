#include "savingsAccount.h"

#include <iostream>

using namespace std;

bool SavingsAccount::withdraw(const double amount) {
    if (amount > balance) {
        cout << endl << "No hay saldo suficiente en la cuenta." << endl << endl;
        return false;
    }

    balance -= amount;

    cout << endl << "Se retiraron $" << amount << " de la cuenta (Caja de Ahorro)." << endl << endl;
    return true;
};

void SavingsAccount::showInfo() {
    if (payToShow == 0) {
        cout << endl << "Usos gratuitos restantes: 1." << endl;
    } else if (payToShow == 1)
    {
        cout << endl << "No quedan usos gratuitos, el próximo intento se ralizará un descuento de $20 del balance por consultar la información." << endl << endl;
    }
    
    if (payToShow > 2) {
        cout << endl << "Se mostró la información de la cuenta más de dos veces, por lo que se realizará un descuento de $20 del balance." << endl << endl;
        if (!withdraw(20)) {
            cout << "No se pudo mostrar la información de la cuenta." << endl << endl;
            return;
        }
    }

    cout << endl << "== Informe de la Cuenta ==" << endl << endl;
    cout << "Titular: " << holder << "." << endl;
    cout << "ID: " << id << "." << endl;
    cout << "Tipo de Cuenta: Caja de Ahorro." << endl;
    cout << "Balance: $" << balance << "." << endl << endl;

    payToShow++;
    return;
};