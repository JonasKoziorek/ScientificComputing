#include <iostream>
#include <vector>
#include "../include/CSR.h"
#include "../include/MatrixVector.h"
#include "../include/num_linalg/CG.h"
#include "../include/Vector.h"
#include "../include/Norms.h"

CSR<double> generate_sparse_matrix(const size_t N) {
    std::vector<double> values;
    std::vector<size_t> col_index; 
    std::vector<size_t> row_index;

    for(size_t i = 0; i < N; i++)
    {
        row_index.push_back(values.size());
        if(i == 0)
        {
            values.push_back(2.0);
            col_index.push_back(i);

            values.push_back(-1.0);
            col_index.push_back(i+1);
        }
        else if(1 <= i  && i <= N-2)
        {
            values.push_back(-1.0);
            col_index.push_back(i-1);

            values.push_back(2.0);
            col_index.push_back(i);

            values.push_back(-1.0);
            col_index.push_back(i+1);
        }
        else if(i == N-1)
        {
            values.push_back(-1.0);
            col_index.push_back(i-1);

            values.push_back(2.0);
            col_index.push_back(i);
        }
    }
    row_index.push_back(values.size());
    return CSR<double>(N, N, values, col_index, row_index);
}

int main()
{
    std::vector<double> vals = {2.0, -1.0, -1.0, 1.0};
    std::vector<size_t> cols = {0, 1, 0, 1};
    std::vector<size_t> rows = {0, 2, 4};

    CSR<double> A(2, 2, vals, cols, rows);
    Vector<double> b(std::vector<double> {14.0, 2.0});
    Vector<double> x = CSR_CG(A, b, 100, 1e-6);
    Vector<double> analytic_solution(std::vector<double> {16.0, 18.0});

    std::cout << A << std::endl;
    std::cout << b << std::endl;
    std::cout << x << std::endl << std::endl;
    std::cout << "Norm between numeric and analytic solution: " << l2_norm(x - analytic_solution) << std::endl << std::endl;


    CSR<double> A2 = generate_sparse_matrix(5);
    Vector<double> b2(std::vector<double> {6.0, 3.0, 10.0, 9.0, 12.0});
    Vector<double> x2 = CSR_CG(A2, b2, 100, 1e-6);
    Vector<double> analytic_solution2(std::vector<double> {17.0, 28.0, 36.0, 34.0, 23.0});

    std::cout << "Norm between numeric and analytic solution: " << l2_norm(x2 - analytic_solution2) << std::endl << std::endl;

    return 0;
}