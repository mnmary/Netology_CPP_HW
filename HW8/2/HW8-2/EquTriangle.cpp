#include "EquTriangle.h"
#include <iostream>
#include "MyException.h"

EquTriangle::EquTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {
        this->name = "�������������� �����������";
    }
    void EquTriangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c  << "; ����: " << this->A << ", " << this->B << ", " << this->C  << " ) ������" << std::endl;
        std::cout << std::endl;
    }

