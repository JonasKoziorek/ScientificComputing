#include <iostream>
#include <cassert>
#include "../include/Vector.h"
#include "../include/InnerProduct.h"

void test_dot_product()
{
    std::vector<double> data1 = {1.0, 2.0, 3.0};
    std::vector<double> data2 = {4.0, 5.0, 6.0};
    Vector<double> vec1(data1);
    Vector<double> vec2(data2);

    double result = inner_product(vec1, vec2);
    double expected = 32.0; // 1*4 + 2*5 + 3*6 = 32
    assert(result == expected);
    std::cout << "Dot product test passed!" << std::endl;
}

void test_inner_product()
{
    test_dot_product();
    std::cout << "All inner product tests passed!" << std::endl;
}