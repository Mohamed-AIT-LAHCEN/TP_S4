#ifndef CONTENEUR_HPP
#define CONTENEUR_HPP

#include <vector>
#include <iostream>

template<typename T>
class Conteneur {
private:
    std::vector<T> elements;
    size_t capacite;

public:
    Conteneur(size_t max_size) : capacite(max_size) {}

    void ajouter(const T& element) {
        if (elements.size() < capacite) {
            elements.push_back(element);
        } else {
            std::cout << "Erreur: Capacité dépassée!" << std::endl;
        }
    }

    T obtenir(size_t index) const {
        if (index < elements.size()) {
            return elements[index];
        }
        throw std::out_of_range("Index hors limites");
    }

    size_t taille() const {
        return elements.size();
    }
};

#endif // CONTENEUR_HPP 