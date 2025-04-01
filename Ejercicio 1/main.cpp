#include "timer.h"
#include <iostream>
#include <limits>  // Para std::numeric_limits

using namespace std;

void input(string message, int* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void input(string message, string* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void input(string message, bool* variable) {
    cout << message << endl << ">> ";
    cin >> *variable;
    cout << endl;
};

void pauseAndContinue(string message = "Presione Enter para continuar...") {
    cout << message << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin.get();
}

int main() {
    Timer timer;

    int choice = 0;
    int secondChoice = 0;

    while (true) {
        cout << endl << "==== MENÚ DEL TEMPORIZADOR ====" << endl;
        cout << "1.  Iniciar un Nuevo Temporizador" << endl ;
        cout << "2.  Mostrar Temporizador (formato 12h)" << endl;
        cout << "3.  Mostrar Temporizador (formato 24h)" << endl;
        cout << "4.  Mostrar Horas" << endl;
        cout << "5.  Mostrar Minutos" << endl;
        cout << "6.  Mostrar Segundos" << endl;
        cout << "7.  Mostrar Meridiem" << endl;
        cout << "8.  Configurar Horas" << endl;
        cout << "9.  Configurar Minutos" << endl;
        cout << "10. Configurar Segundos" << endl;
        cout << "11. Configurar Meridiem" << endl;
        cout << "0.  Salir" << endl;
        cout << endl;

        input("Ingrese su opción:", &choice);
        cout << "================================" << endl << endl;

        switch (choice) {
            case 1: {
                int hours, minutes, seconds;

                cout << endl << "== Iniciar Nuevo Temporizador ==" << endl;
                cout << "1. Sin parámetros (00h, 00m, 00s a.m.)" << endl ;
                cout << "2. Horas (HHh, 00m, 00s a.m.)" << endl;
                cout << "3. Horas, Minutos (HHh, MMm, 00s a.m.)" << endl;
                cout << "4. Horas, Minutos, Segundos (HHh, MMm, SSs a.m.)" << endl;
                cout << "5. Horas, Minutos, Segundos, Meridiem (HHh, MMm, SSs a.m./p.m.)" << endl;
                cout << "0. Volver" << endl;
                cout << endl;

                input("Ingrese su opción:", &secondChoice);
                cout << "================================" << endl << endl;

                switch (secondChoice) {
                    case 1:
                        timer = Timer();

                        cout << "Temporizador Inicializado." << endl << endl;
                        break;
                    case 2:
                        cout << "Ingrese los parámetros" << endl;
                        input("Horas: (0-11)", &hours);
                        
                        timer = Timer(hours);

                        cout << "Temporizador Inicializado." << endl << endl;
                        break;
                    case 3:
                        cout << "Ingrese los parámetros" << endl;
                        input("Horas: (0-11)", &hours);
                        input("Minutos: (0-59)", &minutes);
                        
                        timer = Timer(hours, minutes);

                        cout << "Temporizador Inicializado." << endl << endl;
                        break;
                    case 4:
                        cout << "Ingrese los parámetros" << endl;
                        input("Horas: (0-11)", &hours);
                        input("Minutos: (0-59)", &minutes);
                        input("Segundos: (0-59)", &seconds);
                        
                        timer = Timer(hours, minutes, seconds);

                        cout << "Temporizador Inicializado." << endl << endl;
                        break;
                    case 5: {
                        string formatMeridiem;

                        cout << "Ingrese los parámetros" << endl;
                        input("Horas: (0-11)", &hours);
                        input("Minutos: (0-59)", &minutes);
                        input("Segundos: (0-59)", &seconds);

                        input("Meridiem: ('a', 'am', 'a.m.'/'p', 'pm', 'p.m.')", &formatMeridiem);
                        
                        timer = Timer(hours, minutes, seconds, formatMeridiem);

                        cout << "Temporizador Inicializado." << endl << endl;
                        break;
                    }
                    case 0:
                        cout << "Volviendo al menú principal..." << endl;
                        break;
                    default:
                        cout << "Opción inválida. Intente nuevamente." << endl;
                }
                break;
            }
            case 2:
                cout << "Mostrar Temporizador (12hs)" << endl;
                timer.showTimer();
                break;
            case 3:
                cout << "Mostrar Temporizador (24hs)" << endl;
                timer.showTimer24();
                break;
            case 4:
                cout << "Mostrar Horas" << endl;
                timer.showHours();
                break;
            case 5:
                cout << "Mostrar Minutos" << endl;
                timer.showMinutes();
                break;
            case 6:
                cout << "Mostrar Segundos" << endl;
                timer.showSeconds();
                break;
            case 7:
                cout << "Mostrar Meridiem" << endl;
                timer.showFormatMeridiem();
                break;
            case 8: {
                cout << "Configurar Horas" << endl;
                int hours;
                input("Ingrese nuevas horas (0-11):", &hours);

                timer.setHours(hours);

                break;
            }
            case 9: {
                cout << "Configurar Minutos" << endl;
                int minutes;
                input("Ingrese nuevos minutos (0-59):", &minutes);

                timer.setMinutes(minutes);

                break;
            }
            case 10: {
                cout << "Configurar Segundos" << endl;
                int seconds;
                input("Ingrese nuevos segundos (0-59):", &seconds);

                timer.setSeconds(seconds);

                break;
            }
            case 11: {
                cout << "Configurar Meridiem" << endl;
                
                cout << "El temporizador actualmente está configurado como <" << timer.getFormatMeridiem() << ">" << endl;
                cout << "1. Cambiar a a.m." << endl;
                cout << "2. Cambiar a p.m." << endl;
                cout << "3. Invertir (a.m. ↔ p.m.)" << endl;
                cout << "0. Volver al menú principal" << endl << endl;
                
                input("Ingrese su opción:", &secondChoice);
                
                switch (secondChoice) {
                    case 1:
                        timer.setMeridiem("a.m.");
                        cout << "Meridiem actualizado a a.m." << endl;
                        break;
                    case 2:
                        timer.setMeridiem("p.m.");
                        cout << "Meridiem actualizado a p.m." << endl;
                        break;
                    case 3:
                        timer.toggleMeridiem();
                        cout << "Meridiem invertido a " << timer.getFormatMeridiem() << endl;
                        break;
                    case 0:
                        cout << "Volviendo al menú principal..." << endl;
                        break;
                    default:
                        cout << "Opción inválida." << endl;
                }
                break;
            }
            case 0:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
        pauseAndContinue();
    };
    return 0;
};