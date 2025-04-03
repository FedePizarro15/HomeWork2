#include "complex.h"

#include <string>
#include <cstdio>

using namespace std;

Complex::Complex(float value, bool isReal) {
    if (isReal) {
        realValue = value;
        imaginaryValue = 0;
    } else {
        realValue = 0;
        imaginaryValue = value;
    }
};

unique_ptr<Number> Complex::operator+(const Number& number) const {
    const Complex& complex = static_cast<const Complex&>(number);

    float newRealValue = realValue + complex.realValue;
    float newImaginaryValue = imaginaryValue + complex.imaginaryValue;

    return make_unique<Complex>(newRealValue, newImaginaryValue);
};

unique_ptr<Number> Complex::operator-(const Number& number) const {
    const Complex& complex = static_cast<const Complex&>(number);

    float newRealValue = realValue - complex.realValue;
    float newImaginaryValue = imaginaryValue - complex.imaginaryValue;

    return make_unique<Complex>(newRealValue, newImaginaryValue);
};

unique_ptr<Number> Complex::operator*(const Number& number) const {
    const Complex& complex = static_cast<const Complex&>(number);

    float newRealValue = (realValue * complex.realValue) - (imaginaryValue * complex.imaginaryValue);
    float newImaginaryValue = (realValue * complex.imaginaryValue) + (imaginaryValue * complex.realValue);

    return make_unique<Complex>(newRealValue, newImaginaryValue);
};

string Complex::toString() const {
    char realStr[50], imagStr[50];
    sprintf(realStr, "%.2f", realValue);
    sprintf(imagStr, "%.2f", imaginaryValue >= 0 ? imaginaryValue : -imaginaryValue);
    
    if (imaginaryValue >= 0) {
        return string(realStr) + " + " + string(imagStr) + "i";
    } else {
        return string(realStr) + " - " + string(imagStr) + "i";
    }
};