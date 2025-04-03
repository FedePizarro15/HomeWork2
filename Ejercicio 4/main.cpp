#include "bankAccount.h"
#include "savingsAccount.h"
#include "checkingAccount.h"

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<BankAccount*> accounts;
unsigned int nextId = 1000;

void pauseAndContinue(string message = "Presione Enter para continuar...") {
    cout << message << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin.get();
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    cout << "===== SISTEMA BANCARIO =====" << endl << endl;
    cout << "1. Crear nueva Caja de Ahorro" << endl;
    cout << "2. Crear nueva Cuenta Corriente" << endl;
    cout << "3. Depositar dinero" << endl;
    cout << "4. Retirar dinero" << endl;
    cout << "5. Ver información de Cuenta" << endl;
    cout << "6. Vincular Caja de Ahorro a Cuenta Corriente" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opción: " << endl << "> ";
}

BankAccount* selectAccount() {
    cout << "Seleccione una Cuenta (1-" << accounts.size() << "):" << endl << endl;

    if (accounts.empty()) {
        cout << "No hay Cuentas creadas todavía." << endl << endl;
        pauseAndContinue();
        return nullptr;
    }
    
    cout << endl;
    for (size_t i = 0; i < accounts.size(); i++) {
        cout << i + 1 << ". ";
        if (dynamic_cast<SavingsAccount*>(accounts[i])) {
            cout << "Caja de Ahorro - ID: " << accounts[i]->getId() << endl;
        } else if (dynamic_cast<CheckingAccount*>(accounts[i])) {
            cout << "Cuenta Corriente - ID: " << accounts[i]->getId() << endl;
        }
    }
    
    size_t index;
    cout << endl << "Ingrese una opción: " << endl << "> ";
    cin >> index;
    
    if (cin.fail() || index < 1 || index > accounts.size()) {
        clearInputBuffer();
        cout << "Selección inválida." << endl << endl;
        pauseAndContinue();
        return nullptr;
    }
    
    return accounts[index - 1];
}

void createSavingsAccount() {
    string holder;
    double initialBalance;
    
    cout << endl << "--- CREAR CAJA DE AHORRO ---" << endl << endl;
    cout << "Ingrese el nombre del titular: " << endl << "> ";
    clearInputBuffer();
    getline(cin, holder);
    
    cout << "Ingrese el saldo inicial: " << endl << "> $";
    cin >> initialBalance;
    
    if (cin.fail() || initialBalance < 0) {
        clearInputBuffer();
        cout << "Monto inválido." << endl << endl;
        pauseAndContinue();
        return;
    }
    
    SavingsAccount* newAccount = new SavingsAccount(holder, nextId++, initialBalance);
    accounts.push_back(newAccount);
    cout << endl << "Caja de Ahorro (ID: " << newAccount->getId() << ") creada exitosamente."  << endl << endl;

    pauseAndContinue();
}

void createCheckingAccount() {
    string holder;
    double initialBalance;
    
    cout << endl << "--- CREAR CUENTA CORRIENTE ---" << endl << endl;
    cout << "Ingrese el nombre del titular: " << endl << "> ";
    clearInputBuffer();
    getline(cin, holder);
    
    cout << "Ingrese el saldo inicial: " << endl << "> $";
    cin >> initialBalance;
    
    if (cin.fail() || initialBalance < 0) {
        clearInputBuffer();
        cout << "Monto inválido." << endl << endl;
        pauseAndContinue();
        return;
    }
    
    CheckingAccount* newAccount = new CheckingAccount(holder, nextId++, initialBalance);
    accounts.push_back(newAccount);
    cout << endl << "Cuenta Corriente (ID: " << newAccount->getId() << ") creada exitosamente."  << endl << endl;
    pauseAndContinue();
}

void depositToAccount() {
    BankAccount* account = selectAccount();
    if (!account) {
        pauseAndContinue();
        return;
    }
    
    cout << "Cuenta seleccionada - ID: " << account->getId() << endl;
    double amount;
    cout << "Ingrese el monto a depositar: " << endl << "> $";
    cin >> amount;
    
    if (cin.fail() || amount <= 0) {
        clearInputBuffer();
        cout << "Monto inválido." << endl << endl;
        pauseAndContinue();
        return;
    }

        account->deposit(amount);
        
    pauseAndContinue();
}

void withdrawFromAccount() {
    BankAccount* account = selectAccount();
    if (!account) {
        pauseAndContinue();
        return;
    }
    
    cout << "Cuenta seleccionada - ID: " << account->getId() << endl;
    double amount;
    cout << "Ingrese el monto a retirar: " << endl << "> $";
    cin >> amount;
    
    if (cin.fail() || amount <= 0) {
        clearInputBuffer();
        cout << "Monto inválido." << endl << endl;
        pauseAndContinue();
        return;
    }
    
    account->withdraw(amount);
    pauseAndContinue();
    }

void showAccountInfo() {
    BankAccount* account = selectAccount();
    if (!account) {
        pauseAndContinue();
        return;
    }
    
    account->showInfo();
    pauseAndContinue();
}

void linkSavingsToChecking() {
    vector<SavingsAccount*> savingsAccounts;

    for (auto& acc : accounts) {
        SavingsAccount* sa = dynamic_cast<SavingsAccount*>(acc);
        if (sa) {
            savingsAccounts.push_back(sa);
        }
    }
    
    if (savingsAccounts.empty()) {
        cout << "No hay Cajas de Ahorro disponibles para vincular." << endl << endl;
        pauseAndContinue();
        return;
    }
    
    vector<CheckingAccount*> checkingAccounts;

    for (auto& acc : accounts) {
        CheckingAccount* ca = dynamic_cast<CheckingAccount*>(acc);
        if (ca) {
            checkingAccounts.push_back(ca);
        }
    }
    
    if (checkingAccounts.empty()) {
        cout << "No hay Cuentas Corrientes disponibles para vincular." << endl << endl;
        pauseAndContinue();
        return;
    }
    
    cout << endl << "--- CAJAS DE AHORRO DISPONIBLES ---" << endl << endl;

    for (size_t i = 0; i < savingsAccounts.size(); i++) {
        cout << i + 1 << ". Caja de Ahorro - ID: " << savingsAccounts[i]->getId() << endl;
    }
    
    int saIndex;
    cout << endl << "Seleccione una Caja de Ahorro (1-" << savingsAccounts.size() << "): ";
    cin >> saIndex;
    
    if (cin.fail() || saIndex < 1 || saIndex > static_cast<int>(savingsAccounts.size())) {
        clearInputBuffer();
        cout << "Selección inválida." << endl << endl;
        pauseAndContinue();
        return;
    }
    
    cout << endl << "--- CUENTAS CORRIENTES DISPONIBLES ---" << endl << endl;

    for (size_t i = 0; i < checkingAccounts.size(); i++) {
        cout << i + 1 << ". Cuenta Corriente - ID: " << checkingAccounts[i]->getId() << endl;
    }
    
    int caIndex;
    cout << endl << "Seleccione una Cuenta Corriente (1-" << checkingAccounts.size() << "): ";
    cin >> caIndex;
    
    if (cin.fail() || caIndex < 1 || caIndex > static_cast<int>(checkingAccounts.size())) {
        clearInputBuffer();
        cout << "Selección inválida." << endl << endl;
        pauseAndContinue();
        return;
    }
    
    SavingsAccount* selectedSA = savingsAccounts[saIndex - 1];
    CheckingAccount* selectedCA = checkingAccounts[caIndex - 1];
    
    selectedCA->setSavingsAccount(selectedSA);
    
    cout << "Caja de Ahorro vinculada exitosamente a la Cuenta Corriente." << endl << endl;
    pauseAndContinue();
}

int main() {
    int choice;
    bool running = true;
    
    while (running) {
        system("clear");
        
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            clearInputBuffer();
            cout << "Opción inválida. Intente nuevamente." << endl << endl;
            pauseAndContinue();
            continue;
        }
        
        switch (choice) {
            case 1:
                createSavingsAccount();
                break;
            case 2:
                createCheckingAccount();
                break;
            case 3:
                depositToAccount();
                break;
            case 4:
                withdrawFromAccount();
                break;
            case 5:
                showAccountInfo();
                break;
            case 6:
                linkSavingsToChecking();
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl << endl;
                pauseAndContinue();
                break;
        }
    }
    
    for (auto& account : accounts) {
        delete account;
    }
    
    cout << "Gracias por usar el sistema bancario!" << endl << endl;
    return 0;
}