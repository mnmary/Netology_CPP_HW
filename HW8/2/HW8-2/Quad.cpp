#include "Quad.h"
#include <iostream>
#include "MyException.h"

Quad::Quad(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4, "���������������")
    {
        if ((a == 0) || (b == 0) || (c == 0) || (d == 0))
        {
            throw MyException("������ �������� ������. �������: ���� �� ������ ����� 0");
        }
        if ((A + B + C + D) != 360)
        {   
            throw MyException("������ �������� ������. �������: ����� ����� �� ����� 360");
        }
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;

        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;

    }
Quad::Quad() : Figure(4, "���������������")
{

}
void Quad::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }

