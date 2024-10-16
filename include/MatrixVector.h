#ifndef MATRIXVECTOR_H
#define MATRIXVECTOR_H

#include "Matrix.h"
#include "Vector.h"


template <typename T>
Vector<T> operator*(const Matrix<T>& A, const Vector<T>& b)
{
    if (A.cols != b.size())
    {
        throw std::invalid_argument("Invalid dimensions for matrix-vector multiplication.");
    }

    std::vector<T> result(A.rows);
    for(size_t row = 0; row < A.rows; row++)
    {
        T sum = 0;
        for(size_t col = 0; col < A.cols; col++)
        {
            sum += A.data[row * A.cols + col] * b.data[col];
        }
        result[row] = sum;
    }

    return Vector<T>(result);
}

#endif // MATRIXVECTOR_H