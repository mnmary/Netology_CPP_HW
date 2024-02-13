#include "RectTriangle.h"
#include <iostream>
#include "MyException.h"

    RectTriangle::RectTriangle(int a, int b, int c, int A, int B) //: Triangle(a, b, c, A, B, 90)
    {
        if ((a == 0) || (b == 0) || (c == 0))
        {
            throw MyException("Ошибка создания фигуры Прямоугольный треугольник. Причина: одна из сторон равна 0");
        }
        if ((A == 0) || (B == 0))
        {
            throw MyException("Ошибка создания фигуры Прямоугольный треугольник. Причина: один из углов равен 0");
        }
        if (A + B != 90)
        {
            throw MyException("Ошибка создания фигуры Прямоугольный треугольник. Причина: сумма углов не равна 180");
        }

        this->name = "Прямоугольный треугольник";
        this->cntPoint = 3;

        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = 90;
    }
    void RectTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << "; углы: " << this->A << ", " << this->B << ", " << this->C << " ) создан" << std::endl;
        std::cout << std::endl;
    }
