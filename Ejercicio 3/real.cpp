#include "real.h"

#include <string>

using namespace std;

unique_ptr<Number> Real::operator+(const Number& number) const {
    const Real& real = static_cast<const Real&>(number);
    
    float newValue = value + real.value;

    return make_unique<Real>(newValue);
};

unique_ptr<Number> Real::operator-(const Number& number) const {
    const Real& real = static_cast<const Real&>(number);

    float newValue = value - real.value;

    return make_unique<Real>(newValue);
};

unique_ptr<Number> Real::operator*(const Number& number) const {
    const Real& real = static_cast<const Real&>(number);

    float newValue = value * real.value;

    return make_unique<Real>(newValue);
};

string Real::toString() const {
    char formatedValue[50];
    sprintf(formatedValue, "%.2f", value);

    return string(formatedValue);}