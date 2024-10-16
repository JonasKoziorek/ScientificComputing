#ifndef CG_H
#define CG_H

#include "../Vector.h"
#include "../Matrix.h"
#include "../MatrixVector.h"
#include "../Norms.h"
#include "../InnerProduct.h"

template <typename T>
Vector<T> CG(const Matrix<T>& A, const Vector<T>& b, size_t maxiters, double reduction_factor)
{
    Vector<T> x(std::vector<T> (b.size()));

    // Compute initial direction d and residuum r
    Vector<T> d = b - A * x;
    Vector<T> r = d;
    size_t k = 0; // iterations of CG
    T r_norm_sq = inner_product(r, r);
    double first_residuum = std::sqrt(r_norm_sq);

    while (std::sqrt(r_norm_sq) > first_residuum * reduction_factor && k < maxiters) {
        // Compute the next iteration with the CG method
        double alpha = inner_product(r, r) / inner_product(d, A * d);
        x = x + alpha * d;
        Vector<T> r_next = r - alpha * A * d;
        T beta = inner_product(r_next, r_next) / inner_product(r, r);
        r = r_next;
        d = r + beta * d;
        r_norm_sq = inner_product(r,r);
        k += 1;
    }

    std::cout << "CG finished after " << k << " iterations" << std::endl;

    return x;
}

#endif // CG_H
