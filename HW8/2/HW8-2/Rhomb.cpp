#include "Rhomb.h"
#include <iostream>
#include "MyException.h"

Rhomb::Rhomb(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B)
{
    this->name = "����";
}
void Rhomb::print_info()
{
    std::cout << this->name << "(������� " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; ����: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) ������" << std::endl;
    std::cout << std::endl;
}

