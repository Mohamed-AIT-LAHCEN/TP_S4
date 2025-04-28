#include "ex3_stack.hpp"
#include <iostream>

Stack::Stack(size_t max_size) : capacity(max_size) {}

void Stack::push(int value) {
    if (data.size() >= capacity) {
        throw StackFullException();
    }
    data.push_back(value);
}

int Stack::pop() {
    if (data.empty()) {
        throw StackEmptyException();
    }
    int value = data.back();
    data.pop_back();
    return value;
}

size_t Stack::size() const {
    return data.size();
}

bool Stack::empty() const {
    return data.empty();
}

void func_c(Stack& stack) {
    std::cout << "func_c: Attempting to push to stack" << std::endl;
    stack.push(3); // This will throw StackFullException
}

void func_b(Stack& stack) {
    std::cout << "func_b: Calling func_c" << std::endl;
    func_c(stack);
}

void func_a(Stack& stack) {
    std::cout << "func_a: Calling func_b" << std::endl;
    func_b(stack);
} 