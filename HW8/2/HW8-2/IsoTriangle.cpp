#include "IsoTriangle.h"
#include <iostream>
#include "MyException.h"

    IsoTriangle::IsoTriangle(int a, int b, int A, int B) //: Triangle(a, b, a, A, B, A)
    {
        if ((a == 0) || (b == 0))
        {
            throw MyException("Ошибка создания фигуры равнобедренный треугольник. Причина: одна из сторон равна 0");
        }
        if ((A == 0) || (B == 0))
        {
            throw MyException("Ошибка создания фигуры равнобедренный треугольник. Причина: один из углов равен 0");
        }
        if (A * 2 + B != 180)
        {
            throw MyException("Ошибка создания фигуры равнобедренный треугольник. Причина: сумма углов не равна 180");
        }
        this->cntPoint = 3;
        this->name = "Равнобедренный треугольник";
        this->a = a;
        this->b = b;
        this->c = a;
        this->A = A;
        this->B = B;
        this->C = A;
    }
    void IsoTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << "; углы: " << this->A << ", " << this->B << ", " << this->C << " ) создан" << std::endl;
        std::cout << std::endl;
    }

