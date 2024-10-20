#include <iostream>
#include <cassert>
#include "../include/Vector.h"
#include "../include/Matrix.h"
#include "../include/num_linalg/CG.h"

void test_cg()
{
    // Example: Solve Ax = b where A is a 2x2 symmetric positive-definite matrix
    std::vector<double> data = {4.0, 1.0, 1.0, 3.0};
    Matrix<double> A(data, 2, 2);
    std::vector<double> b_data = {1.0, 2.0};
    Vector<double> b(b_data);

    // Expected solution: x = [1/11, 7/11]
    std::vector<double> expected_data = {1.0 / 11.0, 7.0 / 11.0};
    Vector<double> expected(expected_data);

    // Solve using CG method
    Vector<double> x = CG(A, b, 1000, 1e-9);

    // Check if the solution is close to the expected solution
    assert(l2_norm(x - expected) < 1e-9);
    std::cout << "CG test passed!" << std::endl;
}

void test_all_cg()
{
    test_cg();
    std::cout << "All CG tests passed!" << std::endl;
}