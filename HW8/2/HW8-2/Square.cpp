#include "Square.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


Square::Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90)
    {
        this->name = "�������";
    }
Square::Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "�������";
    if (!compare4(a , c , b , d))
    {
        throw MyException("������ �������� ������. �������: ������� �� �����");
    };
    if (!(compare4(A , B , C , D)&&(A == 90)))
    {
        throw MyException("������ �������� ������. �������: ���� �� ����� �� ����� 90 ��������");
    };

}
void Square::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }
