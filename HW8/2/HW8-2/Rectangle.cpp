#include "Rectangle.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


_Rectangle::_Rectangle(int a, int b) : Quad(a, b, a, b, 90, 90, 90, 90)
    {
        this->name = "�������������";
    }
_Rectangle::_Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "�������������";
    if (!((a == c) && (b == d)))
    {
        throw MyException("������ �������� ������. �������: ������� a � c ��� b � d �� �����");
    };
    if (!(compare4(A , B , C , D)&&(A == 90)))
    {
        throw MyException("������ �������� ������. �������: ���� �� ����� �� ����� 90 ��������");
    };
}
void _Rectangle::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }

