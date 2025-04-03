#include "integer.h"

#include <string>

unique_ptr<Number> Integer::operator+(const Number& number) const {
    const Integer& integer = static_cast<const Integer&>(number);

    int newValue = value + integer.value;

    return make_unique<Integer>(newValue);
};

unique_ptr<Number> Integer::operator-(const Number& number) const {
    const Integer& integer = static_cast<const Integer&>(number);

    int newValue = value - integer.value;

    return make_unique<Integer>(newValue);
};

unique_ptr<Number> Integer::operator*(const Number& number) const {
    const Integer& integer = static_cast<const Integer&>(number);

    int newValue = value * integer.value;

    return make_unique<Integer>(newValue);
};

string Integer::toString() const {return to_string(value);}