#include "Rhomb.h"
#include <iostream>
#include "MyException.h"

Rhomb::Rhomb(int a, int A, int B) : Quad(a, a, a, a, A, B, A, B)
{
    this->name = "Ромб";
}
void Rhomb::print_info()
{
    std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
    std::cout << std::endl;
}

