#include<iostream>
#include<array>
#include<vector>
using namespace std;


void allouer_matrice(int** &matrice, int n, int m) {
    matrice = new int*[n];
    for (int i=0; i<n; i++) {
        matrice[i] = new int[m];
    }
}

void initialiser_matrice(int** &matrice, int n, int m) {
    int val = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matrice[i][j] = val;
            val++;
        }
    }
}

void print_matrice(int** &matrice, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose_matrice(int** &matrice, int n, int m) {
    int** matrice_t = new int*[m];
    for (int i=0; i<m; i++) {
        matrice_t[i] = new int[n];
        for (int j=0; j<n; j++) {
            matrice_t[i][j] = matrice[j][i];
        }
    }
    delete[] matrice;
    matrice = matrice_t;

}



int main() {
    int** matrice;
    int n = 3;
    int m = 4;
    allouer_matrice(matrice, n, m);
    initialiser_matrice(matrice, n, m);
    transpose_matrice(matrice, n, m);
    print_matrice(matrice, m, n);
    return 0;
}