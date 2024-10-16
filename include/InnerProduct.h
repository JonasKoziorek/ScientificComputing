#ifndef INNERPRODUCT_H
#define INNERPRODUCT_H

#include "Vector.h"

template <typename T>
T inner_product(const Vector<T>& a, const Vector<T>& b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must have the same size.");
    }

    T result = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a.data[i] * b.data[i];
    }

    return result;
}

#endif // INNERPRODUCT_H
