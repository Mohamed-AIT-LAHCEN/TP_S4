#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <iostream>
#include <stdexcept>

template<typename T, size_t M, size_t N>
class Matrix {
private:
    std::array<T, M * N> data;

public:
    Matrix() : data{} {}

    void set(size_t i, size_t j, const T& value) {
        if (i >= M || j >= N) {
            throw std::out_of_range("Index hors limites");
        }
        data[i * N + j] = value;
    }

    T get(size_t i, size_t j) const {
        if (i >= M || j >= N) {
            throw std::out_of_range("Index hors limites");
        }
        return data[i * N + j];
    }

    template<size_t P>
    Matrix<T, M, P> add(const Matrix<T, M, P>& other) const {
        static_assert(N == P, "Dimensions incompatibles pour l'addition");
        Matrix<T, M, P> result;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.set(i, j, get(i, j) + other.get(i, j));
            }
        }
        return result;
    }
};

// Spécialisation pour l'addition de matrices de dimensions incompatibles
template<typename T, size_t M1, size_t N1, size_t M2, size_t N2>
class MatrixAdder {
public:
    static Matrix<T, M1, N1> add(const Matrix<T, M1, N1>& m1, const Matrix<T, M2, N2>& m2) {
        std::cout << "Erreur: Dimensions incompatibles pour l'addition" << std::endl;
        return Matrix<T, M1, N1>();
    }
};

#endif // MATRIX_HPP 