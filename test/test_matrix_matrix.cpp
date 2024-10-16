#include <iostream>
#include <cassert>
#include "../include/Matrix.h"
#include "../include/MatrixMatrix.h"

void test_matrix_matrix_multiplication() {
    // Define a 2x3 matrix
    std::vector<double> dataA = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    Matrix<double> A(dataA, 2, 3);

    // Define a 3x2 matrix
    std::vector<double> dataB = {7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
    Matrix<double> B(dataB, 3, 2);

    // Perform matrix-matrix multiplication
    Matrix<double> C = A * B;

    // Define the expected result
    std::vector<double> expectedData = {58.0, 64.0, 139.0, 154.0};
    Matrix<double> expected(expectedData, 2, 2);

    // Check if the result matches the expected result
    for (size_t i = 0; i < C.getRows(); ++i) {
        for (size_t j = 0; j < C.getCols(); ++j) {
            assert(C.at(i, j) == expected.at(i, j));
        }
    }

    std::cout << "Matrix-matrix multiplication test passed!" << std::endl;
}

void test_matrix_matrix() {
    test_matrix_matrix_multiplication();
}
