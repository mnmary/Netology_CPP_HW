#include "Square.h"
#include <iostream>
#include "MyException.h"

Square::Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90)
    {
        this->name = " вадрат";
    }
    void Square::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
        std::cout << std::endl;
    }
