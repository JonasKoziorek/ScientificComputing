#include "test_matrix_matrix.h"
#include "test_matrix_vector.h"
#include "test_matrix.h"
#include "test_vector.h"
#include "test_norms.h"
#include "test_inner_product.h"
#include "test_cg.h"
#include "test_csr_matrix_vector.h"

int main()
{
    test_matrix_matrix();
    test_matrix_vector();
    test_matrix();
    test_vector();
    test_norms();
    test_inner_product();
    test_all_cg();
    test_csr_matrix_vector();
    return 0;
}