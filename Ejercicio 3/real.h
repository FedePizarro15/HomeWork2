#pragma once

#include "number.h"
#include "integer.h"

using namespace std;

class Real final : public Number {
    private:
        const double value;

    public:
        Real() : value(0) {};
        Real(const double _value) : value(_value) {};

        unique_ptr<Number> operator+(const Number& number) const override;
        unique_ptr<Number> operator-(const Number& number) const override;
        unique_ptr<Number> operator*(const Number& number) const override;

        string toString() const override;
};