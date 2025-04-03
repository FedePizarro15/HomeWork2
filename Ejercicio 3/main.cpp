#include "number.h"
#include "integer.h"
#include "real.h"
#include "complex.h"

#include <iostream>
#include <vector>
#include <memory>
#include <limits>

using namespace std;

enum class NUMBER_TYPE {INTEGER, REAL, COMPLEX};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseAndContinue(string message = "Presione Enter para continuar...") {
    cout << message << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayMainMenu() {
    cout << "===== SISTEMA DE OPERACIONES NUMÉRICAS =====" << endl << endl;
    cout << "1. Operaciones con Enteros" << endl;
    cout << "2. Operaciones con Reales" << endl;
    cout << "3. Operaciones con Números Complejos" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opción: " << endl << "> ";
}

void displayOperationsMenu(const string& type) {
    cout << "===== OPERACIONES CON " << type << " =====" << endl << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicación" << endl;
    cout << "0. Volver al menú principal" << endl << endl;
    cout << "Ingrese una opción: " << endl << "> ";
}

unique_ptr<Number> createInteger() {
    int value;
    cout << "Ingrese un valor entero: ";
    cin >> value;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Valor inválido. Se usará 0." << endl;
        return make_unique<Integer>(0);
    }

    unique_ptr<Integer> newInteger = make_unique<Integer>(value);

    cout << "Se ingresó correctamente el número '" << newInteger->toString() << "'." << endl << endl;
    
    return newInteger;
}

unique_ptr<Number> createReal() {
    float value;
    cout << "Ingrese un valor real: ";
    cin >> value;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Valor inválido. Se usará 0." << endl;
        return make_unique<Real>(0.0f);
    }

    unique_ptr<Real> newReal = make_unique<Real>(value);

    cout << "Se ingresó correctamente el número '" << newReal->toString() << "'." << endl << endl;
    
    return newReal;
}

unique_ptr<Number> createComplex() {
    float realPart, imaginaryPart;
    
    cout << "Ingrese la parte real: ";
    cin >> realPart;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Valor inválido. Se usará 0." << endl;
        realPart = 0.0f;
    }
    
    cout << "Ingrese la parte imaginaria: ";
    cin >> imaginaryPart;
    
    if (cin.fail()) {
        clearInputBuffer();
        cout << "Valor inválido. Se usará 0." << endl;
        imaginaryPart = 0.0f;
    }

    unique_ptr<Complex> newComplex = make_unique<Complex>(realPart, imaginaryPart);

    cout << "Se ingresó correctamente el número '" << newComplex->toString() << "'." << endl << endl;
    
    return newComplex;
}

int selectNumberType() {
    cout << "Seleccione el tipo de número:" << endl;
    cout << "1. Entero" << endl;
    cout << "2. Real" << endl;
    cout << "3. Complejo" << endl;
    cout << "> ";
    
    int choice;
    cin >> choice;
    
    if (cin.fail() || choice < 1 || choice > 3) {
        clearInputBuffer();
        cout << "Opción inválida. Seleccionando Entero por defecto." << endl;
        return 1;
    }
    
    return choice;
}

unique_ptr<Number> createNumber(NUMBER_TYPE type) {    
    switch(type) {
        case NUMBER_TYPE::INTEGER:
            return createInteger();
        case NUMBER_TYPE::REAL:
            return createReal();
        case NUMBER_TYPE::COMPLEX:
            return createComplex();
        default:
            return createInteger();
    }
}

void performSameTypeOperations(NUMBER_TYPE type) {
    string typeName;
    
    switch(type) {
        case NUMBER_TYPE::INTEGER:
            typeName = "ENTEROS";
            break;
        case NUMBER_TYPE::REAL:
            typeName = "REALES";
            break;
        case NUMBER_TYPE::COMPLEX:
            typeName = "COMPLEJOS";
            break;
        default:
            return;
    }
    
    int choice;
    bool running = true;
    
    while (running) {
        system("clear");
        displayOperationsMenu(typeName);
        cin >> choice;
        
        if (cin.fail()) {
            clearInputBuffer();
            cout << "Opción inválida. Intente nuevamente." << endl;
            pauseAndContinue();
            continue;
        }
        
        if (choice == 0) {
            running = false;
            continue;
        }
        
        if (choice < 1 || choice > 3) {
            cout << "Opción inválida. Intente nuevamente." << endl;
            pauseAndContinue();
            continue;
        }
        
        cout << endl << "--- Ingrese el primer número ---" << endl;
        auto num1 = createNumber(type);
        
        cout << endl << "--- Ingrese el segundo número ---" << endl;
        auto num2 = createNumber(type);
        
        unique_ptr<Number> result;
        string operation;
        
        switch(choice) {
            case 1:
                result = *num1 + *num2;
                operation = "+";
                break;
            case 2:
                result = *num1 - *num2;
                operation = "-";
                break;
            case 3:
                result = *num1 * *num2;
                operation = "*";
                break;
        }
        
        cout << endl << "Resultado: " << num1->toString() << " " << operation << " " 
             << num2->toString() << " = " << result->toString() << endl;
        
        pauseAndContinue();
    }
}

int main() {
    int choice;
    bool running = true;
    
    while (running) {
        system("clear");
        displayMainMenu();
        cin >> choice;
        
        if (cin.fail()) {
            clearInputBuffer();
            cout << "Opción inválida. Intente nuevamente." << endl;
            pauseAndContinue();
            continue;
        }
        
        switch (choice) {
            case 1:
                performSameTypeOperations(NUMBER_TYPE::INTEGER);
                break;
            case 2:
                performSameTypeOperations(NUMBER_TYPE::REAL);
                break;
            case 3:
                performSameTypeOperations(NUMBER_TYPE::COMPLEX);
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                pauseAndContinue();
                break;
        }
    }
    
    cout << "Gracias por usar el sistema de operaciones numéricas!" << endl;
    return 0;
}
