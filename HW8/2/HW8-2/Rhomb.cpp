#include "Rhomb.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


Rhomb::Rhomb(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B)
{
    this->name = "����";
}
Rhomb::Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "����";
    if (!compare4(a , b , c , d))
    {
        throw MyException("������ �������� ������. �������: ������� �� �����");
    };
    if (!((A == C) && (B == D)))
    {
        throw MyException("������ �������� ������. �������: ���� a � c ��� b � d �� �����");
    };
}
void Rhomb::print_info()
{
    std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
    std::cout << std::endl;
}

