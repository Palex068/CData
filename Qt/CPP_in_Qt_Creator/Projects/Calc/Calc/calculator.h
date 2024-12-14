#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <Qstring>


class Calculator
{
public:
    Calculator();
    int reset();
    int digit(int d);
    int operation(int o);
    int calculate();
    QString india();

private:
    double value1;
    double value2;
    double result;
    int oper;
};

#endif // CALCULATOR_H
