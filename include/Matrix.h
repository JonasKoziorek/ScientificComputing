#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

template <typename T>
class Matrix
{
    public:
        std::vector<T> data;
        size_t rows;
        size_t cols;
        static int decimal_digits;

        Matrix(const std::vector<T>& data, size_t rows, size_t cols);

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& m);
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
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m)
{
    // Determine the maximum width needed for the elements
    size_t max_width = 0;
    for (const auto& elem : m.data)
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(Matrix<T>::decimal_digits) << elem;
        max_width = std::max(max_width, oss.str().length());
    }


    os << std::fixed << std::setprecision(Matrix<T>::decimal_digits);
    os << "[";
    for (size_t i = 0; i < m.rows; ++i)
    {
        os << "[";
        for (size_t j = 0; j < m.cols; ++j)
        {
            os << std::setw(max_width) << m.data[i * m.cols + j];
            if (j != m.cols - 1) os << ",  ";
        }
        os << "]";
        if (i != m.rows - 1) os << ",\n ";
    }
    os << "]";
    return os;
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& A, const Matrix<T>& B)
{
    if (A.cols * A.rows != B.cols * B.rows)
    {
        throw std::invalid_argument("Matrices must have valid dimensions for addition.");
    }

    std::vector<T> result_data(A.data.size());

    for (size_t i = 0; i < A.data.size(); ++i)
    {
        result_data[i] = A.data[i] + B.data[i];
    }

    return Matrix<T>(result_data, A.rows, B.cols);
}

template <typename T>
Matrix<T> operator*(const T a, const Matrix<T>& A)
{
    std::vector<T> result_data(A.data.size());
    for (size_t i = 0; i < A.data.size(); ++i)
    {
        result_data[i] = A.data[i] * a;
    }

    return Matrix<T>(result_data, A.rows, A.cols);
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