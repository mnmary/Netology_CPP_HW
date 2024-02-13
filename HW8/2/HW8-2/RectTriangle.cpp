#include "RectTriangle.h"
#include <iostream>
#include "MyException.h"

    RectTriangle::RectTriangle(int a, int b, int c, int A, int B) //: Triangle(a, b, c, A, B, 90)
    {
        if ((a == 0) || (b == 0) || (c == 0))
        {
            throw MyException("������ �������� ������ ������������� �����������. �������: ���� �� ������ ����� 0");
        }
        if ((A == 0) || (B == 0))
        {
            throw MyException("������ �������� ������ ������������� �����������. �������: ���� �� ����� ����� 0");
        }
        if (A + B != 90)
        {
            throw MyException("������ �������� ������ ������������� �����������. �������: ����� ����� �� ����� 180");
        }

        this->name = "������������� �����������";
        this->cntPoint = 3;

        this->a = a;
        this->b = b;
        this->c = c;

        this->A = A;
        this->B = B;
        this->C = 90;
    }
    void RectTriangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << "; ����: " << this->A << ", " << this->B << ", " << this->C << " ) ������" << std::endl;
        std::cout << std::endl;
    }
