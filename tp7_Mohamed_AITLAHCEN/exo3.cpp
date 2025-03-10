#include<iostream>

int main() {
    class Joueur {
        private:
            std::string nom;
            int score;
        public:
            Joueur(std::string n, int s) {
                nom = n;
                score = s;
                std::cout << "Constructeur appelé" << std::endl;
            }
            ~Joueur() {
                std::cout << "Destructeur appelé" << std::endl;
            }
            void afficher() {
                std::cout << "Joueur: " << nom <<","<< " Score: " << score << std::endl;
            }
    };

    Joueur j1("Alice", 100);
    j1.afficher();
    return 0;
}