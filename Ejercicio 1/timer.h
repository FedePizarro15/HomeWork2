#pragma once
#include <string>

class Timer {
private:
    int hours, minutes, seconds;
    bool meridiem;

public:
    Timer();
    Timer(int _hours);
    Timer(int _hours, int _minutes);
    Timer(int _hours, int _minutes, int _seconds);
    Timer(int _hours, int _minutes, int _seconds, std::string fromatMeridiem);

    // ~Timer();

    void showTimer();
    void showTimer24();
    void showHours();
    void showMinutes();
    void showSeconds();
    void showFormatMeridiem();

    int getHours();
    int getMinutes();
    int getSeconds();
    bool getMeridiem();
    std::string getFormatMeridiem();
    
    void setHours(int _hours);
    void setMinutes(int _minutes);
    void setSeconds(int _seconds);
    void setMeridiem(std::string formatMeridiem);
    void toggleMeridiem();
};