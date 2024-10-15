#include <iostream>
#include <vector>
#include "include/Vector.h"

int main(){
    std::cout << "Hello world!" << std::endl;
    std::vector<int> data = {1, 2, 3, 4};
    Vector<int> a = Vector(data);
    std::cout << a << std::endl;

    Vector<double> b = Vector(std::vector<double>{1.1, 2.2, 3.3, 4.4});
    std::cout << b << std::endl;
    std::cout << b+b+b << std::endl;
    std::cout << 2.5*b << std::endl;

    std::cout << 2.5*b - (-2.1)*b << std::endl;
    
    return 0;
}
