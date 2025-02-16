#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

#define EXO 1  // Par défaut, l'exercice 1 sera compilé

using namespace std;

#if EXO == 1
void exercice1() {
    int tableau[5] = {10, 20, 30, 40, 50};
    int somme = 0;
    cout << "Éléments : ";
    for (int n : tableau) {
        cout << n << " ";
        somme += n;
    }
    cout << "\nSomme : " << somme << endl;
}
#endif

#if EXO == 2
void exercice2() {
    int matrice[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int somme_diagonale = 0;
    cout << "Matrice :\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrice[i][j] << " ";
            if (i == j) somme_diagonale += matrice[i][j];
        }
        cout << endl;
    }
    cout << "Somme diagonale : " << somme_diagonale << endl;
}
#endif

#if EXO == 3
void exercice3() {
    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "Original : ";
    for (int n : arr) cout << n << " ";
    cout << "\nInversé : ";
    reverse(arr.begin(), arr.end());
    for (int n : arr) cout << n << " ";
    cout << endl;
}
#endif

#if EXO == 4
void exercice4() {
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Doublé : ";
    for (int &n : vec) {
        n *= 2;
        cout << n << " ";
    }
    cout << endl;
}
#endif

#if EXO == 5
void exercice5() {
    list<int> lst = {10, 20, 30, 40, 50};
    lst.push_front(0);
    lst.push_back(60);
    cout << "Après insertion : ";
    for (int n : lst) cout << n << " ";
    cout << endl;
}
#endif

#if EXO == 6
void exercice6() {
    set<int> s = {5, 10, 15, 20};
    s.insert(10);
    cout << "Après insertion de 10 : ";
    for (int n : s) cout << n << " ";
    cout << endl;
}
#endif

#if EXO == 7
void exercice7() {
    map<string, int> notes = {{"John", 85}, {"Alice", 90}, {"Bob", 78}};
    for (const auto &[nom, note] : notes) {
        cout << nom << " : " << note << endl;
    }
}
#endif

#if EXO == 8
void exercice8() {
    unordered_map<string, int> compteur;
    vector<string> mots = {"pomme", "banane", "pomme", "orange", "banane", "banane"};
    for (const string &mot : mots) {
        compteur[mot]++;
    }
    for (const auto &[mot, count] : compteur) {
        cout << mot << " : " << count << endl;
    }
}
#endif

#if EXO == 9
void exercice9() {
    vector<int> vec = {30, 10, 50, 20, 40};
    sort(vec.begin(), vec.end());
    cout << "Trié : ";
    for (int n : vec) cout << n << " ";
    cout << endl;
}
#endif

#if EXO == 10
void exercice10() {
    set<int> s = {100, 4, 200, 1, 3, 2};
    int longest = 0, current = 0, prev = -1;
    for (int num : s) {
        if (num == prev + 1) {
            current++;
        } else {
            current = 1;
        }
        longest = max(longest, current);
        prev = num;
    }
    cout << "Plus longue séquence : " << longest << endl;
}
#endif

#if EXO == 11
int capacity = 2;
list<pair<int, int>> lru;
unordered_map<int, list<pair<int, int>>::iterator> cache;

int get(int key) {
    if (cache.find(key) == cache.end()) return -1;
    lru.splice(lru.begin(), lru, cache[key]);
    return cache[key]->second;
}

void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
        lru.erase(cache[key]);
    } else if (lru.size() >= capacity) {
        cache.erase(lru.back().first);
        lru.pop_back();
    }
    lru.push_front({key, value});
    cache[key] = lru.begin();
}

void display() {
    for (const auto &[key, value] : lru) {
        cout << "(" << key << ", " << value << ") ";
    }
    cout << endl;
}

void exercice11() {
    put(1, 10);
    put(2, 20);
    display();
    cout << "Accès à la clé 1 : " << get(1) << endl;
    display();
    put(3, 30);
    display();
}
#endif

int main() {
    #if EXO == 1
    exercice1();
    #elif EXO == 2
    exercice2();
    #elif EXO == 3
    exercice3();
    #elif EXO == 4
    exercice4();
    #elif EXO == 5
    exercice5();
    #elif EXO == 6
    exercice6();
    #elif EXO == 7
    exercice7();
    #elif EXO == 8
    exercice8();
    #elif EXO == 9
    exercice9();
    #elif EXO == 10
    exercice10();
    #elif EXO == 11
    exercice11();
    #endif
    return 0;
}
