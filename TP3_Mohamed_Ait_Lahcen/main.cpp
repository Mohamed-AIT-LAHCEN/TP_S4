#include <iostream>
#include <limits>
#include <cmath>

// Preprocessor directive to select the exercise
#define EXO 1

#if EXO == 1

// Exercise 1: Memory analysis of an array
void exercise1() {
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Taille totale du tableau : " << sizeof(tab) << " octet(s)" << std::endl;
    std::cout << "Taille d'un élément : " << sizeof(tab[0]) << " octet(s)" << std::endl;
    std::cout << "Nombre d'éléments : " << sizeof(tab) / sizeof(tab[0]) << std::endl;
}

#elif EXO == 2

// Exercise 2: Carpet cleaning service estimate
void exercise2() {
    const int smallRoomPrice = 250;
    const int largeRoomPrice = 350;
    const double taxRate = 0.06;
    const int validityDays = 30;

    int smallRooms, largeRooms;
    std::cout << "Number of small rooms: ";
    std::cin >> smallRooms;
    std::cout << "Number of large rooms: ";
    std::cin >> largeRooms;

    int cost = smallRooms * smallRoomPrice + largeRooms * largeRoomPrice;
    double tax = cost * taxRate;
    double total = cost + tax;

    std::cout << "Estimate for carpet cleaning service" << std::endl;
    std::cout << "Number of small rooms: " << smallRooms << std::endl;
    std::cout << "Number of large rooms: " << largeRooms << std::endl;
    std::cout << "Price per small room: " << smallRoomPrice << "dh" << std::endl;
    std::cout << "Price per large room: " << largeRoomPrice << "dh" << std::endl;
    std::cout << "Cost : " << cost << "dh" << std::endl;
    std::cout << "Tax: " << tax << "dh" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Total estimate: " << total << "dh" << std::endl;
    std::cout << "This estimate is valid for " << validityDays << " days" << std::endl;
}

#elif EXO == 3

// Exercise 3: Compile-time factorial calculation with constexpr
constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

void exercise3() {
    constexpr int fact = factorial(5);
    static_assert(fact == 120, "Factorial calculation is incorrect");
    std::cout << "Factorial of 5: " << fact << std::endl;
}

#elif EXO == 4

// Exercise 4: Global and Local Variables (Shadowing)
int value = 100;

void exercise4() {
    int value = 50;
    std::cout << "Valeur locale : " << value << std::endl;
    std::cout << "Valeur globale : " << ::value << std::endl;
}

#elif EXO == 5

// Exercise 5: Advanced use of constants
void exercise5() {
    const int monthsInYear = 12;
    constexpr double radius = 7.0;
    #define PI 3.14159

    double area = PI * std::pow(radius, 2);

    std::cout << "Nombre de mois dans une année : " << monthsInYear << std::endl;
    std::cout << "Rayon du cercle : " << radius << std::endl;
    std::cout << "Aire du cercle : " << area << std::endl;

    // Uncommenting the following line will cause a compilation error
    // monthsInYear = 13;
}

#elif EXO == 6

// Exercise 6: Overflow detection in multiplication
int safeMultiply(int a, int b) {
    if (a > 0 && b > 0 && a > std::numeric_limits<int>::max() / b) {
        std::cerr << "Error: Overflow detected!" << std::endl;
        return -1;
    }
    return a * b;
}

void exercise6() {
    int a = 30000;
    int b = 1000;
    int result = safeMultiply(a, b);
    if (result != -1) {
        std::cout << "Result: " << result << std::endl;
    }

    a = 300000;
    b = 10000;
    result = safeMultiply(a, b);
    if (result != -1) {
        std::cout << "Result: " << result << std::endl;
    }
}

#endif

int main() {
    #if EXO == 1
    exercise1();
    #elif EXO == 2
    exercise2();
    #elif EXO == 3
    exercise3();
    #elif EXO == 4
    exercise4();
    #elif EXO == 5
    exercise5();
    #elif EXO == 6
    exercise6();
    #else
    std::cerr << "Invalid exercise number!" << std::endl;
    #endif

    return 0;
}
