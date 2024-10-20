#ifndef CSR_H
#define CSR_H

#include <vector>
#include <iostream>
#include "AbstractSparseMatrix.h"

template <typename T>
class CSR : public AbstractSparseMatrix<T>
{
public:
    CSR(size_t rows, size_t cols, 
        const std::vector<T>& values,
        const std::vector<size_t>& col_index, 
        const std::vector<size_t>& row_index
    );

    T& at(size_t row, size_t col) override;
    const T& at(size_t row, size_t col) const override;

    size_t getRows() const override { return rows; }
    size_t getCols() const override { return cols; }

    void print(std::ostream& os) const override;

    size_t rows;
    size_t cols;
    std::vector<T> values;
    std::vector<size_t> col_index;
    std::vector<size_t> row_index;
};

template <typename T>
CSR<T>::CSR(size_t rows, size_t cols, 
    const std::vector<T>& values, 
    const std::vector<size_t>& col_index, 
    const std::vector<size_t>& row_index
)
{
    if (values.size() != col_index.size() || row_index.size() != rows + 1)
    {
        throw std::invalid_argument("Invalid input");
    }
    for (size_t row = 0; row < rows; ++row)
    {
        if (row_index[row] > row_index[row + 1])
        {
            throw std::invalid_argument("Invalid input");
        }
    }
    this->rows = rows;
    this->cols = cols;
    this->values = values;
    this->col_index = col_index;
    this->row_index = row_index;
}

template <typename T>
T& CSR<T>::at(size_t row, size_t col)
{
    for (size_t idx = row_index[row]; idx < row_index[row + 1]; ++idx)
    {
        if (col_index[idx] == col)
        {
            return values[idx];
        }
    }
    throw std::out_of_range("Element not found");
}

template <typename T>
const T& CSR<T>::at(size_t row, size_t col) const
{
    for (size_t idx = row_index[row]; idx < row_index[row + 1]; ++idx)
    {
        if (col_index[idx] == col)
        {
            return values[idx];
        }
    }
    throw std::out_of_range("Element not found");
}

template <typename T>
void CSR<T>::print(std::ostream& os) const
{
    os << "CSR Sparse Matrix(" << rows << "x" << cols << "):\n";
    for (size_t row = 0; row < rows; ++row)
    {
        for (size_t idx = row_index[row]; idx < row_index[row + 1]; ++idx)
        {
            os << "(" << row << ", " << col_index[idx] << ") = " << values[idx] << "\n";
        }
    }
}

template <typename T>
CSR<T> operator*(const T a, const CSR<T>& A)
{
    std::vector<T> result_data(A.values.size());
    for (size_t i = 0; i < A.values.size(); ++i)
    {
        result_data[i] = A.values[i] * a;
    }

    return CSR<T>(A.rows, A.cols, result_data, A.col_index, A.row_index);
}

template <typename T>
CSR<T> operator*(const CSR<T>& A, const T a)
{
    return a * A;
}

#endif // CSR_H