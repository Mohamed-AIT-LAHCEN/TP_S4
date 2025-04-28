#include "ex3_stack.hpp"
#include <iostream>

int main() {
    // Test 1: Démontrer StackFullException via func_a
    try {
        Stack stack(2); // Stack with capacity of 2
        stack.push(1);
        stack.push(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        func_a(stack); // Will throw StackFullException
    }
    catch (const StackFullException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    
    // Test 2: Démontrer StackEmptyException avec pop
    try {
        Stack stack(2); // Nouvelle pile vide
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.pop(); // Will throw StackEmptyException
    }
    catch (const StackEmptyException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    
    std::cout << "Program completed" << std::endl;
    return 0;
} 