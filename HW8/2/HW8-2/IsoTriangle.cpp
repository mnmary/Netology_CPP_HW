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
    IsoTriangle::IsoTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->name = "�������������� �����������";
        if (!(a == c))
        {
            throw MyException("������ �������� ������. �������: ������� a � c �� �����");
        }
        if (!(A == C))
        {
            throw MyException("������ �������� ������. �������: ���� A � C �� �����");
        }
    }

