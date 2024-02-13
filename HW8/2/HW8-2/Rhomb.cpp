#include "Rhomb.h"
#include <iostream>
#include "MyException.h"

Rhomb::Rhomb(int a, int A, int B) //: Quad(a, a, a, a, A, B, A, B)
{
    if (a == 0)
    {
        throw MyException("������ �������� ������ ����. �������: ���� �� ������ ����� 0");
    }
    if (A * 2 + B * 2 != 360)
    {
        throw MyException("������ �������� ������ ����. �������: ����� ����� �� ����� 360");
    }
    this->cntPoint = 4;
    this->name = "����";
    this->a = a;
    this->b = a;
    this->c = a;
    this->d = a;
    this->A = A;
    this->B = B;
    this->C = A;
    this->D = B;
}
void Rhomb::print_info()
{
    std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
    std::cout << std::endl;
}

