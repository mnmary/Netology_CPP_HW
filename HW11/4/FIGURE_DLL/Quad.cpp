#include "pch.h"
#include "Quad.h"
#include <iostream>
Quad::Quad(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        cntPoint = 4;

        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;

        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;

        this->name = "Четырехугольник";
    }
Quad::Quad()  //default
    {
        cntPoint = 4;

        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;

        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;

        this->name = "Четырехугольник";
    }
    void Quad::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
        std::cout << std::endl;
    }

