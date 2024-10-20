#ifndef MATRIXVECTOR_H
#define MATRIXVECTOR_H

#include "Matrix.h"
#include "CSR.h"
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

template <typename T>
Vector<T> operator*(const CSR<T>& matrix, const Vector<T>& x)
{
    if (matrix.getCols() != x.size())
    {
        throw std::invalid_argument("Invalid dimensions for matrix-vector multiplication.");
    }

    size_t dim = matrix.row_index.size()-1;
    Vector<T> result(dim);
    for(size_t i = 0; i < dim; i++)
    {
        double sum = 0;
        for(size_t j = matrix.row_index[i]; j < matrix.row_index[i+1]; j++)
        {
            int id = matrix.col_index[j];
            sum += matrix.values[j] * x.at(id);
        }
        result.at(i) = sum;
    }
    return result;
}

#endif // MATRIXVECTOR_H