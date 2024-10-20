#include <iostream>
#include <cassert>
#include "../include/Vector.h"
#include "../include/Norms.h"

void test_l1_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0};
    Vector<double> vec(data);
    double result = l1_norm(vec);
    double expected = 10.0;
    assert(result == expected);
    std::cout << "L1 norm test passed!" << std::endl;
}

void test_l2_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0};
    Vector<double> vec(data);
    double result = l2_norm(vec);
    double expected = std::sqrt(30.0);
    assert(std::fabs(result - expected) < 1e-9);
    std::cout << "L2 norm test passed!" << std::endl;
}

void test_linf_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0};
    Vector<double> vec(data);
    double result = linf_norm(vec);
    double expected = 4.0;
    assert(result == expected);
    std::cout << "L-infinity norm test passed!" << std::endl;
}

void test_rowsum_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    Matrix<double> mat(data, 2, 3);
    double result = rowsum_norm(mat);
    double expected = 15.0;
    assert(result == expected);
    std::cout << "Row sum norm test passed!" << std::endl;
}

void test_colsum_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    Matrix<double> mat(data, 2, 3);
    double result = colsum_norm(mat);
    double expected = 9.0;
    assert(result == expected);
    std::cout << "Column sum norm test passed!" << std::endl;
}

void test_frobenius_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    Matrix<double> mat(data, 2, 3);
    double result = frobenius_norm(mat);
    double expected = std::sqrt(91.0);
    assert(std::fabs(result - expected) < 1e-9);
    std::cout << "Frobenius norm test passed!" << std::endl;
}

void test_norms()
{
    test_l1_norm();
    test_l2_norm();
    test_linf_norm();
    test_rowsum_norm();
    test_colsum_norm();
    test_frobenius_norm();
    std::cout << "All norms tests passed!" << std::endl;
}