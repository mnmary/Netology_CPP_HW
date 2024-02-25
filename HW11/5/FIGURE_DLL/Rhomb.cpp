//#include "pch.h"
#include "Rhomb.h"
#include <iostream>
Rhomb::Rhomb(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B)
    {
        this->name = "Ромб";
    }
void Rhomb::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }

