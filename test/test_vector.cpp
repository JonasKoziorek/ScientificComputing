#include <iostream>
#include <cassert>
#include "../include/Vector.h"

void test_vector_addition()
{
    std::vector<int> data1 = {1, 2, 3};
    std::vector<int> data2 = {4, 5, 6};
    Vector<int> vec1(data1);
    Vector<int> vec2(data2);

    Vector<int> result = vec1 + vec2;

    assert(result.data[0] == 5);
    assert(result.data[1] == 7);
    assert(result.data[2] == 9);

    std::cout << "test_vector_addition passed!" << std::endl;
}

void test_vector_scalar_multiplication()
{
    std::vector<int> data = {1, 2, 3};
    Vector<int> vec(data);

    Vector<int> result = 2 * vec;

    assert(result.data[0] == 2);
    assert(result.data[1] == 4);
    assert(result.data[2] == 6);

    std::cout << "test_vector_scalar_multiplication passed!" << std::endl;
}

void test_vector_subtraction()
{
    std::vector<int> data1 = {5, 7, 9};
    std::vector<int> data2 = {1, 2, 3};
    Vector<int> vec1(data1);
    Vector<int> vec2(data2);

    Vector<int> result = vec1 - vec2;

    assert(result.data[0] == 4);
    assert(result.data[1] == 5);
    assert(result.data[2] == 6);

    std::cout << "test_vector_subtraction passed!" << std::endl;
}

int main()
{
    test_vector_addition();
    test_vector_scalar_multiplication();
    test_vector_subtraction();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}