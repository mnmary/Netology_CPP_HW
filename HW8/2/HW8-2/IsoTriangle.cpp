#include "IsoTriangle.h"
#include <iostream>
#include "MyException.h"

    IsoTriangle::IsoTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        this->name = "�������������� �����������";
    }
    void IsoTriangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << "; ����: " << this->A << ", " << this->B << ", " << this->C << " ) ������" << std::endl;
        std::cout << std::endl;
    }

