#include "Rectangle.h"
#include <iostream>
#include "MyException.h"

_Rectangle::_Rectangle(int a, int b)
    {
        if ((a == 0) || (b == 0))
        {
            throw MyException("������ �������� ������ �������������. �������: ���� �� ������ ����� 0");
        }
        this->cntPoint = 4;
        this->name = "�������������";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = 90;
        this->C = 90;
        this->D = 90;
    }
    void _Rectangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }

