#include <iostream>

template <typename T>
class SharedPtr {
private:
    T* ptr;
    unsigned int* refCount;

public:
    // Constructor
    explicit SharedPtr(T* p = nullptr) : ptr(p), refCount(new unsigned int(1)) {
        if (ptr) {
            std::cout << "Création d'un SharedPtr vers " << *ptr << std::endl;
            std::cout << "Nombre de références : " << *refCount << std::endl;
        }
    }

    // Copy Constructor
    SharedPtr(const SharedPtr<T>& sp) : ptr(sp.ptr), refCount(sp.refCount) {
        ++(*refCount);
        std::cout << "Création d'une copie" << std::endl;
        std::cout << "Nombre de références : " << *refCount << std::endl;
    }

    // Destructor
    ~SharedPtr() {
        --(*refCount);
        std::cout << "Destruction d'un SharedPtr" << std::endl;
        std::cout << "Nombre de références : " << *refCount << std::endl;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
            std::cout << "Objet supprimé" << std::endl;
        }
    }

    // Overload dereference operator
    T& operator*() {
        return *ptr;
    }

    // Overload arrow operator
    T* operator->() {
        return ptr;
    }
};

int main() {
    SharedPtr<int> sp1(new int(10));
    {
        SharedPtr<int> sp2 = sp1;
    }
    return 0;
}