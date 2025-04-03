#include "complex.h"

Complex::Complex() {
    realValue = 0;
    imaginaryValue = 0;
};

Complex::Complex(float value, bool isReal) {
    if (isReal) {
        realValue = value;
        imaginaryValue = 0;
    } else {
        realValue = 0;
        imaginaryValue = value;
    }
};

Complex::Complex(float _realValue, float _imaginaryValue) {
    realValue = _realValue;
    imaginaryValue = _imaginaryValue;
}

unique_ptr<Number> Complex::sum(const Number& number) {
    float newRealValue = realValue + number.getValue();
    float newImaginaryValue = imaginaryValue + number.getValue();

    return make_unique<Complex>(Complex(newRealValue, newImaginaryValue));
};

unique_ptr<Number> Complex::substraction(const Number& number) {
    float newRealValue = realValue - number.getValue();
    float newImaginaryValue = imaginaryValue - number.getValue();

    return make_unique<Complex>(Complex(newRealValue, newImaginaryValue));
    
};

unique_ptr<Number> Complex::multiplication(const Number& number) {
    float newRealValue = realValue * number.getValue();
    float newImaginaryValue = imaginaryValue * number.getValue();

    return make_unique<Complex>(Complex(newRealValue, newImaginaryValue));
    
};

