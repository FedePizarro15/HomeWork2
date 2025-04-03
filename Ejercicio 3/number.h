#pragma once

#include <memory>

using namespace std;

class Number
{
public:
    virtual unique_ptr<Number> sum(const Number& number) const = 0;
    virtual unique_ptr<Number> substraction(const Number& number) const = 0;
    virtual unique_ptr<Number> multiplication(const Number& number) const = 0;

    virtual string toString() const = 0;
};;