#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>

template <typename T>
class Vector
{
    public:
        std::vector<T> data;
        Vector(const std::vector<T>& data);
        Vector(size_t size);

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Vector<U>& v);

        size_t size() const { return data.size(); }
};

template <typename T>
Vector<T>::Vector(const std::vector<T>& data)
{
    this->data = data;
}

template <typename T>
Vector<T>::Vector(size_t size)
{
    this->data = std::vector<T>(size);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
    if (v.size() == 0)
    {
        os << "[]";
        return os;
    }
    else
    {
        os << "[";
        for(size_t i = 0; i < v.size()-1; i++)
        {
            os << v.data[i] << ", ";
        }
        os << v.data[v.size()-1] << "]";
        return os;
    }
}

template <typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
    if (a.size() != b.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }
    
    std::vector<T> result(a.size());
    for(size_t i = 0; i < a.size(); i++)
    {
        result[i] = a.data[i] + b.data[i];
    }
    return result;
}

template <typename T>
Vector<T> operator*(const T a, const Vector<T>& x)
{
    std::vector<T> result(x.size());
    for(size_t i = 0; i < x.size(); i++)
    {
        result[i] = a * x.data[i];
    }
    return result;
}

template <typename T>
Vector<T> operator*(const Vector<T>& x, const T a)
{
    return a * x;
}

template <typename T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b)
{
    if (a.size() != b.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }
    
    return a + static_cast<T>(-1)*b;
}

#endif // VECTOR_H