#include <iostream>
#include "ex1_calculator.hpp"
#include "ex2_inventory.hpp"
#include "ex3_stack.hpp"

void runCalculator() {
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
}

void runInventory() {
    // Copy the main logic from ex2_main.cpp here
    std::cout << "Running Inventory Management System..." << std::endl;
    // Add the inventory management code here
}

void runStack() {
    // Copy the main logic from ex3_main.cpp here
    std::cout << "Running Stack Implementation..." << std::endl;
    // Add the stack implementation code here
}

int main() {
    int choice;
    
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Calculator\n";
        std::cout << "2. Inventory Management\n";
        std::cout << "3. Stack Implementation\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                runCalculator();
                break;
            case 2:
                runInventory();
                break;
            case 3:
                runStack();
                break;
            case 4:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
} 