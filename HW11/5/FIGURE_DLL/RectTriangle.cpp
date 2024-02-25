//#include "pch.h"
#include "RectTriangle.h"
#include <iostream>
    RectTriangle::RectTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        this->name = "Прямоугольный треугольник";
    }
    void RectTriangle::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }
