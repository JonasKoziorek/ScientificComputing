#include <iostream>
#include <cassert>
#include "../include/Vector.h"
#include "../include/Norms.h"

void test_l1_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0};
    Vector<double> vec(data);
    double result = norms::l1_norm(vec);
    double expected = 10.0;
    assert(result == expected);
    std::cout << "L1 norm test passed!" << std::endl;
}

void test_l2_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0};
    Vector<double> vec(data);
    double result = norms::l2_norm(vec);
    double expected = std::sqrt(30.0);
    assert(std::fabs(result - expected) < 1e-9);
    std::cout << "L2 norm test passed!" << std::endl;
}

void test_linf_norm()
{
    std::vector<double> data = {1.0, -2.0, 3.0, -4.0};
    Vector<double> vec(data);
    double result = norms::linf_norm(vec);
    double expected = 4.0;
    assert(result == expected);
    std::cout << "L-infinity norm test passed!" << std::endl;
}

void test_norms()
{
    test_l1_norm();
    test_l2_norm();
    test_linf_norm();
    std::cout << "All norms tests passed!" << std::endl;
}