#include "Quad.h"
#include <iostream>
#include "MyException.h"

Quad::Quad(int a, int b, int c, int d, int A, int B, int C, int D) : Quad()
    {
        if ((a == 0) || (b == 0) || (c == 0) || (d == 0))
        {
            throw MyException("Ошибка создания фигуры Четырехугольник. Причина: одна из сторон равна 0");
        }
        if ((A + B + C + D) != 360)
        {   
            throw MyException("Ошибка создания фигуры Четырехугольник. Причина: сумма углов не равна 360");
        }
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;

        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;

    }
Quad::Quad()
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
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
        std::cout << std::endl;
    }

