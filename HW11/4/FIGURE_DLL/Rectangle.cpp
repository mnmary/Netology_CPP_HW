#include "pch.h"
#include "Rectangle.h"
#include <iostream>
Rectangle::Rectangle(int a, int b) : Quad(a, b, a, b, 90, 90, 90, 90)
    {
        this->name = "Прямоугольник";
    }
    void Rectangle::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }

