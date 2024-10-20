#ifndef ABSTRACT_SPARSE_MATRIX_H
#define ABSTRACT_SPARSE_MATRIX_H

#include "AbstractMatrix.h"

template <typename T>
class AbstractSparseMatrix : public AbstractMatrix<T>
{
public:
    virtual ~AbstractSparseMatrix() = default;
};

#endif // ABSTRACT_SPARSE_MATRIX_H