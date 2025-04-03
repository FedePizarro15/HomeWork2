#pragma once

#include "number.h"

class Complex final : public Number {
    private:
        float realValue;
        float imaginaryValue;
    public:
        Complex();
        Complex (float value, bool isReal);
        Complex (float realValue, float imaginaryValue);

        unique_ptr<Number> sum(const Number& number) override;
        unique_ptr<Number> substraction(const Number& number) override;
        unique_ptr<Number> multiplication(const Number& number) override;

        float getValue() const override;
        string toString() override;
};