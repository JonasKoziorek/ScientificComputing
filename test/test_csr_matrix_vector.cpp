#include <iostream>
#include <cassert>
#include "../include/Vector.h"
#include "../include/CSR.h"
#include "../include/MatrixVector.h"

void test_csr_matrix_vector()
{
    // Define a 2x2 CSR matrix
    std::vector<double> values = {4.0, 1.0, 1.0, 3.0};
    std::vector<size_t> col_index = {0, 1, 0, 1};
    std::vector<size_t> row_index = {0, 2, 4};
    CSR<double> A(2, 2, values, col_index, row_index);

    // Define a 2-element vector
    std::vector<double> vectorData = {1.0, 1.0};
    Vector<double> b(vectorData);

    // Perform CSR matrix-vector multiplication
    Vector<double> result = A * b;

    // Define the expected result
    std::vector<double> expectedData = {5.0, 4.0};
    Vector<double> expected(expectedData);

    // Check if the result matches the expected result
    assert(result.data == expected.data);
    std::cout << "CSR matrix-vector multiplication test passed!" << std::endl;
}