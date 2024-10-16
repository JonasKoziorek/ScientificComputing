#include <iostream>
#include <cassert>
#include "../include/Matrix.h"
#include "../include/Vector.h"
#include "../include/MatrixVector.h"

void test_matrix_vector_multiplication()
{
    // Define a 2x2 matrix
    std::vector<double> matrixData = {1.0, 2.0, 3.0, 4.0};
    Matrix<double> A(matrixData, 2, 2);

    // Define a 2-element vector
    std::vector<double> vectorData = {1.0, 1.0};
    Vector<double> b(vectorData);

    // Perform matrix-vector multiplication
    Vector<double> result = A * b;

    // Define the expected result
    std::vector<double> expectedData = {3.0, 7.0};
    Vector<double> expected(expectedData);

    // Check if the result matches the expected result
    assert(result.data == expected.data);
    std::cout << "Matrix-vector multiplication test passed!" << std::endl;
}

void test_matrix_vector_invalid_dimensions()
{
    // Define a 2x3 matrix
    std::vector<double> matrixData = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    Matrix<double> A(matrixData, 2, 3);

    // Define a 2-element vector
    std::vector<double> vectorData = {1.0, 1.0};
    Vector<double> b(vectorData);

    // Expect an invalid_argument exception due to dimension mismatch
    try {
        Vector<double> result = A * b;
        // If no exception is thrown, the test should fail
        assert(false);
    } catch (const std::invalid_argument& e) {
        std::cout << "Matrix-vector invalid dimensions test passed!" << std::endl;
    }
}

int main()
{
    test_matrix_vector_multiplication();
    test_matrix_vector_invalid_dimensions();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
