#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
public:
    double calculate(const std::string& expression);
private:
    size_t pos = 0;
    std::string expr;

    double parseExpression();
    double parseTerm();
    double parseFactor();
    double parseNumber();
    void skipWhitespace();
};

#endif
