#include "Rectangle.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


_Rectangle::_Rectangle(int a, int b) : Quad(a, b, a, b, 90, 90, 90, 90)
    {
        this->name = "Прямоугольник";
    }
_Rectangle::_Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "Прямоугольник";
    if (!((a == c) && (b == d)))
    {
        throw MyException("Ошибка создания фигуры. Причина: стороны a и c или b и d не равны");
    };
    if (!(compare4(A , B , C , D)&&(A == 90)))
    {
        throw MyException("Ошибка создания фигуры. Причина: один из углов не равен 90 градусов");
    };
}
void _Rectangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
        std::cout << std::endl;
    }

