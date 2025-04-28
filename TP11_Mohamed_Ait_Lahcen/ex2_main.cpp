#include "ex2_inventory.hpp"
#include <iostream>

int main() {
    // Test 1: Initialisation et ajout d'articles
    Inventory inv(100); // Initial stock of 100 items
    std::cout << "Initial stock: " << inv.get_stock() << std::endl;
    
    try {
        inv.add_items(50);
        std::cout << "After adding 50 items: " << inv.get_stock() << std::endl;
    }
    catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    
    // Test 2: Tentative de retrait excessif
    try {
        inv.remove_items(160); // Should throw InsufficientStockException
        std::cout << "After removing 160 items: " << inv.get_stock() << std::endl;
    }
    catch (const InsufficientStockException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    
    // Test 3: Tentative d'ajout d'une quantité négative
    try {
        inv.add_items(-10); // Should throw NegativeQuantityException
        std::cout << "After adding -10 items: " << inv.get_stock() << std::endl;
    }
    catch (const NegativeQuantityException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
    
    std::cout << "Program completed" << std::endl;
    return 0;
} 