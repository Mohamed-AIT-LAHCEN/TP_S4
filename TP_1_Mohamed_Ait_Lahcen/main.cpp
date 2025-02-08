#include <iostream>
using namespace std;

void exo1() {
    cout << "Hello, World!" << endl;
    cout << "Bienvenue en C++!";
}

void exo2() {
    int n;
    cout << "Entrez un nombre: ";
    cin >> n;
    cout << "Vous avez entré: " << n;
}

void exo3() {
    int n, m;
    cout << "Entrez deux nombres: ";
    cin >> n >> m;
    cout << "Somme: " << n+m << endl;
    cout << "Difference: " <<n-m<<endl;
    cout << "Produit: " << n*m<<endl;
    cout << "Quotient: " << n/m<<endl;
}

void exo4() {
    std::cout << "Entrez un nombre:";
    int nombre;
    std::cin >> nombre;
    std::cout << "Vous avez entré: " << nombre << std::endl;
}

void exo5() {
    int C, F;
    cout << "Entrez une temperature en Celsius: ";
    cin >> C;
    F = 9*C / 5 + 32;
    cout << "Temperature en Fahrenheit: " << F;
}

int main() {
    int exo;
    cin >> exo;
    if (exo == 1) {
        exo1();
    }
    else if (exo == 2) {
        exo2();
    }
    else if (exo == 3) {
        exo3();
    }
    else if (exo == 4) {
        exo4();
    }
    else if (exo == 5) {
        exo5();
    }
    return 0;
}