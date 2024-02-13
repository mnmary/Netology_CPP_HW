#include "Rhomb.h"
#include <iostream>
#include "MyException.h"

Rhomb::Rhomb(int a, int A, int B) //: Quad(a, a, a, a, A, B, A, B)
{
    if (a == 0)
    {
        throw MyException("Ошибка создания фигуры Ромб. Причина: одна из сторон равна 0");
    }
    if (A * 2 + B * 2 != 360)
    {
        throw MyException("Ошибка создания фигуры Ромб. Причина: сумма углов не равна 360");
    }
    this->cntPoint = 4;
    this->name = "Ромб";
    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
}
void Rhomb::print_info()
{
    std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
    std::cout << std::endl;
}

