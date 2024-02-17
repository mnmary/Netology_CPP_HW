#include "EquTriangle.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


EquTriangle::EquTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {
        this->name = "�������������� �����������";
    }
    void EquTriangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c  << "; ����: " << this->A << ", " << this->B << ", " << this->C  << " ) ������" << std::endl;
        std::cout << std::endl;
    }

    EquTriangle::EquTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        this->name = "�������������� �����������";
        if (!compare3(a , b , c))
        {
            throw MyException("������ �������� ������. �������: ������� �� �����");
        };
        if (!(compare3(A , B , C)&&(A == 60)))
        {
            throw MyException("������ �������� ������. �������: ���� �� ����� 60 ��������");
        }
    }
