#include "IsoTriangle.h"
#include <iostream>
    IsoTriangle::IsoTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        this->name = "Равнобедренный треугольник";
    }
    void IsoTriangle::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }

