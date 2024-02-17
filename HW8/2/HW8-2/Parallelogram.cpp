#include "Parallelogram.h"
#include <iostream>
#include "MyException.h"


Parallelogram::Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B)
    {
        this->name = "Параллелограмм";
    }
Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "Параллелограмм";
    if (!((a == c) && (b == d)))
    {
        throw MyException("Ошибка создания фигуры. Причина: стороны a и c или b и d не равны");
    };
    if (!((A == C) && (B == D)))
    {
        throw MyException("Ошибка создания фигуры. Причина: углы A и C или B и D не равны");
    };

}
    void Parallelogram::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
        std::cout << std::endl;
    }

