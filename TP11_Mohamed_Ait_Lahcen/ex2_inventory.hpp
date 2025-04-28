#ifndef EX2_INVENTORY_HPP
#define EX2_INVENTORY_HPP

#include <stdexcept>
#include <string>

class NegativeQuantityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot add negative quantity of items";
    }
};

class InsufficientStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient stock available";
    }
};

class Inventory {
private:
    int stock;

public:
    Inventory(int initial_stock);
    int get_stock() const;
    void add_items(int quantity);
    void remove_items(int quantity);
};

#endif // EX2_INVENTORY_HPP 