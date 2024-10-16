#ifndef NORMS_H
#define NORMS_H

#include <cmath>
#include "Vector.h"

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

#endif // NORMS_H
