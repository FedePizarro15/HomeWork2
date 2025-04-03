#include "real.h"

#include <string>

using namespace std;

Real::Real() {
    value = 0;
};

Real::Real(float _value) {
    value = _value;
};

unique_ptr<Number> Real::sum(const Number& number) {
    float newValue = value + number.getValue();

    return make_unique<Real>(Real(newValue));
};

unique_ptr<Number> Real::substraction(const Number& number) {
    float newValue = value - number.getValue();

    return make_unique<Real>(Real(newValue));
    
};

unique_ptr<Number> Real::multiplication(const Number& number) {
    float newValue = value * number.getValue();

    return make_unique<Real>(Real(newValue));
    
};

float Real::getValue() const {
    return value;
};

string Real::toString() {
    return to_string(value);
}