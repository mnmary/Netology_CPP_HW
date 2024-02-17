#include "EquTriangle.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


EquTriangle::EquTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {
        this->name = "Равносторонний треугольник";
    }
    void EquTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c  << "; углы: " << this->A << ", " << this->B << ", " << this->C  << " ) создан" << std::endl;
        std::cout << std::endl;
    }

    EquTriangle::EquTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->name = "Равносторонний треугольник";
        if (!compare3(a , b , c))
        {
            throw MyException("Ошибка создания фигуры. Причина: стороны не равны");
        };
        if (!(compare3(A , B , C)&&(A == 60)))
        {
            throw MyException("Ошибка создания фигуры. Причина: углы не равны 60 градусов");
        }
    }
