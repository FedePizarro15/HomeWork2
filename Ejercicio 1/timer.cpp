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

Timer::Timer(int hours) {
    if (hours < 0 || hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}

    this->hours = hours;
    minutes = 0;
    seconds = 0;
    meridiem = true;
};

Timer::Timer(int hours, int minutes) {
    if (hours < 0 || hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}
    if (minutes < 0 || minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}

    this->hours = hours;
    this->minutes = minutes;
    seconds = 0;
    meridiem = true;
};

Timer::Timer(int hours, int minutes, int seconds) {
    if (hours < 0 || hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}
    if (minutes < 0 || minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}
    if (seconds < 0 || seconds > 59) {throw runtime_error("Los segundos deben ser entre 0 y 59.");}

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    meridiem = true;
};

Timer::Timer(int hours, int minutes, int seconds, string formatMeridiem) {
    if (hours < 0 || hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}
    if (minutes < 0 || minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}
    if (seconds < 0 || seconds > 59) {throw runtime_error("Los segundos deben ser entre 0 y 59.");}

    if (formatMeridiem == "a.m." || formatMeridiem == "a" || formatMeridiem == "am") {this->meridiem = true;}
    else if (formatMeridiem == "p.m." || formatMeridiem == "p" || formatMeridiem == "pm") {this->meridiem = false;}
    else {throw runtime_error("Formato meridiem no válido: " + formatMeridiem);}

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
};

void Timer::showTimer() {
    cout << setfill('0') << setw(2) << hours << "h, " 
         << setfill('0') << setw(2) << minutes << "m, " 
         << setfill('0') << setw(2) << seconds << "s "
         << (meridiem ? "a.m." : "p.m.") << endl << endl;
};

void Timer::showTimer24() {
    cout << setfill('0') << setw(2) << (meridiem ? hours : hours + 12) << "h, "
         << setfill('0') << setw(2) << minutes << "m, "
         << setfill('0') << setw(2) << seconds << "s" << endl << endl;
};

void Timer::showHours() {
    cout << hours << " Horas" << endl << endl;
};

void Timer::showMinutes() {
    cout << minutes << " Minutos" << endl << endl;
};

void Timer::showSeconds() {
    cout << seconds << " Segundos" << endl << endl;

};

void Timer::showFormatMeridiem() {
    cout << getFormatMeridiem() << endl << endl;
};

int Timer::getHours() {
    return hours;
};

int Timer::getMinutes() {
    return minutes;
};

int Timer::getSeconds() {
    return seconds;
};

bool Timer::getMeridiem() {
    return meridiem;
};

string Timer::getFormatMeridiem() {
    return (meridiem ? "a.m." : "p.m.");
};

void Timer::setHours(int hours) {
    if (hours < 0 || hours > 11) {throw runtime_error("Las horas deben ser entre 0 y 11.");}

    this->hours = hours;
};

void Timer::setMinutes(int minutes) {
    if (minutes < 0 || minutes > 59) {throw runtime_error("Los minutos deben ser entre 0 y 59.");}

    this->minutes = minutes;
};

void Timer::setSeconds(int seconds) {
    if (seconds < 0 || seconds > 59) {throw runtime_error("Los segundos deben ser entre 0 y 59.");}

    this->seconds = seconds;
};

void Timer::setMeridiem(string formatMeridiem) {
    if (formatMeridiem == "a.m." || formatMeridiem == "a" || formatMeridiem == "am") {
        this->meridiem = true;
    }
    else if (formatMeridiem == "p.m." || formatMeridiem == "p" || formatMeridiem == "pm") {
        this->meridiem = false;
    }
    else {
        throw runtime_error("Formato meridiem no válido: " + formatMeridiem);
    }
}

void Timer::toggleMeridiem() {
    this->meridiem = !this->meridiem;
};