#include "IsoTriangle.h"
#include <iostream>
#include "MyException.h"

    IsoTriangle::IsoTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        this->name = "Равнобедренный треугольник";
    }
    void IsoTriangle::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << "; углы: " << this->A << ", " << this->B << ", " << this->C << " ) создан" << std::endl;
        std::cout << std::endl;
    }

