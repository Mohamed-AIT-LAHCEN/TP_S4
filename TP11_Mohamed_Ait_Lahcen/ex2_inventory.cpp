#include "ex2_inventory.hpp"

Inventory::Inventory(int initial_stock) : stock(initial_stock) {}

int Inventory::get_stock() const {
    return stock;
}

void Inventory::add_items(int quantity) {
    if (quantity < 0) {
        throw NegativeQuantityException();
    }
    stock += quantity;
}

void Inventory::remove_items(int quantity) {
    if (quantity < 0) {
        throw NegativeQuantityException();
    }
    if (quantity > stock) {
        throw InsufficientStockException();
    }
    stock -= quantity;
} 