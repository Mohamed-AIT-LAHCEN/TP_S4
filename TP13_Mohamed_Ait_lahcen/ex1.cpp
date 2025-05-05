#include <iostream>
#include <vector>
#include <algorithm>

class Additionneur {
private:
    int valeur;

public:
    Additionneur(int v) : valeur(v) {}

    void operator()(int& x) const {
        x += valeur;
        std::cout << x << " ";
    }
};

int main() {
    std::vector<int> nombres = {10, 11, 12, 13, 14};
    
    std::cout << "Resultat apres addition de 1 : ";
    std::for_each(nombres.begin(), nombres.end(), Additionneur(1));
    std::cout << std::endl;

    return 0;
} 