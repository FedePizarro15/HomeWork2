#pragma once

#include "number.h"

class Integer final : public Number {
    private:
        int value;
    public:
        Integer() : value(0) {};
        Integer(const int _value) : value(_value) {};

        unique_ptr<Number> sum(const Number& number) const override;
        unique_ptr<Number> substraction(const Number& number) const override;
        unique_ptr<Number> multiplication(const Number& number) const override;

        string toString() const override;
        
        int getValue() const;
};