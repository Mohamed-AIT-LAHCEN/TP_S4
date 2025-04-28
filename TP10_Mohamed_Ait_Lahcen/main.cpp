#include <iostream>
#include "maximum.hpp"
#include "conteneur.hpp"
#include "paire.hpp"
#include "matrix.hpp"

void test_maximum() {
    std::cout << "\nTest de la fonction maximum:" << std::endl;
    std::cout << "maximum(5, 10) = " << maximum(5, 10) << std::endl;
    std::cout << "maximum(3.14, 2.71) = " << maximum(3.14, 2.71) << std::endl;
    std::cout << "maximum(\"chat\", \"chien\") = " << maximum(std::string("chat"), std::string("chien")) << std::endl;
}

void test_conteneur() {
    std::cout << "\nTest de la classe Conteneur:" << std::endl;
    
    Conteneur<int> c1(3);
    c1.ajouter(10);
    c1.ajouter(20);
    c1.ajouter(30);
    c1.ajouter(40); // Capacité dépassée
    
    std::cout << "Conteneur d'entiers: " << c1.obtenir(0) << " " << c1.obtenir(1) << std::endl;
    
    Conteneur<std::string> c2(2);
    c2.ajouter("Bonjour");
    c2.ajouter("Monde");
    std::cout << "Conteneur de chaînes: " << c2.obtenir(0) << " " << c2.obtenir(1) << std::endl;
}

void test_paire() {
    std::cout << "\nTest de la classe Paire:" << std::endl;
    
    std::vector<std::unique_ptr<PaireBase>> paires;
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(10, true));
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));
    
    for (const auto& p : paires) {
        p->afficher();
    }
}

void test_matrix() {
    std::cout << "\nTest de la classe Matrix:" << std::endl;
    
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    
    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);
    
    auto m3 = m1.add(m2);
    std::cout << "Résultat de l'addition de matrices:" << std::endl;
    std::cout << m3.get(0, 0) << " " << m3.get(0, 1) << std::endl;
    std::cout << m3.get(1, 0) << " " << m3.get(1, 1) << std::endl;
}

int main() {
    test_maximum();
    test_conteneur();
    test_paire();
    test_matrix();
    return 0;
} 