#include <iostream>
#include <cassert>
#include "../include/Matrix.h"

void test_matrix_addition()
{
    std::vector<double> data1 = {1, 2, 3, 4};
    std::vector<double> data2 = {5, 6, 7, 8};
    Matrix<double> mat1(data1, 2, 2);
    Matrix<double> mat2(data2, 2, 2);

    Matrix<double> result = mat1 + mat2;
    std::vector<double> expected_data = {6, 8, 10, 12};
    Matrix<double> expected(expected_data, 2, 2);

    assert(result.data == expected.data);
    std::cout << "Matrix addition test passed!" << std::endl;
}

void test_matrix_subtraction()
{
    std::vector<double> data1 = {1, 2, 3, 4};
    std::vector<double> data2 = {5, 6, 7, 8};
    Matrix<double> mat1(data1, 2, 2);
    Matrix<double> mat2(data2, 2, 2);

    Matrix<double> result = mat1 - mat2;
    std::vector<double> expected_data = {-4, -4, -4, -4};
    Matrix<double> expected(expected_data, 2, 2);

    assert(result.data == expected.data);
    std::cout << "Matrix subtraction test passed!" << std::endl;
}

void test_matrix_scalar_multiplication()
{
    std::vector<double> data = {1.1, 2.2, 3.3, 4.4};
    Matrix<double> mat(data, 2, 2);

    Matrix<double> result = 2.0 * mat;
    std::vector<double> expected_data = {2.2, 4.4, 6.6, 8.8};
    Matrix<double> expected(expected_data, 2, 2);

    assert(result.data == expected.data);
    std::cout << "Matrix scalar multiplication test passed!" << std::endl;
}

void test_matrix_pretty_printing()
{
    std::vector<double> data = {1.1, 2.2, 3.3, 4.4};
    Matrix<double> mat(data, 2, 2);

    std::ostringstream oss;
    oss << mat;
    std::string expected_output = "[[1.100,  2.200],\n [3.300,  4.400]]";

    assert(oss.str() == expected_output);
    std::cout << "Matrix pretty printing test passed!" << std::endl;
}

int main()
{
    test_matrix_addition();
    test_matrix_subtraction();
    test_matrix_scalar_multiplication();
    test_matrix_pretty_printing();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}