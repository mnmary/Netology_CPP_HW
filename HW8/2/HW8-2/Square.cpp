#include "Square.h"
#include <iostream>
#include "MyException.h"

Square::Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90)
    {
        this->name = "�������";
    }
    void Square::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }
