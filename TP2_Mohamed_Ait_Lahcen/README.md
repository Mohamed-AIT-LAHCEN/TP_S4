## Contenu du code
Le fichier `main.cpp` contient quatre exercices distincts :

1. **Utilisation des directives du préprocesseur**
   - Définit une constante `PI`.
   - Vérifie si la macro `DEBUG` est activée et affiche un message le cas échéant.

2. **Utilisation de la fonction `main` avec `argc` et `argv`**
   - Affiche les arguments passés en ligne de commande.

## Compilation et Exécution
Le programme peut être compilé avec `g++`, en choisissant quel exercice exécuter en définissant `EXO`.

### Compilation
# Compiler avec l'exercice 1 par défaut
g++ main.cpp -o main.exe

# Compiler avec un autre exercice (exemple: exercice 2)
g++ main.cpp -o main.exe -DEXO=2

### Exécution
# Exécuter le programme
./main.exe

# Exécuter avec des arguments (pour l'exercice 2)
./main.exe arg1 arg2



