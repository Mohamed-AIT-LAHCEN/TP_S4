#include "ex1_calculator.hpp"
#include <iostream>

int main() {
    double num1, num2;
    char operation;
    
    std::cout << "Enter first number: ";
    std::cin >> num1;
    
    std::cout << "Enter second number: ";
    std::cin >> num2;
    
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;
    
    try {
        double result = calculate(num1, num2, operation);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const DivideByZeroException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InvalidOperationException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    
    std::cout << "Program completed" << std::endl;
    return 0;
} 