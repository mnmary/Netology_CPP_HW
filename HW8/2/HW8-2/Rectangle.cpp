#include "Rectangle.h"
#include <iostream>
#include "MyException.h"

_Rectangle::_Rectangle(int a, int b) : Quad(a, b, a, b, 90, 90, 90, 90)
    {
        this->name = "Прямоугольник";
    }
    void _Rectangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
        std::cout << std::endl;
    }

