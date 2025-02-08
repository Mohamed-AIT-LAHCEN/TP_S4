#include <iostream>

// Définition de la constante PI
#define PI 3.141592653589793

// Vérification de la macro DEBUG
#ifdef DEBUG
    #define DEBUG_MSG "Mode Debug activé"
#endif

// Sélection de l'exercice à compiler
#ifndef EXO
    #define EXO 1
#endif

#if EXO == 1
// Exercice 1: Utilisation des directives du préprocesseur
int main() {
    std::cout << "Valeur de PI: " << PI << std::endl;
    #ifdef DEBUG_MSG
        std::cout << DEBUG_MSG << std::endl;
    #endif
    return 0;
}

#elif EXO == 2
// Exercice 2: Utilisation de la fonction main avec argc et argv
int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}

#elif EXO == 3
// Exercice 3: Espaces de noms et portée des variables
namespace MonEspace {
    int valeur = 10;
}

int main() {
    std::cout << "Valeur dans l'espace de noms: " << MonEspace::valeur << std::endl;
    using namespace std;
    cout << "Affichage avec using namespace std" << endl;
    return 0;
}

#elif EXO == 4
// Exercice 4: Entrée et sortie avec cin et cout
int main() {
    int entier;
    double decimal;
    
    std::cout << "Entrez un entier: ";
    std::cin >> entier;
    
    std::cout << "Entrez un nombre décimal: ";
    std::cin >> decimal;
    
    std::cout << "Valeurs saisies: " << entier << " et " << decimal << std::endl;
    return 0;
}

#endif