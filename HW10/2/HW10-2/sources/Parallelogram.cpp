#include "Parallelogram.h"
#include <iostream>

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B)
    {
        this->name = "Параллелограмм";
    }
    void Parallelogram::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }

