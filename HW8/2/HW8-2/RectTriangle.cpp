#include "RectTriangle.h"
#include <iostream>
#include "MyException.h"

    RectTriangle::RectTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        this->name = "������������� �����������";
    }
    void RectTriangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << "; ����: " << this->A << ", " << this->B << ", " << this->C << " ) ������" << std::endl;
        std::cout << std::endl;
    }
