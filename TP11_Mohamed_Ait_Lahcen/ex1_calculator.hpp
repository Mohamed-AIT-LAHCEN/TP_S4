#ifndef EX1_CALCULATOR_HPP
#define EX1_CALCULATOR_HPP

#include <stdexcept>
#include <string>

class DivideByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Division by zero is not allowed";
    }
};

class InvalidOperationException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid operation. Only +, -, *, / are allowed";
    }
};

double calculate(double num1, double num2, char operation);

#endif // EX1_CALCULATOR_HPP 