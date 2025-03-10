#include<iostream>
#include<string>
using namespace std;
int main() {
    class Joueur {
        private:
            string nom;
            int score;
        public:
            void setNom(string n) {
                nom = n;
            }
            void setScore(int s) {
                score = s;
            }
            string getNom() {
                return nom;
            }
            int getScore() {
                return score;
            }
            void afficher() {
                cout << "Joueur: " << nom <<","<< " Score: " << score << endl;
            }
    };

    Joueur j1;
    j1.setNom("Alice");
    j1.setScore(100);
    Joueur j2;
    j2.setNom("Bob");
    j2.setScore(200);
    j1.afficher();
    j2.afficher();
    
    return 0;
}