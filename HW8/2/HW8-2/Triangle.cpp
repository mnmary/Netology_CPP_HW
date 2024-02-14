#include "Triangle.h"
#include <iostream>
#include "MyException.h"

    Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3, "Треугольник")
    {
        if ((a == 0) || (b == 0) || (c == 0))
        {
            throw MyException("Ошибка создания фигуры. Причина: одна из сторон равна 0");
        }
        if ((A == 0) || (B == 0) || (C == 0))
        {
            throw MyException("Ошибка создания фигуры. Причина: один из углов равен 0");
        }
        if (A + B + C != 180)
        {
            throw MyException("Ошибка создания фигуры. Причина: сумма углов не равна 180");
        }
        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = C;

    }
    Triangle::Triangle() : Figure(3, "Треугольник")
    {
    }

    void Triangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << "; углы: " << this->A << ", " << this->B << ", " << this->C << " ) создан" << std::endl;
        std::cout << std::endl;
    }
