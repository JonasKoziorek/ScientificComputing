#ifndef MATRIXMATRIX_H
#define MATRIXMATRIX_H

#include "Matrix.h"


template <typename T>
Matrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B)
{
    Matrix<T> C = Matrix<T>(A.rows, B.cols);

    for(size_t Bcol = 0; Bcol < B.cols; Bcol++)
    {
        for(size_t Arow = 0; Arow < A.rows; Arow++)
        {
            T sum = static_cast<T>(0);
            for(size_t Acol = 0; Acol < A.cols; Acol++)
            {
                sum += A.at(Arow, Acol) * B.at(Acol, Bcol);
            }
            C.at(Arow, Bcol) = sum;
        }
    }

    return C;
}

#endif // MATRIXMATRIX_H
