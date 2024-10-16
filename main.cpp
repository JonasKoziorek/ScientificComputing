#include <iostream>
#include <vector>
#include "include/Vector.h"
#include "include/Matrix.h"
#include "include/MatrixVector.h"

int main(){
    std::cout << "Hello world!" << std::endl;
    std::vector<int> data = {1, 2, 3, 4};
    Vector<int> a = Vector(data);
    std::cout << a << std::endl;

    Vector<double> b = Vector(std::vector<double>{1.1, 2.2, 3.3, 4.4});
    std::cout << b << std::endl;
    std::cout << b+b+b << std::endl;
    std::cout << 2.5*b << std::endl;

    std::cout << 2.5*b - (-2.1)*b << std::endl << std::endl;


    std::vector<double> matrix_data = {
        1.1, 2.2, 3.332,
        4.4, 5.532, 6.6,
        1.7, 1.0002, 1.0
    };
    Matrix<double> mat(matrix_data, 3, 3);
    std::cout << mat << std::endl << std::endl;

    std::cout << mat + mat - 0.2 * mat * 2.3 << std::endl << std::endl;
    Vector<double> c = Vector(std::vector<double>{1.0, 1.0, 1.0});
    std::cout << mat * c << std::endl << std::endl;

    return 0;
}
