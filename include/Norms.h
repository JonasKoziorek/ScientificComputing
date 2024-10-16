#ifndef NORMS_H
#define NORMS_H

#include <cmath>
#include "Vector.h"
#include "Matrix.h"

namespace norms
{
    template <typename T>
    T l1_norm(const Vector<T> x)
    {
        T norm = 0;
        for (size_t i = 0; i < x.size(); i++)
        {
            norm += std::abs(x.data[i]);
        }
        return norm;
    }

    template <typename T>
    T l2_norm(const Vector<T> x)
    {
        T norm = 0;
        for (size_t i = 0; i < x.size(); i++)
        {
            norm += x.data[i] * x.data[i];
        }
        return std::sqrt(norm);
    }

    template <typename T>
    T linf_norm(const Vector<T> x)
    {
        T norm = 0;
        for (size_t i = 0; i < x.size(); i++)
        {
            norm = std::max(norm, std::abs(x.data[i]));
        }
        return norm;
    }
}

template <typename T>
T rowsum_norm(const Matrix<T>& A)
{
    T norm = static_cast<T>(0);
    for(size_t row = 0; row < A.getRows(); row++)
    {
        T sum = static_cast<T>(0);
        for(size_t col = 0; col < A.getCols(); col++)
        {
            sum += std::abs(A.at(row, col));
        }
        norm = std::max(norm, sum);
    }
    return norm;
}

template <typename T>
T colsum_norm(const Matrix<T>& A)
{
    T norm = static_cast<T>(0);
    for(size_t col = 0; col < A.getCols(); col++)
    {
        T sum = static_cast<T>(0);
        for(size_t row = 0; row < A.getRows(); row++)
        {
            sum += std::abs(A.at(row, col));
        }
        norm = std::max(norm, sum);
    }
    return norm;
}

template <typename T>
T frobenius_norm(const Matrix<T>& A)
{
    T norm = static_cast<T>(0);
    for(size_t row = 0; row < A.getRows(); row++)
    {
        for(size_t col = 0; col < A.getCols(); col++)
        {
            norm += A.at(row, col) * A.at(row, col);
        }
    }
    return std::sqrt(norm);
}

#endif // NORMS_H
