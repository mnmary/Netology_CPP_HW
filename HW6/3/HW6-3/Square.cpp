#include "Square.h"
#include <iostream>

Square::Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90)
    {
        this->name = "Квадрат";
    }
    void Square::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }
