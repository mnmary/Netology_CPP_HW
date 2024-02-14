#include "EquTriangle.h"
#include <iostream>
#include "MyException.h"

EquTriangle::EquTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {
        this->name = "Равносторонний треугольник";
    }
    void EquTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c  << "; углы: " << this->A << ", " << this->B << ", " << this->C  << " ) создан" << std::endl;
        std::cout << std::endl;
    }

