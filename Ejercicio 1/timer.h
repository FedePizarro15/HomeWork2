#pragma once
#include <string>

class Timer {
public:
    Timer();
    Timer(int horus);
    Timer(int horus, int minutes);
    Timer(int horus, int minutes, int seconds);
    Timer(int horus, int minutes, int seconds, std::string fromatMeridiem);

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
    
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);
    void setMeridiem(std::string formatMeridiem);
    void toggleMeridiem();

private:
    int hours, minutes, seconds;
    bool meridiem;    
};