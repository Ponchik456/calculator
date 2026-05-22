#include "calculator.h"
#include <cctype>
#include <stdexcept>
#include <cmath>

double Calculator::calculate(const std::string& expression) {
    pos = 0;
    expr = expression;
    skipWhitespace();
    double result = parseExpression();

    if (pos < expr.length()) {
        throw std::runtime_error("Неожиданный символ в выражении");
    }

    return result;
}

double Calculator::parseExpression() {
    double result = parseTerm();

    while (pos < expr.length()) {
        skipWhitespace();
        if (expr[pos] == '+') {
            pos++;
            result += parseTerm();
        } else if (expr[pos] == '-') {
            pos++;
            result -= parseTerm();
        } else {
            break;
        }
    }

    return result;
}

double Calculator::parseTerm() {
    double result = parseFactor();

    while (pos < expr.length()) {
        skipWhitespace();
        if (expr[pos] == '*') {
            pos++;
            result *= parseFactor();
        } else if (expr[pos] == '/') {
            pos++;
            double divisor = parseFactor();
            if (divisor == 0) {
                throw std::runtime_error("Деление на ноль");
            }
            result /= divisor;
        } else {
            break;
        }
    }

    return result;
}

double Calculator::parseFactor() {
    skipWhitespace();

    if (expr[pos] == '(') {
        pos++;
        double result = parseExpression();
        skipWhitespace();
        if (pos >= expr.length() || expr[pos] != ')') {
            throw std::runtime_error("Отсутствует закрывающая скобка");
        }
        pos++;
        return result;
    }

    if (expr[pos] == '-') {
        pos++;
        return -parseFactor();
    }

    double result = parseNumber();

    skipWhitespace();
    if (pos < expr.length() && expr[pos] == '^') {
        pos++;
        double exponent = parseFactor();
        result = std::pow(result, exponent);
    }

    return result;
}

double Calculator::parseNumber() {
    size_t start = pos;

    if (pos < expr.length() && expr[pos] == '.') {
        throw std::runtime_error("Некорректное число");
    }

    bool hasDigit = false;
    while (pos < expr.length() && (std::isdigit(expr[pos]) || expr[pos] == '.')) {
        if (expr[pos] == '.') {
            if (hasDigit) {
                break;
            }
            hasDigit = true;
        }
        pos++;
    }

    if (start == pos) {
        throw std::runtime_error("Ожидалось число");
    }

    std::string numStr = expr.substr(start, pos - start);
    return std::stod(numStr);
}

void Calculator::skipWhitespace() {
    while (pos < expr.length() && std::isspace(expr[pos])) {
        pos++;
    }
}
