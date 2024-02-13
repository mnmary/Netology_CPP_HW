#include "EquTriangle.h"
#include <iostream>
#include "MyException.h"

EquTriangle::EquTriangle(int a)// : Triangle(a, a, a, 60, 60, 60)
    {
        if ((a == 0) || (b == 0))
        {
            throw MyException("Ошибка создания фигуры равносторонний треугольник. Причина: одна из сторон равна 0");
        }
    this->cntPoint = 3;
    this->name = "Равносторонний треугольник";
    this->a = a;
    this->b = a;
    this->c = a;
    this->A = 60;
    this->B = 60;
    this->C = 60;

    }
    void EquTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c  << "; углы: " << this->A << ", " << this->B << ", " << this->C  << " ) создан" << std::endl;
        std::cout << std::endl;
    }

