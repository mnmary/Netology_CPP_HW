#include "IsoTriangle.h"
#include <iostream>
#include "MyException.h"

    IsoTriangle::IsoTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        this->name = "Равнобедренный треугольник";
    }
    void IsoTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << "; углы: " << this->A << ", " << this->B << ", " << this->C << " ) создан" << std::endl;
        std::cout << std::endl;
    }
    IsoTriangle::IsoTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->name = "Равнобедренный треугольник";
        if (!(a == c))
        {
            throw MyException("Ошибка создания фигуры. Причина: стороны a и c не равны");
        }
        if (!(A == C))
        {
            throw MyException("Ошибка создания фигуры. Причина: углы A и C не равны");
        }
    }

