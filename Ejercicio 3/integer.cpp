#include "integer.h"

#include <string>

Integer::Integer() {
    value = 0;
};

Integer::Integer(int _value) {
    value = _value;
};

unique_ptr<Number> Integer::sum(const Number& number) const {
    int newValue = value + number.getValue();

    return make_unique<Integer>(Integer(newValue));
};

unique_ptr<Number> Integer::substraction(const Number& number) const {
    int newValue = value - number.getValue();

    return make_unique<Integer>(Integer(newValue));
};

unique_ptr<Number> Integer::multiplication(const Number& number) const {
    int newValue = value * number.getValue();

    return make_unique<Integer>(Integer(newValue));
};

int Integer::getValue() const {
    return value;
}

string Integer::toString() const {
    return to_string(value);
}