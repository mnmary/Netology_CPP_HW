//#include "pch.h"
#include "Triangle.h"
#include <iostream>
    Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    {
        cntPoint = 3;

        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = C;

        this->name = "Треугольник";
    }
    Triangle::Triangle()  //default
    {
        cntPoint = 3;

        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = C;

        this->name = "Треугольник";
    }

    void Triangle::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "Стороны: а = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }
