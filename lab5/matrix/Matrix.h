//
// Created by adrja on 16.04.2018.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <vector>
#include <cstring>

namespace algebra {

    class Matrix {

    public:

        Matrix();

        // Matrix m x n > m =height, n=width
        Matrix(size_t height, size_t width);

        Matrix(const Matrix &other);

        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &matrix);

        Matrix(std::string init_string);

        std::complex<double> GetElement(size_t vertical, size_t horizontal) const;

        std::pair<size_t, size_t> Size() const;

        Matrix Add(const Matrix &other) const;

        Matrix Sub(const Matrix &other) const;

        Matrix Mul(const Matrix &other) const;

        Matrix Mul(const std::complex<double> &complex_value);

        Matrix Pow(const size_t &power) const;

        std::string Print() const;

    private:
        void Clear();

        std::complex<double> ParseComplex(std::string init, size_t &pos);

        std::string PrintComplex(const std::complex<double> value) const;

        std::vector<std::vector<std::complex<double>>> matrix_;

        size_t rows_;
        size_t columns_;

    };
}

#endif //JIMP_EXERCISES_MATRIX_H
