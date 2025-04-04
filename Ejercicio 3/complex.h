#pragma once

#include "number.h"

class Complex final : public Number {
    private:
        const float realValue;
        const float imaginaryValue;
        
    public:
        Complex() : realValue(0), imaginaryValue(0) {};
        Complex (const float _realValue, const float _imaginaryValue) : realValue(_realValue), imaginaryValue(_imaginaryValue) {};

        unique_ptr<Number> operator+(const Number& number) const override;
        unique_ptr<Number> operator-(const Number& number) const override;
        unique_ptr<Number> operator*(const Number& number) const override;

        string toString() const override;
};