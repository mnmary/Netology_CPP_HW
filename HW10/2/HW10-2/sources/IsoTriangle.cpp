#include "IsoTriangle.h"
#include <iostream>
    IsoTriangle::IsoTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        this->name = "�������������� �����������";
    }
    void IsoTriangle::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "�������: � = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "����: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }

