//
// Created by adrja on 16.04.2018.
//

#include "Matrix.h"

algebra::Matrix::Matrix() {
    rows_ = 0;
    columns_ = 0;
};

algebra::Matrix::Matrix(size_t height, size_t width) {
    rows_ = height;
    columns_ = width;

    if (height * width != 0) {
        matrix_ = std::move(std::vector<std::vector<std::complex<double>>>(height));

        for (size_t i = 0; i < height; ++i) {
            for (size_t j = 0; j < width; ++j) {
                matrix_[i].emplace_back(0);
            }
        }
    }
}

algebra::Matrix::Matrix(const Matrix &other) {
    this->Clear();
    rows_ = other.Size().first;
    columns_ = other.Size().second;

    matrix_ = std::move(std::vector<std::vector<std::complex<double>>>(other.Size().first));
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < columns_; ++j) {
            matrix_[i].emplace_back(other.GetElement(i, j));
        }
    }
}

algebra::Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &matrix) : matrix_(matrix) {
    rows_ = matrix_.size();
    columns_ = matrix_[0].size();
}

algebra::Matrix::Matrix(std::string init_string) {

    std::vector<std::complex<double>> temp_vect{};
    for (size_t i = 1; i < init_string.size() - 1; ++i) {
        if (i != ';') {
            temp_vect.emplace_back(ParseComplex(init_string, i));
        } else {
            matrix_.emplace_back(temp_vect);
            temp_vect.clear();
        }
    }
}

std::complex<double> algebra::Matrix::ParseComplex(std::string init_string, size_t &i) {
    std::string temp{};
    double value1 = 0, value2 = 0;
    bool was_i = false;

    while (std::isdigit(init_string[i]) || init_string[i] == '.') {
        if (init_string[i] == ' ') {
            break;
        }
        temp += init_string[i];
        ++i;

        if (init_string[i] == 'i' && !was_i) {
            value1 = std::stod(temp);
            was_i = true;
            temp.clear();
            ++i;
        } else if ((init_string[i] == ',' || init_string[i] == ';') && was_i) {
            value2 = std::stod(temp);
            temp.clear();
            was_i = false;
            ++i;
            if (init_string[i - 1] == ';') {
                i -= 2;
                break;
            }
        }
    }
    return {value1, value2};
}

std::complex<double> algebra::Matrix::GetElement(size_t vertical, size_t horizontal) const {
    return matrix_[vertical][horizontal];
}

std::string algebra::Matrix::Print() const {
    if (rows_ * columns_ == 0) return "[]";

    std::string temp = "[";

    for (size_t i = 0; i < this->Size().first; ++i) {
        for (size_t j = 0; j < this->Size().second; ++j) {
            temp += this->PrintComplex(matrix_[i][j]) + ", ";
        }
        temp.pop_back();
        temp.pop_back();
        temp += "; ";
    }
    temp.pop_back();
    temp.pop_back();
    temp += ']';

    return temp;
}

std::string algebra::Matrix::PrintComplex(const std::complex<double> value) const {
    std::ostringstream stream;
    stream << value.real();
    std::string real = stream.str();
    stream.str(std::string());
    stream << value.imag();
    std::string imag = stream.str();
    return real + 'i' + imag;

}

std::pair<size_t, size_t> algebra::Matrix::Size() const {
    return {rows_, columns_};
}

algebra::Matrix algebra::Matrix::Add(const algebra::Matrix &other) const {

    Matrix tmp(other);
    if (this->Size() == other.Size()) {
        for (size_t i = 0; i < other.Size().first; ++i) {
            for (size_t j = 0; j < other.Size().second; ++j) {
                tmp.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
            }
        }
        return tmp;
    } else {
        return Matrix();
    }
}

algebra::Matrix algebra::Matrix::Sub(const algebra::Matrix &other) const {
    Matrix tmp = other;
    if (this->Size() == other.Size()) {
        for (size_t i = 0; i < other.Size().first; ++i) {
            for (size_t j = 0; j < other.Size().second; ++j) {
                tmp.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
            }
        }
        return tmp;
    } else {
        for (size_t i = 0; i < other.Size().first; ++i) {
            for (size_t j = 0; j < other.Size().second; ++j) {
                tmp.matrix_[i][j] = (0, 0);
            }
        }
        return tmp;
    }
}

algebra::Matrix algebra::Matrix::Mul(const algebra::Matrix &other) const {
    if (matrix_[0].size() != other.Size().first) {
        return Matrix();
    }

    std::complex<double> sum;
    Matrix tmp(matrix_.size(), other.matrix_[0].size());

    for (size_t i = 0; i < tmp.matrix_.size(); ++i) {
        for (size_t j = 0; j < tmp.matrix_[0].size(); ++j) {
            for (size_t k = 0; k < matrix_[0].size(); ++k) {
                sum += matrix_[i][k] * other.GetElement(k, j);
            }
            tmp.matrix_[i][j] = sum;
            sum.real(0);
            sum.imag(0);
        }
    }

    return tmp;
}

algebra::Matrix algebra::Matrix::Mul(const std::complex<double> &complex_value) {

    for (size_t i = 0; i < this->Size().first; ++i) {
        for (size_t j = 0; j < this->Size().second; ++j) {
            matrix_[i][j] *= complex_value;
        }
    }
    return *this;
}

algebra::Matrix algebra::Matrix::Pow(const size_t &power) const {

    if (rows_ != columns_) { // macierz nie jest kwadratowa
        return Matrix();
    }

    if (power == 1) {
        return Matrix(*this);
    }

    if (power == 0) {  // zwroc macierz jednostkowa
        Matrix tmp(rows_, columns_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < columns_; ++j) {
                tmp.matrix_[i][j].imag(0);
                tmp.matrix_[i][j].real(0);
                if (i == j) tmp.matrix_[i][j].real(1);
            }
        }
        return tmp;
    }

    Matrix tmp(*this);
    for (size_t i = 0; i < power - 1; ++i) {
        tmp = tmp.Mul(*this);
    }
    return tmp;
}

void algebra::Matrix::Clear() {
    matrix_.clear();
    rows_ = 0;
    columns_ = 0;
}


