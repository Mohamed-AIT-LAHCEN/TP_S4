#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Livre {
private:
    std::string titre;
    int pages;

public:
    Livre(const std::string& t, int p) : titre(t), pages(p) {}

    const std::string& getTitre() const { return titre; }
    int getPages() const { return pages; }

    friend std::ostream& operator<<(std::ostream& os, const Livre& livre) {
        os << livre.titre << " - " << livre.pages << " pages";
        return os;
    }
};

int main() {
    std::vector<Livre> bibliotheque = {
        Livre("C++ Moderne", 350),
        Livre("Apprendre Python", 500),
        Livre("Algorithmique", 450)
    };

    // Tri par titre
    std::sort(bibliotheque.begin(), bibliotheque.end(),
              [](const Livre& a, const Livre& b) {
                  return a.getTitre() < b.getTitre();
              });

    std::cout << "Tri par titre :" << std::endl;
    for (const auto& livre : bibliotheque) {
        std::cout << livre << std::endl;
    }
    std::cout << std::endl;

    // Tri par nombre de pages (décroissant)
    std::sort(bibliotheque.begin(), bibliotheque.end(),
              [](const Livre& a, const Livre& b) {
                  return a.getPages() > b.getPages();
              });

    std::cout << "Tri par nombre de pages décroissant :" << std::endl;
    for (const auto& livre : bibliotheque) {
        std::cout << livre << std::endl;
    }

    return 0;
} 