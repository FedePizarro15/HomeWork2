#pragma once

#include "number.h"

class Integer final : public Number {
    private:
        int value;
        
    public:
        Integer() : value(0) {};
        Integer(const int _value) : value(_value) {};

        unique_ptr<Number> operator+(const Number& number) const override;
        unique_ptr<Number> operator-(const Number& number) const override;
        unique_ptr<Number> operator*(const Number& number) const override;

        string toString() const override;
};