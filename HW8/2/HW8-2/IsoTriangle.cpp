#include "IsoTriangle.h"
#include <iostream>
#include "MyException.h"

    IsoTriangle::IsoTriangle(int a, int b, int A, int B) //: Triangle(a, b, a, A, B, A)
    {
        if ((a == 0) || (b == 0))
        {
            throw MyException("������ �������� ������ �������������� �����������. �������: ���� �� ������ ����� 0");
        }
        if ((A == 0) || (B == 0))
        {
            throw MyException("������ �������� ������ �������������� �����������. �������: ���� �� ����� ����� 0");
        }
        if (A * 2 + B != 180)
        {
            throw MyException("������ �������� ������ �������������� �����������. �������: ����� ����� �� ����� 180");
        }
        this->cntPoint = 3;
        this->name = "�������������� �����������";
        this->a = a;
        this->b = b;
        this->c = a;
        this->A = A;
        this->B = B;
        this->C = A;
    }
    void IsoTriangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << "; ����: " << this->A << ", " << this->B << ", " << this->C << " ) ������" << std::endl;
        std::cout << std::endl;
    }

