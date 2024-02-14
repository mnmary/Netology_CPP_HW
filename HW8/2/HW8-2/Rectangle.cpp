#include "Rectangle.h"
#include <iostream>
#include "MyException.h"

_Rectangle::_Rectangle(int a, int b) : Quad(a, b, a, b, 90, 90, 90, 90)
    {
        this->name = "�������������";
    }
    void _Rectangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }

