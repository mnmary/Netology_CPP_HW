#include "RectTriangle.h"
#include <iostream>
#include "MyException.h"

    RectTriangle::RectTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        this->name = "Прямоугольный треугольник";
    }
    RectTriangle::RectTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->name = "Прямоугольный треугольник";
        if (!(C == 90))
        {
            throw MyException("Ошибка создания фигуры. Причина: угол С не равен 90 градусов");
        }
    }
    void RectTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << "; углы: " << this->A << ", " << this->B << ", " << this->C << " ) создан" << std::endl;
        std::cout << std::endl;
    }
