#include "timer.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Valida que los parametro para inicializar un temporizador sean correctos

void Timer::validateTime(const int h, const int m = 0, const int s = 0, const string formatMeridiem = "a.m") const {
    if (h < 0 || h > 11) {
        throw runtime_error("Las horas deben ser entre 0 y 11.");
    }
    if (m < 0 || m > 59) {
        throw runtime_error("Los minutos deben ser entre 0 y 59.");
    }
    if (s < 0 || s > 59) {
        throw runtime_error("Los segundos deben ser entre 0 y 59.");
    }
    if (formatMeridiem != "a.m." && formatMeridiem != "a" && formatMeridiem != "am" && formatMeridiem != "p.m." && formatMeridiem != "p" && formatMeridiem != "pm") {
        throw runtime_error("Formato meridiem no válido: " + formatMeridiem);
    }
}

Timer::Timer(const int _hours) {
    validateTime(_hours);

    hours = _hours;
    minutes = 0;
    seconds = 0;
    meridiem = true;
};

Timer::Timer(const int _hours, const int _minutes) {
    validateTime(_hours, _minutes);

    hours = _hours;
    minutes = _minutes;
    seconds = 0;
    meridiem = true;
};

Timer::Timer(const int _hours, const int _minutes, const int _seconds) {
    validateTime(_hours, _minutes, _seconds);

    hours = _hours;
    minutes = _minutes;
    seconds = _seconds;
    meridiem = true;
};

Timer::Timer(const int _hours, const int _minutes, const int _seconds, const string formatMeridiem) {
    validateTime(_hours, _minutes, _seconds, formatMeridiem);

    hours = _hours;
    minutes = _minutes;
    seconds = _seconds;
    
    if (formatMeridiem == "a.m." || formatMeridiem == "a" || formatMeridiem == "am") {meridiem = true;}
    else if (formatMeridiem == "p.m." || formatMeridiem == "p" || formatMeridiem == "pm") {meridiem = false;}
};

void Timer::showTimer() const {
    cout << setfill('0') << setw(2) << hours << "h, " 
         << setfill('0') << setw(2) << minutes << "m, " 
         << setfill('0') << setw(2) << seconds << "s "
         << (meridiem ? "a.m." : "p.m.") << endl << endl;
};

void Timer::showTimer24() const {
    cout << setfill('0') << setw(2) << (meridiem ? hours : hours + 12) << "h, "
         << setfill('0') << setw(2) << minutes << "m, "
         << setfill('0') << setw(2) << seconds << "s" << endl << endl;
};

// Asumo que hay que mostrar las horas según si es a.m. o p.m.

void Timer::showHours() const {
    cout << (meridiem ? hours : hours + 12) << " Horas" << endl << endl;
};

void Timer::showMinutes() const {
    cout << minutes << " Minutos" << endl << endl;
};

void Timer::showSeconds() const {
    cout << seconds << " Segundos" << endl << endl;

};

void Timer::showFormatMeridiem() const {
    cout << getFormatMeridiem() << endl << endl;
};

int Timer::getHours() const {
    return hours;
};

int Timer::getMinutes() const {
    return minutes;
};

int Timer::getSeconds() const {
    return seconds;
};

bool Timer::getMeridiem() const {
    return meridiem;
};

string Timer::getFormatMeridiem() const {
    return (meridiem ? "a.m." : "p.m.");
};

void Timer::setHours(const int _hours) {
    if (_hours < 0 || _hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}

    hours = _hours;
};

void Timer::setMinutes(const int _minutes) {
    if (_minutes < 0 || _minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}

    minutes = _minutes;
};

void Timer::setSeconds(const int _seconds) {
    if (_seconds < 0 || _seconds > 59) {throw runtime_error("Los segundos deben ser entre 0 y 59.");}

    seconds = _seconds;
};

void Timer::setMeridiem(const string formatMeridiem) {
    if (formatMeridiem == "a.m." || formatMeridiem == "a" || formatMeridiem == "am") {meridiem = true;}
    else if (formatMeridiem == "p.m." || formatMeridiem == "p" || formatMeridiem == "pm") {meridiem = false;}
    else {throw runtime_error("Formato meridiem no válido: " + formatMeridiem);}
};

void Timer::toggleMeridiem() {
    meridiem = !meridiem;
};