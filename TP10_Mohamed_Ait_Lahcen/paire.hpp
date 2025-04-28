#ifndef PAIRE_HPP
#define PAIRE_HPP

#include <string>
#include <memory>
#include <vector>
#include <iostream>

class PaireBase {
public:
    virtual ~PaireBase() = default;
    virtual void afficher() const = 0;
};

// Helper templates for printing values
template<typename T>
struct ValuePrinter {
    static void print(std::ostream& os, const T& value) {
        os << value;
    }
};

template<>
struct ValuePrinter<bool> {
    static void print(std::ostream& os, bool value) {
        os << (value ? "vrai" : "faux");
    }
};

template<typename T, typename U>
class Paire : public PaireBase {
private:
    T premier;
    U second;

public:
    Paire(const T& p, const U& s) : premier(p), second(s) {}

    void afficher() const override {
        std::cout << "Premier: ";
        ValuePrinter<T>::print(std::cout, premier);
        std::cout << ", Second: ";
        ValuePrinter<U>::print(std::cout, second);
        std::cout << std::endl;
    }
};

template<typename T>
class Paire<T, int> : public PaireBase {
private:
    T premier;
    int second;

public:
    Paire(const T& p, int s) : premier(p), second(s) {}

    void afficher() const override {
        std::cout << "Paire spécialisée avec entier - Premier: " << premier 
                  << ", Second (entier): " << second << std::endl;
    }
};

#endif // PAIRE_HPP 