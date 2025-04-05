#pragma once

#include <string>

class Timer {
private:
    int hours, minutes, seconds;
    bool meridiem;

    void validateTime(const int h, const int m = 0, const int s = 0, const std::string formatMeridiem = "a.m") const;

public:
    Timer();
    Timer(const int _hours);
    Timer(const int _hours, const int _minutes);
    Timer(const int _hours, const int _minutes, const int _seconds);
    Timer(const int _hours, const int _minutes, const int _seconds, const std::string fromatMeridiem);

    void showTimer() const;
    void showTimer24() const;
    void showHours() const;
    void showMinutes() const;
    void showSeconds() const;
    void showFormatMeridiem() const;

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool getMeridiem() const;
    std::string getFormatMeridiem() const;
    
    void setHours(const int _hours);
    void setMinutes(const int _minutes);
    void setSeconds(const int _seconds);
    void setMeridiem(const std::string formatMeridiem);
    void toggleMeridiem();
};