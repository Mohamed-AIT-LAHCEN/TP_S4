#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void filtrer(const std::vector<int>& vec, std::function<bool(int)> predicat) {
    for (int x : vec) {
        if (predicat(x)) {
            std::cout << x << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nombres = {10, 15, 20, 25, 30, 50, 75};

    std::cout << "Nombres > 20 : ";
    filtrer(nombres, [](int x) { return x > 20; });

    std::cout << "Nombres pairs : ";
    filtrer(nombres, [](int x) { return x % 2 == 0; });

    return 0;
} 