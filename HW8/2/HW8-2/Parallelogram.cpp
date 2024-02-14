#include "Parallelogram.h"
#include <iostream>
#include "MyException.h"


Parallelogram::Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B)
    {
        this->name = "��������������";
    }
    void Parallelogram::print_info()
    {
        std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
        std::cout << std::endl;
    }

