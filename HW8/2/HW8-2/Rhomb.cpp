#include "Rhomb.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


Rhomb::Rhomb(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B)
{
    this->name = "Ромб";
}
Rhomb::Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "Ромб";
    if (!compare4(a , b , c , d))
    {
        throw MyException("Ошибка создания фигуры. Причина: стороны не равны");
    };
    if (!((A == C) && (B == D)))
    {
        throw MyException("Ошибка создания фигуры. Причина: углы a и c или b и d не равны");
    };
}
void Rhomb::print_info()
{
    std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
    std::cout << std::endl;
}

