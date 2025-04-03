#include "timer.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Timer::Timer() {
    hours = 0;
    minutes = 0;
    seconds = 0;
    meridiem = true;
};

Timer::Timer(const int _hours) {
    if (_hours < 0 || _hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}

    hours = _hours;
    minutes = 0;
    seconds = 0;
    meridiem = true;
};

Timer::Timer(const int _hours, const int _minutes) {
    if (_hours < 0 || _hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}
    if (_minutes < 0 || _minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}

    hours = _hours;
    minutes = _minutes;
    seconds = 0;
    meridiem = true;
};

Timer::Timer(const int _hours, const int _minutes, const int _seconds) {
    if (_hours < 0 || _hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}
    if (_minutes < 0 || _minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}
    if (_seconds < 0 || _seconds > 59) {throw runtime_error("Los segundos deben ser entre 0 y 59.");}

    hours = _hours;
    minutes = _minutes;
    seconds = _seconds;
    meridiem = true;
};

Timer::Timer(const int _hours, const int _minutes, const int _seconds, const string formatMeridiem) {
    if (_hours < 0 || _hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}
    if (_minutes < 0 || _minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}
    if (_seconds < 0 || _seconds > 59) {throw runtime_error("Los segundos deben ser entre 0 y 59.");}

    if (formatMeridiem == "a.m." || formatMeridiem == "a" || formatMeridiem == "am") {meridiem = true;}
    else if (formatMeridiem == "p.m." || formatMeridiem == "p" || formatMeridiem == "pm") {meridiem = false;}
    else {throw runtime_error("Formato meridiem no válido: " + formatMeridiem);}

    hours = _hours;
    minutes = _minutes;
    seconds = _seconds;
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

void Timer::showHours() const {
    cout << hours << " Horas" << endl << endl;
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
    if (formatMeridiem == "a.m." || formatMeridiem == "a" || formatMeridiem == "am") {
        meridiem = true;
    }
    else if (formatMeridiem == "p.m." || formatMeridiem == "p" || formatMeridiem == "pm") {
        meridiem = false;
    }
    else {
        throw runtime_error("Formato meridiem no válido: " + formatMeridiem);
    }
};

void Timer::toggleMeridiem() {
    meridiem = !meridiem;
};