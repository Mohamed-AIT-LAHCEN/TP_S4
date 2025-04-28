#ifndef EX3_STACK_HPP
#define EX3_STACK_HPP

#include <stdexcept>
#include <vector>
#include <string>

class StackFullException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Stack is full";
    }
};

class StackEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Stack is empty";
    }
};

class Stack {
private:
    std::vector<int> data;
    size_t capacity;

public:
    Stack(size_t max_size);
    void push(int value);
    int pop();
    size_t size() const;
    bool empty() const;
};

// Function declarations for stack unwinding demonstration
void func_a(Stack& stack);
void func_b(Stack& stack);
void func_c(Stack& stack);

#endif // EX3_STACK_HPP 