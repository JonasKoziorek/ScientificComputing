#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H

template <typename T>
class AbstractMatrix
{
public:
    virtual ~AbstractMatrix() = default;

    virtual T& at(size_t row, size_t col) = 0;
    virtual const T& at(size_t row, size_t col) const = 0;

    virtual size_t getRows() const = 0;
    virtual size_t getCols() const = 0;

    virtual void print(std::ostream& os) const = 0;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const AbstractMatrix<U>& m)
    {
        m.print(os);
        return os;
    }
};

#endif // ABSTRACTMATRIX_H