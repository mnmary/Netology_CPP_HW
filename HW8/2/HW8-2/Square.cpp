#include "Square.h"
#include <iostream>
#include "MyException.h"
#include "Utils.h"


Square::Square(int a) : Quad(a, a, a, a, 90, 90, 90, 90)
    {
        this->name = "Квадрат";
    }
Square::Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quad(a, b, c, d, A, B, C, D)
{
    this->name = "Квадрат";
    if (!compare4(a , c , b , d))
    {
        throw MyException("Ошибка создания фигуры. Причина: стороны не равны");
    };
    if (!(compare4(A , B , C , D)&&(A == 90)))
    {
        throw MyException("Ошибка создания фигуры. Причина: один из углов не равен 90 градусов");
    };

}
void Square::print_info()
    {
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
        std::cout << std::endl;
    }
