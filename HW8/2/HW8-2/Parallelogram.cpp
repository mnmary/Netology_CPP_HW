#include "Parallelogram.h"
#include <iostream>
#include "MyException.h"


Parallelogram::Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B)
    {
        this->name = "��������������";
    }
Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "��������������";
    if (!((a == c) && (b == d)))
    {
        throw MyException("������ �������� ������. �������: ������� a � c ��� b � d �� �����");
    };
    if (!((A == C) && (B == D)))
    {
        throw MyException("������ �������� ������. �������: ���� A � C ��� B � D �� �����");
    };

}
    void Parallelogram::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }

