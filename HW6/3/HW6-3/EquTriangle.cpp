#include "EquTriangle.h"
#include <iostream>
    EquTriangle::EquTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {
        this->name = "�������������� �����������";
    }
    void EquTriangle::print_info()
    {
        std::cout << name << ": " << std::endl;
        std::cout << "�������: � = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "����: A = " << A << ", B = " << B << ", C = " << C << std::endl;
        std::cout << std::endl;
    }
