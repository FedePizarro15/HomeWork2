#pragma once

#include "number.h"
#include "integer.h"

#include <memory>

using namespace std;

class Real final : public Number {
    private:
        float value;
    public:
        Real();
        Real(float value);

        unique_ptr<Number> sum(const Number& number) override;
        unique_ptr<Number> substraction(const Number& number) override;
        unique_ptr<Number> multiplication(const Number& number) override;

        float getValue() const override;
        string toString() override;

        friend ostream& operator<< (ostream& os, const Real& real);
};