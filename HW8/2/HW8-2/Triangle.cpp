#include "Triangle.h"
#include <iostream>
#include "MyException.h"

    Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3, "�����������")
    {
        if ((a == 0) || (b == 0) || (c == 0))
        {
            throw MyException("������ �������� ������. �������: ���� �� ������ ����� 0");
        }
        if ((A == 0) || (B == 0) || (C == 0))
        {
            throw MyException("������ �������� ������. �������: ���� �� ����� ����� 0");
        }
        if (A + B + C != 180)
        {
            throw MyException("������ �������� ������. �������: ����� ����� �� ����� 180");
        }
        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = C;

    }
    Triangle::Triangle() : Figure(3, "�����������")
    {
    }

    void Triangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << "; ����: " << this->A << ", " << this->B << ", " << this->C << " ) ������" << std::endl;
        std::cout << std::endl;
    }
