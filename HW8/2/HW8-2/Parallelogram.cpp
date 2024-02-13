#include "Parallelogram.h"
#include <iostream>
#include "MyException.h"


Parallelogram::Parallelogram(int a, int b, int A, int B) //: Quad(a, b, a, b, A, B, A, B)
    {
        if ((a == 0) || (b == 0))
        {
            throw MyException("Ошибка создания фигуры Параллелограмм. Причина: одна из сторон равна 0");
        }
        if ((A * 2 + B * 2) != 360)
        {
            throw MyException("Ошибка создания фигуры Параллелограмм. Причина: сумма углов не равна 360");
        }

        this->cntPoint = 4;
        this->name = "Параллелограмм";
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
        std::cout << this->name << "(стороны " << this->a << ", " << this->b << ", " << this->c << ", " << this->d << "; углы: " << this->A << ", " << this->B << ", " << this->C << ", " << this->D << " ) создан" << std::endl;
        std::cout << std::endl;
    }

