#include<iostream>
#include<string>
#include<vector>

class Objet {
private:
    std::string nom;
    int quantite;

public:
    Objet(std::string n, int q) : nom(n), quantite(q) {}

    std::string getNom() const {
        return nom;
    }

    int getQuantite() const {
        return quantite;
    }

    void setQuantite(int q) {
        quantite = q;
    }
};

class Inventaire {
private:
    std::vector<Objet*> objets;

public:
    ~Inventaire() {
        for (Objet* obj : objets) {
            delete obj;
        }
        std::cout << "Mémoire de l'inventaire libérée." << std::endl;
    }

    void ajouterObjet(std::string nom, int quantite) {
        objets.push_back(new Objet(nom, quantite));
        std::cout << "Ajout de " << nom << " (x" << quantite << ")" << std::endl;
    }

    void afficherInventaire() const {
        std::cout << "Inventaire :" << std::endl;
        for (const Objet* obj : objets) {
            std::cout << "- " << obj->getNom() << " (x" << obj->getQuantite() << ")" << std::endl;
        }
    }
};

int main() {
    Inventaire inventaire;
    inventaire.ajouterObjet("Pomme", 3);
    inventaire.ajouterObjet("Épée", 1);
    inventaire.afficherInventaire();
    return 0;
}
