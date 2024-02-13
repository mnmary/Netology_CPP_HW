#include "Square.h"
#include <iostream>
#include "MyException.h"

Square::Square(int a)// : Quad(a, a, a, a, 90, 90, 90, 90)
    {
    if (a == 0)
    {
        throw MyException("������ �������� ������ �������. �������: ���� �� ������ ����� 0");
    }
    this->cntPoint = 4;
    this->name = "�������";
    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = 90;
    this->B = 90;
    this->C = 90;
    this->D = 90;

    }
    void Square::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }
