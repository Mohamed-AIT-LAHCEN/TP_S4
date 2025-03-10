#include<iostream>
#include<string>
using namespace std;

int main() {
    class Person{
        private:
            std::string nom;
            int score;
        public:
            void setNom(std::string n) {
                nom = n;
            }
            void setScore(int s) {
                score = s;
            }
            std::string getNom() {
                return nom;
            }
            int getScore() {
                return score;
            }
    };

    Person* p1 = new Person();
    p1->setNom("Alice");
    p1->setScore(100);
    cout << "Nom: " << p1->getNom()<<endl;
    cout << "Score: " << p1->getScore()<<endl;
    delete p1;
    cout<<"Objet dynamique supprimé";
    return 0;
}