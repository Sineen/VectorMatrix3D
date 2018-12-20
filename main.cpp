#include <iostream>
#include <sstream>
#include "Vector3D.h"
int main()
{
    Vector3D a(3.0, 2.2, 5.0);
    Vector3D d;
    std::stringstream os;

    os << d;
    std::cout << os.str().compare("0 0 0");
//    std::cout << "a.norm = " << a.norm() << std::endl;
    Vector3D b(7.0, 1.0, 0.0);
//    std::cout << "a.dist(b) = " << a.dist(b) << std::endl;
    Vector3D c(5.0, 1.0, 4.0);

//    Matrix3D m(a, b, c);
//    std::cout << "Matrix m = \n" << m;
//    std::cout << "m.determinant = " << m.determinant() << std::endl;
//    std::cout << "m*a = " << m*a << std::endl;
    return 0;
}