#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "AbstractMatrix.h"

template <typename T>
class Matrix : public AbstractMatrix<T>
{
    public:
        std::vector<T> data;
        size_t rows;
        size_t cols;
        static int decimal_digits;

        Matrix(const std::vector<T>& data, size_t rows, size_t cols);
        Matrix(size_t rows, size_t cols);

        T& at(size_t row, size_t col) override;
        const T& at(size_t row, size_t col) const override;

        size_t getRows() const override { return rows; }
        size_t getCols() const override { return cols; }

        void print(std::ostream& os) const override;

    private:
};

template <typename T>
int Matrix<T>::decimal_digits = 3; // default number of decimal digits for printing

template <typename T>
Matrix<T>::Matrix(const std::vector<T>& data, size_t rows, size_t cols)
{
    if(data.size() != rows*cols)
    {
        throw std::invalid_argument(
            "Provided data does not match the provided dimensions of the matrix."
        );
    }

    this->data = data;
    this->rows = rows;
    this->cols = cols;
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols)
{
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<T>(rows * cols);
}

template <typename T>
T& Matrix<T>::at(size_t row, size_t col)
{
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Matrix indices out of range.");
    }
    return this->data[row * this->cols + col];
}

template <typename T>
const T& Matrix<T>::at(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[row * cols + col];
}

template <typename T>
void Matrix<T>::print(std::ostream& os) const
{
    // Determine the maximum width needed for the elements
    size_t max_width = 0;
    for (const auto& elem : this->data)
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(Matrix<T>::decimal_digits) << elem;
        max_width = std::max(max_width, oss.str().length());
    }


    os << std::fixed << std::setprecision(Matrix<T>::decimal_digits);
    os << "[";
    for (size_t i = 0; i < this->getRows(); ++i)
    {
        os << "[";
        for (size_t j = 0; j < this->getCols(); ++j)
        {
            os << std::setw(max_width) << this->at(i, j);
            if (j != this->getCols() - 1) os << ",  ";
        }
        os << "]";
        if (i != this->getRows() - 1) os << ",\n ";
    }
    os << "]";
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& A, const Matrix<T>& B)
{
    if (A.getCols() * A.getRows() != B.getCols() * B.getRows())
    {
        throw std::invalid_argument("Matrices must have valid dimensions for addition.");
    }

    std::vector<T> result_data(A.data.size());

    for (size_t i = 0; i < A.data.size(); ++i)
    {
        result_data[i] = A.data[i] + B.data[i];
    }

    return Matrix<T>(result_data, A.getRows(), B.getCols());
}

template <typename T>
Matrix<T> operator*(const T a, const Matrix<T>& A)
{
    std::vector<T> result_data(A.data.size());
    for (size_t i = 0; i < A.data.size(); ++i)
    {
        result_data[i] = A.data[i] * a;
    }

    return Matrix<T>(result_data, A.getRows(), A.getCols());
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& A, const T a)
{
    return a * A;
}

template <typename T>
Matrix<T> operator-(const Matrix<T>& A, const Matrix<T>& B)
{
    return A + static_cast<T>(-1) * B;
}

#endif // MATRIX_H
