#include "Parallelogram.h"
#include <iostream>
#include "MyException.h"


Parallelogram::Parallelogram(int a, int b, int A, int B) //: Quad(a, b, a, b, A, B, A, B)
    {
        if ((a == 0) || (b == 0))
        {
            throw MyException("������ �������� ������ ��������������. �������: ���� �� ������ ����� 0");
        }
        if ((A * 2 + B * 2) != 360)
        {
            throw MyException("������ �������� ������ ��������������. �������: ����� ����� �� ����� 360");
        }

        this->cntPoint = 4;
        this->name = "��������������";
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
        this->A = A;
        this->B = B;
        this->C = A;
        this->D = B;
}
    void Parallelogram::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }

