#include <iostream>
#include <fstream>
#include <string>

class Fichier {
private:
    std::fstream* fileStream;

public:
    Fichier() : fileStream(nullptr) {}

    ~Fichier() {
        if (fileStream) {
            fileStream->close();
            delete fileStream;
            std::cout << "Mémoire du flux libérée." << std::endl;
        }
    }

    void sauvegarder(const std::string& filename, const std::string& data) {
        fileStream = new std::fstream(filename, std::ios::out);
        if (fileStream->is_open()) {
            *fileStream << data;
            fileStream->close();
            std::cout << "Sauvegarde des données..." << std::endl;
        } else {
            std::cerr << "Erreur lors de l'ouverture du fichier pour l'écriture." << std::endl;
        }
        delete fileStream;
        fileStream = nullptr;
    }

    void charger(const std::string& filename) {
        fileStream = new std::fstream(filename, std::ios::in);
        if (fileStream->is_open()) {
            std::cout << "Lecture des données..." << std::endl;
            std::string line;
            std::cout << "Contenu du fichier :" << std::endl;
            while (getline(*fileStream, line)) {
                std::cout << line << std::endl;
            }
            fileStream->close();
        } else {
            std::cerr << "Erreur lors de l'ouverture du fichier pour la lecture." << std::endl;
        }
        delete fileStream;
        fileStream = nullptr;
    }
};

int main() {
    Fichier fichier;
    std::string filename = "test.txt";
    std::string data = "Bonjour, ceci est un test.";

    fichier.sauvegarder(filename, data);
    fichier.charger(filename);

    return 0;
}