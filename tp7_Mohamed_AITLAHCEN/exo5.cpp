#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Etudiant {
private:
    std::string nom;
    std::vector<int> notes;

public:
    Etudiant(std::string n, std::vector<int> ns) : nom(n), notes(ns) {}

    std::string getNom() const {
        return nom;
    }

    std::vector<int> getNotes() const {
        return notes;
    }

    double calculerMoyenne() const {
        if (notes.empty()) return 0.0;
        int sum = std::accumulate(notes.begin(), notes.end(), 0);
        return static_cast<double>(sum) / notes.size();
    }

    void afficherNotes() const {
        std::cout << "Notes: ";
        for (size_t i = 0; i < notes.size(); ++i) {
            std::cout << notes[i];
            if (i < notes.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> notes = {15, 18, 12};
    Etudiant etudiant("Karim", notes);

    std::cout << "Nom: " << etudiant.getNom() << std::endl;
    etudiant.afficherNotes();
    std::cout << "Moyenne: " << etudiant.calculerMoyenne() << std::endl;

    return 0;
}