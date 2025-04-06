#pragma once

#include "number.h"

class Complex final : public Number {
    private:
        const double realValue;
        const double imaginaryValue;
        
    public:
        Complex() : realValue(0), imaginaryValue(0) {};
        Complex (const double _realValue, const double _imaginaryValue) : realValue(_realValue), imaginaryValue(_imaginaryValue) {};

        unique_ptr<Number> operator+(const Number& number) const override;
        unique_ptr<Number> operator-(const Number& number) const override;
        unique_ptr<Number> operator*(const Number& number) const override;

        string toString() const override;
};