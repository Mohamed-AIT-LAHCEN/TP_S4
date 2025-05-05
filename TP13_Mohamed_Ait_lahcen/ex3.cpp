#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nombres = {10, 12, 15, 17};
    int ajout = 5;

    std::transform(nombres.begin(), nombres.end(), nombres.begin(),
                  [&ajout](int x) { return x + ajout; });

    std::cout << "Résultat après ajout de " << ajout << " : ";
    for (int x : nombres) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
} 